#pragma once
#include "IGroupManagerListener.h"
#include "IGroupGetListListener.h"
#include "IGroupListener.h"
#include "CIMMessage.h"
#include "StarRtcCore.h"
#include "CUserManager.h"
#include "CCallbackResult.h"
#include <list>
#include <map>
using namespace std;

class CGroupManager : public IGroupListener, public CCallbackResult
{
public:
	/*
	 * ���캯��
	 * @param pUserManager �û���Ϣ
	 */
	CGroupManager(CUserManager* pUserManager, IGroupManagerListener* pGroupManagerListener);
	/*
	 * ��������
	 */
	~CGroupManager();
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
	static void getGroupList(CUserManager* pUserManager);
	/*
	 * ��ȡȺ���Ա�б�
	 * @param pUserManager �û���Ϣ
	 * @param strGroupId Ⱥ��id
	 */
	static void getUserList(CUserManager* pUserManager, string strGroupId);
	/**
	 * ��Ӽ���
	 * @param groupManagerListener
	 */
	void addListener(IGroupManagerListener* pGroupManagerListener);

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
public:
	/**
	 * ��ȡgroup list�ص�����
	 */
	virtual int applyGetGroupListFin(list<CGroupInfo>& groupInfoList);
	/**
	 * ��ȡgroup ��Ա��Ϣ�ص�����
	 */
	virtual int applyGetUserListFin(list<string>& userList);
	/**
	 * Ⱥ��Ա�������仯
	 * @param groupID
	 * @param number
	 */
	virtual void onMembersUpdeted(string groupID, int number);

	/**
	 * �Լ����Ƴ�Ⱥ��
	 * @param groupID
	 */
	virtual void onSelfKicked(string groupID);

	/**
	 * Ⱥ���Ѿ���ɾ��
	 * @param groupID
	 */
	virtual void onGroupDeleted(string groupID);

	/**
	 *  �յ���Ϣ
	 * @param message
	 */
	virtual void onReceivedMessage(string groupId, CIMMessage* pMessage);

	/**
	 *  ����Ⱥ��ص�
	 * @param message
	 */
	virtual void onApplyCreateGroupFin(string groupID);

	/**
	 *  ɾ��Ⱥ��ص�
	 * @param message
	 */
	virtual void onApplyDelGroupFin(string groupID);

	/**
	 *  ��ӳ�Ա�ص�
	 * @param message
	 */
	virtual void onApplyAddUserToGroupFin(string groupID);

	/**
	 *  ɾ����Ա�ص�
	 * @param message
	 */
	virtual void onApplyRemoveUserFromGroupFin(string groupID);
	
private:
	static IGroupGetListListener* m_pGroupGetListListener;
	CUserManager* m_pUserManager;
	IGroupManagerListener* m_pGroupManagerListener;
	map<string, CIMMessage*> m_MsgMap;
	string m_strGroupId;
};

