#pragma once
#ifndef __CLIENT__SOCKET__H__
#define __CLIENT__SOCKET__H__

#include <SDL_net.h>
#include <string>
#include <iostream>

using namespace std;


#define MAX_PACKET 1024








class ClientSocket
{
public:

	void closeSocket();
	void sendData(uint8_t* data, uint16_t length);
	void initNetwork(const char* pIP, int iPort);
	bool checkSocket();
	uint8_t* recvData(uint16_t &length);
private:
	TCPsocket socket;
	SDLNet_SocketSet socket_set;
};












#endif // !__CLIENT__SOCKET__H__
