// exam12.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	//char strTemp[5] = "Hani";
	char strTemp[5];

	strTemp[0] = 'H';
	strTemp[1] = 'a';
	strTemp[2] = 'n';
	strTemp[3] = 'i';
	strTemp[4] = '\0';

	printf("%s \n", strTemp);

	char szBuf[256];
	printf("당신의 이름은 무엇입니까?");
	scanf("%s", szBuf);

	printf("안녕하세요 %s 님 \n", szBuf);

    return 0;
}

