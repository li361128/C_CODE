#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int Status;

typedef struct DuLNode
{
    ElemType data;          // ������
    struct DuLNode* prior;  // ָ��ֱ��ǰ��
    struct DuLNode* next;   // ָ��ֱ�Ӻ��
} DuLNode, * DuLinkList;

Status GetElem_DuL(DuLinkList L, int i, ElemType* e)
{
    int j;
    DuLinkList p;
    p = L->next; // pָ���һ�����
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR; // ��i��Ԫ�ز�����
    *e = p->data;     // ȡ��i��Ԫ�ص�����
    return OK;
}

Status ListInsert_DuL(DuLinkList* L, int i, ElemType e)
{
    DuLinkList p, s;
    if (i < 1) // ���λ�ò��Ϸ�
        return ERROR;
    
    s = (DuLinkList)malloc(sizeof(DuLNode));
    if (!s)
        exit(EXIT_FAILURE); // �ڴ����ʧ�ܣ��˳�����
    s->data = e;
    
    if (i == 1 || !(*L)->next) { // �ڵ�һ��λ�ò����������Ϊ��ʱ
        s->next = (*L)->next;
        if ((*L)->next) // �������Ϊ��
            (*L)->next->prior = s;
        s->prior = *L;
        (*L)->next = s;
        return OK;
    }
    
    p = (*L)->next;
    while (--i && p) p = p->next; // �ҵ��� i-1 ���ڵ�
    if (!p) // ���λ�ó���������
        return ERROR;
    
    s->next = p->next;
    s->next->prior = s;
    s->prior = p;
    p->next = s;
    return OK;
}


Status ListDelete_DuL(DuLinkList* L, int i)
{
    DuLinkList p, q;
    int j = 1;
    p = *L; // �� p ָ��ͷ�ڵ�
    while (p->next && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p->next || j > i)
        return ERROR; // ��i��Ԫ�ز�����
    q = p->next;
    p->next = q->next;
    if (q->next) // ��� q ����һ���ڵ㲻Ϊ��
        q->next->prior = p;
    free(q);
    return OK;
}



int main()
{
    DuLinkList L;
    L = (DuLinkList)malloc(sizeof(DuLNode));
    if (!L)
        exit(EXIT_FAILURE); // �ڴ����ʧ�ܣ��˳�����
    L->next = NULL;
    ElemType e;
    if (ListInsert_DuL(&L, 1, 10) == OK)
        printf("Insert successful!\n");
    if (GetElem_DuL(L, 1, &e) == OK)
        printf("The first element is: %d\n", e);
    if (ListDelete_DuL(&L, 1) == OK)
        printf("Delete successful!\n");
    system("pause");
    return 0;
}










//
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node,*pNode;
//
//pNode Creat_linkList()
//{
//	Node* L;
//	L = (Node*)malloc(sizeof(Node));
//	L->next = NULL;
//	return L;
//}
//
//void Gen_linkList(pNode L)
//{
//	Node* r;
//	r = L;
//	int i = 0; 
//	for (i = 0; i < 6; i++)
//	{
//		Node* p;
//		p = (Node*)malloc(sizeof(Node));
//		p->data = i;
//		p->next = NULL;
//		r->next = p;
//		r = p;
//	}
//}
//
//void Print_linklist(pNode L)
//{
//	Node* p;
//	for (p = L->next; p != NULL; p = p->next)
//	{
//		printf("%d ", p->data);
//	}
//}
//
//int main()
//{
//	Node *L;
//	L = Creat_linkList();
//	Gen_linkList(L);
//	Print_linklist(L);
//	return 0;
//}	



