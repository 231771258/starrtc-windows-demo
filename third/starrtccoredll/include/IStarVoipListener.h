#pragma once
#include "CIMMessage.h"
class IStarVoipListener 
{
public:
	//���ͷ�׼���ã����Կ�ʼ��������
	virtual void voipCallingOk() = 0;
	//callingʧ��
	virtual void voipCallingFailed(char* errString) = 0;
	//���շ�׼���ã����Կ�ʼ��������
	virtual void voipResponseOk() = 0;
	//responseʧ��
	virtual void voipResponseFailed(char* errString) = 0;

	virtual void voipStopOK(int stopType) = 0;
	//������յ�calling���󣬴�ʱ�ͻ��˿���ͨ����Ϣϵͳ֪ͨ�Է�
	virtual void voipCallingAck() = 0;

	virtual int voipError(char* errString) = 0;
	virtual int voipSpeedTestFinish(char* userIp, int uploadVariance, int uploadSpeed, int downloadVariance, int downSpeed) = 0;
	virtual int voipEchoTestFinish(int index, int len, int timeCost) = 0;
	virtual int voipGetRealtimeData(uint8_t* data, int len) = 0;
	virtual int reportVoipTransState(int state) = 0;
};
