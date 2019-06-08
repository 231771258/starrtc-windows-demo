#pragma once
#include "CUserManager.h"

#define STREAM_CONFIG_MAX_SIZE	7

enum LIVE_TYPE
{
	LIVE_TYPE_VDN,
	LIVE_TYPE_SRC
};

class StarLiveUserInfo
{
public:
	string userId;
	int upId;
	bool isBig;
};

class ILiveInterface
{
public:
	ILiveInterface(CUserManager* pUserManager);
	virtual ~ILiveInterface();

	void setChannelId(string strChannelId);

	void resetReturnVal();

	/**
	 * �ɹ�
	 * @param data
	 */
	virtual void success();

	/**
	 * ʧ��
	 * @param errMsg
	 */
	virtual void failed(string errMsg);

	string getChannelId();
	/*
	 * ��������������
	 */
	virtual bool setStreamConfig(int upId, bool isBig) = 0;
	virtual void querySoundData(uint8_t** pData, int* nLength) = 0;
public:
	LIVE_TYPE m_liveType;
protected:
	CUserManager* m_pUserManager;
	string m_ChannelId;
	bool m_bReturn;
	bool m_bSuccess;
	string m_strErrInfo;
	int m_configArr[STREAM_CONFIG_MAX_SIZE];
	
};

