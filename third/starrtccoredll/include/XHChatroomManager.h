#pragma once
#ifndef MATH_API
#define MATH_API _declspec(dllexport)
#endif

#include "CChatroomManager.h"
#include "IChatroomManagerListener.h"

/*
 *�����ҹ�����
 */
class MATH_API XHChatroomManager
{
public:
	/*
	 * ���캯��
	 * @param pUserManager �û���Ϣ
	 * @param pChatroomManagerListener �ص�����ָ��
	 */
	XHChatroomManager(IChatroomManagerListener* pChatroomManagerListener);
	/*
	 * ��������
	 */
	~XHChatroomManager();
public:
	/*
	 * ��ӻ�ȡ�б��ص�����ָ��
	 * @param pChatroomGetListListener �ص�����ָ��
	 */
	static void addChatroomGetListListener(IChatroomGetListListener* pChatroomGetListListener);
	
	/*
	 * ��ȡ�������б�
	 * @param pUserManager �û���Ϣ
	 * @param listType ����
	 */
	static void getChatroomList(int listType);

	/*
	 * ����ChatRoom
	 * @param strName ����
	 * @param chatroomType ����
	 */
	bool createChatRoom(string strName, int chatroomType);

	/**
	 * ɾ��������
	 * @param strChatroomId ɾ����������ID
	 */
	bool deleteChatRoom(string strChatroomId);

	/**
	 * ����������
	 * @param strChatroomId Ҫ�����������ID
	 */
	bool joinChatRoom(string strChatroomId);

	/**
	 * �˳�������
	 * @param strChatroomId Ҫ�˳���������ID
	 */
	bool exitChatroom(string strChatroomId);

	/**
	 * �����������ڵ��û�
	 * @param strChatroomId ����������ID
	 * @param strMemberId �����Ե��û�ID
	 * @param muteSeconds ����ʱ������λ���룩
	 */
	bool muteMember(string strChatroomId, string strMemberId, int muteSeconds);

	/**
	 * ����û��Ľ���
	 * @param chatroomID ����������ID
	 * @param memberID ������Ե��û�ID
	 */
	bool unMuteMember(string strChatroomId, string strMemberId);

	/**
	 * ���������߳��û�
	 * @param chatroomID ����������ID
	 * @param memberID �߳����û�ID
	 */
	bool kickMember(string chatroomID, string memberID);

	/*
	 * ������Ϣ
	 * @param strMsg ��Ϣ����
	 */
	CIMMessage* sendMessage(string strMsg);

	/*
	 * ����˽��
	 * @param toUserId �Է�userId
	 * @param msgData ��Ϣ����
	 */
	CIMMessage* sendPrivateChat(string toUserId, char* msgData);

	/**
	 * ��ѯ�б�
	 * @param userId �û�Id
	 * @param callback ����ص�
	 */
	void queryList(string userId, string type);

	/**
	 * ���б�ɾ��
	 * @param userId �û�Id
	 * @param chatroomId ������ID
	 */
	void deleteFromList(string userId, int type, string chatroomId);
	/*
	 * ��ѯchatroom��������
	 */
	bool getOnlineNumber(string strChatroomId);

	/**
	 * ��ȡ��ǰChatroom id
	 * @return Chatroom id
	 */
	string getChatroomId();
private:
	CChatroomManager* m_pChatroomManager;
};

