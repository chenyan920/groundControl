#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QTextCodec>
#include <QTranslator>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include "CInterface/CI.h"
#include "CInterface/CUdpSocket.h"
#include <QQuickStyle>
#include <QIcon>
#include <QQmlContext>
#include <QQmlComponent>
#include "CInterface/CEnum.h"
#include <QWindow>
#include <QWidget>
#include <QPalette>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QIcon::setThemeName("automotive");
    // QQuickStyle::setStyle("Material");
    qmlRegisterType<CUdpSocket>("CI", 1, 0, "CUdpSocket");
    qmlRegisterType<CEnum>("CI", 1, 0, "CEnum");
    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    CI ci;
    engine.rootContext()->setContextProperty("CI", &ci);
    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;
    QObject *QmlObj= engine.rootObjects().first();
    const QRect &rect = QmlObj->property("viedoRect").value<QRect>();
    QWindow *QmlWindow=qobject_cast<QWindow *>(QmlObj);
    WId parent_HWND = QmlWindow->winId();
    QWidget Widget;
    QPalette pal(Widget.palette());
    pal.setColor(QPalette::Background, Qt::transparent);
    Widget.setAutoFillBackground(true);
    Widget.setPalette(pal);

    Widget.setProperty("_q_embedded_native_parent_handle",QVariant(parent_HWND));
    Widget.setGeometry(rect.x(),rect.y(),rect.width(),rect.height());
    WId wHWND = Widget.winId();
    Widget.windowHandle()->setParent(QmlWindow);
    HWND hWnd = reinterpret_cast<HWND>(wHWND);
    CI::mHWND = hWnd;
    Widget.show();
    return app.exec();
}
