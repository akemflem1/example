// exam9.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int i = 0;
	while (true) {
		i++;
		if (i > 10){
			break;
		}
		printf("count : %d \n", i);
	}


	i = 0;
	while (true) {
		i++;
		if (i > 10) {
			break;
		}
		if (i % 2) {
			continue;
		}
		printf("count : %d \n", i);
	}
    return 0;
}

