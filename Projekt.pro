#-------------------------------------------------
#
# Project created by QtCreator 2015-06-04T18:13:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projekt
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    ship.cpp \
    player.cpp \
    battleship.cpp \
    cruiser.cpp \
    destroyer.cpp \
    classwindow.cpp \
    summit.cpp \
    enemy.cpp \
    upgradewindow.cpp

HEADERS  += mainwindow.h \
    ship.h \
    gameplayfunctions.h \
    player.h \
    battleship.h \
    cruiser.h \
    destroyer.h \
    classwindow.h \
    summit.h \
    enemy.h \
    upgradewindow.h

FORMS    += mainwindow.ui \
    classwindow.ui \
    upgradewindow.ui
