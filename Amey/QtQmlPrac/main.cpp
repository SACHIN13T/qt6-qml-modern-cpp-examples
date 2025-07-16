// main.cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickPaintedItem>
#include <QPainter>
#include "BackendService.h"
#include "ExpenseItem.h"
#include "AppSettings.h"
#include "ExpenseCircleItem.h"
#include "expensemodel.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    BackendService backend;
    engine.rootContext()->setContextProperty("backendService", &backend);

    ExpenseModel expenseModel;
    engine.rootContext()->setContextProperty("expensemodel", &expenseModel);
    engine.load(QUrl("qrc:/ExpenseListView.qml"));

    qmlRegisterType<ExpenseItem>("App.Models", 1, 0, "ExpenseItem");

    qmlRegisterSingletonType<AppSettings>("App.Config", 1, 0, "AppSettings",
                                          [](QQmlEngine*, QJSEngine*) -> QObject* {
                                              return new AppSettings();
                                          });

    qmlRegisterType<ExpenseCircleItem>("App.Visuals", 1, 0, "ExpenseCircle");
    \
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QtQmlPrac", "Main");


    return app.exec();
}
