#pragma once
#include "CIMMessage.h"
#include <string>
#include "CGroupInfo.h"
using namespace std;

class IGroupManagerListener
{
public:
	IGroupManagerListener() {}
	virtual ~IGroupManagerListener() {}
public:
	/**
	 * Ⱥ��Ա�������仯
	 * @param groupID
	 * @param number
	 */
	virtual void onMembersUpdeted(string groupID, int number) = 0;

	/**
	 * �Լ����Ƴ�Ⱥ��
	 * @param groupID
	 */
	virtual void onSelfKicked(string groupID) = 0;

	/**
	 * Ⱥ���Ѿ���ɾ��
	 * @param groupID
	 */
	virtual void onGroupDeleted(string groupID) = 0;

	/**
	 *  �յ���Ϣ
	 * @param message
	 */
	virtual void onReceivedMessage(string groupId, CIMMessage* pMessage) = 0;
};

