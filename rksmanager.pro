# -------------------------------------------------
# Project created by QtCreator 2009-06-30T09:19:10
# -------------------------------------------------
QT += sql
TARGET = rksmanager
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    tourdialog.cpp \
    addteamdialog.cpp \
    match.cpp \
    league.cpp \
    randomgenerator.cpp \
    planningdialog.cpp \
    aboutdialog.cpp \
    selectmatchdialog.cpp \
    eventdialog.cpp \
    viewer/reporter.cpp \
    viewer/addmatchdialog.cpp \
    viewer/imageprovider.cpp \
    exporter.cpp \
    teaminfo.cpp
HEADERS += mainwindow.h \
    tourdialog.h \
    addteamdialog.h \
    player.h \
    match.h \
    common.h \
    league.h \
    randomgenerator.h \
    planningdialog.h \
    aboutdialog.h \
    selectmatchdialog.h \
    eventdialog.h \
    viewer/reporter.h \
    viewer/addmatchdialog.h \
    viewer/imageprovider.h \
    exporter.h \
    teaminfo.h
FORMS += mainwindow.ui \
    tourdialog.ui \
    addteamdialog.ui \
    planningdialog.ui \
    aboutdialog.ui \
    selectmatchdialog.ui \
    eventdialog.ui \
    viewer/reporter.ui \
    viewer/addmatchdialog.ui \
    teaminfo.ui
RESOURCES += icons.qrc

# Hack for Windows
INCLUDEPATH += ./viewer \
    ./
win32:CONFIG += console