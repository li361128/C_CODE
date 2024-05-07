#include <stdio.h>
#include "stdlib.h"
#include <malloc.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE -2

/*������нڵ�ṹ�����͡��Ͷ��нڵ�ṹ��ָ������*/ 
typedef struct QUEUE_NODE 
{ 
	int data;
	struct QUEUE_NODE *next; 
//    ��������
} QUEUE_NODE, *QUEUE_NODE_PTR; 

/*���нṹ�����͡��Ͷ��нṹ��ָ�����Ͷ��壬������
  ������ʵ���ȣ�
  ��ͷλ��ָ�룻
  ��βλ��ָ��*/ 
typedef struct 
{ 
    int Len; 
    QUEUE_NODE_PTR front;
    QUEUE_NODE_PTR rear;
//    ��������
} LINK_QUEUE, *LINK_QUEUE_PTR; 

/*���г�ʼ��������Ҫ������ͷ��㣬��������ͷָ�롢βָ��ͳ�����ȷ��ֵ*/ 
int InitQueue(LINK_QUEUE *q) 
{  
	q->front = (QUEUE_NODE_PTR)malloc(sizeof(QUEUE_NODE));
	if(!q->front) return ERROR;
	q->rear = q->front;
	q->rear->next = NULL;
	return OK;
//    ��������
    return 1; /*��ʼ���ɹ�����1*/ 
} 

/*.�����пպ�����Ҫ��
�����ӿڶ���Ϊ��int IsQueueEmpty(LINK_QUEUE *q)��
2.������������пն���q��
3 ������򼰷���ֵ��ͨ�����г���Ԫ���пա�
                     ����Ϊ�շ���1�����зǿշ���0.*/
int IsQueueEmpty(LINK_QUEUE *q) 
{ 
	return ((q->Len == 0)?1:0); 
//    ��������
}

/*.����к�����Ҫ��
1.�����ӿڶ���Ϊ��int EnQueue(LINK_QUEUE *q, int MRN)��
2.���������������������q�����������ֵ�������ţ�MRN��
3 ������򼰷���ֵ�����ڴ��������һ�����н���С�Ĵ洢�ռ���Ϊ�µĶ��н��newNode�����ڵ�������ֵMRN��ָ����Ϊ�ա�
    �����ж�β����ָ����ָ���½ڵ�newNode����βָ��ָ���½ڵ�newNode��
    ����гɹ�ʱ����1�������ʧ��ʱ����0.*/
int EnQueue(LINK_QUEUE *q, int MRN) 
{ 
	QUEUE_NODE_PTR p ;
	p = (QUEUE_NODE_PTR)malloc(sizeof(QUEUE_NODE));
	if(!p)	return ERROR;
	p->data = MRN;
	p->next = q->rear->next;
	q->rear->next = p;
	q->rear = q->rear->next;
	q->Len ++;
	return OK;
//    ��������
} 
 

/*.�����к�����Ҫ��
.�����ӿڶ���Ϊ��int DeQueue(LINK_QUEUE *q)��
2.�������������������q��
3 ������򼰷���ֵ��ȡ��ͷ�ڵ㣬������������ֵ��Ϊ����ֵ�����
                     ɾ����ͷ��㣬����ͷ�ڵ��nextָ��ָ���µĶ�ͷ�ڵ㣻
                     ��������ʧ��ʱ����0���ɹ�ʱ����ԭ��ͷ������������ֵ��*/
int DeQueue(LINK_QUEUE *q) 
{  
	if(IsQueueEmpty(q))	return ERROR;
    int mn;
    QUEUE_NODE_PTR p = q->front->next;
    mn = p->data;
    q->front->next = q->front->next->next;
	if(p == q->rear ) q->rear = q->front;
	q->Len --;
	free(p);	 
//    ��������
    return mn;//����ԭ��ͷ���Ĳ����� 
} 

/*.���ٶ��к�����Ҫ��
�����ӿڶ���Ϊ��int DestroyQueue(LINK_QUEUE *q)
2.��������������ٶ���q��
3 ������򼰷���ֵ���ڶ�βָ��ĸ����£���ͷ��β��һ�ͷŶ��н��ռ䡣
                     ���ٳɹ�����1�����򣬷���0.*/
int DestroyQueue(LINK_QUEUE *q) 
{ 
    /*һ�������������в����ڣ����ش���*/ 
    if(q->front == NULL) 
    { 
        return 0; 
    } 
    /*�ڶ�βָ��ĸ����£���ͷ��β��һ�ͷŶ��н��ռ�*/
    while(q->Len)
    {
    	DeQueue(q);
	}
	q->front = q->rear = NULL; 
    
//    ��������
    return 1; 
} 

/*.���б���������Ҫ��
.�����ӿڶ���Ϊ��int QTraverse(LINK_QUEUE *q)
2.������������б����Ķ���q��
3 ������򼰷���ֵ��������β�������У����δ�ӡ������ж��н����������ֵ����ֵ֮����һ���Ʊ��λ�ã�
                     �����ɹ�����1�����в����ڻ�Ϊ�շ���0*/
int QTraverse(LINK_QUEUE *q) 
{ 
    QUEUE_NODE_PTR p; 
    /*���в����ڻ�Ϊ�շ���0*/ 
    if(q->front == NULL || q->Len == 0) 
    { 
        return 0; 
    } 
    /*�Ӷ��е�һ��Ԫ�ؿ�ʼ�������У����δ�ӡ������ж��н����������ֵ��ÿ��ѭ������p����һ���ڵ�*/ 
    for(p=q->front->next; p!=NULL; p= p->next) 
    { 
        printf("%d\t", p->data); 
    } 
    return 1; 
} 

/**************************************************************************/ 
/*                                                                        */ 
/**************************************************************************/ 

int main() 
{ 
    LINK_QUEUE QPatient ={0};//���岡�˶��� 
    int flag = 1; /*���°��־λ�� 1Ϊ�ϰ࣬0Ϊ�°�*/ 
    int Medical_Record_NO = 0; 
    char ch = 0; 
    char a[100];
    int length;
    int index;
    //��ʼ�����˶��� 
    InitQueue(&QPatient); 
    //���봦������ 
    gets(a); 
    length = strlen(a); 
    index = 0; 
    /*�ϰ�ʱ�����δ��������������*/ 
    while( (flag==1) && (index<length) ) 
    { 
        ch = a[index] &0xff; /*�ӿ���̨��������*/ 
        index++; 
        switch (ch) 
        { 
            case 'a': 
                /*��������������β*/ 
                Medical_Record_NO=Medical_Record_NO+1;  /*��¼��������*/
                EnQueue(&QPatient, Medical_Record_NO); 
                printf("\nYour patient's No. is:%d.\t", Medical_Record_NO); 
                printf("There are %d patient(s) waiting ahead of you.", QPatient.Len); 
                break; 
            case 'n': 
                /*��ͷ���˳��ӿ���*/ 
                if(!IsQueueEmpty(&QPatient)) 
                { 
                    Medical_Record_NO = DeQueue(&QPatient); 
                    printf("\nPatient No. %d, please go to the clinic", Medical_Record_NO); 
                } 
                else 
                { 
                    printf("\n No patient is waiting in line.\n"); 
                } 
                break; 
            case 'q': 
                /*�°ࣺ��������л��в��������γ��ӣ������ӡhello*/ 
                if(!IsQueueEmpty(&QPatient)) 
                { 
                    printf("\nIt is the end of today. Following patients please go to the clinic in turn: "); 
                    QTraverse(&QPatient); 
                    printf("\n"); 
                } 
                else 
                {                    
                    printf("hello\n"); 
                } 
                flag = 0;//���°��־ 
                //���ٶ��� 
                DestroyQueue(&QPatient); 
                break; 
            default: 
                printf("ERROR\n"); 
                break; 
        }// end of switch(ch) 
    }//end of while() 
    return 0; 
} 

