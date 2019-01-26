#-------------------------------------------------
#
# Project created by QtCreator 2014-03-24T23:18:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ballbouncing
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    ball.cpp \
    coordinate.cpp \
    ground.cpp \
    pipes.cpp \
    guid.cpp

HEADERS  += dialog.h \
    ball.h \
    coordinate.h \
    ground.h \
    pipes.h \
    guid.h

FORMS    += dialog.ui

RESOURCES += \
    images.qrc
	
	RC_FILE += ico.rc
