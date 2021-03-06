QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11 #aggiunto da codice amico paolo, vedere se serve!
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addclientwindow.cpp \
    cliente.cpp \
    controller.cpp \
    info.cpp \
    main.cpp\
    mainwindow.cpp \
    model.cpp \
    modifyclientwindow.cpp \
    palestra.cpp\
    piscina.cpp\
    viewlistaclienti.cpp \
    vip.cpp

HEADERS += \
    addclientwindow.h \
    cliente.h\
    container.h \
    controller.h \
    deeppointer.h \
    info.h \
    mainwindow.h \
    model.h \
    modifyclientwindow.h \
    palestra.h\
    piscina.h\
    viewlistaclienti.h \
    vip.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Risorse.qrc
