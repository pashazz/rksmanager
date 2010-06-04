#include "matchinfo.h"
#include "ui_matchinfo.h"
#include "imageprovider.h"
#include "playerinfo.h"

MatchInfo::MatchInfo(QWidget *parent,Match m) :
    QDialog(parent),
    m_ui(new Ui::MatchInfo)
{
    //UI setup
    m_ui->setupUi(this);
    //loading emblems & score
    QString score;
    score.append(m.home.club.displayName);
    score.append(" " + QVariant(m.home.goals).toString() + " - " + QVariant(m.away.goals).toString());
    score.append(" " + m.away.club.displayName);
    m_ui->lblScore->setText(score);
    m_ui->lblAwayPict->setPixmap(ImageProvider::getClubEmblem(m.away.club.name));
    m_ui->lblHomePict->setPixmap(ImageProvider::getClubEmblem(m.home.club.name));

    //стартовый состав
    foreach (Player p, m.home.start) {
        m_ui->lstHomeStart->addItem(p.name);

    }
    foreach (Player p, m.away.start) {
       m_ui->lstAwayStart->addItem(p.name);
    }
   //события
    foreach (Player p, m.home.golaedors) {
        QListWidgetItem *it = new QListWidgetItem (0);
        it->setIcon(QIcon(":/images/images/ball.png"));
        it->setFlags(Qt::ItemIsEnabled);
        it->setText(p.name);
        m_ui->lstHomeEvents->addItem(it);
    }
    foreach (Player p, m.home.yellowCards) {
             QListWidgetItem *it = new QListWidgetItem (0);
        it->setIcon(QIcon(":/images/images/whistle.png"));
        it->setFlags(Qt::ItemIsEnabled);
        it->setText(p.name);
        m_ui->lstHomeEvents->addItem(it);

    }
          foreach (Player p, m.home.redCards) {
             QListWidgetItem *it = new QListWidgetItem (0);
        it->setIcon(QIcon(":/images/images/cards.png"));
        it->setFlags(Qt::ItemIsEnabled);
        it->setText(p.name);
        m_ui->lstHomeEvents->addItem(it);

             foreach (Player p, m.home.traumas) {
             QListWidgetItem *it = new QListWidgetItem (0);
        it->setIcon(QIcon(":/images/images/boots.png"));
        it->setFlags(Qt::ItemIsEnabled);
        it->setText(p.name);
        m_ui->lstHomeEvents->addItem(it);
    }
    }
          match = &m;
          //connects
 connect(m_ui->lstHomeStart, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(viewPlayer(QListWidgetItem*)));
  connect(m_ui->lstAwayStart, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(viewPlayer(QListWidgetItem*)));
  connect(m_ui->lstAwayEvents, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(viewPlayer(QListWidgetItem*)));
  connect(m_ui->lstHomeEvents, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(viewPlayer(QListWidgetItem*)));

}

MatchInfo::~MatchInfo()
{
    delete m_ui;
}

void MatchInfo::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MatchInfo::viewPlayer(QListWidgetItem *it) {
Player p;
Club c;
bool isShow = false;
foreach (Player pl, match->home.club.players) {
    if (pl.name == it->text()) {
    isShow = true;
    c= match->home.club;
    p = pl;}
}

foreach (Player pl, match->away.club.players){
    if (pl.name == it->text()) {
            c= match->away.club;

    isShow = true;
    p = pl;}
}
if (isShow) {
    PlayerInfo *dlg = new PlayerInfo (this, p, c);
    dlg->exec();
}

}
