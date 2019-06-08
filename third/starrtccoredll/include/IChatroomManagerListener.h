#pragma once
#include "CIMMessage.h"

class IChatroomManagerListener 
{
public:
	/**
	 * �����ҳ�Ա���仯
	 * @param number
	 */
	virtual void onMembersUpdated(int number) = 0;

	/**
	 * �Լ����߳�������
	 */
	virtual void onSelfKicked() = 0;

	/**
	 * �Լ����߳�������
	 */
	virtual void onSelfMuted(int seconds) = 0;

	/**
	 * �������ѹر�
	 */
	virtual void onClosed() = 0;

	/**
	 * �յ���Ϣ
	 * @param message
	 */
	virtual void onReceivedMessage(CIMMessage* pMessage) = 0;

	/**
	 * �յ�˽����Ϣ
	 * @param message
	 */
	virtual void onReceivePrivateMessage(CIMMessage* pMessage) = 0;
};