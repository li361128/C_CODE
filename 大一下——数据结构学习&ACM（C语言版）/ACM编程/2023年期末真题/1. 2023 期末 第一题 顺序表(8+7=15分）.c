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
    if(a >= b)	
	{
		printf("SqList delete range error.");
		return ERROR;
	} 
	int i = 0, k = 0;

	for(i = 0;i < L->length;i ++)
	{
		if(L->elem[i] >b || L->elem[i] < a)
		{
			L->elem[k ++] = L->elem[i];
		}
	}
	L->length = k;
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
	if(n <= 0 || n > MAXSIZE)
	{
		printf("SqList length error.");
		return ERROR;
	}
	SqList L;
	InitList_Sq(&L);
	CreateList_Sq(&L, n);
	
	int a, b;
	scanf("%d %d",&a, &b);
	if(DeleteItem(&L, a, b) == OK)
		PrintList_Sq(L);
	
	return 0;
}
