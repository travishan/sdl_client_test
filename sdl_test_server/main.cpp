/*
*/

//#include "AdBase.h"
//#include "AdLevel.h"
//#include "AdScreen.h"
//#include "AdSpriteManager.h"

#include "MyWindow.h"
#include "ClientSocket.h"

#include <string.h>
#include <string>
#include <iostream>


using namespace std;

MyWindow win;
ClientSocket client;

//-----------------------------------------------------------------------------
int SDL_main(int argc, char* argv[]) {
	win.init("test");

	//client.initNetwork("115.159.220.253", 9088); 
	client.initNetwork("127.0.0.1", 9088);

	//char data[MAX_PACKET] = "abcdefghijklmn";
	B_POINT p{ 5,10 };
	while (true) {
		/*flag = FLAG_PLAY;
		client.sendData((uint8_t*)&p, sizeof(p), flag);
		flag = FLAG_CONN;
		client.sendData((uint8_t*)&p, sizeof(p), flag);*/
		uint16_t recvFlag;
		uint16_t recvLength;
		uint8_t *data = client.recvData(recvFlag, recvLength);

		cout << recvFlag << endl;

		if (data != nullptr) {
			char *str = new char[recvLength];
			memcpy(str, data, recvLength);
			delete data;
			cout << "time:" << str << endl;
		}
		
	}

		

	
	//SDL_Event sdlEvent = {};
	//while (sdlEvent.type != SDL_QUIT) {
	//	SDL_PollEvent(&sdlEvent);

	//	win.clear();

	//	//string message("Hello Server I'm Han!");
	//	
	//	win.present();
	//}

	
	client.closeSocket();

	win.quit();

	return 0;
}