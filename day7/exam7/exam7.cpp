// exam7.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

void dumpBuf(int nBuf[])
{
	for (int i = 0; i < 16; i++) {
		printf("%d", nBuf[i]);
	}
	printf("\n");
}

int main()
{
	int nBuf[16] = {};

	bool bLoop = true;
	while (bLoop) {
		int nIndex, nValue;
		printf("������ ��ġ�� ���� �Է��ϼ��� : ");
		scanf("%d %d", &nIndex, &nValue);
		if (nIndex > sizeof(nBuf) / sizeof(nBuf[0])) bLoop = false;

		//nBuf[nIndex + 1] = nBuf[nIndex];
		for (int i = (sizeof(nBuf) / sizeof(nBuf[0]) - 1); i > nIndex; i--) {
			nBuf[i] = nBuf[i - 1];

		}
		
			nBuf[nIndex] = nValue;

		dumpBuf(nBuf);
	}
    return 0;
}

