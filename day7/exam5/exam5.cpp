// exam5.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[] = {1,2,3,4,5,6,7,8,9,10};
	int buf;
	for (int i = 0; i < sizeof(ary) / sizeof(ary[0]); i++) {
		if (i < (sizeof(ary) / sizeof(ary[0])) / 2) {
			buf = ary[i];
			ary[i] = ary[(sizeof(ary) / sizeof(ary[0])) - (1 + i)];
			ary[(sizeof(ary) / sizeof(ary[0])) - (1 + i)] = buf;
		}
		printf("%d \n", ary[i]);
	}

    return 0;
}

