#include "wrappers.h"
#include <QMetaObject>
#include <QPointer>

template<typename... Args>
void connect(QObject* sender, const char* signal, QObject* receiver, std::function<void(Args...)> slot) {
    auto lambdaSlot = [slot](Args... args) {
        slot(args...);
    };
    QMetaObject::Connection connection = QObject::connect(sender, signal, lambdaSlot);
    if (connection) {
        // Store the connection if needed for later disconnection
    }
}

template<typename... Args>
void connect(QPointer<QObject> sender, const char* signal, QObject* receiver, std::function<void(Args...)> slot) {
    if (sender) {
        connect(sender.data(), signal, receiver, slot);
    }
}