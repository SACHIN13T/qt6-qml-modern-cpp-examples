#ifndef EXPENSEITEM_H
#define EXPENSEITEM_H

#endif // EXPENSEITEM_H

#pragma once
#include <QObject>

class ExpenseItem : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(double amount READ amount WRITE setAmount NOTIFY amountChanged)

public:
    QString m_description;
    double m_amount = 0.0;

    QString description() const { return m_description; }
    void setDescription(const QString &d) {
        if (d != m_description) {
            m_description = d;
            emit descriptionChanged();
        }
    }

    double amount() const { return m_amount; }
    void setAmount(double a) {
        if (a != m_amount) {
            m_amount = a;
            emit amountChanged();
        }
    }

signals:
    void descriptionChanged();
    void amountChanged();
};
