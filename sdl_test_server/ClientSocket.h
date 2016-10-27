#pragma once
#ifndef __CLIENT__SOCKET__H__
#define __CLIENT__SOCKET__H__

#include <SDL_net.h>
#include <string>
#include <iostream>

using namespace std;


#define MAX_PACKET 1024


#define GRID_MIN 0
#define GRID_NUM 15
#define GRID_COUNT 15*15

//�ͻ�������������͵���Ϣͷ   uint16_t��ʽ
#define FLAG_QUIT 0x0000   //�˳���Ϣ
#define FLAG_CONN 0x0010   //����
#define FLAG_PLAY 0x0011    //����
#define FLAG_REGRET 0x0012 //����

//�������ͻ��˷��͵���Ϣͷ  uint16_t��ʽ
#define FLAG_FULL 0x0013   //��Ա
#define FLAG_UPDATE 0x0014  //������Ϸ״̬


typedef struct
{
	int row;
	int col;
}B_POINT;



class ClientSocket
{
public:

	void closeSocket();
	void sendData(uint8_t* data, uint16_t length, uint16_t flag);
	void initNetwork(const char* pIP, int iPort);
	bool checkSocket();
	uint8_t* recvData(uint16_t &length);
private:
	TCPsocket socket;
	SDLNet_SocketSet socket_set;
};












#endif // !__CLIENT__SOCKET__H__
