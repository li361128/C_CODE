#define MAXINTSIZE 512 /* ����������� */

#include<stdio.h>

#include<stdlib.h>



#define ERROR 0

#define OK 1

typedef int Status;



typedef struct Node

{

    int data;

    struct Node *next;

} LNode;

typedef LNode *LinkList;



/* ��ͷ�巨���������� */

Status CreateList(LinkList *L, char *chars)

{

     //�����벹ȫ����
    LinkList p = (*L);
	int i = 0;
	for(;chars[i] != '\0';i ++)
	{
		LNode *r;
		r = (LinkList)malloc(sizeof(LNode));
		if(!r)	return ERROR;
		r->data = chars[i] - '0';
		r->next = p->next;
		p->next = r;
		p = r;
	}
	return OK;



}



int ListLength_L(LinkList L){

    LinkList p;

    int i=0;             

    p=L->next;        //pָ���һ�����

    while(p){         //����������,ͳ�ƽ����

        i++;

        p=p->next;

    } 

    return i;                             

}// ListLength_L



Status  InversePrint(LinkList p){

   //�����ӡ����ͷ���ĵ������Ԫ��    

   if(!p) return OK;
   
    printf("%d",p->data);

   InversePrint(p->next);

  // printf("%d",p->data);

   return OK;

}// 



int main()

{

    int len;

    char str[MAXINTSIZE+1];

    LinkList L;

    scanf("%s", str);
    
    L = (LinkList)malloc(sizeof(LNode));

    CreateList(&L, str);

    len=ListLength_L(L);

    printf("the length of the integer is %d\n", len);

    InversePrint(L->next);

    printf("\n");

    return 0;

}


