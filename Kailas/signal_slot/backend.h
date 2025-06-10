#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QDebug>

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = nullptr);

signals:
    void sendToQml(const QString &message);  // signal to QML

public slots:
    void receiveFromQml(const QString &message);  // slot to be called from QML
};

#endif // BACKEND_H
