#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQmlContext>
#include"cppcode.h"
#include<QRect>
#include<QScreen>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

      qmlRegisterType<Cppcode>("Abcd",1,0,"Myobj");

     QQmlApplicationEngine engine;
     QQmlContext *context=engine.rootContext();
     QScreen *screen=QGuiApplication::primaryScreen();
       QRect rect=screen->virtualGeometry();

       context->setContextProperty("mywidth",rect.width());
       context->setContextProperty("myheight",rect.height());


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
