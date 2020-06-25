QT       += core gui opengl sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    datamanager.cpp \
    main.cpp \
    maincontroller.cpp \
    mainwindow.cpp \
    openglview.cpp \
    perceptron.cpp

HEADERS += \
    maincontroller.h \
    models/cell.h \
    constants.h \
    datamanager.h \
    mainwindow.h \
    openglview.h \
    models/point.h \
    perceptron.h \
    utils.h \
    view.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
