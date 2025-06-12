#ifndef BACKENDSERVICE_H
#define BACKENDSERVICE_H

#endif // BACKENDSERVICE_H

#pragma once
#include <QObject>
#include <QString>
#include <QDebug>

class BackendService : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString status READ status CONSTANT)
public:
    QString status() const { return "Backend Ready"; }

    Q_INVOKABLE void addExpense(const QString &desc, double amount) {
        qDebug() << "Expense Added:" << desc << amount;
    }
};
