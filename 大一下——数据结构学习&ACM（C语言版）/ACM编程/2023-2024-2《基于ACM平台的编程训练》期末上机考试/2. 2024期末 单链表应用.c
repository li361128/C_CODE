#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

typedef struct LNode {
    ElemType data; //����������
    struct LNode *next; //����ָ����
} LNode, *LinkList;


/*
�����������޵к���ʦ������
���˺þã��������ݶ����ˣ����� 
��С���ܲ�������㣬�����������Ӱɣ�����
С��ʵ��ʵ���ǿ۲����ˣ�������ô�û����۵ģ����� 
��֪����һ����ȫ������õ���ʦ������ 
*/


//ǰ�巨��������������λ������n��Ԫ�ص�ֵ��������ͷ���ĵ�����L
Status CreateList_F(LinkList *L, int n) 
{ 
//�벹ȫ����
    if(n<=0) 
    {
        return ERROR;
	}
        
    (*L) = (LinkList)malloc(sizeof(LNode));//��ʼ��ͷ��㣬Ϊͷ�������ڴ� 
    if(!(*L))	
		return ERROR;
	(*L)->next = NULL;
	
    LinkList p = (*L);
    int i;
    for(i = 0;i < n;i ++)
    {
    	//�����µ������� 
    	LinkList r = (LinkList)malloc(sizeof(LNode));
		if(!r)	return ERROR;
    	scanf("%d",&r->data);
    	
    	//���´����Ľ����ͷ��ķ�ʽ��*L���� 
    	r->next = p->next;
    	p->next = r;
	}
    
    return OK;
}

//��ӡ������
Status ListPrint(LinkList L)
{
//�벹ȫ����
	if(!L)
		return ERROR; 
	LinkList p = L->next;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

//ʹ�õݹ��㷨������L����Ԫ��֮��
int ListSum(LinkList L)
{
//�벹ȫ����
	if(!L || !L->next)
		return 0;
		
	return ListSum(L->next) + L->next->data;

}
 
int main()
{
//�벹ȫ����
	int n;
	scanf("%d",&n);
	
	LinkList L;
	if(CreateList_F(&L, n) == OK)
	{
		printf("The linked list is: ");
		ListPrint(L);
	}
	else
	{
		printf("This is an empty List.\n");
	}
	
	
	printf("The sum of the linked list is: %d",ListSum(L));
	
	return 0;

}
