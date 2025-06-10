#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include "applicatiodata.h"
#include <QQmlContext>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;

    ApplicatioData data;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("applicationData", &data);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QtQmlPrac", "Main");

    return app.exec();
}
