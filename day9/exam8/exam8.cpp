// exam8.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	char *strltems = "pick,plate amor,lather grove,sword,dager";
	int nIndexTable[32];

	int nCount = 0;
	int i = 0;
	for (int i = 0; strltems[i] != 0x00; i++) {

		if (strltems[i] == ',') {
			nIndexTable[nCount++] = i;
		}
	}
	nIndexTable[nCount] = i;

	int nIndex = 0;
	printf("select index : ");
	scanf("%d", &nIndex);

	//printf("%s \n",&(strltems[nIndexTable[nIndex]]));
	char *pTemp = &(strltems[nIndexTable[nIndex]]);
	int nSize = (nIndexTable[nIndex + 1] - nIndexTable[nIndex]) - 1;
	pTemp += 1;
	for (int i = 0; i < nSize; i++) {
		printf("%c", pTemp[i]);
	}
	printf("\n");

    return 0;
}

