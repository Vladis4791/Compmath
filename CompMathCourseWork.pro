QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chart.cpp \
    ellipsemodel.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix.cpp \
    model.cpp \
    CalculationMethods/ClassicFourthRKMethod/classicfourthrkmethod.cpp \
    CalculationMethods/method.cpp \
    Functions/function.cpp \
    point3d.cpp

HEADERS += \
    chart.h \
    ellipsemodel.h \
    mainwindow.h \
    matrix.hpp \
    model.h \
    CalculationMethods/ClassicFourthRKMethod/classicfourthrkmethod.h \
    CalculationMethods/method.h \
    Functions/function.h \
    point3d.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
