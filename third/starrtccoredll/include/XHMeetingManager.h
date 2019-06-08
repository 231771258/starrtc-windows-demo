#pragma once
#include "CMeetingManager.h"
#ifndef MATH_API
#define MATH_API _declspec(dllexport)
#endif
class MATH_API XHMeetingManager
{
public:
	XHMeetingManager(IMeetingManagerListener* pListener);
	virtual ~XHMeetingManager();
public:
	static void addChatroomGetListListener(IChatroomGetListListener* pChatroomGetListListener);
	static void getMeetingList();

	/**
	 * ����ý������
	 * @param mediaTypeEnum ����Ƶͬʱ���ڣ�����ֻ��������һ�
	 */
	void setRtcMediaType(int mediaTypeEnum);

	/**
	 * ��������
	 * @param strName ��
	 * @param chatroomType chatroom����
	  *@param channelType channel����
	 */
	bool createMeeting(string strName, int chatroomType, int channelType);
	/**
	 * �������
	 * @param strMeetingID ����ID
	 */
	bool joinMeeting(string strMeetingID);

	/**
	 * �뿪����
	 * @param strMeetingID ����ID
	 */
	bool leaveMeeting(string strMeetingID);

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
	bool muteMember(string meetingID, string memberID, int muteSeconds);

	/**
	 * ���������ĳ�˵Ľ���
	 * @param meetingID ����ID
	 * @param memberID ��������ID
	 */
	bool unMuteMember(string meetingID, string memberID);

	/**
	 * �ӻ������߳��û�
	 * @param meetingID ����ID
	 * @param memberID ������ID
	 */
	bool kickMember(string meetingID, string memberID);

	/**
	 * ���浽�б�
	 * @param userId
	 * @param type
	 * @param meetingId
	 * @param data
	 */
	bool saveToList(string userId, int type, string meetingId, string data);

	/**
	 * ���б�ɾ��
	 * @param userId �û�ID
	 * @param type ����
	 * @param meetingId ������ID
	 */
	void deleteFromList(string userId, int type, string meetingId);

	/**
	 * ����RTMP��
	 * @param rtmpurl ���͵�ַ
	 */
	void pushRtmp(string rtmpurl);

	/**
	 * ֹͣ����RTMP��
	 */
	void stopPushRtmp();

	void insertAudioRaw(uint8_t* audioData, int dataLen);
	void insertVideoRaw(uint8_t* videoData, int dataLen, int isBig);
	int cropVideoRawNV12(int w, int h, uint8_t* videoData, int dataLen, int yuvProcessPlan, int rotation, int needMirror, uint8_t* outVideoDataBig, uint8_t* outVideoDataSmall);
	void querySoundData(uint8_t** pData, int* nLength);
private:
	CMeetingManager* m_pMeetingManager;
};

