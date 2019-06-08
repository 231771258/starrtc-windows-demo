#pragma once
#include "IVoipManagerListener.h"
#ifndef MATH_API
#define MATH_API _declspec(dllexport)
#endif
class MATH_API XHVoipManager
{
public:
	XHVoipManager(IVoipManagerListener* pVoipManagerListener);
	virtual ~XHVoipManager();
public:
	/**
	* ����ý�����ͣ�����Ƶ����Ƶ����Ƶ ���ֿ�ѡ��
	* @param mediaTypeEnum ý������
	*/
	void setRtcMediaType(int mediaTypeEnum);

	/**
	* ��ȡý�����ͣ�����Ƶ����Ƶ����Ƶ ���ֿ�ѡ��
	*/
	int getRtcMediaType();

	/**
	 * ���з�����
	 * ����ͨ��
	 * @param toID
	 * @param callback
	 */
	bool call(string strTargetId);

	/**
	* ���з�����
	* �Է�������ܾ�ǰ ���з�����ȡ������
	*/
	void cancel();

	/**
	 * ���з�����
	 * ͬ������з�ͨ��
	 * @param fromID
	 */
	void accept(string fromID);

	/**
	 * ���з�����
	 * �ܾ������з�ͨ��
	 */
	void refuse();

	/**
	 * ˫�����ɵ���
	 * �Ҷ�
	 */
	void hangup(int isActive);	
	
	void insertAudioRaw(uint8_t* audioData, int dataLen);
	//videoData���ͷ��ɴ˺�������
	void insertVideoRaw(uint8_t* videoData, int dataLen, int isBig);
	int cropVideoRawNV12(int w, int h, uint8_t* videoData, int dataLen, int yuvProcessPlan, int rotation, int needMirror, uint8_t* outVideoDataBig, uint8_t* outVideoDataSmall);	
	void querySoundData(uint8_t** pData, int* nLength);

};

