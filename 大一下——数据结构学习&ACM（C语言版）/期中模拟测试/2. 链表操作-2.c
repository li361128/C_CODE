#include <stdio.h>

#include <stdlib.h>

#define OK 1

#define ERROR 0

#define MAXSIZE 100 //˳�����ܴﵽ����󳤶�

typedef int Status; //Status�Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬����

typedef int ElemType; //ElemTypeΪ�ɶ�����������ͣ��˴���Ϊint����

typedef struct

{

ElemType *elem; //�洢�ռ�Ļ���ַ

int length; //���Ա�ǰ����

}SqList;

//˳���ĳ�ʼ��������һ���յ�˳���L��

Status InitList_Sq(SqList *L)

{

L->elem=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE); //Ϊ˳������һ����СΪMAXSIZE������ռ�

if(!L->elem)

return ERROR; //�洢����ʧ��

L->length=0; //�ձ�����Ϊ0

return OK;

}

//��������Ϊn��˳���

Status CreateList_Sq(SqList *L, int n)

{

if(n<=0||n>MAXSIZE)

return ERROR;

int i;

for(i=0;i<n;i++)

{

scanf("%d", &L->elem[i]);

}

L->length=n;

return OK;

}

//ɾ�����Ա�L��������[a,b]��Χ�ڵ�����Ԫ�أ�����a,b��Ϊ��������a<b

//Ҫ���㷨ʱ�临�Ӷ�ΪO(n)�ҿռ临�Ӷ�ΪO(1)

Status DeleteItem(SqList *L,int a,int b)

{

//�벹ȫ����
	
	SqList s = *L;
	int i;
	for(i = 0;i < s.length - b;i ++)
	{
		s.elem[a + i - 1] = s.elem[b + i ];
	}
	//s.elem[s.length - b + a - 1] = '\0';
	L->length = L->length - b + a - 1;
	return OK;

}

//���˳���L�е�ȫ��Ԫ��

void PrintList_Sq(SqList L)

{

int i;

for(i=0;i<L.length;i++)

{

printf("%d ", L.elem[i]);

}

printf("\n");

}

int main()

{

//�벹ȫ����
	int n;
	scanf("%d",&n);
	if(n > MAXSIZE || n <= 0)	
	{
		printf("SqList length error.");
		return 0;
	}
	
	SqList S;
	InitList_Sq(&S);
	CreateList_Sq(&S,n);
	
	int a,b;
	scanf("%d %d",&a,&b);
	if(a >= b)
	{
			printf("SqList delete range error.");
			return 0;
	}
	DeleteItem(&S,a,b);
	PrintList_Sq(S);
		

}
