#ifndef APPLICATIODATA_H
#define APPLICATIODATA_H

#include <QObject>
#include <QDateTime>
#include <QQuickView>

class ApplicatioData : public QObject
{
    Q_OBJECT
public:
    ApplicatioData();
    Q_INVOKABLE QDateTime getCurrentDateTime() const {
        return QDateTime::currentDateTime();
    }
};

#endif // APPLICATIODATA_H
