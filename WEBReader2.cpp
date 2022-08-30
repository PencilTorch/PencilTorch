#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>
#include <string>
#include <fstream>
using namespace std;

string get_source() {
	WSADATA WSAData;
	if (WSAStartup(MAKEWORD(2, 2), (LPWSADATA)&WSAData) != 0) {
		cout << "WSAStartup faled!\n";
	}

	SOCKET sock = INVALID_SOCKET;
	SOCKADDR_IN sin;

	char buffer[1024];

	////////////////This is portion that is confusing me//////////////////////////////////////////////////
	string srequete = "GET /index.php HTTP/1.1\r\n";
	srequete += "Host: localhost\r\n";
	srequete += "Connection: close\r\n";
	srequete += "Accept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5\r\n";
	srequete += "Accept-Language: fr,fr-fr;q=0.8,en-us;q=0.5,en;q=0.3\r\n";
	srequete += "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7\r\n";
	srequete += "User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; fr; rv:1.8.1.3) Gecko/20070309 Firefox/2.0.0.3\r\n";
	//srequete += "Referer: http://pozzyx.net/\r\n";
	srequete += "\r\n";
	///////////////////////////////////////////////////////////////////////////////////////////////////////

	size_t requete_taille = srequete.size() + 1;

	char crequete[5000];
	strncpy(crequete, srequete.c_str(), requete_taille);

	string source = "";

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) {
		cout << "Socked creation failed!";
	}
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(80);

	// on se connecte sur le site web.
	if (connect(sock, (SOCKADDR*)&sin, sizeof(sin)) == SOCKET_ERROR) {
		cout << "Connecting socket failed!\n";
	}

	if (send(sock, crequete, strlen(crequete), 0) == SOCKET_ERROR) {
		cout << "Unable to send!";
	}
	
	int i = 0;
	do {
		i = recv(sock, buffer, sizeof(buffer), 0);
		source += buffer;
	} while (i != 0); 

	closesocket(sock);
	WSACleanup();

	return source;
}

int main() {
	ofstream fout;
	fout.open("Buffer.txt");
	fout << get_source();
	fout.close();
	system("PAUSE");

	return 0;
}