#pragma once
#include <list>
#include "CGroupInfo.h"
class IGroupGetListListener
{
public:
	/**
	 * ��ѯȺ���б�ص�
	 */
	virtual int applyGetGroupListFin(list<CGroupInfo>& groupInfoList) = 0;

	/**
	 * ��ѯ�û��б�ص�
	 */
	virtual int applyGetUserListFin(list<string>& userList) = 0;
};
