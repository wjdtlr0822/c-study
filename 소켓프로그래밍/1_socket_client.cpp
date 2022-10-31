#include <iostream>
#include <WinSock2.h>

#pragma comment(lib,"ws2_32") //위에서 선언한 헤더파일들을 가져다 쓰기위한 링크
using namespace std;

#define PORT 7777
#define PACKET_SIZE 1024
#define SERVER_IP "175.112.65.198"
#define SERVER_IP1 "175.112.65.198"

int main() {
	WSADATA wsaData;
	int code = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (code == 0) {
		SOCKET hSocket;
		hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

		SOCKADDR_IN tAddr = {};
		tAddr.sin_family = AF_INET;
		tAddr.sin_port = htons(PORT);
		tAddr.sin_addr.s_addr = inet_addr(SERVER_IP1);

		connect(hSocket, (SOCKADDR*)&tAddr, sizeof(tAddr)); //소켓 / 소켓 구성요소 구조체의 주소 / 구조체의 크기

		char cMsg[] = "Client Send";
		send(hSocket, cMsg, strlen(cMsg), 0);

		char cBuffer[PACKET_SIZE] = {};
		recv(hSocket, cBuffer, PACKET_SIZE, 0);

		cout << "recv : " << cBuffer << endl;

		closesocket(hSocket);

		WSACleanup();
	}
	else {
		cout << "서버 연결 실패" << endl;
	}
	return 0;
}