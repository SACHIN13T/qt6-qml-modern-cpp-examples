#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "wrappers.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Load the main QML file
    engine.load(QUrl(QStringLiteral("qrc:/App.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    // Example of connecting a signal using a modern function wrapper
    auto rootObject = engine.rootObjects().first();
    connectLambda(rootObject, "someSignal", [](const QString &message) {
        qDebug() << "Received message:" << message;
    });

    return app.exec();
}