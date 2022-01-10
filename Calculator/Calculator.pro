QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#Give qmake information about the application's configuration.
CONFIG += c++11

#Source files that implement the application.
SOURCES += \
    main.cpp \
    calculator.cpp

# Used to specify this file created for use by the application.
HEADERS += \
    calculator.h

#Implement the User Interface.
FORMS += \
    calculator.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#Implement the resources file
RESOURCES += \
    Resources.qrc

#Add an icon to application form
RC_ICONS = calculator_icon.ico
