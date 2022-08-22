//for Visual Studio (add ws2_32.lib & not unicode in settings project)

#define WIN32_LEAN_AND_MEAN
#define BUFFER_SIZE 512

#include <iostream>
#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

void trableDown(ADDRINFO*, SOCKET*);

int main() {
	int result = 0;
	const char sendBuffer[BUFFER_SIZE] = "Welcome to Server!";
	char recBuffer[BUFFER_SIZE]{ 0 };
	WSADATA wsaData;
	ADDRINFO hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET; //ip4 family
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;
	ADDRINFO* addrResult = nullptr;
	SOCKET ClientSocket = INVALID_SOCKET;
	SOCKET ListenSocket = INVALID_SOCKET;

	try {
		result = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (result != 0)
			throw "WSAStartup faled!";

		result = getaddrinfo(NULL, "666", &hints, &addrResult);
		if (result != 0) {
			trableDown(addrResult, &ListenSocket);
			throw "getaddrinfo failed!";
		}

		ListenSocket = socket(addrResult->ai_family, addrResult->ai_socktype, addrResult->ai_protocol);
		if (ListenSocket == INVALID_SOCKET) {
			trableDown(addrResult, &ListenSocket);
			throw "Socked creation failed!";
		}

		result = bind(ListenSocket, addrResult->ai_addr, (int)addrResult->ai_addrlen);
		if (result == SOCKET_ERROR) {
			trableDown(addrResult, &ListenSocket);
			throw "Binding socket failed!";
		}
		//result = send(ConnectCocket, sendBuffer, (int)strlen(sendBuffer), 0);
		result = listen(ListenSocket, SOMAXCONN);
		if (result == SOCKET_ERROR) {
			trableDown(addrResult, &ListenSocket);
			throw "Listening socked failed!";
		}
		//std::cout << "sent: " << result << " bites. \n";

		ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			trableDown(addrResult, &ListenSocket);
			throw "Accepting socked failed!";
		}
		closesocket(ListenSocket);

		do {
			ZeroMemory(recBuffer, BUFFER_SIZE);
			result = recv(ClientSocket, recBuffer, BUFFER_SIZE, 0);
			if (result > 0) {
				std::cout << "Received " << result << " bytes. \n";
				std::cout << "Received data " << recBuffer << std::endl;
				if (send(ClientSocket, sendBuffer, BUFFER_SIZE, 0) == SOCKET_ERROR) {
					trableDown(addrResult, &ClientSocket);
					throw "Failed to send data back!";
				}
			}
			else if (result == 0)
				std::cout << "Connection closed.\n";
			else {
				trableDown(addrResult, &ClientSocket);
				throw "recv filed with error.";
			}	
		} while (result > 0);

		result = shutdown(ClientSocket, SD_SEND);
		if (result == SOCKET_ERROR) {
			trableDown(addrResult, &ClientSocket);
			throw "Shutdown client socket failed!";
		}
		trableDown(addrResult, &ClientSocket);
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}

	return 0;
}

void trableDown(ADDRINFO* addrResult, SOCKET* ConnectCocket) {
	if (*ConnectCocket == SOCKET_ERROR) {
		closesocket(*ConnectCocket);
	}
	else if (*ConnectCocket != INVALID_SOCKET) {
		*ConnectCocket = INVALID_SOCKET;
	}
	if (addrResult != nullptr) {
		FreeAddrInfo(addrResult);
	}
	WSACleanup();
}
