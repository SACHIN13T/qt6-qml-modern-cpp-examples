#ifndef WRAPPERS_H
#define WRAPPERS_H

#include <QObject>
#include <functional>

template<typename... Args>
using SignalSlotFunction = std::function<void(Args...)>;

template<typename Sender, typename... Args>
void connectSignal(Sender* sender, const char* signal, QObject* receiver, SignalSlotFunction<Args...> slot) {
    QObject::connect(sender, signal, [=](Args... args) {
        slot(args...);
    });
}

#endif // WRAPPERS_H