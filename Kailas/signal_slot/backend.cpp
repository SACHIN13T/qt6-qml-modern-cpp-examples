#include "backend.h"

Backend::Backend(QObject *parent) : QObject(parent) {}

void Backend::receiveFromQml(const QString &message)
{
    qDebug() << "Received from QML:" << message;

    // You can emit a signal back to QML if needed
    emit sendToQml("Reply from C++ to QML: " + message);
}
