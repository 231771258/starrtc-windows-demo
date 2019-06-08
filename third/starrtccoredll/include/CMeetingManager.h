#pragma once
#include "ISrcManagerListener.h"
#include "IMeetingManagerListener.h"
#include "CUserManager.h"
#include "CChatroomManager.h"
#include "CSrcManager.h"
#include <map>
enum MEETING_TYPE
{
	MEETING_TYPE_GLOBAL_PUBLIC,	// �����¼����֤
	MEETING_TYPE_LOGIN_PUBLIC,	// ��Ҫ��¼��������֤
	MEETING_TYPE_LOGIN_SPECIFY	// ��Ҫ��¼����֤
};



class CMeetingManager: public IChatroomManagerListener, public ISrcManagerListener
{
public:
	CMeetingManager(CUserManager* pUserManager, IMeetingManagerListener* pListener);
	virtual ~CMeetingManager();
public:
	static void addChatroomGetListListener(IChatroomGetListListener* pChatroomGetListListener);
	static void getMeetingList(CUserManager* pUserManager);
	bool createMeeting(string strName, int chatroomType, int channelType);
	void insertAudioRaw(uint8_t* audioData, int dataLen);
	void insertVideoNalu(uint8_t* videoData, int dataLen);
	void insertVideoRaw(uint8_t* videoData, int dataLen, int isBig);
	int cropVideoRawNV12(int w, int h, uint8_t* videoData, int dataLen, int yuvProcessPlan, int rotation, int needMirror, uint8_t* outVideoDataBig, uint8_t* outVideoDataSmall);

	/*
	 * �ϱ�chatroom �� channelID
	 */
	bool reportChatRoomAndChannel(string strName, string strChatroomId, string strChannelId);
	bool joinChatroom(string strChatroomId);
	bool join(string strChatroomId, string strChannelId);
	bool closeChatroom();

	bool closeLive();

	bool close();

	/**
	 * �л��ɴ�ͼ
	 * @param strUserID �л��ɴ�ͼ���û�ID
	 */
	bool changeToBig(string strUserID);

	/**
	 * �л���Сͼ
	 * @param userID �л���Сͼ���û�ID
	 */
	bool changeToSmall(string strUserID);

	/**
	 * ��̬������Ƶ��ֱ�������п���ʱ������Ƶ��ֱ��������״̬�Զ����á�
	 */
	void setAudioEnable(bool bEnable);

	/**
	 * ��̬������Ƶ��ֱ�������п���ʱ������Ƶ��ֱ��������״̬�Զ����á�
	 */
	void setVideoEnable(bool bEnable);
	/**
	 * ���ͻ�����Ϣ
	 * @param message ���͵���Ϣ����
	 * @param callback ����ص�
	 * @return ���ط��͵���Ϣ����
	 */
	CIMMessage* sendMessage(string strMessage);

	/**
	 * ���ͻ���˽����Ϣ
	 * ˽����Ϣֻ��Ŀ���û������յ�
	 * @param toID Ŀ���û�ID
	 * @param message ���͵���Ϣ����
	 * @return ���ط��͵���Ϣ����
	 */
	CIMMessage* sendPrivateMessage(string toID, string strMessage);

	/**
	 * �Ի����е�ĳ�˽���
	 * @param meetingID ����ID
	 * @param memberID ��������ID
	 * @param muteSeconds ����ʱ��
	 * @param callback ����ص�
	 */
	bool muteMember(string strChatRoomId, string memberID, int muteSeconds);

	/**
	 * ���������ĳ�˵Ľ���
	 * @param meetingID ����ID
	 * @param memberID ��������ID
	 */
	bool unMuteMember(string strChatRoomId, string memberID);

	/**
	 * �ӻ������߳��û�
	 * @param meetingID ����ID
	 * @param memberID ������ID
	 */
	bool kickMember(string strChatRoomId, string memberID);

	bool applyToBroadcaster(string chatroomId, string channelId, string toId);

	void agreeApplyToBroadcaster(string toId);

	void refuseApplyToBroadcaster(string toId);

	void inviteToBroadcaster(string toId);

	void agreeInviteToBroadcaster(string toId);

	void refuseInviteToBroadcaster(string toId);
	void querySoundData(uint8_t** pData, int* nLength);
public:
	/**
	 * �����ҳ�Ա���仯
	 * @param number
	 */
	virtual void onMembersUpdated(int number);

	/**
	 * �Լ����߳�������
	 */
	virtual void onSelfKicked();

	/**
	 * �Լ����߳�������
	 */
	virtual void onSelfMuted(int seconds);

	/**
	 * �������ѹر�
	 */
	virtual void onClosed();

	/**
	 * �յ���Ϣ
	 * @param message
	 */
	virtual void onReceivedMessage(CIMMessage* pMessage);

	/**
	 * �յ�˽����Ϣ
	 * @param message
	 */
	virtual void onReceivePrivateMessage(CIMMessage* pMessage);
public:
	//src
	virtual int uploaderAddSrc(char* upUserId, int upId);
	virtual int uploaderRemoveSrc(char* upUserId, int upId);
	virtual int getRealtimeDataSrc(int upId, uint8_t* data, int len);
	virtual int getVideoRawSrc(int upId, int w, int h, uint8_t* videoData, int videoDataLen);

	virtual int deleteChannel(char* channelId);
	virtual int stopOK();
	virtual int srcError(char* errString);

public:
	static IChatroomGetListListener* m_pChatroomGetListListener;
	IMeetingManagerListener* m_pMeetingManagerListener;
	CUserManager* m_pUserManager;
	CChatroomManager* m_pChatroomManager;
	CSrcManager* m_pSrcManager;
	

	map<int, StarLiveUserInfo> m_StarLiveUserInfo;
};

