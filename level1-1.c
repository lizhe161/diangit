#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

#include <math.h>
int main(void)
{
	int A, B, C;
	printf(" ������һ�����ڵĲ���A,Ŀ�Ĳ���,�������ڵĲ���C\n");
	(void)scanf("%d %d %d",&A,&B,&C);
	printf("�������ڵĲ���   ���е�ʱ��     �����ڵ�����\n");
	printf("%11d,          0,         0\n",C);
	int D = abs(A-C);//���ݵ����ڵĲ�����ʱ��
	int E = abs(A-B);//�˵�Ŀ�Ĳ�����ʱ��
	int F = D + E;//�ܹ����е�ʱ��
	printf("%11d,%11d,         1\n",A,D);
	printf("%11d,%11d,         0\n",B,F);
	return 0;
}

