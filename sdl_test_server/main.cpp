/*
*/

//#include "AdBase.h"
//#include "AdLevel.h"
//#include "AdScreen.h"
//#include "AdSpriteManager.h"

#include "define.h"
#include "MyWindow.h"
#include "Connector.h"


MyWindow win;
Connector client;
//-----------------------------------------------------------------------------
int SDL_main(int argc, char* argv[]) {
	win.init("test");

	client.connect("127.0.0.1", 9088);

	while (true) {
		client.recv();
	}

	client.disconnect();
	win.quit();

	return 0;
}