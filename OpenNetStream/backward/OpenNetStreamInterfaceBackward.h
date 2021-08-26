/** \file      OpenNetStreamInterfaceBackward.h
 *  \copyright HangZhou Ezviz All Right Reserved.
 *  \brief     开放SDK向后兼容接口定义
 *
 *  \author    pikongxuan
 *  \date      2015/07/31
 *
 *  \note      history:
 *  \note      V2.4.1 2015/07/31 
 */

#ifndef _H_OPENNETSTREAMINTERFACE_BACKWARD_H_
#define _H_OPENNETSTREAMINTERFACE_BACKWARD_H_

#ifdef __GNUC__
#define DEPRECATED(func)  func __attribute__ ((deprecated))
#elif defined(_MSC_VER)
#define DEPRECATED(func) __declspec(deprecated) func
#endif


#include "OpenNetStreamBackwardWarning.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup alloc 分配会话
 *  @{
 */

/** 
 *  \brief 申请一个会话Id
 *  \param[in]  pHandle     设置回调函数， #OpenSDK_MessageHandler
 *  \param[in]  pUser       用户自定义数据，会在pHandle中原样抛出
 *  \param[out] pSession    用于接收分配的会话ID
 *  \param[out] iSessionLen pSession的长度
 *  \return 0表示成功，-1表示失败
 *  \sa OpenSDK_FreeSession()
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_AllocSession_Old(OpenSDK_MessageHandler pHandle, void* pUser, char** pSession, int* iSessionLen));


/** 
 *  \brief 申请一个会话Id
 *  \param[in]  pHandle     设置回调函数， #OpenSDK_MessageHandler
 *  \param[in]  pUser       用户自定义数据，会在pHandle中原样抛出
 *  \param[out] pSession    用于接收分配的会话ID
 *  \param[out] iSessionLen pSession的长度
 *	\param[in]  bSync		设置同步，默认为异步
 *	\param[in]	iTimeOut	同步等待时长， 默认0xEA60=1min
 *  \return 0表示成功，-1表示失败
 *  \sa OpenSDK_FreeSession()
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_AllocSession(OpenSDK_MessageHandler pHandle, void* pUser, char** pSession, int* iSessionLen, const bool bSync = false,const unsigned int iTimeOut = 0xEA60));

/** @} */ // end of alloc

/** \defgroup play 预览接口
 *  @{
 */

/** 
 *  \brief 预览
 *  \param[in] szSessionId   会话ID
 *  \param[in] hPlayWnd      播放窗口句柄 
 *  \param[in] szCameraId    监控点ID
 *  \param[in] szAccessToken 认证token
 *  \param[in] iVideoLevel   视频质量，输入范围在0-2之间
 *  \param[in] szSafeKey	 视频加密密钥 
 *  \param[in] szAppKey      从平台获取的AppKey
 *  \return 0表示成功，非0表示失败
 *  \sa OpenSDK_StopRealPlay()
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StartRealPlay_Old(const char* szSessionId, HWND hPlayWnd, const char* szCameraId, const char* szAccessToken, int iVideoLevel, const char* szSafeKey, const char* szAppKey));

/** 
 *  \brief 预览
 *  \param[in] szSessionId   会话ID
 *  \param[in] hPlayWnd      播放窗口句柄, 如果窗口句柄为NULL表示纯粹取流，不做播放
 *  \param[in] szCameraId    监控点ID
 *  \param[in] szAccessToken 认证token
 *  \param[in] iVideoLevel   视频质量，输入范围在0-2之间
 *  \param[in] szSafeKey	 视频加密密钥 
 *  \param[in] szAppKey      从平台获取的AppKey
 *	\param[out] pNSCBMsg	 同步回调传出参数,如果为同步，不允许为NULL
 *  \return 0表示成功，非0表示失败
 *  \sa OpenSDK_StopRealPlay()
 *	\sa OpenSDK_SetDataCallBack
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StartRealPlay(const char* szSessionId, HWND hPlayWnd, const char* szCameraId, const char* szAccessToken, int iVideoLevel, const char* szSafeKey, const char* szAppKey, LP_NSCBMsg pNSCBMsg = NULL));


/** 
 *  \brief 停止预览
 *  \param[in] szSessionId 会话ID
 *  \return 0表示成功，非0表示失败
 *  \sa OpenSDK_StartRealPlay()
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StopRealPlay_Old(const char* szSessionId));

/** 
 *  \brief 停止预览
 *  \param[in] szSessionId 会话ID
 *	\param[out] pNSCBMsg   同步回调传出参数,如果为同步，不允许为NULL
 *  \return 0表示成功，非0表示失败
 *  \sa OpenSDK_StartRealPlay()
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StopRealPlay(const char* szSessionId, LP_NSCBMsg pNSCBMsg = NULL));

/** @} */ // end of play

/** \defgroup playback 回放接口
 *  @{
 */

/** 
 *  \brief 回放
 *  \param[in] szSessionId   会话Id
 *  \param[in] hPlayWnd      播放窗口句柄
 *  \param[in] szCameraId    监控点ID
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szSafeKey     视频加密密钥
 *  \param[in] szStartTime   开始时间
 *  \param[in] szStopTime    停止时间
 *  \param[in] szAppKey      从平台获取的AppKey
 *  \return 0表示成功，非0表示失败
 *  \sa OpenSDK_StopPlayBack()
 *  \note 
 *  时间格式为：yyyy-MM-dd hh:mm:ss
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StartPlayBack_Old(const char* szSessionId, HWND hPlayWnd, const char* szCameraId, const char* szAccessToken, const char* szSafeKey, const char* szStartTime, const char* szStopTime, const char* szAppKey));


/** 
 *  \brief 回放
 *  \param[in] szSessionId   会话Id
 *  \param[in] hPlayWnd      播放窗口句柄
 *  \param[in] szCameraId    监控点ID
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szSafeKey     视频加密密钥
 *  \param[in] szStartTime   开始时间
 *  \param[in] szStopTime    停止时间
 *  \param[in] szAppKey      从平台获取的AppKey
 *	\param[out] pNSCBMsg	 同步回调传出参数,如果为同步，不允许为NULL
 *  \return 0表示成功，非0表示失败
 *  \sa OpenSDK_StopPlayBack()
 *  \note 
 *  时间格式为：yyyy-MM-dd hh:mm:ss
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StartPlayBack(const char* szSessionId, HWND hPlayWnd, const char* szCameraId, const char* szAccessToken, const char* szSafeKey, const char* szStartTime, const char* szStopTime, const char* szAppKey, LP_NSCBMsg pNSCBMsg = NULL));

/** 
 *  \brief 停止回放
 *  \param[in] szSessionId 会话Id
 *  \return 0表示成功，非0表示失败
 *	\sa OpenSDK_StartPlayBack()
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StopPlayBack_Old(const char* szSessionId));

/** 
 *  \brief 停止回放
 *  \param[in] szSessionId 会话Id
 *	\param[out] pNSCBMsg   同步回调传出参数,如果为同步，不允许为NULL
 *  \return 0表示成功，非0表示失败
 *	\sa OpenSDK_StartPlayBack()
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StopPlayBack(const char* szSessionId, LP_NSCBMsg pNSCBMsg = NULL));

/** 
 *  \brief 录像搜索，包含云存储和设备SD卡录像
 *  \param[in] szSessionId   会话Id
 *  \param[in] szCameraId    监控点Id
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szStartTime   开始时间
 *  \param[in] szStopTime    停止时间 
 *  \return 0表示成功，非0表示失败 
 *  \note
 *  时间格式为：yyyy-MM-dd hh:mm:ss
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StartSearch_Old(const char* szSessionId, const char* szCameraId, const char* szAccessToken, const char* szStartTime, const char* szStopTime));

/** 
 *  \brief 录像搜索，包含云存储和设备SD卡录像
 *  \param[in] szSessionId   会话Id
 *  \param[in] szCameraId    监控点Id
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szStartTime   开始时间
 *  \param[in] szStopTime    停止时间 
 *	\param[out] pNSCBMsg	 同步回调传出参数,如果为同步，不允许为NULL
 *  \return 0表示成功，非0表示失败 
 *  \note
 *  时间格式为：yyyy-MM-dd hh:mm:ss
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StartSearch(const char* szSessionId, const char* szCameraId, const char* szAccessToken, const char* szStartTime, const char* szStopTime, LP_NSCBMsg pNSCBMsg = NULL));

/** @} */ // end of playback

/** \defgroup voice_talk 语音对讲
 *  @{
 */

/** 
 *  \brief 开启语音对讲, 不支持多个设备同时对接
 *  \param[in] szSessionId   会话Id
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szCameraId    摄像头Id
 *  \return 0表示成功，-1表示失败， -2表示对讲已经开启
 *  \sa OpenSDK_StopVoiceTalk()
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StartVoiceTalk(const char* szSessionId, const char* szAccessToken, const char* szCameraId));

/** @} */ // end of voice_talk

/** \defgroup data 数据接口
 *  @{
 */

/** 
 *  \brief 获取摄像头列表
 *  \param[in]  szAccessToken 认证Token
 *  \param[in]  iPageStart    分页起始页，从0开始
 *  \param[in]  iPageSize     分页大小
 *  \param[out] pBuf          摄像头列表的JSON字符串
 *  \param[out] iLength       获取到的数据大小
 *  \return 0表示成功，-1表示失败 
 *
 *  \note 
 *  摄像头列表的JSON格式如下
 *  \code {.json}
 *	{
 *		"resultCode":"200", 
 *		"count":num, 
 *		"cameraList":[
 *			{
 *				"deviceId":"",					// 设备在平台的唯一标识
 *				"deviceSerial":"421877673",		// 设备序列号
 *				"cameraId":"",					// 监控点ID
 *				"cameraNo":"",					// 设备通道号
 *				"cameraName":"",				// 监控点名称
				"deviceName" :"",				// 设备名称
 *				"display":"",					// 
 *				"status": 1,					// 设备在线状态, 0-离线; 1-在线
 *				"isShared":"0",					// 设备分享状态, 0-未共享;1-共享所有者;2-共享接受者
 *				"picUrl":"",					// 监控点图片url
 *				"isEncrypt":0,					// 加密状态, 0-未加密;1-加密
 *				"defence" : 1,					// 布撤防状态, 0-未布防; 1-布防
 *				"videoLevel" : 0				// 视频清晰度, 0-流畅; 1-均衡; 2-高清
 *			}
 *		]
 *	}
 *  \endcode
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_Data_GetDevList( const char* szAccessToken, int iPageStart, int iPageSize, void** pBuf, int* iLength));

/** 
 *  \brief 获取告警列表
 *  \param[in]  szAccessToken 认证Token
 *  \param[in]  szCameraId    监控点Id
 *  \param[in]  szStartTime   开始时间
 *  \param[in]  szEndTime     结束时间
 *  \param[in]  iAlarmType    告警类型，参见 #AlarmType
 *  \param[in]  iStatus       告警状态，0表示未读，1表示已读，2表示所有
 *  \param[in]  iPageStart    分页起始页，从0开始
 *  \param[in]  iPageSize     分页大小
 *  \param[out] pBuf		  告警信息列表
 *  \param[out] iLength       告警信息列表长度
 *  \return 0表示成功，-1表示失败
 *  
 *  \note 
 *  时间格式为：yyyy-MM-dd hh:mm:ss
 *
 *  \note 
 *  告警信息列表JSON格式如下：
 *  \code {.json}
 *  {
 *		"resultCode":"200", 
 *		"count":1, 
 *		"alarmList":[
 *			{	
 *				 "alarmId" : "24027912025641573",			// 告警编号
 *				 "alarmName" : "C2(497413183)",				// 告警名称
 *				 "alarmPicUrl" : "",						// 告警图片Url
 *				 "alarmStart" : "2016-02-24 18:27:48",		// 告警触发时间
 *				 "alarmType" : 10000,						// 告警类型
 *				 "deviceSerial" : "497413183",				// 设备序列号
 *				 "channelNo" : 1,							// 设备通道号
 *				 "delayTime" : 30,							// 延迟时间
 *				 "isChecked" : 0,							// 信息是否已读
 *				 "isEncrypt" : 1,							// 视频是否加密
 *				 "preTime" : 10,							
 *				 "relationAlarms" : [],						// 联动信息
 *				 "customerInfo" : ,							// 自定义信息 
 *				 "customerType" :							// 自定义类型
 *			}
 *		]
 *	}
 *  \endcode
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_Data_GetAlarmList( const char* szAccessToken, const char* szCameraId, const char* szStartTime, const char* szEndTime, AlarmType iAlarmType, int iStatus, int iPageStart, int iPageSize, void** pBuf, int* iLength));

/** 
 *  \brief 更新监控点详细信息到缓存
 *  \param[in] szCameraId		监控点ID
 *  \param[in] szAccessToken	认证Token
 *	\param[out] isEncrypt		监控点设备是否加密
 *  \return 0表示成功，其他值表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_UpdateCameraInfoToLocal(const char* szCameraId, const char* szAccessToken, bool& isEncrypt));

/** 
 *  \brief 获取设备详情监控点详细信息
 *  \param[in] szCameraId		监控点ID
 *  \param[in] szAccessToken	认证Token
 *	\param[out] pCameraInfo		监控点信息，需要调用OpenSDK_FreeData接口释放
 *	\param[out] iLength			监控点信息的长度
 *
 *  \note 
 *  告警信息列表JSON格式如下：
 *  \code {.json}
 *  {
 *		"cameraID":"fb7****",		// 监控点ID
 *		"devSerial":"426931084",	// 设备序列号
 *		"channelNo":1,				// 通道号
 *		"videoLevel":2				// 视频质量 2-高清 1-标清 0-流畅
 *		"type":1					// 1 网络录像机 2 模拟录像机
 *		"capability":"2-2-1"		// 预览能力级, 2-2-1 三挡分别对应流畅,均衡,清晰, 1:主码流, 2:子码流, 0:不支持
 *		"isEncrypt":0				// 是否开启安全模式:1-开启,0-关闭, 即视频图像是否加密
 *	}
 *  \endcode
 *  \return 0表示成功，其他值表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_GetCameraInfo(const char* szCameraId, const char* szAccessToken, void** pCameraInfo, int* iLength));

/** @} */ // end of data

/** \defgroup device 设备操作相关接口
 *  @{
 */

/**
 *  \brief 云台控制
 *  \param[in] szSessionId   会话ID
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szCameraId	 监控点Id
 *  \param[in] enCommand	 云台控制命令，参见 #PTZCommand
 *  \param[in] enAction		 云台操作命令，参见 #PTZAction
 *  \param[in] iSpeed		 速度0-7之间
 *	\param[out] pNSCBMsg	 同步回调传出参数,如果为同步，不允许为NULL
 *  \return 0表示成功，-1表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_PTZCtrl(const char* szSessionId, const char* szAccessToken, const char* szCameraId, PTZCommand enCommand, PTZAction enAction, int iSpeed, LP_NSCBMsg pNSCBMsg = NULL));

/** 
 *  \brief 按监控点ID进行布撤防
 *  \param[in] szSessionId   会话Id
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szCameraId    监控点Id
 *  \param[in] enType        布撤防类型
 *  \param[in] enStatus      布撤防状态
 *  \param[in] enActor		 布撤防设备类型
 *	\param[out] pNSCBMsg	 同步回调传出参数,如果为同步，不允许为NULL
 *  \return 非负表示成功，-1表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_DevDefence(const char* szSessionId, const char* szAccessToken, const char* szCameraId, DefenceType enType, DefenceStatus enStatus, DefenceActor enActor, LP_NSCBMsg pNSCBMsg = NULL));

/** 
 *  \brief 按设备ID和通道号进行布撤防
 *  \param[in] szSessionId   会话Id
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szDeviceId    设备Id
 *  \param[in] iCameraNo     通道号，操作设备本身通道号为0
 *  \param[in] enType        布撤防类型
 *  \param[in] enStatus      布撤防状态
 *  \param[in] enActor		 布撤防设备类型
 *	\param[out] pNSCBMsg	 同步回调传出参数,如果为同步，不允许为NULL
 *  \return 非负表示成功，-1表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_DevDefenceByDev(const char* szSessionId, const char* szAccessToken, const char* szDeviceId, int iCameraNo, DefenceType enType, DefenceStatus enStatus, DefenceActor enActor, LP_NSCBMsg pNSCBMsg = NULL));
/** @} */ // end of device

/** \defgroup alaram 告警相关接口
 *  @{
 */

/** 
 *  \brief 告警消息推送回调函数
 *  \param szCameraId  监控点Id
 *  \param szContent   告警推送内容
 *  \param szAlarmTime 告警推送时间
 *  \param pUser       用户自定义数据
 *  \sa OpenSDK_Alarm_SetMsgCallBack()
 *  \sa OpenSDK_DecryptPicture
 *
 *  \note 
 *  告警推送内容JSON格式如下：
 *  \code {.json}
 *	{
 *		"alarmID": "11",						// 告警ID
 *		"alarmType": "11",						// 告警类型
 *		"deviceSeril": "231213",				// 设备序列号
 *		"alarmTime": "2012-12-25 15:25:42",		// 告警时间
 *		"channelID": "1",						// 通道ID
 *		"channelName": "通道1",					// 通道名称
 *		"picUrl": "http://www.openys7.com/",	// 图片URL,通过调用OpenSDK_DecryptPicture接口来解密
 *		"content":"string",						// 消息发送的内容
 *		"custominfo":"sn=507669173^cn=30",		// 自定义内容，涉及告警防区
 *		"custominfoType":"CS-A1-32W_01"			// 自定义内容的类型
 *	}
 *  \endcode
 */
typedef void (CALLBACK *OpenSDK_Alarm_MessageHandler)(const char* szCameraId, const char* szContent, const char* szAlarmTime, void* pUser);

/** 
 *  \brief 设置告警推送
 *  \param[in] handle			告警推送函数
 *  \param[in] pUser			用户自定义数据，回调函数会原样抛出
 *  \return 0表示成功，-1表示失败
 *  \sa OpenSDK_Alarm_MessageHandler()
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_Alarm_SetMsgCallBack_Old(OpenSDK_Alarm_MessageHandler alarmHandle, void* pUser));

/** 
 *  \brief 推送消息回调函数(此功能已经废弃, OpenSDK_Alarm_SetMsgCallBack的第二个参数设置为NULL)
 *  \param szContent   消息推送内容
 *  \param pUser       用户自定义数据
 *  \sa OpenSDK_Publish_SetMsgCallBack()
 *
 *  \note 
 *  消息推送内容JSON格式如下：
 *  \code {.json}
 *	{
 *		"type": "message",						// 推送类型(不变)
 *		"messageType": "A100",					// 推送类型号(不变)
 *		"destination": "dest",					// 推送对象
 *		"MsgType": "1",							// 推送的消息类型
 *		"data":{								// 推送的消息内容
 *			... ,
 *			...
 *		}
 *	}
 *  \endcode
 */
typedef void (CALLBACK *OpenSDK_Publish_MessageHandler)(const char* szContent, void* pUser);

/** 
 *  \brief 设置告警消息以及推送消息
 *  \param[in] handle			告警推送函数
 *	\param[in] publishHandle	推送消息函数
 *  \param[in] pUser			用户自定义数据，回调函数会原样抛出
 *  \return 0表示成功，-1表示失败
 *  \sa OpenSDK_Alarm_MessageHandler
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_Alarm_SetMsgCallBack(OpenSDK_Alarm_MessageHandler alarmHandle, OpenSDK_Publish_MessageHandler publishHandle, void* pUser));

/** 
 *  \brief 告警消息透传回调函数,功能类似OpenSDK_Alarm_SetMsgCallBack，这个接口不去查询cameraId.
 *  \param szContent   告警内容
 *  \param szAlarmTime 告警时间
 *  \param pUser       用户自定义数据
 *  \sa OpenSDK_Alarm_SetTransparentCallBack()
 *  \sa OpenSDK_DecryptPicture
 *
 *  \note 
 *  告警推送内容JSON格式如下：
 *  \code {.json}
 *	{
 *		"alarmID": "11",						// 告警ID
 *		"alarmType": "11",						// 告警类型
 *		"deviceSeril": "231213",				// 设备序列号
 *		"alarmTime": "2012-12-25 15:25:42",		// 告警时间
 *		"channelID": "1",						// 通道ID
 *		"channelName": "通道1",					// 通道名称
 *		"picUrl": "http://www.openys7.com/",	// 图片URL,通过调用OpenSDK_DecryptPicture接口来解密
 *		"content":"string",						// 消息发送的内容
 *		"custominfo":"sn=507669173^cn=30",		// 自定义内容，涉及告警防区
 *		"custominfoType":"CS-A1-32W_01"			// 自定义内容的类型
 *	}
 *  \endcode
 */
typedef void (CALLBACK *OpenSDK_Alarm_TransparentHandler)( const char* szContent, void* pUser );

/** 
 *  \brief 设置消息透传回调
 *  \param[in] handle			告警透传函数
 *  \param[in] pUser			用户自定义数据，回调函数会原样抛出
 *  \return 0表示成功，-1表示失败
 *  \sa OpenSDK_Alarm_TransparentHandler
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_Alarm_SetTransparentCallBack(OpenSDK_Alarm_TransparentHandler transparentHandle, void* pUser));


/** 
 *  \brief 告警通知
 *	\param[in] eNotifyType		告警通知类型，比方连接异常、重连成功、重连失败
 *  \param[in] iErrorCode		错误码
 *  \sa OpenSDK_Alarm_SetNotifyCallBack
 */
typedef void (CALLBACK *OpenSDK_Alarm_NotifyHandler)(AlarmNotifyType eNotifyType, int iErrorCode, void* pUser);

/** 
 *  \brief 设置告警通知回调
 *  \param[in] notifyHandle		告警通知函数
 *  \param[in] pUser			用户自定义数据，回调函数会原样抛出
 *  \return 0表示成功，-1表示失败
 *  \sa OpenSDK_Alarm_NotifyHandler
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_Alarm_SetNotifyCallBack(OpenSDK_Alarm_NotifyHandler notifyHandle, void* pUser));

/** 
 *  \brief 开始接受告警
 *  \param[in] szAccessToken 认证token
 *  \return 0表示成功，-1表示失败, -2 已经连接成功, -3 正在重连
 *  \sa OpenSDK_Alarm_StopRecv()
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_Alarm_StartRecv(const char* szAccessToken));

/** 
 *  \brief 停止接收告警
 *  \return 0表示成功，-1表示失败
 *  \sa OpenSDK_Alarm_StartRecv()
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_Alarm_StopRecv());


/** @} */ // end of alaram


/** \defgroup push 消息推送
 *  @{
 */
/** 
 *  \brief 开始接收推送
 *  \param[in] szAccessToken 认证token
 *  \param[in] szPushId      接入Push的标识，默认使用开发平台的AppKey
 *  \param[in] szPushSecret  接入Push所使用密钥，创建应用的时候有平台生成
 *  \return 0表示成功，-1表示失败, 失败时调用GetLastErrorCode()
 *  \sa OpenSDK_Push_StopRecv()
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_Push_StartRecv(const char* szPushId, const char* szPushSecret, const char* szAccessToken));

/** @} */ // end of push

/** \defgroup device 设备操作相关接口
 *  @{
 */

/**
 *  \brief 云台控制
 *  \param[in] szSessionId   会话ID
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szCameraId	 监控点Id
 *  \param[in] enCommand	 云台控制命令，参见 #PTZCommand
 *  \param[in] enAction		 云台操作命令，参见 #PTZAction
 *  \param[in] iSpeed		 速度0-7之间
 *  \return 0表示成功，-1表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_PTZCtrl_Old(const char* szSessionId, const char* szAccessToken, const char* szCameraId, PTZCommand enCommand, PTZAction enAction, int iSpeed));

/** 
 *  \brief 按监控点ID进行布撤防
 *  \param[in] szSessionId   会话Id
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szCameraId    监控点Id
 *  \param[in] enType        布撤防类型
 *  \param[in] enStatus      布撤防状态
 *  \param[in] enActor		 布撤防设备类型
 *  \return 非负表示成功，-1表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_DevDefence_Old(const char* szSessionId, const char* szAccessToken, const char* szCameraId, DefenceType enType, DefenceStatus enStatus, DefenceActor enActor));

/** 
 *  \brief 按设备ID和通道号进行布撤防
 *  \param[in] szSessionId   会话Id
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szDeviceId    设备Id
 *  \param[in] iCameraNo     通道号，操作设备本身通道号为0
 *  \param[in] enType        布撤防类型
 *  \param[in] enStatus      布撤防状态
 *  \param[in] enActor		 布撤防设备类型
 *  \return 非负表示成功，-1表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_DevDefenceByDev_Old(const char* szSessionId, const char* szAccessToken, const char* szDeviceId, int iCameraNo, DefenceType enType, DefenceStatus enStatus, DefenceActor enActor));

/** @} */ // end of device

/** \defgroup sms_code 第三方短信验证码相关接口
 *  @{
 */

/** 
 *  \brief 获取AccessToken短信验证码
 *  \param[in]  szSignString 签名字符串 参照萤石平台接口使用说明文档
 *  \return 0表示成功，其他值表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_GetAccessTokenSmsCode(const char* szSignString));

/** 
 *  \brief 验证AccessToken短信验证码
 *  \param[in] szSmsCode     短信验证码
 *  \param[in] szUserId      用户Id
 *  \param[in] szPhoneNumber 用户手机号码
 *  \param[in] szAppKey      从平台获取的AppKey
 *  \return 0表示成功，其他值表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_VerifyAccessTokenSmsCode(const char* szSmsCode, const char* szUserId, const char* szPhoneNumber, const char* szAppKey));

/** 
 *  \brief 获取硬件特征码短信验证码
 *  \param[in]  szAccessToken 认证Token
 *  \param[in]  szSignString  签名字符串 参照萤石平台接口使用说明文档
 *  \return 0表示成功，其他值表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_GetHdSignSmsCode(const char* szAccessToken, const char* szSignString));

/** 
 *  \brief 验证硬件特征码短信验证码
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szSmsCode     短信验证码
 *  \param[in] szUserId      用户Id
 *  \param[in] szAppKey      从平台获取的AppKey
 *  \return 0表示成功，其他值表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_VerifyHdSignSmsCode(const char* szAccessToken, const char* szSmsCode, const char* szUserId, const char* szAppKey));

/** @} */ // end of sms_code

/** \defgroup transparent 开放萤石云透传接口
 *  @{
 */

/** 
 *  \brief 方法透传,透传萤石云平台接口
 *  \param[in]  reqStr		发给萤石云平台的请求
 *  \param[out] pBuf		萤石云平台响应消息（需要调用SDK接口释放内存）
 *	\param[out] iLength		pBuf的长度
 *  \return 0表示成功，其他值表示失败
 *  \sa OpenSDK_Data_Free
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_RequestPassThrough(const char* reqStr, char** pBuf, int* iLength));

/** 
 *  \brief 获取单个设备信息
 *  \param[in]  szAccessToken	认证Token
 *  \param[in]  szSerial		设备序列号
 *  \param[out] pOutDeviceInfo	设备信息（需要调用OpenSDK_Data_Free释放内存）
 *	\param[out] iOutLen			pOutDeviceInfo的长度
 *  \return 0表示成功，-1表示失败, 失败时调用GetLastErrorCode()
 *  \sa OpenSDK_Data_Free
 *  \sa OpenSDK_RequestPassThrough
 *  \note 
 *  告警推送内容JSON格式如下：
 *  \code {.json}
 *	{
 *		"deviceId":"",					// 设备在平台的唯一标识
 *		"deviceSerial":"421877673",		// 设备序列号
 *		"deviceName":"C1(421877673)",	// 设备名称
 *		"status":1,						// 设备在线状态, 0-默认值; 1-在线; 2-不在线; 4-异常情况
 *		"picUrl":"",					// 监控点图片url
 *		"isEncrypt":0,					// 加密状态, 0-未加密;1-加密
 *		"defence":1						// 设备布撤防状态, 0-未布防; 1-布防
 *	}
 *  \endcode
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_GetSingleDeviceInfo(const char* szAccessToken, const char* szSerial, void** pOutDeviceInfo, int* iOutLen));

/** 
 *  \brief 对设备布撤防
 *  \param[in]  szAccessToken	认证Token
 *  \param[in]  szSerial		设备序列号
 *  \param[in]  bDefence		布撤防, true 布防; false 撤防
 *  \return 0表示成功，-1表示失败, 失败时调用GetLastErrorCode()
 *  \sa OpenSDK_RequestPassThrough
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_DefenceDeviceBySerial(const char* szAccessToken, const char* szSerial, const bool bDefence));

/** 
 *  \brief 添加设备
 *  \param[in]  szAccessToken	认证Token
 *  \param[in]  szSerial		设备序列号
 *  \param[in]  szSafeCode		设备验证码
 *  \return 0表示成功，-1表示失败, 失败时调用GetLastErrorCode()
 *  \sa OpenSDK_RequestPassThrough
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_AddDevice(const char* szAccessToken, const char* szSerial, const char* szSafeCode));

/** 
 *  \brief 获取开通萤石云服务的短信验证码
 *  \param[in]  szPhone		开通萤石服务账号手机号码
 *  \return 0表示成功，-1表示失败, 失败时调用GetLastErrorCode()
 *  \sa OpenSDK_RequestPassThrough
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_GetAuthSmsOfYSService(const char* szPhone));

/** 
 *  \brief 方法透传,透传萤石云平台接口
 *  \param[in]  szPhone		开通萤石服务账号手机号码
 *  \param[in]  szSmsCode	通过OpenSDK_GetAuthSmsOfYSService接口获取的短信验证码
 *  \return 0表示成功，-1表示失败, 失败时调用GetLastErrorCode()
 *  \sa OpenSDK_RequestPassThrough
 *  \sa OpenSDK_GetAuthSmsOfYSService
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_OpenYSService(const char* szPhone, const char* szSmsCode));


/** @} */ // end of transparent

/** 
 *  \brief 针对国标摄像头进行预览
           异步接口，返回值只是表示操作成功，不代表播放成功
           如果接口返回-1, 结果根据消息回调函数msgid判断, 若msgid=INS_PLAY_START, 表示成功, 若msgid=INS_PLAY_EXCEPTION, 表示失败
 *  \param[in] szSessionId   会话ID
 *  \param[in] hPlayWnd      播放窗口句柄, 如果窗口句柄为NULL表示纯粹取流，不做播放
 *  \param[in] szDevice_id   设备标识
 *  \param[in] szChannel     国标设备通道号
 *  \param[in] szPlatform_id 平台id
 *  \param[in] szBizType     国标标识
 *  \param[in] szSafeKey	 视频加密密钥,如果视频未加密, 可以设置为NULL,目前暂未使用
 *  \return 0表示成功，非0表示失败
 *  \sa OpenSDK_StopRealPlayEx
 *	\sa OpenSDK_SetDataCallBack
 */

DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StartRealPlay_gbCode(const char* szSessionId, HWND hPlayWnd, const char* szDevice_id, const char* szChannel,const char* szPlatform_id,const char* szBizType,const char* szSafeKey));

/** 
 *  \brief 录像搜索，包含云存储和设备SD卡录像, 如果关联NVR优先搜索NVR录像，不适用于国标设备,不支持长序列号设备搜索
           异步接口，返回值只是表示操作成功，不代表搜索成功
           如果接口返回-1, 结果根据消息回调函数msgid判断, 若msgid=INS_RECORD_SEARCH_END, 表示成功, 若msgid= INS_RECORD_SEARCH_FAILED, 表示失败
 *  \param[in] szSessionId   会话Id
 *  \param[in] szDevSerial   设备序列号
 *  \param[in] iChannelNo    设备通道号
 *  \param[in] szStartTime   开始时间
 *  \param[in] szStopTime    停止时间 
 *  \return 0表示成功，-1表示失败 
 *  \note
 *  时间格式为：yyyy-MM-dd hh:mm:ss
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StartSearchEx(const char* szSessionId, const char* szDevSerial, const int iChannelNo, const char* szStartTime, const char* szStopTime));



/** 
 *  \brief 用于国标设备的录像搜索，目前仅支持搜索设备录像
           异步接口，返回值只是表示操作成功，不代表搜索成功
           如果接口返回-1, 结果根据消息回调函数msgid判断, 若msgid=INS_RECORD_SEARCH_END, 表示成功, 若msgid= INS_RECORD_SEARCH_FAILED, 表示失败
 *  \param[in] szSessionId   会话Id
 *  \param[in] szDevSerial   设备序列号
 *  \param[in] szChannel  设备序列号
 *  \param[in] szPlatform_id 平台id
 *  \param[in] szPlatform_id 国标标识，目前填写gb28181
 *  \param[in] szStartTime   开始时间
 *  \param[in] szStopTime    停止时间 
 *  \param[in] iSearchType   该参数暂未使用
 *  \return 0表示成功，-1表示失败 
 *  \note
 *  时间格式为:yyyy-MM-dd hh:mm:ss
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StartSearchRecord(const char* szSessionId, const char* szDevSerial,const char* szChannel, const char* szPlatform_id, const char* szBizType,const char* szStartTime, const char* szStopTime, const int iSearchType));


/** 
*  \brief 开始回放，国标设备回放接口
          异步接口，返回值只是表示操作成功，不代表播放成功
          如果接口返回-1, 结果根据消息回调函数msgid判断, 若msgid=INS_PLAY_START, 表示成功, 若msgid=INS_PLAY_EXCEPTION, 表示失败,可调用此接口下载本地录像,
          只取流状态下不支持连续跨片段取流
 *  \param[in] szSessionId   会话Id
 *  \param[in] hPlayWnd      播放窗口句柄, 如果窗口句柄为NULL表示纯粹取流，不做播放
 *  \param[in] szDevice_id   国标设备设备序列号
 *  \param[in] szChannel     国标设备通道号
 *  \param[in] szPlatform_id 平台id
 *  \param[in] szBizType     国标标识，目前填写gb28181
 *  \param[in] szStartTime   开始时间
 *  \param[in] szStopTime    停止时间
 *  \param[in] szSafeKey     暂未使用该参数,传空
 *  \return 0表示成功，非0表示失败
 *  \sa OpenSDK_StopPlayBackEx()
 *  \note 
 *  时间格式为：yyyy-MM-dd hh:mm:ss
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_StartPlayBack_gbCode(const char* szSessionId, HWND hPlayWnd, const char* szDevice_id, const char* szChannel,const char* szPlatform_id,const char* szBizType, const char* szStartTime, const char* szStopTime,const char* szSafeKey));


/*
*  \brief 获取国标摄像头列表
*  \param[in]  szBizType     国标标识,目前填写gb28181
*  \param[in]  iPageStart    分页起始页，从0开始
*  \param[in]  iPageSize     分页大小, 限制最大36,默认36
*  \param[out] pBuf          摄像头列表的JSON字符串
*  \param[out] iLength       获取到的数据大小
*  \return 0表示成功,       -1表示失败 
*  \note 
*  摄像头列表的JSON格式如下
*{
*   "result": {
*                 "page": {
*                 "total": 1,
*                 "page": 0,
*                 "size": 36
*                 },
*                 "data": {
*                    "device":[
*                        {
*                              "devLogicId": "1207995620812394496",//国标设备logic_id
*                              "deviceName": "IP CAMERA",          //设备名称
*                              "deviceModel": "DS-2CD7D27DWD-IZS", //设备型号
*                              "deviceVersion": "V5.5.91",         //设备版本
*                              "platformId": "33010142992577394892", //平台id
*                              "deviceId": "33010672991327538650",   //设备唯一标识
*                              "status": 1,                          //设备在线状态,1 表示在线 2表示离线
*                              "activatedStatus": 1,                 //设备激活状态
*                              "dasId": "das_10.215.35.14_1579177660", 
*                              "netAddress": "123.157.216.218",
*                              "manufacturer": "Ezviz",
*                              "createTime": 1577067330525,          
*                              "updateTime": 1582774537577
*                        }
*                     ]
*               },
*               "code": "200",
*               "msg": "操作成功!"
*        }
*}
*/
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_Data_GetDeviceList(const char* szBizType, int iPageStart, int iPageSize, void** pBuf, int* iLength));

/** 
 *  \brief 国标设备获取设备详细信息接口,该接口仅用于国标设备的信息的获取.
 *  \param[in]  szDevSerial     设备序列号
 *  \param[in]  szChannel       设备通道号
 *  \param[in]  szBizType       国标标识
 *  \param[in]  szPlatform_id   平台id
 *  \param[in]  bUpdate         是否重新获取设备详细信息, 暂未使用该参数
 *	\param[out] pDevDetailInfo	监控点信息，需要调用OpenSDK_FreeData接口释放
 *	\param[out] iLength			监控点信息的长度
 *  \note 
 *  JSON格式如下：
 *  \code {.json}
 *  {				       
 *      "devSerial":"33010709991327238715",	        // 设备序列号
 *		"deviceStatus":1,				            // 设备在线状态:1在线 2离线
 *		"devlogicId":"1204664917580410880",		    // 设备逻辑Id			           
 *      "strCameraNo": "33010709991327238715",      // 设备通道号
 *  }  
 *  \endcode
 *  \return 0表示成功，其他值表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_Data_GetDeviceDetailInfo(const char* szDevSerial, const char* szChannel, const char* szBizType, const char*szPlatform_id, const bool bUpdate, void** pDevDetailInfo, int* iLength));


/** \defgroup ddns 设备DDNS相关接口不支持国标设备
 *  @{
 */
/** 
 *  \brief Get area list of all the nations. use in register.
 *  \return 
 *  \sa
 */

DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_GetAreaList(void** pBuf, int* iBufLen));

/** 
 *  \brief This API is used to turn page to get the DDNS information of all the devices in the account.
 *  \param[in]  iPageStart    Start page, start from 0. The default is 0.
 *  \param[in]  iPageSize     Page size, the default is 10, the maximum is 50.
 *  \param[out]  pBuf          Ezviz platform return Data.
 *  \param[out] iBufLen       The size of pBuf.
 *  \return 0 success，otherwise return Ezviz platform error code. reference to https://open.ys7.com/doc/en/HTTP/api-code.html
 *  \sa
 *  \note 
 *  摄像头列表的JSON格式如下
 *  \code {.json}
 *	{

 *		"page":{
 *          "total":1,
 *          "page":0,
 *          "size":1
 *      },     
 *		"data":[
 *          {
 *              "upnpMappingMode": 0,                               // upnp的映射模式
 *              "domain": "test123456",                             // 设备域名
 *              "hiddnsHttpPort": 0,                                // 设备远程Http端口
 *              "hiddnsHttpsPort": 0,                               // 设备远程Https端口
 *              "hiddnsCmdPort": 0,                                 // 设备SDKCMD控制端口
 *              "hiddnsRtspPort": 0,                                // 设备rtsp端口
 *              "mappingHiddnsHttpPort": 81,                        // 设备远程Http映射端口
 *              "mappingHiddnsCmdPort": 80,                         // 设备远程cmd映射端口
 *              "deviceIp": "212.140.29.17",                        // 设备ip地址
 *              "subSerial": "704122511",                           // 设备序列号
 *              "serial": "CS-C13-31WFR0120170112AACC704122511",    // 设备完整编号
 *              "deviceName": "C2C(704122511)"                      // 设备名称
 *           }
 *		]
 *	}
 *  \endcode
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_GetDeviceDDNSList(int iPageStart, int iPageSize, void** pBuf, int* iBufLen));

/** 
 *  \brief This API is used to set the device DDNS domain, including the shared device's DDNS domain.
 *  \param[in]  szDevSerial    Device serial No.
 *  \param[in]  szDomain       Device domain, 6 to 32 characters are allowed, including lower-case letters, digits and dashes. 
                               The first character should be a letter, and the last character cannot be a dash. 
                               It can also be device serial No. When editing device domain rule, this field is required.
 *  \return 0 success，otherwise return Ezviz platform error code. reference to https://open.ys7.com/doc/en/HTTP/api-code.html
 *  \sa
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_SetDeviceDDNSDomain(const char* szDevSerial, const char* szDomain));

/** 
 *  \brief This API is used to get the device DDNS information, including the shared device DDNS information.
 *  \param[in]  szDevSerial    Device serial No., at least one of the deviceSerial and domain is required. 
 *                             If the deviceSerial and domain are both provided, searching DDNS information of deviceSerial device is preferred.
 *  \param[in]  szDomain       Device domain name.
 *  \param[in]  pBuf       
 *  \param[in]  iBufLen       
 *  \return 0 success，otherwise return Ezviz platform error code. reference to https://open.ys7.com/doc/en/HTTP/api-code.html
 *  \sa
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_GetDeviceDDNSInfo(const char* szDevSerial, const char* szDomain, void** pBuf, int* iBufLen));

/** 
 *  \brief This API is used to set device DDNS auto mapping mode by single device.
 *  \param[in]  szDevSerial    Device serial No.
 *  \return 0 success，otherwise return Ezviz platform error code. reference to https://open.ys7.com/doc/en/HTTP/api-code.html
 *  \sa
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_SetDeviceDDNSAutoMapping(const char* szDevSerial));

/** 
 *  \brief This API is used to set device DDNS manual mapping mode by single device.
 *  \param[in]  szDevSerial    Device serial No.
 *  \param[in]  iCmdPort       CMD (server) port.
 *  \param[in]  iHttpPort      HTTP port.
 *  \return 0 success，otherwise return Ezviz platform error code. reference to https://open.ys7.com/doc/en/HTTP/api-code.html
 *  \sa
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_SetDeviceDDNSManualMapping(const char* szDevSerial, const int iCmdPort, const int iHttpPort));

/** 
 *  \brief This API is used to Share DDNS information to other account by single device.
 *  \param[in]  szDevSerial    Device serial No.
 *  \param[in]  szAccount      Account to share. It can be email address, mobile phone number (contains country code) or not full digital user name.
 *  \return 0 success，otherwise return Ezviz platform error code. reference to https://open.ys7.com/doc/en/HTTP/api-code.html
 *  \sa
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_ShareDeviceDDNSInfo(const char* szDevSerial, const char* szAccount));

/** 
 *  \brief This API is used to turn page to get the DDNS information of all the shared devices in the current account.
 *  \param[in]  iPageStart    Start page, start from 0. The default is 0.
 *  \param[in]  iPageSize     Page size, the default is 10, the maximum is 50.
 *  \param[out] pBuf          Ezviz platform return Data.
 *  \param[out] iBufLen       The size of pBuf.
 *  \return 0 success，otherwise return Ezviz platform error code. reference to https://open.ys7.com/doc/en/HTTP/api-code.html
 *  \sa
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_GetShareDeviceDDNSList(int iPageStart, int iPageSize, void** pBuf, int* iBufLen));

/** @} */ // end of DDNS


/** 
 *  \brief 删除设备,不支持国标设备
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szDeviceId    设备Id
 *  \return 0表示成功，非0表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_Data_DeleteDevice( const char* szAccessToken, const char* szDeviceId));

/** 
 *  \brief 设备添加，不支持国标设备
 *  \param[in] szAccessToken 认证Token
 *  \return 0表示成功，非0表示失败
 */
DEPRECATED(OPENSDK_API int CALLBACK OpenSDK_Mid_Device_Add(const char* szAccessToken));

/** 
 *  \brief 设备操作，不支持国标设备
 *  \param[in] szAccessToken 认证Token
 *  \param[in] szDeviceId    设备Id
 *  \return 0表示成功，-1表示失败
 */
DEPRECATED(OPENSDK_API int CALLBACK OpenSDK_Mid_Device_Oper(const char* szAccessToken, const char* szDeviceId));

/** \defgroup device 设备操作相关接口
 *  @{
 */

/**
 *  \brief 云台控制,,不支持国标设备
           异步接口，返回值只是表示操作成功，不代表云台控制成功
           如果接口返回-1, 结果根据消息回调函数msgid判断, 若msgid=INS_PTZCTRL_SUCCESS, 表示成功, 若msgid=INS_PTZCTRL_FAILED, 表示失败
 *  \param[in] szSessionId   会话ID
 *  \param[in] szDevSerial	 设备序列号
 *  \param[in] iChannelNo  	 设备通道号
 *  \param[in] enCommand	 云台控制命令，参见 #PTZCommand
 *  \param[in] enAction		 云台操作命令，参见 #PTZAction
 *  \param[in] iSpeed		 速度0-7之间
 *  \return 0表示成功，-1表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_PTZCtrlEx(const char* szSessionId, const char* szDevSerial, const int iChannelNo, PTZCommand enCommand, PTZAction enAction, int iSpeed));

/** 
 *  \brief 按监控点ID进行布撤防, 针对NVR的通道进行布撤防，需要NVR和IPC支持之间协议支持,不支持国标设备
           异步接口，返回值只是表示操作成功，不代表布撤防成功
           如果接口返回-1, 结果根据消息回调函数msgid判断, 若msgid=INS_DEFENSE_SUCCESS, 表示成功, 若msgid=INS_DEFENSE_FAILED, 表示失败
 *  \param[in] szSessionId   会话Id
 *  \param[in] szDevSerial	 设备序列号
 *  \param[in] iChannelNo  	 设备通道号
 *  \param[in] enType        布撤防类型
 *  \param[in] enStatus      布撤防状态
 *  \param[in] enActor		 布撤防设备类型
 *  \return 非负表示成功，-1表示失败
 */
DEPRECATED(OPENSDK_API OPENSDK_RESULT CALLBACK OpenSDK_DevDefenceEx(const char* szSessionId, const char* szDevSerial, const int iChannelNo, DefenceType enType, DefenceStatus enStatus, DefenceActor enActor));

/** @} */ // end of device



/** @} */ // end of alaram

#ifdef __cplusplus
}
#endif

#endif