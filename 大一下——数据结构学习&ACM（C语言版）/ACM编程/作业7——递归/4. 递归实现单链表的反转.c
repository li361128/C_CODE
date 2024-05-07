#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define ERROR 0
#define OK 1

typedef struct L_Node
{
	int data;
	struct L_Node *next;
}LNode,*LinkList;

void InitList_L(LinkList* L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if(!(*L))	return ;
	(*L)->next = NULL;
}

void CreateList_L(LinkList L)
{
	int input;
	if(scanf("%d",&input) == EOF)	
	{
		L->next = NULL;
		return ;
	}	
	L->next = (LinkList)malloc(sizeof(LNode));
	if(!L->next)	return ;
	L->next->data = input;
	
	CreateList_L(L->next);
}

void reverse_List(LinkList L)
{
    if (L == NULL || L->next == NULL || L->next->next == NULL) {
        return;
    }

    // �ݹ鷴ת��ͷ���֮��Ĳ���
    reverse_List(L->next);

    // �ҵ���ת���β�ڵ�
    LNode *tail = L->next;
    while (tail->next != NULL) 
	{
        tail = tail->next;
    }

    // ��ͷ����Ľڵ㣨��ת���β�ڵ㣩�Ƶ�ͷ���֮ǰ
    tail->next = L->next;
    L->next = L->next->next;
    tail->next->next = NULL;
}


void LinkListPrint(LinkList L)
{
	if(!L->next)	return ;
	printf("%d ",L->next->data);
	LinkListPrint(L->next);
}


int main()

{

    int n;
	
	scanf("%d",&n);
	
	LinkList La;
	
	InitList_L(&La);
	
	CreateList_L(La);
	
	reverse_List(La);
	
	LinkListPrint(La);

    return 0;

}


