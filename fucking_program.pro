#-------------------------------------------------
#
# Project created by QtCreator 2019-12-31T08:54:53
#
#-------------------------------------------------

QT       += core gui sql webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = fucking_program
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    main_menu.cpp \
    mysql.cpp \
    signup.cpp \
    exif.cpp \
    widget.cpp \
    content.cpp \
    baseinfo.cpp \
    detail.cpp \
    contact.cpp

HEADERS  += mainwindow.h \
    main_menu.h \
    mysql.h \
    signup.h \
    exif.h \
    widget.h \
    content.h \
    baseinfo.h \
    detail.h \
    contact.h

FORMS    += mainwindow.ui \
    main_menu.ui \
    signup.ui \
    widget.ui

RC_FILE += app.rc

RESOURCES += \
    picture.qrc
