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

//客户端向服务器发送的消息头   uint16_t格式
#define FLAG_QUIT 0x0000   //退出消息
#define FLAG_CONN 0x0010   //连接
#define FLAG_PLAY 0x0011    //下棋
#define FLAG_REGRET 0x0012 //悔棋

//服务端向客户端发送的消息头  uint16_t格式
#define FLAG_FULL 0x0013   //满员
#define FLAG_UPDATE 0x0014  //更新游戏状态


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
