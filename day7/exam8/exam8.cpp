// exam8.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

void dumpBuf(int nBuf[],int nSize)
{
	for (int i = 0; i < nSize; i++) {
		printf("%d", nBuf[i]);
	}
	printf("\n");
}

int main()
{
	int nBuf[16] = {1,2,3,4,5,6,7,8};

	bool bLoop = true;
	while (bLoop) {
		int nIndex;
		printf("������ ��ġ�� �Է��ϼ��� : ");
		scanf("%d", &nIndex);
		
		for (int i = nIndex ; i < sizeof(nBuf) / sizeof(nBuf[0]); i++) {
			nBuf[i] = nBuf[i + 1];
			nBuf[sizeof(nBuf) / sizeof(nBuf[0])] = 0;

		}

		//nBuf[nIndex] = nBuf[nIndex + 1];

		dumpBuf(nBuf,sizeof(nBuf)/sizeof(nBuf[0]));
	}
	return 0;
}