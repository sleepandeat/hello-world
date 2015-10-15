#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	WSAData wsaData;
	WSAStartup(MAKEWORD(2,2), &wsaData);

	SOCKET sock =  socket(AF_INET, SOCK_STREAM, 0);
	
	//判断是否创建成功
	if (sock == INVALID_SOCKET) {
		printf("创建套接字失败。\n");
		WSACleanup();
		return 1;
	}

	printf("成功创建一个tcp套接字。\n");

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(6000);

	//printf("%08x", inet_addr("127.0.0.1"));
	int result = bind(sock, (sockaddr*)&addr, sizeof(addr));
	if(result == SOCKET_ERROR)
{
		printf("邦定套接字失败。\n");
		closesocket(sock);
		WSACleanup();
		return 1;
	}

	printf("成功邦定套接字。\n");

	//关闭套接字
	closesocket(sock);
	WSACleanup();

	system("pause");
	return 0;
}
