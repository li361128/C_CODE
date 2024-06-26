#include <stdio.h>

#include <stdlib.h>



typedef int Status;

#define OK 1

#define ERROR 0

#define OVERFLOW -2



//�����еĴ洢�ṹ

typedef struct QNode {

     int data;

     struct QNode *next;

} QNode, *QueuePtr;



typedef struct {

     QueuePtr front; //��ͷָ��

     QueuePtr rear; //��βָ��

     int QLength; //�ӳ� 

} LinkQueue;



//�����еĳ�ʼ��

Status InitQueue(LinkQueue *Q) {

     Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));

     Q->front->next = NULL;

     Q->QLength = 0; 

     return OK;

}



//����Ԫ��eΪ������Q���µĶ�βԪ��

Status EnQueue(LinkQueue *Q, int e) {

     QueuePtr p;

     p = (QueuePtr) malloc(sizeof(QNode));

     p->data = e;

     p->next = NULL;

     Q->rear->next = p;

     Q->rear = p;

     Q->QLength++;

     return OK;

}



//ɾ��������Q�Ķ�ͷԪ�أ���e������ֵ

Status DeQueue(LinkQueue *Q, int *e) { 

    //�벹ȫ����
    if(Q->QLength == 0)	return ERROR;
    

	 QueuePtr p = Q->front->next;
	*e = p->data;  
	 Q->front->next = p->next;
	 free(p);
	 Q->QLength --;
	 return OK;






}



//����������Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��

int GetHead(LinkQueue Q) {

     if ((Q.front != Q.rear) && (Q.QLength != 0))

          return Q.front->next->data;

}





int main() {

    //�벹ȫ����
    LinkQueue Q;
    InitQueue(&Q);
    
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i = 0;i < n;i ++)
    {
    	scanf("%d",&arr[i]); 
    	EnQueue(&Q,arr[i]);
	}
	if(n == 1)	printf("%d",arr[i]);
	for(i = 0;i <n;i ++)
	{
		int temp;
		DeQueue(&Q,&temp);
		if(Q.QLength == 0 || Q.rear->data != temp)	EnQueue(&Q,temp);
	}
		
	QueuePtr p = Q.front->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}

}
