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
	LNode*p = L; 
	int len = 0;
	while(p->next)
	{
		len ++;
		p = p->next; 
	 } 
	 return len;

}





Status ListDelete(LinkList L, int i, ElemType* e)

{

    LinkList p = L;

    int j = 0; //������



//����i�����Ϊ�գ�����j = i-1ʱ����ѭ������ʱpָ���i-1�����

    while (p->next && j < i - 1)

    {

        p = p->next;

        j++;

    }



    if (!(p->next) || j > i - 1) return ERROR;



    LinkList q = p->next; //q����ɾ������ַ

    p->next = p->next->next; //ɾ��

    *e = q->data; //e���ɾ���ڵ������

    free(q); //�ͷ�



    return OK;

}



Status ListTraverse(LinkList L)

{

    LinkList p = L->next;

    while (p) //��pΪ��ʱ����ѭ��

    {

        printf("%d ",p->data); //ÿһ�����ݶ�����visit��������������visit�����Ǵ�ӡ����

        p = p->next;

    }

    printf("\n");

    return OK;

}

Status ListInsert(LinkList L,int i,ElemType e)
{
	LinkList p = L;
	int j = 0;
	while(p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i - 1)	return ERROR;
	LNode *r ;
	r = (LNode*)malloc(sizeof(LNode));
	if(!r) return ERROR;
	r ->data = e;
	r->next = p->next;
	p->next = r;
	return OK;
}



Status ListOperate(LinkList L)

{

//��ȫ����
	if(ListEmpty(L)) 
	{
		printf("0 0");
		return OK;
	}
	int max = L->next->data,min = L->next->data;
	LNode *p = L->next;
	while(p)
	{
		if(max < p->data)	max = p->data;
		if(min > p->data)	min = p->data;
		
		p = p->next;
	}
	ListInsert(L,1,max);
	ListInsert(L,ListLength(L) + 1,min);
	return OK;
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

    ListOperate(L);

    ListTraverse(L);//��Ӧ�����д�ӡ���

    DestoryList(&L);

    return 0;

}

