//��һ�ʴ�����覴ã� ��1��
//�ڶ����߼���ȸ��ӣ� ��1��
//������Ч�ʵͣ� ��1��
#include <stdio.h>

#include "stdio.h"

#include "malloc.h"

#include "stdlib.h"

 

#define ERROR -1

#define OK 1

 

typedef struct Lnode

{

       int data;

      struct Lnode *next;

}LNode,*LinkList;

 

int Initlist(LinkList *L)

{

     (*L)=(LinkList)malloc(sizeof(LNode));

     if(L==NULL)

     {

                printf("Memory failure \n");

              return ERROR;

     }

     (*L)->next=NULL;

 

       LinkList r;

       r=*L;

       int x;

       int i;

       for(i=0; ; i++)

       {

              scanf("%d",&x);

              if(x==-1)

              break;

              LNode *p=(LinkList)malloc(sizeof(LNode));

              if(!p)

              {

                     printf("Initialization failure ");

                  return ERROR;

              }

              p->data=x;

              p->next= NULL;

              r->next=p;

              r=p;

       }

      return OK;

}

 

void ListPrint(LinkList L)

{

       LNode *p;

       for(p=L->next;p!=NULL;p=p->next){

              printf("%d ",p->data);

       }

      

}


int ListLength(LinkList L)

{

       //�����벹ȫ����
       LNode *p = L->next;
       int count = 0;	//count ��������
	   while(p)
	   {
	   		count ++;
	   		p = p->next;
		} 
		return count;

}



void MoveMin(LinkList *L)

{

//�����벹ȫ����
	//�ڱ�������Ѱ����Сֵʱ��ά������Сֵ���ڽ�㼰��ǰ�� 
	// ��˱㲻��Ҫ��¼��Сֵdata�� ����Ҫ�����ٱ���һ�� 
	LNode *min_p = (*L)->next;
	LNode *min_pre = (*L);//��¼��Сֵ���ڽڵ��ǰ����㣬�Ա�ɾ������
	LNode *pre = (*L);
	LNode *p = (*L)->next;
	while(p)
	{
		if(p->data < min_p->data)
		{
			min_pre = pre;//�ҵ��������Сֵ
			min_p = p;
		}
		pre = p;
		p = p->next;
	}
	
	if(min_p != (*L)->next)
	{
		min_pre->next = min_p->next;
		min_p->next = (*L)->next;
		(*L)->next = min_p; 
	}
	
	
//	int i = 0;
//	for(;i < ListLength(*L);i ++)
//	{
//        if(min_p->data == min)
//		{//������Сֵ���ڽڵ㣬�������ƶ�
//			min_pre->next = min_p->next;//ȥ��ԭ��������Сֵ���ڽڵ�
//			min_p->next =  r->next;//����Сֵ�����뵽��Ԫ���
//			r->next = min_p;
//			return ;
//		}
//        min_pre = min_pre->next;
//		min_p = min_p->next;
//	}

}

int SumToNewlist(LinkList *L)

{

//�����벹ȫ����
	int sum = 0;
	LNode *p = (*L)->next;
    LNode *tail = NULL;
	while(p)
	{
		sum += p->data;//���
        if (p->next == NULL) {
            tail = p; // Keep track of the last node
        }
		p = p->next;
	}
    //����sum�ڵ�
	LNode *r ;
	r = (LNode*)malloc(sizeof(LNode));
	r->data = sum;
	r->next = NULL;
    
    //�嵽β�ڵ�
//	LNode *q = (*L);
//	while(q->next)
//	{
//		q = q->next;
//	}
	tail->next = r;
    
	return 1;
}

 

int main()

{

       int length;

       LinkList L;

       Initlist(&L);

        printf("The original linked list is��");

       ListPrint(L);

       printf("\nThe length of list is��");

       length=ListLength(L);

       printf("%d ",length);

       MoveMin(&L);

       printf("\nAfter moving the minimum, the linked list is: ");

       ListPrint(L);

       printf("\nAfter inserting the sum, the new list is: ");

       SumToNewlist(&L);

       ListPrint(L);

       return 0;

}
