#include "ValuesFromC.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlEngine>
#include <QtQuick>
#include <QTimer>

int main(int argc, char* argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    ValuesFromC valueC;
    valueC.setName("boczek");
    qmlRegisterSingletonType<ValuesFromC>("pl.nstrefa.avrkwiat", 1, 0, "ValueC",
                                     [&](QQmlEngine *, QJSEngine *) -> QObject * {
        return &valueC;
    });

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.addImportPath(":/qml");
    engine.addImportPath(":/qml/imports");
    engine.addImportPath(":/qml/asset_imports");
    engine.load(url);

    // Update the Role from C++ after 3 seconds.
//    QTimer* timer = new QTimer(&app);
//    timer->start(3000);
//    QObject::connect(timer, &QTimer::timeout, &user, &User::nameChanged);

    return app.exec();
}
