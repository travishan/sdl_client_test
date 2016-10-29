#ifndef __CONNECTOR__H__
#define __CONNECTOR__H__

#include "define.h"
#include "ClientSocket.h"


class Connector
{
public:
	Connector();
	~Connector();

	/*
	���ӷ�����������  ip��ַ �˿�
	*/
	void connect(const string &ip, const int port);

	/*
	�Ͽ��������������
	*/
	void disconnect();

	/*
	���շ�������Ϣ
	*/
	void recv();

private:

	/*
	����ͬ����Ϣ
	*/
	void handleWait();
	void handleStart();
	void handleRun();
	void handleChange();
	void handleQueryRegret();
	void handleRegret();
	void handleFull();
private:
	/*
	ʹ��SDL��װ��socket��������
	*/
	ClientSocket client;
	
	/*
	�ӷ��������յ�����   ��Ϣ����flag�����ݳ���length������data
	*/
	FlagType flag;
	LengthType length;
	DataType data;
};


#endif // !__CONNECTOR__H__



