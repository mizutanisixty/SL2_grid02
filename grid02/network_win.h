#ifndef __network_win__
#define __network_win__
//Network Dynamic Link Library depending on Windows API
//#pragma comment(linker,"/export:connect=_connect4")
//_declspec(dllexport) 
#include <stdio.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include "includer_std.h"
#include "define.h"

class network{
	char destination[32];
	int dstSocket;
	sockaddr_in dstAddr;
	network(){};
	~network(){};
};

#endif
