#pragma once

#ifndef MATH_API
#define MATH_API _declspec(dllexport)
#endif

#include "CChatManager.h"
#include "IChatManagerListener.h"
/*
 *һ��һ���������
 */
class MATH_API XHChatManager
{
public:
	/*
	 * ���캯��
	 * @param pUserManager �û���Ϣ
	 * @param pListener �ص�����ָ��
	 */
	XHChatManager(IChatManagerListener* pListener);
	/*
	 * ��������
	 */
	virtual ~XHChatManager();

	/*
	 * ������Ϣ
	 * @param toUserId �Է�userId
	 * @param msgStr ��Ϣ����
	 * @return ��Ϣ����
	 */
	CIMMessage* sendMessage(char* toUserId, char* msgStr);

	/*
	 * ����������Ϣ
	 * @param toUserId �Է�userId
	 * @param msgStr ��Ϣ����
	 * @return �Ƿ�ɹ�
	 */
	bool sendOnlineMessage(char* toUserId, char* msgStr);
private:
	CChatManager* m_pChatManager;
};

