#include "ClientSocket.h"






void ClientSocket::closeSocket() {
	if (SDLNet_TCP_DelSocket(socket_set, socket) == -1) {
		fprintf(stderr, "%s\n", SDLNet_GetError());
		system("pause");
		exit(-1);
	}

	SDLNet_FreeSocketSet(socket_set);
	SDLNet_TCP_Close(socket);
}

void ClientSocket::sendData(uint8_t* data, uint16_t length) {

	int num_sent = SDLNet_TCP_Send(socket, data,length);
	if (num_sent < length) {
		fprintf(stderr, "ER: SDLNet_TCP_Send: %s\n", SDLNet_GetError());
		closeSocket();
	}
}

void ClientSocket::initNetwork(const char* pIP, int iPort) {
	IPaddress ip;
	if (SDLNet_ResolveHost(&ip, pIP, iPort) == -1) {
		fprintf(stderr, "%s\n", SDLNet_GetError());
		system("pause");
		exit(-1);
	}

	socket = SDLNet_TCP_Open(&ip);
	if (socket == NULL) {
		fprintf(stderr, "%s\n", SDLNet_GetError());
		cerr << SDLNet_GetError() << endl;
		system("pause");
		exit(-1);
	}

	socket_set = SDLNet_AllocSocketSet(1);
	if (socket_set == NULL) {
		fprintf(stderr, "%s\n", SDLNet_GetError());
		system("pause");
		exit(-1);
	}

	if (SDLNet_TCP_AddSocket(socket_set, socket) == -1) {
		fprintf(stderr, "%s\n", SDLNet_GetError());
		system("pause");
		exit(-1);
	}
}


bool ClientSocket::checkSocket() {
	if (SDLNet_CheckSockets(socket_set, 0) == -1) {
		fprintf(stderr, "%s\n", SDLNet_GetError());
		system("pause");
		exit(-1);
	}

	return SDLNet_SocketReady(socket);
}


uint8_t* ClientSocket::recvData(uint16_t &length) {
	uint8_t temp_data[MAX_PACKET];
	int num_recv = SDLNet_TCP_Recv(socket, temp_data, MAX_PACKET);

	if (num_recv <= 0) {
		closeSocket();

		const char* err = SDLNet_GetError();
		if (strlen(err) == 0) {
			printf("DB: server shutdown\n");
		} else {
			fprintf(stderr, "ER: SDLNet_TCP_Recv: %s\n", err);
		}

		return nullptr;
	} else {
		length = num_recv;

		uint8_t* data = (uint8_t*)malloc(num_recv * sizeof(uint8_t));
		memcpy(data, temp_data, num_recv);

		return data;
	}
}