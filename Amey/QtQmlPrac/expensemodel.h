#pragma once
#include <QAbstractListModel>
#include <QList>

struct Expense {
    QString description;
    double amount;
};

class ExpenseModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles {
        DescriptionRole = Qt::UserRole + 1,
        AmountRole
    };

    explicit ExpenseModel(QObject *parent = nullptr) : QAbstractListModel(parent) {
        // Add some sample data (optional)
        m_expenses.append({"Coffee", 120});
        m_expenses.append({"Taxi", 300});
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return m_expenses.count();
    }

    QVariant data(const QModelIndex &index, int role) const override {
        if (!index.isValid() || index.row() >= m_expenses.count())
            return QVariant();

        const Expense &expense = m_expenses.at(index.row());
        if (role == DescriptionRole)
            return expense.description;
        else if (role == AmountRole)
            return expense.amount;
        return QVariant();
    }

    QHash<int, QByteArray> roleNames() const override {
        return {
            {DescriptionRole, "description"},
            {AmountRole, "amount"}
        };
    }

    Q_INVOKABLE void addExpense(const QString &desc, double amount) {
        beginInsertRows(QModelIndex(), m_expenses.count(), m_expenses.count());
        m_expenses.append({desc, amount});
        endInsertRows();
    }

private:
    QList<Expense> m_expenses;
};
