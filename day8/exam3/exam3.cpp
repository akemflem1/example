// exam3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>


int main()
{
	char szInputBuf[] = "23,45,67,100,45";
	char szTemp[16];
	int nTeptIndex = 0;

	int nSum = 0;
	for (int i = 0; i < sizeof(szInputBuf) / sizeof(szInputBuf[0]); i++) {
		if (szInputBuf[i] == ',' || szInputBuf[i] == NULL) {
			szTemp[nTeptIndex] = NULL;
			printf("%s \n", szTemp);
			int nNum = atoi(szTemp);
			nSum += nNum;
			nTeptIndex = 0;
		}
		else {
			szTemp[nTeptIndex++] = szInputBuf[i];
		}
	}
	printf("Sum : %d \n", nSum);
	
    return 0;
}

