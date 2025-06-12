#ifndef EXPENSECIRCLEITEM_H
#define EXPENSECIRCLEITEM_H

#endif // EXPENSECIRCLEITEM_H

#pragma once
#include <QQuickPaintedItem>
#include <QPainter>

class ExpenseCircleItem : public QQuickPaintedItem {
    Q_OBJECT
public:
    ExpenseCircleItem(QQuickItem *parent = nullptr) : QQuickPaintedItem(parent) {}
    void paint(QPainter *painter) override {
        painter->setBrush(Qt::blue);
        painter->drawEllipse(boundingRect());
    }
};
