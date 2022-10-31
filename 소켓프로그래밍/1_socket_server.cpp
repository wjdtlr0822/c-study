#include <iostream>
#include <WinSock2.h>

#pragma comment(lib,"ws2_32") //위에서 선언한 헤더파일들을 가져다 쓰기위한 링크

using namespace std;

#define PORT 7777
#define PACKET_SIZE 1024

int main() {
	WSADATA was; //윈도우의 소켓 초기화 정보를 저장하기위한 구조체
	int code = WSAStartup(MAKEWORD(2, 2), &was);

	// WSAStartup(소켓버전, WSADATA 구조체 주소);
	// : 이 함수를 가장 먼저 호출해준다.이 함수를 호출해서 윈도우즈에 어느 소켓을 활용할 것인지 알려준다.
	// 	첫번째 인자는 소켓 버전이 들어간다. 2.2 버전을 활용할건데 WORD 타입으로 들어가게 된다.
	// 	WORD는 unsigned short 타입을 typedef 해놓은 것이다.그런데 2.2 버전은 실수이므로,
	// 	2.2라는 실수를 정수값으로 변환하여 넣어줄 수 있어야 한다.MAKEWORD 매크로를 이용해서 만들어준다.
	// 	2번째 인자는 WSADATA 구조체의 포인터타입이 들어간다.
	if (code == 0) {
		SOCKET skt;
		skt = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // ip4v / sock_stream, TCP

		SOCKADDR_IN addr = {}; //소켓의 구성요소를 담을 구조체 생성 및 값 할당
		addr.sin_family = AF_INET; // 인자들에 대한 설명중 sin_family 는 반드시 AF_INET 이어야 함을 알 수 있다.
		addr.sin_port = htons(PORT); // port
		addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY에 서버의 주소를 적어주면 되는데 
		//INADDR_ANY는 지금 컴퓨터의 주소를 의미한다.

		cout << "서버 ON / 클라이언트 대기중" << endl;
		bind(skt, (SOCKADDR*)&addr, sizeof(addr)); // 소켓 /  소켓 구성요소 구조체의 주소  / 구조체의 크기
		listen(skt, SOMAXCONN); // 소켓 / 한꺼번에 요청 가능한 최대 접속승인 수


		SOCKADDR_IN tClntAddr = {};
		int iclntsize = sizeof(tClntAddr);
		SOCKET hClient = accept(skt, (SOCKADDR*)&tClntAddr, &iclntsize);
		//accept(소켓, 소켓 구성요소 주소체의 주소, 구조체의 크기를 담고있는 변수의 주소);

		char cBuffer[PACKET_SIZE] = {};
		recv(hClient, cBuffer, PACKET_SIZE, 0);
		cout << "RECV MSG : " << cBuffer << endl;

		char cMsg[] = "Server Send";
		send(hClient, cMsg, strlen(cMsg), 0);

		closesocket(hClient);
		closesocket(skt);

		WSACleanup();
		//	소켓을 활용하는것은 WSAStartup 함수와 WSACleanup 함수 사이에 작성해야 한다.생성자와 소멸자 같은 개념이다.
		//	WSACleanup 함수는 WSAStartup 을 하면서 지정한 내용을 지워준다.
	}
	else {
		cout << "서버 open 실패 " << endl;
	}
	return 0;
}