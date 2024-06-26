
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status;

typedef struct Lnode
{
    int data;
    struct Lnode *next;
} LNode;
typedef struct Lnode *LinkList;

Status InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if (!(*L))
        return 0;
    (*L)->next = NULL;
    return 1;
}


/*
�����������޵к���ʦ������
���˺þã��������ݶ����ˣ����� 
��С���ܲ�������㣬�����������Ӱɣ�����
С��ʵ��ʵ���ǿ۲����ˣ�������ô�û����۵ģ����� 
��֪����һ����ȫ������õ���ʦ������ 
*/


/* ����������e������뵽һ���������������L�� */
Status SortInsert(LinkList *L, int e)
{
    //�����벹ȫ����
    LinkList r ;//�����µ������� 
    r = (LinkList)malloc(sizeof(LNode));
    if(!r)
    {
    	return ERROR;
	}
	r->data = e;
	
	LinkList p = (*L);
	if(p->next)
	{//Ѱ�ҵ��½��r��Ҫ�ӵ�������ĸ�λ��
	//��Ȼ��������Ϊ�գ�������Ƚ� 
		while(p->next && p->next->data < e)
		{
			p = p->next;
		}
	}
	
	r->next = p->next;
	p->next = r;
	
	return OK;   
}

Status Display(LinkList L)
{
    LNode *p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    LinkList L;
    int elem;
    InitList(&L);
    scanf("%d", &elem);
    while(elem != -1)
    {
        SortInsert(&L, elem);
        scanf("%d", &elem);
    }
    Display(L);
    return 0;
}
