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
	uint16_t flag;
	while (true) {
		flag = FLAG_PLAY;
		client.sendData((uint8_t*)&p, sizeof(p), flag);
		flag = FLAG_CONN;
		client.sendData((uint8_t*)&p, sizeof(p), flag);
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