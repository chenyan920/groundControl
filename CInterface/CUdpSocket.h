#ifndef CUDPSOCKET_H
#define CUDPSOCKET_H

#include <QObject>
#include <QUdpSocket>
#include <QTimer>

class CUdpSocket : public QObject
{
    Q_OBJECT

public:
    explicit CUdpSocket(QObject* parent = nullptr);

    Q_INVOKABLE qint64 send(QString msg) const;

    Q_SLOT void slotReceiveMessage();
    Q_SIGNAL void sigRecieveMsg(QString msg);

private:
    void init();
    void heartBeat();

private:
    QUdpSocket * mpUdpSocket;
    QHostAddress mHost = QHostAddress("115.29.240.46");
    quint16 mPort = 6000;
    QTimer mHeartBeatTimer;
};

#endif // CUDPSOCKET_H
