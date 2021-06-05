QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 resources_big

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
    basketball.cpp \
    bipea.cpp \
    bucketzom.cpp \
    car.cpp \
    card.cpp \
    cherrybomb.cpp \
    fightbutton.cpp \
    footballzom.cpp \
    garlic.cpp \
    hatzom.cpp \
    highnut.cpp \
    icepea.cpp \
    item.cpp \
    jokerzom.cpp \
    land.cpp \
    levelscene.cpp \
    main.cpp \
    mainscene.cpp \
    norzom.cpp \
    nut.cpp \
    paperzom.cpp \
    pause.cpp \
    pea.cpp \
    peashooter.cpp \
    plant.cpp \
    potato.cpp \
    pumpkin.cpp \
    remove.cpp \
    rodzom.cpp \
    screenzom.cpp \
    store.cpp \
    sun.cpp \
    sunflower.cpp \
    zombie.cpp

HEADERS += \
    basketball.h \
    bipea.h \
    bucketzom.h \
    car.h \
    card.h \
    cherrybomb.h \
    config.h \
    fightbutton.h \
    footballzom.h \
    garlic.h \
    hatzom.h \
    highnut.h \
    icepea.h \
    item.h \
    jokerzom.h \
    land.h \
    levelscene.h \
    mainscene.h \
    norzom.h \
    nut.h \
    paperzom.h \
    pause.h \
    pea.h \
    peashooter.h \
    plant.h \
    potato.h \
    pumpkin.h \
    remove.h \
    rodzom.h \
    screenzom.h \
    store.h \
    sun.h \
    sunflower.h \
    zombie.h

FORMS += \
    mainscene.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
