// exam2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int nIndex = 0;
	while (nIndex < 10){
		printf("%d \n", nIndex);
		nIndex++;
	}

	nIndex = 0;
	do {
		printf("%d \n", nIndex);
		nIndex++;
	} while (nIndex < 10);

    return 0;
}

