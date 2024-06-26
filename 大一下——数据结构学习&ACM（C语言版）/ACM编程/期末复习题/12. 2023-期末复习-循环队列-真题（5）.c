
#include<stdio.h>
#include<stdlib.h>

#define OK    1
#define ERROR 0
#define TRUE  1
#define FALSE 0
#define MAXSIZE 6

typedef  int  Elemtype;
typedef  int  Status;

typedef  struct {
	Elemtype *base;
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue *Q)
{
	Q->base=(Elemtype*)malloc(sizeof(Elemtype)*MAXSIZE);
	if(Q->base==NULL)
		return ;
	Q->front=Q->rear=0;
}

Status EnQueue(SqQueue *Q,Elemtype e)
{
//ѧ����ӵĳ���
	if(Q->rear - Q->front == MAXSIZE + 1)
		return ERROR;
	Q->base[Q->rear ++] = e; 
	return OK;
}

Status DeQueue(SqQueue *Q,Elemtype *e)
{
//ѧ����ӵĳ���
	if(Q->rear - Q->front == 0)
		return ERROR;
	*e = Q->base[Q->front ++];
	return OK;
}

Status QueueEmpty(SqQueue *Q)
{
	if(Q->rear==Q->front)
	{
		return TRUE;
	}
	return FALSE;
}

Status QueueLength(SqQueue *Q)
{
	return (Q->rear-Q->front+MAXSIZE)%MAXSIZE;
}

Status GetHead(SqQueue *Q,Elemtype *e)
{
	if(Q->rear==Q->front)
	{
		return ERROR;
	}
	*e=Q->base[Q->front];
	return OK;
}

void ClearQueue(SqQueue *Q)
{
	Q->front=Q->rear=0;
}

void DestoryQueue(SqQueue *Q)
{
	if(Q->base)
	{
		free(Q->base);
	}
	Q->base=0;
	Q->front=Q->rear=0;
}

void QueueTraverse(SqQueue *Q,void(*visit)(Elemtype))
{
	int i=Q->front;
	while(i!=Q->rear)
	{
		visit(Q->base[i]);
		i=(i+1)%MAXSIZE;
	}
	printf("\n");
}

void Print(Elemtype e)
{
	printf("%d ",e);
}

int main()
{
	int i,k;
	Elemtype d,e;
	SqQueue Q;
	InitQueue(&Q);
	printf("������%d������Ԫ��:\n",MAXSIZE-1);
	for(i=1;i<MAXSIZE;i++)
	{
		scanf("%d",&d);
		EnQueue(&Q,d);
	}
	printf("����Ԫ��Ϊ:");
	QueueTraverse(&Q,Print);
	printf("���г���Ϊ%d\n",QueueLength(&Q));
	
	k=QueueLength(&Q);
	for(i=0;i<k;i++)
	{
		DeQueue(&Q,&e);
		printf("ɾ���Ķ��е�Ԫ���ǣ�%d\n",e);
	}
	return 0;
}
