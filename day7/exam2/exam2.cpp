// exam2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int nums[5] = { 1,3,15,7 };

	printf("%d \n", sizeof(nums));

	for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++) {
		printf("%d -> %d , %u \n",i, nums[i], &nums[i]);
	}
    return 0;
}

