#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

static int step = 0;

//�ƶ�����

void move(int n, char *A, char *B)

{

    printf("��%d��%c�ƶ���%c.\n", n, *A, *B);

    step++;

    return;

 

}

 

//��n�㺺ŵ����A�ƶ���C��B��Ϊ����

void Hanoi(int n, char *A, char *B, char *C)

{

/* ������������ */
	if(n == 1)	move(n,A,C);
	else
	{
		Hanoi(n - 1,A,C,B);
		move(n,A,C);
		Hanoi(n - 1,B,A,C);	
	} 

 

}

 

int main()

{

    int n;

    char axle[3]={'A','B','C'};

 

    printf("�������n:");

    scanf("%d",&n);

 

    Hanoi(n, axle, axle+1, axle+2);

    printf("����%d�㺺ŵ�������ܲ���Ϊ%d\n", n, step);

    return 0;

}


