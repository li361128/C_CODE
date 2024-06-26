#include <stdio.h>
#include <stdlib.h>

//�������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE 0
//�½��������ͣ���ʾ�������н��
typedef int Status;

/*��̬������Ľṹ�嶨��*/ 
//����ṹ��
typedef int ElemType;
typedef struct LNode
{
    ElemType data; //������
    struct LNode* next; //ָ����
}LNode, *LinkList;

Status InitList(LinkList *L)
{
    int x,i;
    *L = (LinkList)malloc(sizeof(LNode));
    if(*L == NULL)
    {
        printf("memory malloc failure\n");
        return ERROR;
    }
    (*L)->next = NULL;
        //���ݼ���ֵ��������
    LinkList r;
    r = *L;
    for(i=0; ;i++)
    {
        scanf("%d",&x);
        if(x == -1)
            break;
        LinkList p = (LinkList)malloc(sizeof(LNode));
        if(!p) 
        {
            printf("initial failure\n");
            return ERROR;
        }
        p->data = x;
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return OK;

}

Status DestoryList(LinkList *L)
{
    LinkList p;
    while(*L) //��LΪ��ʱѭ������
    {
        p = (*L)->next; //pָ����һ�����
        free(*L); //�ͷ�L
        *L = p;
    }
    return OK;
}

Status ListEmpty(LinkList L)
{
    return (L->next == NULL);
}

Status ClearList(LinkList L) 
{
    LinkList p, q;
    p = L->next; //pָ�������һ�����
    while (p) //��pָ���ʱѭ������
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL; //ͷ���ָ����Ϊ��
    return OK;
}

int ListLength(LinkList L)
{
   //��ȫ����
    int total = 0;
	LinkList p = L->next;
    while(p)
    {
    	total ++;
    	p = p->next;
	}
	return total;


}


Status ListTraverse(LinkList L)
{
    LinkList p = L->next;
    while (p) //��pΪ��ʱ����ѭ��
    {
        printf("%d ",p->data); 
        p = p->next;
    }
    printf("\n");
    return OK;
}

Status ListOperate(LinkList *L)
{

 //��ȫ����
 	LinkList p = (*L);
	if(ListEmpty(*L))
	{
		LinkList r;
		r = (LinkList)malloc(sizeof(LNode));
		if(!r)	return ERROR;
		r->data = 0;
		LinkList s;
		s = (LinkList)malloc(sizeof(LNode));
		if(!s)	return ERROR;
		s->data = 0;
		p->next = r;
		r->next = s;
		s->next = NULL;
		return 0;
	}
	int max = p->next->data, min = p->next->data;
	while(p->next)
	{
		if(p->next->data > max)
		{
			max = p->next->data;
		}
		else if(p->next->data < min)
		{
			min = p->next->data;
		}
		p = p->next;
	 }
 	LinkList r;
	r = (LinkList)malloc(sizeof(LNode));
	if(!r)	return ERROR;
	r->data = min;
	r->next = p->next;
	p->next = r;
	
	LinkList s;
	s = (LinkList)malloc(sizeof(LNode));
	if(!s)	return ERROR;
	s->data = max;
	s->next = (*L)->next;
	(*L)->next = s;

	return 1; 
	 

}

int main()
{
    //��ʼ������
    LinkList L;
    if (InitList(&L) == ERROR)
    {
        return 0;
    }
    ListTraverse(L);//��Ӧ��һ�д�ӡ���
    int len = ListLength(L);
    printf("%d\n",len);//��Ӧ�ڶ��д�ӡ���
    ListOperate(&L);
    ListTraverse(L);//��Ӧ�����д�ӡ���
    DestoryList(&L);
    return 0;
}
