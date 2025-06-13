TEMPLATE = app
QT += quick
CONFIG += c++11

SOURCES += main.cpp \
           wrappers.cpp

RESOURCES += qml.qrc

DISTFILES += App.qml

# Include the QML module
QT += qml

# Specify the minimum required Qt version
QT_MAJOR_VERSION = 6
QT_MINOR_VERSION = 0
QT_VERSION = $$QT_MAJOR_VERSION.$$QT_MINOR_VERSION

# Set the target name
TARGET = LambdaWithWrapper

# Set the output directory
DESTDIR = $$OUT_PWD/../bin

# Additional configurations can be added here if needed.