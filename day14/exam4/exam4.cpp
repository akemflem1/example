// exam4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

int main()
{
	char *pStr = "hello";
	char *pTemp;

	//pTemp = pStr;
	
	pTemp = (char*)malloc(strlen(pStr)+1);
	strcpy(pTemp, pStr);
	pTemp[0] = 'H';
	printf("%u %s \n", pTemp, pTemp);
	printf("%u %s \n", pStr, pStr);
	
	free(pTemp);

	return 0;
}

