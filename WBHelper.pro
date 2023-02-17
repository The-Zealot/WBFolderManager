QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

VERSION = 1.0.6.0
QMAKE_TARGET_COMPANY = The_Zealot
QMAKE_TARGET_PRODUCT = WB Helper
QMAKE_TARGET_DESCRIPTION = Wildberries directory  manager
QMAKE_TARGET_COPYRIGHT = Yaroslav Solovev

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    config.cpp \
    main.cpp \
    mainwindow.cpp \
    settingsform.cpp

HEADERS += \
    config.h \
    mainwindow.h \
    mkdirPolicy.h \
    settingsform.h

FORMS += \
    mainwindow.ui \
    settingsform.ui

RC_ICONS = app.ico
#RC_FILE = resource.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
