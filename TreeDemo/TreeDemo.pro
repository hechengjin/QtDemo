#-------------------------------------------------
#
# Project created by QtCreator 2020-03-08T09:20:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TreeDemo
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    treeitem.cpp \
    treemodel.cpp \
    datadefine.cpp \
    filterwidget.cpp \
    mysortfilterproxymodel.cpp

HEADERS  += dialog.h \
    treeitem.h \
    treemodel.h \
    datadefine.h \
    datatype.h \
    filterwidget.h \
    mysortfilterproxymodel.h

RESOURCES += \
    style.qrc

DISTFILES +=
