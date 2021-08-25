#ifndef CI_H
#define CI_H

//海康接口2QML
#include <QObject>
#include "../OpenNetStream/opennetstream.h"
#include "CEnum.h"
#include "CameraListModel.h"
#include "localsetting.h"
#include <QVariant>
#include <QModelIndex>
#include <QCoreApplication>
#define PTZSPEED 1

typedef struct tagDeviceTableViewInfo
{
    QString strSubserial;
    int iChannelNo;
    bool bEncrypt;
    int  iVideoLevel;
}DeviceTableViewInfo;

class CI : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant cameraModel READ cameraModel NOTIFY cameraModelChanged)

public:
    explicit CI(QObject* parent = nullptr);
    ~CI();

    Q_INVOKABLE void test();
    Q_INVOKABLE void authLogin();
    Q_INVOKABLE void updateDeviceList();
    Q_INVOKABLE int startRealPlay(int videoLevel);
    Q_INVOKABLE void ptzControl(int emDirect, int speed = PTZSPEED);
    Q_INVOKABLE void ptzStop(int emDirect, int speed = PTZSPEED);

    QVariant cameraModel() const {return QVariant::fromValue(mDeviceTableModel);}  
    Q_SIGNAL void cameraModelChanged(const CameraListModel* mDeviceTableModel);

    static void __stdcall messageHandler(const char* szSessionId, unsigned int iMsgType, unsigned int iErrorCode,const char *pMessageInfo, void *pUser);
    static void __stdcall videoDataHandler(DataType enType, char* const pData, int iLen, void* pUser);

    void setVideoPath(const QString devSerial);

public:
    static HWND mHWND;

private:
    bool GetDeviceTableViewInfo(DeviceTableViewInfo& stDeviceInfo, int currentIndex = 0);

private:
    QString mAcToken;
    CameraListModel* mDeviceTableModel;

    QString mSessionId;
    QString mDevSerial;
    int mChannel;

    QString mVideoPath;
};

#endif // CI_H
