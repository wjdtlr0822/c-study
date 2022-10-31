#include <iostream>
#include <WinSock2.h>

#pragma comment(lib,"ws2_32") //������ ������ ������ϵ��� ������ �������� ��ũ

using namespace std;

#define PORT 7777
#define PACKET_SIZE 1024

int main() {
	WSADATA was; //�������� ���� �ʱ�ȭ ������ �����ϱ����� ����ü
	int code = WSAStartup(MAKEWORD(2, 2), &was);

	// WSAStartup(���Ϲ���, WSADATA ����ü �ּ�);
	// : �� �Լ��� ���� ���� ȣ�����ش�.�� �Լ��� ȣ���ؼ� ������� ��� ������ Ȱ���� ������ �˷��ش�.
	// 	ù��° ���ڴ� ���� ������ ����. 2.2 ������ Ȱ���Ұǵ� WORD Ÿ������ ���� �ȴ�.
	// 	WORD�� unsigned short Ÿ���� typedef �س��� ���̴�.�׷��� 2.2 ������ �Ǽ��̹Ƿ�,
	// 	2.2��� �Ǽ��� ���������� ��ȯ�Ͽ� �־��� �� �־�� �Ѵ�.MAKEWORD ��ũ�θ� �̿��ؼ� ������ش�.
	// 	2��° ���ڴ� WSADATA ����ü�� ������Ÿ���� ����.
	if (code == 0) {
		SOCKET skt;
		skt = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // ip4v / sock_stream, TCP

		SOCKADDR_IN addr = {}; //������ ������Ҹ� ���� ����ü ���� �� �� �Ҵ�
		addr.sin_family = AF_INET; // ���ڵ鿡 ���� ������ sin_family �� �ݵ�� AF_INET �̾�� ���� �� �� �ִ�.
		addr.sin_port = htons(PORT); // port
		addr.sin_addr.s_addr = htonl(INADDR_ANY); // INADDR_ANY�� ������ �ּҸ� �����ָ� �Ǵµ� 
		//INADDR_ANY�� ���� ��ǻ���� �ּҸ� �ǹ��Ѵ�.

		cout << "���� ON / Ŭ���̾�Ʈ �����" << endl;
		bind(skt, (SOCKADDR*)&addr, sizeof(addr)); // ���� /  ���� ������� ����ü�� �ּ�  / ����ü�� ũ��
		listen(skt, SOMAXCONN); // ���� / �Ѳ����� ��û ������ �ִ� ���ӽ��� ��


		SOCKADDR_IN tClntAddr = {};
		int iclntsize = sizeof(tClntAddr);
		SOCKET hClient = accept(skt, (SOCKADDR*)&tClntAddr, &iclntsize);
		//accept(����, ���� ������� �ּ�ü�� �ּ�, ����ü�� ũ�⸦ ����ִ� ������ �ּ�);

		char cBuffer[PACKET_SIZE] = {};
		recv(hClient, cBuffer, PACKET_SIZE, 0);
		cout << "RECV MSG : " << cBuffer << endl;

		char cMsg[] = "Server Send";
		send(hClient, cMsg, strlen(cMsg), 0);

		closesocket(hClient);
		closesocket(skt);

		WSACleanup();
		//	������ Ȱ���ϴ°��� WSAStartup �Լ��� WSACleanup �Լ� ���̿� �ۼ��ؾ� �Ѵ�.�����ڿ� �Ҹ��� ���� �����̴�.
		//	WSACleanup �Լ��� WSAStartup �� �ϸ鼭 ������ ������ �����ش�.
	}
	else {
		cout << "���� open ���� " << endl;
	}
	return 0;
}