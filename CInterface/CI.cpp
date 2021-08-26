#include "CI.h"
#include <QtDebug>
#include "localsetting.h"
#include <QModelIndex>

HWND CI::mHWND = nullptr;

CI::CI(QObject* parent)
    :QObject(parent)
{
    mDeviceTableModel = new CameraListModel();

    OpenNetStream::getInstance()->initLibrary(LocalSetting::getInstance()->authAddress(), LocalSetting::getInstance()->platformAddress(), LocalSetting::getInstance()->appKey());
    QString areaID = LocalSetting::getInstance()->areaId();
    if (!areaID.isEmpty())
    {
        OpenNetStream::getInstance()->setAreaID(areaID);
    }
    QString loginVer = LocalSetting::getInstance()->loginVer();
    if (!loginVer.isEmpty())
    {
        OpenNetStream::getInstance()->setLoginVer(loginVer);
    }
    if (LocalSetting::getInstance()->dataUtf8())
    {
        OpenNetStream::getInstance()->setDataUtf8();
    }

    if (LocalSetting::getInstance()->streamTrans())
    {
        OpenNetStream::getInstance()->setStreamTrans();
    }

    if (LocalSetting::getInstance()->closeP2P())
    {
        OpenNetStream::getInstance()->closeP2P();
    }

    int iP2PMaxNum = LocalSetting::getInstance()->P2PMaxNum();
    if (iP2PMaxNum > 0)
    {
        OpenNetStream::getInstance()->setP2PMaxNum(iP2PMaxNum);
    }

    int iP2PCheckPeriod = LocalSetting::getInstance()->P2PCheckPeriod();
    if (iP2PCheckPeriod > 0)
    {
        OpenNetStream::getInstance()->setP2PCheckPeriod(iP2PCheckPeriod);
    }

    int iP2PExpire = LocalSetting::getInstance()->P2PExpire();
    if (iP2PExpire > 0)
    {
        OpenNetStream::getInstance()->setP2PExpire(iP2PExpire);
    }
    int iLogLevel = LocalSetting::getInstance()->logLevel();
    if (iLogLevel > 0)
    {
        OpenNetStream::getInstance()->setLogLevel(iLogLevel);
    }

    mSessionId = OpenNetStream::getInstance()->allocSessionEx(CI::messageHandler, this);
}

CI::~CI()
{
    OpenNetStream::getInstance()->freeSession(mSessionId);
    OpenNetStream::getInstance()->releaseLibrary();
}

void CI::test()
{
    qDebug() << "test";
}

void CI::authLogin()
{    
    mAcToken = OpenNetStream::getInstance()->login();
    if (mAcToken.isEmpty())
    {
        return ;
    }
    OpenNetStream::getInstance()->setAccessToken(mAcToken);
    const char* pTokenExpireTime = OpenNetStream::getInstance()->getTokenExpireTime();
    if (pTokenExpireTime != nullptr)
    {
        qDebug() << __LINE__ << __FUNCTION__ << "Token Expire Time:" << pTokenExpireTime;
    }
    const char* pAreaDomain = OpenNetStream::getInstance()->getAreaDomain();
    if (pAreaDomain != nullptr)
    {
        qDebug() << __LINE__ << __FUNCTION__ << "Platform Domain:" << pAreaDomain;
    }
    // mpMainWindow->on_deviceListButton_clicked();
    updateDeviceList();
}

void CI::updateDeviceList()
{
    int lPageStart = LocalSetting::getInstance()->PageStart();
    int lPageSize = LocalSetting::getInstance()->PageSize();
    int pageStart = 0;
    if(lPageStart > 0)
    {
        pageStart = lPageStart;
    }
    int pageSize = 1000;
    if (lPageSize > 0)
    {
        pageSize = lPageSize;
    }
    void* pBuf = nullptr;
    int length = 0;

    int iRet = OpenNetStream::getInstance()->getDevListEx(pageStart, pageSize, &pBuf, &length);
    if (iRet != OPEN_SDK_NOERROR)
    {
        qDebug() << "Get Device List failed!";
        return ;
    }
    QString json;
    if (LocalSetting::getInstance()->dataUtf8())
    {
        json = static_cast<char*>(pBuf);
    }
    else
    {
        json = QString::fromLocal8Bit(static_cast<char*>(pBuf));
    }

    OpenNetStream::getInstance()->freeData(pBuf);

    QByteArray jsonByte = json.toUtf8();
    mDeviceTableModel->setCameraModel(jsonByte);
}

int CI::startRealPlay(int videoLevel)
{
    DeviceTableViewInfo stDeviceInfo;
    if (GetDeviceTableViewInfo(stDeviceInfo) == false)
    {
        return -1;
    }

    bool bEncrypt = stDeviceInfo.bEncrypt;
    QString devSerial = stDeviceInfo.strSubserial;
    int iChannelNo = stDeviceInfo.iChannelNo;

    mDevSerial = devSerial;
    mChannel = iChannelNo;

    QString safekey = "GVOBHC";
    setVideoPath(devSerial);
    OpenNetStream::getInstance()->setDataCallBack(mSessionId, videoDataHandler, this);

    HWND hWnd = nullptr;
    if (LocalSetting::getInstance()->isPlay())
    {
        hWnd = mHWND;
    }
    int iRet = OpenNetStream::getInstance()->startRealPlay(mSessionId, hWnd, devSerial, iChannelNo, safekey);

    //	m_bRealPlayStarted = true;
    //    m_bCloudPlayBack = false;
    //    m_bPlayBackStarted = false;
    return 0;
}

void CI::ptzControl(int emDirect, int speed)
{
    if (mDevSerial.isEmpty()) {
        //TODO 调试模式信息QMessageBox::information(this, tr("PTZ Control"), tr("Please start real play before PTZ Control"));
        return;
    }
    if (speed < 0 || speed > 7) {
        speed = PTZSPEED;
    }
    int iRet = 0;

    switch (emDirect)
    {
    case CEnum::DIRECTUP:
        iRet = OpenNetStream::getInstance()->PTZCtrl(mSessionId, mDevSerial, mChannel, UP, START, speed);
        break;
    case CEnum::DIRECTDOWN:
        iRet = OpenNetStream::getInstance()->PTZCtrl(mSessionId, mDevSerial, mChannel, DOWN, START, speed);
        break;
    case CEnum::DIRECTLEFT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(mSessionId, mDevSerial, mChannel, LEFT, START, speed);
        break;
    case CEnum::DIRECTRIGHT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(mSessionId, mDevSerial, mChannel, RIGHT, START, speed);
        break;
    default:
        break;
    }
    qDebug() <<"----------------------------" <<
               iRet;
    //TODO 调试模式信息
    //    if (iRet != OPEN_SDK_NOERROR)
    //    {
    //        this->showErrInfo(tr("PTZ Control failed!"));
    //    }
}

void CI::ptzStop(int emDirect, int speed)
{
    int iRet = 0;

    if (speed < 0 || speed > 7) {
        speed = PTZSPEED;
    }

    switch (emDirect)
    {
    case CEnum::DIRECTUP:
        iRet = OpenNetStream::getInstance()->PTZCtrl(mSessionId, mDevSerial, mChannel, UP, STOP, speed);
        break;
    case  CEnum::DIRECTDOWN:
        iRet = OpenNetStream::getInstance()->PTZCtrl(mSessionId, mDevSerial, mChannel, DOWN, STOP, speed);
        break;
    case  CEnum::DIRECTLEFT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(mSessionId, mDevSerial, mChannel, LEFT, STOP, speed);
        break;
    case  CEnum::DIRECTRIGHT:
        iRet = OpenNetStream::getInstance()->PTZCtrl(mSessionId, mDevSerial, mChannel, RIGHT, STOP, speed);
        break;
    default:
        break;
    }
    //TODO 调试模式信息
    //	if (iRet != OPEN_SDK_NOERROR)
    //	{
    //		this->showErrInfo(tr("PTZ Control failed."));
    //	}
}

void CI::messageHandler(const char *szSessionId, unsigned int iMsgType, unsigned int iErrorCode, const char *pMessageInfo, void *pUser)
{
    return;
}

void CI::videoDataHandler(DataType enType, char * const pData, int iLen, void *pUser)
{
    return;
}

void CI::setVideoPath(const QString devSerial)
{
    struct tm t;
    time_t now;
    time(&now);
    localtime_s(&t, &now);
    const int buflen = 32;
    char buffer[buflen] = {0};
    strftime(buffer, buflen, "%Y%m%d%H%M%S", &t);
    const QString strFlag = devSerial + "_" + buffer;
    QString path = QCoreApplication::applicationDirPath();
    mVideoPath = path + "/" + strFlag + ".mp4";
}

bool CI::GetDeviceTableViewInfo(DeviceTableViewInfo &stDeviceInfo, int currentIndex)
{
    QModelIndex index = mDeviceTableModel->index(currentIndex, 0);

    stDeviceInfo.strSubserial = mDeviceTableModel->getSerial(index);
    stDeviceInfo.iChannelNo = mDeviceTableModel->getCameraNo(index);
    stDeviceInfo.bEncrypt = mDeviceTableModel->getIsEncrypt(index);
    stDeviceInfo.iVideoLevel = mDeviceTableModel->getVideoLevel(index);
    qDebug() << stDeviceInfo.strSubserial << stDeviceInfo.iChannelNo << stDeviceInfo.bEncrypt << stDeviceInfo.iVideoLevel;
    return true;
}
