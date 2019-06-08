#pragma once
#include "CIMMessage.h"
class ILiveManagerListener
{
public:
	/**
	 * ����������
	 * @param liveID ֱ��ID
	 * @param actorID �¼��������ID
	 */
	virtual void onActorJoined(string liveID, string actorID) = 0;

	/**
	 * �������뿪
	 * @param liveID ֱ��ID
	 * @param actorID �뿪������ID
	 */
	virtual void onActorLeft(string liveID, string actorID) = 0;

	/**
	 * �����յ������û�����������
	 * @param liveID
	 * @param applyUserID
	 */
	virtual void onApplyBroadcast(string liveID, string applyUserID) = 0;

	/**
	 * ���������û��յ��Ļظ�
	 * @param liveID
	 * @param result
	 */
	virtual void onApplyResponsed(string liveID, bool bAgree) = 0;

	/**
	* ��ͨ�û��յ���������
	* @param liveID ֱ��ID
	* @param applyUserID ����������˵�ID������ID��
	*/
	virtual void onInviteBroadcast(string liveID, string applyUserID) = 0;

	/**
	 * �����յ�������������
	 * @param liveID ֱ��ID
	 * @param result ������
	 */
	virtual void onInviteResponsed(string liveID) = 0;

	/**
	 * һЩ�쳣�������ĳ��������յ��ûص��������Ͽ�ֱ��
	 * @param liveID ֱ��ID
	 * @param error ������Ϣ
	 */
	virtual void onLiveError(string liveID, string error) = 0;

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
	 * �����ߵ�����ǿ��ֹͣ
	 * @param liveID ֱ��ID
	 */
	virtual void onCommandToStopPlay(string  liveID) = 0;

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

	virtual int getRealtimeData(string strUserId, uint8_t* data, int len) = 0;
	virtual int getVideoRaw(string strUserId, int w, int h, uint8_t* videoData, int videoDataLen) = 0;
};