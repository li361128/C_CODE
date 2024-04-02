#include "stdio.h"

#include "stdlib.h"

#include "string.h"

#define OK 1

#define ERROR 0

#define TURE 1

#define FALSE 0

#define MAXSIZE 36 //�洢�ռ�ĳ�ʼ������

typedef int Status;

typedef char QElemType;

typedef struct

{

	QElemType data[MAXSIZE];

	int front;

	int rear;

}SqQueue;

int QueueLength(SqQueue Q)

{
	return ((Q.rear - Q.front + MAXSIZE)%MAXSIZE); 
	//ѧ����������

}

Status EnQueue(SqQueue *Q, QElemType d)

{
	if(QueueLength(*Q) == MAXSIZE)	return ERROR;
	Q->data[Q->rear] = d;
	Q->rear = (Q->rear + 1)%MAXSIZE;
	return OK;
	//ѧ����������

}

Status DeQueue(SqQueue *Q, QElemType *d)

{
	if(!QueueLength(*Q))	return ERROR;
	*d = Q->data[Q->front] ;
	Q->front = (Q->front + 1)%MAXSIZE;
	return OK;
	//ѧ����������

}

int main()

{

	int i,j,d=1;

	char a[20];

	SqQueue Q;

	Q.front = 0;

	Q.rear = 0;

	for(i=0;;i++)

	{

		scanf("%c",&a[i]);

		if(a[i] == '@')

			break;

		else 

			EnQueue(&Q,a[i]);

	}

	j=QueueLength(Q);

	for(i=0;i<(j+1)/2;i++)

	{

		if(Q.data[Q.front+i]==Q.data[Q.rear-i-1])

			d=1;

		else

		{ 

			d=0;

			break;

		}

	}

	if(d==0)  printf("���ַ������ǻ���\n");

	else if(d==1) printf("���ַ���Ϊ����\n");

	return 0;

}


