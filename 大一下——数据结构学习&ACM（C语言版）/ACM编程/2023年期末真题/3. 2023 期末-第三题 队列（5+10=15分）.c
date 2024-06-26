#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>
#define null 0
#define OK 1
#define ERROR 0
#define MAXSIZE 100
 
typedef struct{
    int *base;
    int front;
    int rear;
}SqQueue;
 
 
 
 //��ʼ��ѭ������
void InitQueue(SqQueue *Q){
     
    Q->base=(int *)malloc(MAXSIZE*sizeof(int));
    Q->front=0;
    Q->rear=0;
    
}
 
 
 //����г���
int QueueLength(SqQueue *Q)
{
 
    //�����벹ȫ����
    return  (Q->rear - Q->front + MAXSIZE) % MAXSIZE;

 
}
 
 
int  EnQueue(SqQueue *Q,  int e) // �����
{
    if((Q->rear+1)%MAXSIZE==Q->front)
        return ERROR;
         
    Q->base[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return OK;
 
}
 
int DeQueue(SqQueue *Q,int *e) // ������
{
    if(Q->front==Q->rear)
        return ERROR;
    *e=Q->base[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return OK;

}

int GetHead(SqQueue *Q,int *e) // ȡ��ͷԪ��ֵ
{
    if(Q->front==Q->rear)
        return ERROR;
    *e=Q->base[Q->front];
    return OK;
} 
 
int Baoshu(SqQueue *Q)
{
	while(QueueLength(Q) > 1)
	{
		int bianhao ;
		GetHead(Q, &bianhao);
			
	    int i;
	    for(i = 1;i < MAXSIZE;i ++)
	    {
	    	int e;
	
			DeQueue(Q, &e);
	
			if(i == bianhao)	
			{
				printf("%d ",e);
				break; 
//				Baoshu(Q);
//				continue; 
			}
			
			else	
			{
				EnQueue(Q, e);
			}
		}
	}
	return Q->base[Q->front];		
}
 
int main()
{
	clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    // Ҫ�����Ĵ����
	
	
    int n;
    int i;
    int j;
    SqQueue Q;
    InitQueue(&Q);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        EnQueue(&Q, i);
    j=Baoshu(&Q);
    printf("\n");
    printf("%d ",j);
    


    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("��������ʱ��: %f ��\n", cpu_time_used);
    return 0;
    
    
}
