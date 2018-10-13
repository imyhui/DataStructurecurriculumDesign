#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <Circle.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<Circle>("Union.Lotto.Circle", 1, 0, "Circle");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
    return app.exec();
}
