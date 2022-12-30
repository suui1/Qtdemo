QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    departmentview.cpp \
<<<<<<< HEAD \
    doctoreditview.cpp \
    doctorview.cpp \
    idatabase.cpp \
    loginview.cpp \
    main.cpp \
    masterview.cpp \
    patienteditview.cpp \
    patientview.cpp \
    welcomeview.cpp
    doctoreditview.cpp \
=======

    doctorview.cpp \
    idatabase.cpp \
    loginview.cpp \
    main.cpp \
    masterview.cpp \
    patienteditview.cpp \
    patientview.cpp \
    welcomeview.cpp

HEADERS += \
    departmentview.h \
<<<<<<< HEAD \
    doctoreditview.h \
    doctorview.h \
    idatabase.h \
    loginview.h \
    masterview.h \
    patienteditview.h \
    patientview.h \
    welcomeview.h
    doctoreditview.h \
=======
>>>>>>> 0c6a02efc5febbc04d53b9ab5847bc9493d1f3e6
    doctorview.h \
    idatabase.h \
    loginview.h \
    masterview.h \
    patienteditview.h \
    patientview.h \
    welcomeview.h

FORMS += \
    departmentview.ui \
<<<<<<< HEAD \
    doctoreditview.ui \
    doctorview.ui \
    loginview.ui \
    masterview.ui \
    patienteditview.ui \
    patientview.ui \
    welcomeview.ui
    doctoreditview.ui \
=======
>>>>>>> 0c6a02efc5febbc04d53b9ab5847bc9493d1f3e6
    doctorview.ui \
    loginview.ui \
    masterview.ui \
    patienteditview.ui \
    patientview.ui \
    welcomeview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    lab4.qrc \
    lab4.qrc
