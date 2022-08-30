#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define BUFFER_SIZE 4096

#include <iostream>
#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

void trableDown(SOCKET*);

int main() {
	int result = 0;
	const char host[150] = "www.firststeps.ru";
	char pBuf[150] = "GET /index.html HTTP/1.0\r\nHost: www.firststeps.ru\r\n\r\n";
	char recBuffer[BUFFER_SIZE]{ 0 };
	WSADATA wsaData;

	SOCKET clientSock = INVALID_SOCKET;
	
	/*
	ADDRINFO hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	ADDRINFO* addrResult = nullptr;
	*/
	try {
		result = WSAStartup(MAKEWORD(2, 2), (LPWSADATA) &wsaData);
		if (result != 0)
			throw "WSAStartup faled!";

		LPHOSTENT hostEnt = gethostbyname(host);
		if (!hostEnt) {
			trableDown(&clientSock);
			throw "Unable to collect gethostbyname\n";
		}

		clientSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (clientSock == INVALID_SOCKET) {
			trableDown(&clientSock);
			throw "Socked creation failed!";
		}

		SOCKADDR_IN serverInfo;
		serverInfo.sin_family = PF_INET;
		serverInfo.sin_addr = *((LPIN_ADDR)*hostEnt->h_addr_list);
		serverInfo.sin_port = htons(80);
		result = connect(clientSock, (LPSOCKADDR)&serverInfo, sizeof(serverInfo));
		if (result == SOCKET_ERROR) {
			trableDown(&clientSock);
			throw "Connecting socket failed!";
		}
		else
			std::cout << "Connection made sucessfully!\n";
		
		std::cout << "Sending request from client\n";
		result = send(clientSock, pBuf, strlen(pBuf), 0);
		if (result == SOCKET_ERROR) {
			trableDown(&clientSock);
			throw "Unable to send!";
		}

		while (result = recv(clientSock, recBuffer, BUFFER_SIZE, 0) != 0) {
			//ZeroMemory(recBuffer, BUFFER_SIZE);
			std::cout << recBuffer;
		}
			
		result = shutdown(clientSock, SD_SEND);
		if (result == SOCKET_ERROR) {
			trableDown(&clientSock);
			throw "Shutdown client socket failed!";
		}
		trableDown(&clientSock);
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}

	return 0;
}

void trableDown(SOCKET* clientSock) {
	if (*clientSock == SOCKET_ERROR) {
		closesocket(*clientSock);
	}
	else if (*clientSock != INVALID_SOCKET) {
		*clientSock = INVALID_SOCKET;
	}
	WSACleanup();
}