//for Visual Studio (add ws2_32.lib & not unicode in settings project)

#define WIN32_LEAN_AND_MEAN
#define BUFFER_SIZE 512

#include <iostream>
#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

void trableDown(ADDRINFO* addrResult, SOCKET* ConnectCocket);

int main() {
    int result = 0;
	const char sendBuffer[BUFFER_SIZE] = "Hello from client!";
	char recBuffer[BUFFER_SIZE] { 0 };
    WSADATA wsaData;
	ADDRINFO hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET; //ip4 family
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	ADDRINFO* addrResult = nullptr;
	SOCKET ConnectSocket = INVALID_SOCKET;

	try {
		result = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (result != 0)
			throw "WSAStartup faled!";

		result = getaddrinfo("localhost", "666", &hints, &addrResult);
		if (result != 0) {
			trableDown(addrResult, &ConnectSocket);
			throw "getaddrinfo failed!";
		}

		ConnectSocket = socket(addrResult->ai_family, addrResult->ai_socktype, addrResult->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			trableDown(addrResult, &ConnectSocket);
			throw "Socked creation failed!";
		}

		result = connect(ConnectSocket, addrResult->ai_addr, (int)addrResult->ai_addrlen);
		if (result == SOCKET_ERROR) {
			trableDown(addrResult, &ConnectSocket);
			throw "Unable connect to server!";
		}

		result = send(ConnectSocket, sendBuffer, (int)strlen(sendBuffer), 0);
		if (result == SOCKET_ERROR) {
			trableDown(addrResult, &ConnectSocket);
			throw "Send failed!";
		}
		std::cout << "sent: " << result << " bites. \n";

		result = shutdown(ConnectSocket, SD_SEND);
		if (result == SOCKET_ERROR) {
			trableDown(addrResult, &ConnectSocket);
			throw "Shutdown error!";
		}

		do {
			ZeroMemory(recBuffer, BUFFER_SIZE);
			result = recv(ConnectSocket, recBuffer, BUFFER_SIZE, 0);
			if (result > 0) {
				std::cout << "Received " << result << " bytes. \n";
				std::cout << "Received data " << recBuffer << std::endl;
			}
			else if (result == 0)
				std::cout << "Connection closed.\n";
			else
				throw "recv filed with error.";

		} while (result > 0);
		trableDown(addrResult, &ConnectSocket);
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
