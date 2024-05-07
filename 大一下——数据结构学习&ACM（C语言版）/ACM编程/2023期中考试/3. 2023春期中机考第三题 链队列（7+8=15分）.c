#include <stdio.h>

#include <stdlib.h>

#define OK 1

#define ERROR 0

#define OVERFLOW 0



typedef char ElemType;

typedef int Status;

typedef struct QNode

{

    ElemType data;

    struct QNode *next;

}QNode,*queuePtr;   



typedef struct

{

    queuePtr front; //ָ�������е�ͷ

    queuePtr rear;  //ָ�������е�β 

}LinkQueue;



//���г�ʼ��

Status InitQueue(LinkQueue *q)

{

   q->front=q->rear=(queuePtr)malloc(sizeof(QNode));  //����ͷ�ڵ� ͷָ��ָ��ͷ�ڵ�

   if(!q->front)  //����ʧ��

   {

       return ERROR;

   }

   q->front->next=NULL;

   return OK;

}



//�ж϶����Ƿ�Ϊ��

Status QueueEmpty(LinkQueue Q)

{

    if(Q.front==Q.rear)

        return OK;

    else

        return ERROR;

}// QueueEmpty



int QueueLength (LinkQueue Q)

{

    int i;

    queuePtr p;

    p = Q.front->next;   //pָ���ͷ

    i=1;

    while(p!=Q.rear)  //����������,ͳ�ƽ����

	{

        i++;

        p=p->next;

    }

    return i;

}// QueueLength



//��ö���Ԫ��

Status GetHead(LinkQueue q,ElemType *e)

{

    if(q.front == q.rear)

        return ERROR;

    *e = q.front->next->data;

    return OK;

}



//���

Status EnQueue(LinkQueue *q,ElemType e)

{

    queuePtr p=(queuePtr)malloc(sizeof(QNode)); //Ϊ��Ԫ�ط���ռ�

    if(!p) return ERROR; 

    p->data=e;

    p->next=NULL;

    q->rear->next=p; //Ϊβָ���next���¸�ֵ ��Ԫ�ز����β

    q->rear=p;  //���¶�λβָ��

    return OK;

}



//ɾ��Ԫ��

Status DeQueue(LinkQueue *q,ElemType *e)

{

    if(q->front == q->rear) return ERROR; //��ʱ����Ϊ��

    queuePtr p = q->front->next;  

    *e=p->data;  //ɾ���Ƕ���Ԫ��

    q->front->next=p->next;

    if(q->rear == p)

        q->rear=q->front;

    free(p);

    return OK;

}



//��������У�����ɹ�������OK�����򷵻�ERROR

Status ClearQueue (LinkQueue *Q)

{

	//�����벹ȫ����
	if(!Q->front)	return ERROR;
	free(Q->front);
	Q->front = Q->rear = 0;
	return OK; 







}// ClearQueue



//�������

Status PrintQueue(LinkQueue q)

{

    queuePtr p;

    p = q.front->next;

    while(p)

    {

        printf("%c ",p->data);

        p=p->next;

    }

    return OK;

}



//������Ϸ

void DecryptGame(LinkQueue *Q)

{

	//�����벹ȫ����
	LinkQueue S;
	InitQueue(&S);
	
	while(!QueueEmpty(*Q))
	{
		char temp;
		DeQueue(Q,&temp);
		EnQueue(&S,temp);
		if(!QueueEmpty(*Q))
		{
			DeQueue(Q,&temp);
			EnQueue(Q,temp);
		}
	} 

	PrintQueue(S);

 



}



int main()

{

    LinkQueue Q;

    InitQueue(&Q);

    int i;

    char a;

    for(i=0;i<10;i++)

    {

        scanf("%c",&a);

        EnQueue(&Q,a);

    }

    DecryptGame(&Q);

    printf("\n");

    ClearQueue(&Q);

    return 0;

}
