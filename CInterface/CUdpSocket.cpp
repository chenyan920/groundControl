#include "CUdpSocket.h"
#include <QObject>
#include <QTextCodec>

CUdpSocket::CUdpSocket(QObject* parent)
    :QObject(parent)
{
    mpUdpSocket = new QUdpSocket();
    init();
    connect(&mHeartBeatTimer, &QTimer::timeout, this, &CUdpSocket::heartBeat);
    mHeartBeatTimer.setInterval(5000);
    mHeartBeatTimer.start();
}

qint64 CUdpSocket::send(QString msg) const
{
    return mpUdpSocket->writeDatagram(msg.toLocal8Bit(),
                                 QHostAddress("115.29.240.46"),
                                 6000);
}

void CUdpSocket::slotReceiveMessage()
{
    QByteArray message;

    while (mpUdpSocket->hasPendingDatagrams())
    {
        message.resize(mpUdpSocket->pendingDatagramSize());
        int r = mpUdpSocket->readDatagram(message.data(),message.size());
        if(r == -1)
        {
            qDebug() << "接收数据失败";
        }
        else
        {
            qDebug() << "接收数据成功";
        }
    }

    QTextCodec *codec = QTextCodec::codecForName("GBK");
    QString string = codec->toUnicode(message);
    qDebug() << string;
    emit sigRecieveMsg(string);
}

void CUdpSocket::init()
{
    mpUdpSocket->writeDatagram("ep=K4PDDEC7MYDGXD7V&pw=123456",
                          mHost,
                          mPort);
    mpUdpSocket->bind(mHost,mPort);
    connect(mpUdpSocket,&QUdpSocket::readyRead,this,&CUdpSocket::slotReceiveMessage);
}

void CUdpSocket::heartBeat()
{
    send(".");
}
