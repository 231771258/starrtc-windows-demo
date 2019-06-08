#pragma once

#ifndef MATH_API
#define MATH_API _declspec(dllexport)
#endif

#include<string>
using namespace std;

#include "CUserManager.h"
class MATH_API CLogin
{
public:
	CLogin(CUserManager* pUserManager);

	~CLogin();
	/*
	 * ��¼
	 */
	bool logIn();

	/*
	 * ����IM����
	 */
	bool startIMServer(string strIP, int nPort, string userId, string agentId, string strToken);

	/*
	 * ����IM����
	 */
	bool stopIMServer();
private:
	/*
	 * ��ȡauthKey
	 */
	bool getAuthKey();

	/*
	 * ��ȡToken
	 */
	bool getToken();

	/*
	 * ͨ�����Ȼ�ȡIM�����ַ
	 */
	bool getIMServerAddr();
};

