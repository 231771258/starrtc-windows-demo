#pragma once
#include <string>
using namespace std;
#include "CIMMessage.h"
class IVoipManagerListener
{
public:
	/**
	 * ���з���Ӧ
	 * ���з��յ����з��ĺ���
	 * @param fromID
	 */
	virtual void onCalling(string fromID) = 0;

	/**
	 * ���з���Ӧ
	 * ���з��ڱ��з�����֮ǰ�Ҷϣ�ͨ����ȡ����
	 * @param fromID
	 */
	virtual void onCancled(string fromID) = 0;

	/**
	 * ���з���Ӧ
	 * ���з��ܾ���ͨ��ͨ�����ܾ���
	 * @param fromID
	 */
	virtual void onRefused(string fromID) = 0;

	/**
	 * ���з���Ӧ
	 * ���з���·æ���Է�ͨ���У�
	 * @param fromID
	 */
	virtual void onBusy(string fromID) = 0;

	/**
	 * ͨ���д��������
	 */
	virtual void onMiss(CIMMessage* pMsg) = 0;

	/**
	 * ���з���Ӧ
	 * ���з���ͨ��ͨ����ʼ��
	 * @param fromID
	 */
	virtual void onConnected(string fromID) = 0;

	/**
	 * �Է��Ѿ��Ҷ�
	 * @param fromID
	 */
	virtual void onHangup(string fromID) = 0;

	/**
	 * voip����
	 * @param errorCode
	 */
	virtual void onError(string errorCode) = 0;

	/**
	 * �յ�ʵʱ����
	 * @param data
	 */
	virtual void onReceiveRealtimeData(uint8_t* data, int length) = 0;

	/**
	 * �յ���Ƶ����
	 * @param data
	 */
	virtual int getVideoRaw(string strUserId, int w, int h, uint8_t* videoData, int videoDataLen) = 0;
	
	/**
	* ���ݴ���ģʽ�л�
	* @param state
	*/
	virtual void onTransStateChanged(int state) = 0;
};

