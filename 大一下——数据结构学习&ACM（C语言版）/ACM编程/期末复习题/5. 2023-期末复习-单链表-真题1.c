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

/***************�����ʼ��**********************/
int Initlist(LinkList *L)
{
    (*L)=(LinkList)malloc(sizeof(LNode));
    if(L==NULL)
    {
  		printf("�ڴ洴��ʧ��\n");
   		return ERROR;
    }
    (*L)->next=NULL;
    //���ݼ���ֵ��������
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
			printf("��ʼ��ʧ��");
		    return ERROR;
		}
		p->data=x;
		p->next= NULL;
		r->next=p;
		r=p;
	}
	return OK;
}
/******************��ӡ������*****************/
void ListPrint(LinkList L)
{
//�����벹ȫ����
	LinkList p = L->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");

}
/****************������ĳ���******************/
int ListLength(LinkList L)
{
//�����벹ȫ����
	int total = 0;
	LinkList p = L->next;
	while(p)
	{
		total ++;
		p = p->next;
	}
	return total;

}

/*********Ԫ�ؽ���*********************/
int Exchange(LinkList *L)
{
//�����벹ȫ����
	int ex = (ListLength(*L) + 1) / 2;
	int i = 1;
	LinkList p = (*L)->next;
	LinkList r = (*L)->next;
	LinkList p_pre = *L;
	while(p && i < ex)
	{
		p_pre = p;
		p = p->next;
		i ++;
	}
	LinkList temp = (*L)->next->next;
	r->next = p->next;
	p_pre->next = r;
	
	p->next = temp;
	(*L)->next = p;
	return 1;

}

/************������******************/
int main()
{
	int length;
	LinkList L;
	Initlist(&L);
	ListPrint(L);
	length=ListLength(L);
	printf("%d\n",length);
	Exchange(&L);
	ListPrint(L);
	return 0;
}
