// exam2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#define SERVER "192.168.100.151"
#define BUFLEN 512
#define PORT 3333

int main()
{
	sockaddr_in si_other;
	int s, slen = sizeof(si_other);
	char buf[BUFLEN];
	char message[BUFLEN];
	WSADATA wsa;

	if(WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("error WSAStartup \n");
		exit(EXIT_FAILURE);
	}

	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR) {
		printf("error SOCKET_ERROR \n");
		exit(EXIT_FAILURE);
	}

	memset((char *)&si_other, 0, slen);
	si_other.sin_family = AF_INET;
	si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);
	si_other.sin_port = htons(PORT);

	while (1) {
		printf("enter any message : ");
		scanf("%s", message);

		if (sendto(s, message, strlen(message), 0, (sockaddr *)&si_other, slen) == SOCKET_ERROR) {
			printf("sendto error \n");
			exit(EXIT_FAILURE);
		}
		memset(buf, '\O', BUFLEN);
		if (recvfrom(s, buf, BUFLEN, 0, (sockaddr *)&si_other, &slen) == SOCKET_ERROR) {
			printf("recvform error \n");
			exit(EXIT_FAILURE);
		}
		printf("%s \n", buf);
	}
    return 0;
}

