#pragma once
#ifndef MATH_API
#define MATH_API _declspec(dllexport)
#endif

#include "IGroupManagerListener.h"
#include "IGroupGetListListener.h"
#include "CGroupManager.h"
class MATH_API XHGroupManager
{
public:
	/*
	 * ���캯��
	 * @param pUserManager �û���Ϣ
	 */
	XHGroupManager(IGroupManagerListener* pGroupManagerListener);
	/*
	 * ��������
	 */
	~XHGroupManager();
public:
	/*
	 * ��ӻ�ȡ�б��ص�����ָ��
	 * @param pChatroomGetListListener �ص�����ָ��
	 */
	static void addGroupGetListListener(IGroupGetListListener* pGroupGetListListener);
	/*
	 * ��ȡȺ���б�
	 * @param pUserManager �û���Ϣ
	 */
	static void getGroupList();
	/*
	 * ��ȡȺ���Ա�б�
	 * @param pUserManager �û���Ϣ
	 * @param strGroupId Ⱥ��id
	 */
	static void getUserList(string strGroupId);

	/**
	 * ����Ⱥ
	 * @param groupName
	 */
	string createGroup(string groupName);

	/**
	 * ɾ��Ⱥ
	 * @param groupID
	 */
	bool deleteGroup(string groupID);

	/**
	 * ���Ⱥ��Ա
	 * @param groupID
	 * @param memberIDs
	 */
	void addGroupMembers(string groupID, list<string> memberIDs);

	/**
	 * ɾ��Ⱥ��Ա
	 * @param groupID
	 * @param memberIDs
	 */
	void deleteGroupMembers(string groupID, list<string> memberIDs);

	/**
	 * �������Ϳ���
	 * @param groupID
	 * @param enable
	 * @param callback
	 */
	void setPushEnable(string groupID, bool enable);

	/**
	 *������Ϣ
	 * @param groupID
	 * @param atUserIDs
	 * @param Message
	 * @return ��������Ϣ
	 */
	CIMMessage* sendMessage(string groupID, list<string> atUserIDs, string Message);

	/**
	 *������Ϣ
	 * @param groupID
	 * @param atUserIDs
	 * @param Message
	 * @return ��������Ϣ
	 */
	CIMMessage* sendOnlineMessage(string groupID, list<string> atUserIDs, string Message);
private:
	CGroupManager* m_pGroupManager;
};

