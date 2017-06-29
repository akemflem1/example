// exam4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[] = { 2,4,6,7,12,14,3,13,19,3,1,2,19,6,12,5,3,16,7,9,3,5,6,7 };
	int count[20] = { 0 };
	int nCount = 0;
	/*
	for (int num = 1; num < 21; num++) {
		for (int i = 0; i < sizeof(ary) / sizeof(ary[0]); i++) {
			if (num == ary[i])
				nCount++;
		}
		printf("%d - %d개 \n",num, nCount);
		nCount = 0;
	}
	*/

	for (int i = 0; i < sizeof(ary) / sizeof(ary[0]); i++) {
		count[ary[i]-1]++;
		}

	for (int i = 0; i < 20; i++) {
		printf("%d - %d개 \n", i+1,count[i]);
	}
    return 0;
}

