#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"


typedef int QElement;

//������Ͷ���
typedef struct Node
{
    int value;
    struct Node *next;
}QueueNode;

typedef struct Queue
{
    QueueNode *front;//���ö�ͷ
    QueueNode *rear;//���ö�β
}Queue;

void InitQueue(Queue *q)
{
    q->front = (QueueNode*)malloc(sizeof(Queue));
    if (NULL == q->front)
    {
        printf("malloc free failed!\n ");
        return;
    }
    q->rear = q->front;
    q->front->next= NULL;//ʹ�ô���ͷ�ڵ�ָ���������
}

void EnterQueue(Queue *q, QElement x)
{
	QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
	if(!temp)	
	{
        printf("malloc free failed!\n ");
        return;
    }
	temp->value = x;
	q->rear->next = temp;
	q->rear = q->rear->next; 
}

void DeQueue(Queue *q,QElement *x)
{
	if(q->front == q->rear)	return ;
	*x = q->front->next->value;
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if(!temp)	
	{
        printf("malloc free failed!\n ");
        return;
    }
	temp = q->front;
	q->front = temp->next;
	free(temp); 
}

void GetQueueHead(Queue *q,QElement *x)
{
	if(q->front == q->rear)	return ;
	*x = q->front->next->value;
}

int main(void)
{
    Queue q;
	int QueueHead;
	int DequeValue;
    InitQueue(&q);
    EnterQueue(&q, 1);
	EnterQueue(&q, 2);
	EnterQueue(&q, 3);
	GetQueueHead(&q,&QueueHead);
	printf("��ͷԪ��Ϊ��%d\n",QueueHead);
	DeQueue(&q,&DequeValue);
	printf("����Ԫ��Ϊ��%d\n",DequeValue);

    return 0;
}
