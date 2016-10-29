#include "Connector.h"



Connector::Connector() {}


Connector::~Connector() {}


/*
���ӷ�����������  ip��ַ �˿�
*/
void Connector::connect(const string &ip, const int port) {
	client.initNetwork(ip.c_str(), port);
}

/*
�Ͽ��������������
*/
void Connector::disconnect() {
	client.closeSocket();
}

/*
���շ�������Ϣ
*/
void Connector::recv() {
	data = client.recvData(flag, length);

	switch (flag) {
	case FLAG_WAIT:
		handleWait();
		break;
	case FLAG_START:
		handleStart();
		break;
	case FLAG_RUN:
	{

	}break;
	case FLAG_CHANGE:
	{

	}break;
	case FLAG_QUERY_REGRET:
	{

	}break;
	case FLAG_REGRETED:
	{

	}break;
	case FLAG_FULL:
	{

	}break;
	}
}


void Connector::handleWait() {
	cout << "��ǰ�ǵȴ�״̬...   ���ݰ�����: " << length << endl;
}

void Connector::handleStart() {
	cout << "��ǰ�ǿ�ʼ״̬...   ���ݰ�����: " << length;
	if (length != 0) {
		CHESS_COLOR color;
		memcpy(&color, data, length);
		delete data;
		cout << "  ��ǰ����ɫ��: " << (color ? "�׷�" : "�ڷ�") << endl;
	}
}

void Connector::handleRun() {

}
void Connector::handleChange() {

}
void Connector::handleQueryRegret() {

}
void Connector::handleRegret() {

}
void Connector::handleFull() {

}