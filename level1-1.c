#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

#include <math.h>
int main(void)
{
	int A, B, C;
	printf(" 请输入一人所在的层数A,目的层数,电梯所在的层数C\n");
	(void)scanf("%d %d %d",&A,&B,&C);
	printf("电梯所在的层数   运行的时间     电梯内的人数\n");
	printf("%11d,          0,         0\n",C);
	int D = abs(A-C);//电梯到人在的层数的时间
	int E = abs(A-B);//人到目的层数的时间
	int F = D + E;//总共运行的时间
	printf("%11d,%11d,         1\n",A,D);
	printf("%11d,%11d,         0\n",B,F);
	return 0;
}

