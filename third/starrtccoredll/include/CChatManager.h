#pragma once
#include "StarRtcCore.h"
#include "IChatManagerListener.h"
#include "IStarIMC2CListener.h"
#include "CUserManager.h"
#include <map>
/*
 *һ��һ���������
 */
class CChatManager : public IStarIMC2CListener
{
public:
	/*
	 * ���캯��
	 * @param pUserManager �û���Ϣ
	 * @param pListener �ص�����ָ��
	 */
	CChatManager(CUserManager* pUserManager, IChatManagerListener* pListener);
	/*
	 * ��������
	 */
	virtual ~CChatManager();

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

	/*
	 * ����VOIP������Ϣ
	 * @param fromId ������userId
	 * @param targetId �Է�userId
	 * @param code ��Ϣ����
	 * @param data ��Ϣ����
	 * @return �Ƿ�ɹ�
	 */
	bool sendVoipOnlineMessage(char* fromId, char* targetId, int code, char* data);

	/*
	 * ���յ���Ϣ
	 * @param var1 ��Ϣ����
	 */
	virtual void onNewMessage(CIMMessage* var1);

	/*
	 * ������Ϣ�ɹ��ص�
	 * @param msgIndex ��Ϣ���
	 */
	virtual void onSendMessageSuccess(int msgIndex);

	/*
	 * ������Ϣʧ�ܻص�
	 * @param msgIndex ��Ϣ���
	 */
	virtual void onSendMessageFailed(int msgIndex);

	/*
	 * ����Ϣ�洢��map
	 * @param pMsg ��Ϣ
	 */
	void addMessageToMap(CIMMessage* pMsg);

	/*
	 * ��map���Ƴ���Ϣ
	 * @param nIndex ��Ϣ���
	 */
	void removeMessageFromMap(int nIndex);
public:
	//�û���Ϣ
	CUserManager* m_pUserManager;
	//�ص�����ָ��
	IChatManagerListener* m_pChatManagerListener;
	//�ӿ���ָ��
	StarRtcCore* m_pStarRtcCore;
	//��Ϣmap
	map<string, CIMMessage*> m_MsgMap;
};

