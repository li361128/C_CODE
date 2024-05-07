#include <malloc.h>

#include <stdio.h>

#include <stdlib.h>

 

#define TRUE  1

#define FALSE  0

#define OK 1

#define ERROR 0

#define OVERFLOW -2

typedef int Status;

 

#define INIT_SIZE 100

  /*��ʼ����ռ�Ĵ�С*/

#define LISTINCREMENT 10  

/*��������*/

 

typedef int ElemType;

 

typedef struct{

 

int *elem;
int length;
int listsize; 

 

}SqList;

/*�洢�ռ����ʼ��ַ��*/

/*���Ա�������Ԫ�ظ���������*/

/*���Ա�������Ĵ洢�ռ�Ĵ�С*/

 

SqList CreateList_Sq(SqList L)

/*����һ���յ����Ա�*/

{

    L.elem = (int*)malloc(100*sizeof(int));  /*malloc ����ռ�*/

    L.length = 0;                   /*��Ϊ0*/

    L.listsize = 100;                  /*����Ŀռ�Ϊ��ʼ��С*/

    return   L;

}

 

 

void InsertList_Sq(SqList *L, int i, ElemType e)

/*�����Ա�ĵ�i��λ��ǰ����Ԫ��e*/

{  int * newbase,*q,*p;

    if ((i<1)||(i>L->length+1)) {printf("iֵ���Ϸ�!\n");exit(ERROR);}

    if (L->length>=L->listsize)  /*��ǰ�ռ����������ӷ���ռ�*/

    {

        newbase=(ElemType*)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));

        if (!newbase) exit(ERROR);

        L->elem=newbase;

        L->listsize= L->listsize+LISTINCREMENT;

    }
	int j;
 	for(j = L->length ;j > i - 1;j --)
 	{
 		L->elem[j] = L->elem[j - 1];
	 }
	 L->elem[i - 1] = e;
	L->length ++;
}

 

void DeleteList_Sq(SqList *L, int i)

/* ɾ�����Ա��еĵ�i��Ԫ��*/

{         

       int *q,*p;

    if ((i<1)||(i>L->length)) {printf("iֵ���Ϸ�!\n");exit(ERROR);}
	
	int j;
	for(j = i - 1;j < L->length - 1;j ++ )
	{
		L->elem[j] = L->elem[j + 1];
	}
	L->length --;

 

}

 

 

void Print_Sq(SqList L)

/*����˳�����Ա����*/

{   int i;

    for(i=0;i<L.length;i++)

    {

       printf("%3d ",L.elem[i]);

    }

}

 

 

int equal(ElemType e1,ElemType e2)

/*������Ԫ���Ƿ����*/

{

    if (e1==e2) return 1;

    else return 0;

}

 
int LocateElem_Sq(SqList L,ElemType e, int (* compare)(ElemType e1,ElemType e2))

{   int i;

    i=1;
	for(;i  < L.length;i ++)
	{
		if(L.elem[i] == e) return i + 1;
	}
 	return ERROR;

}


void Getelem(SqList L,int i,ElemType *e)

{

   if(i < 1||i > L.length) return ;
   *e = L.elem[i - 1];
   return ;

}

 

 

int main()

/*������*/

{  int i;

   SqList Lq;

   Lq=CreateList_Sq(Lq);

   InsertList_Sq(&Lq,1,21);

   InsertList_Sq(&Lq,2,18);

   InsertList_Sq(&Lq,3,30);

   InsertList_Sq(&Lq,4,75);

   InsertList_Sq(&Lq,5,42);

   InsertList_Sq(&Lq,6,56);

   printf("��ʼ˳���Ϊ\n");

   Print_Sq(Lq) ;

   InsertList_Sq(&Lq,3,67);

   printf("\n����67��˳���Ϊ\n");

   Print_Sq(Lq) ;

   DeleteList_Sq(&Lq, 6);

   printf("\nɾ����6��Ԫ�غ�˳���Ϊ\n");

   Print_Sq(Lq);

   if ((i=LocateElem_Sq(Lq,75,equal)))

 

       printf("\n����Ԫ��75��λ��Ϊ%d\n",i);

   else

 

        printf("\n������Ԫ��75\n");

free(Lq.elem);

return 1;

}
