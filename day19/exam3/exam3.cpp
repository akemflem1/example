// exam3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#define BUFSIZE 256

int main()
{
	FILE *fp;
	fp = fopen("test.json", "r");

	char Buf[BUFSIZE];
	memset(Buf, 0, 256);

	int c = fread(Buf, 256, 1, fp);

	printf("%d, %s \n",c, Buf);

	printf("---- 파싱한 결과 ---- \n", c, Buf);


	cJSON *root = cJSON_Parse(Buf);

	cJSON *pJsonName = cJSON_GetObjectItemCaseSensitive(root, "name");
	cJSON *pJsonAge = cJSON_GetObjectItemCaseSensitive(root, "age");
	cJSON *pJsonHeight = cJSON_GetObjectItemCaseSensitive(root, "height");

	printf("이름 : %s \n", pJsonName->valuestring);
	printf("나이 : %d \n", pJsonAge->valueint);
	printf("키 : %.2lf \n", pJsonHeight->valuedouble);


	fclose(fp);

    return 0;
}

