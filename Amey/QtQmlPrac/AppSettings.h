#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#endif // APPSETTINGS_H
#pragma once
#include <QObject>

class AppSettings : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString currency READ currency CONSTANT)
public:
    QString currency() const { return "INR"; }
};
