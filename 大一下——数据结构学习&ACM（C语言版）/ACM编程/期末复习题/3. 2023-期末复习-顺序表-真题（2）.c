#include <stdio.h>
#include <stdlib.h>
#define List_init_size 1000
typedef int Element;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct
{
    Element *elem; 
    int length;
    int listsize;
}Sqlist;

//��ʼ����ʼ��˳���
int Initlist(Sqlist *L)
{
    L->elem=(Element *)malloc(List_init_size*sizeof(Element));
    if(!L->elem) return ERROR;
    L->length=0;
	L->listsize=List_init_size;
    return OK;
}


//��������Ϊm��˳���
void Createlist(Sqlist *L, int n)//���뺯��
{
    int i;
    for(i=0; i<n; i++)
    {
        scanf("%d",&L->elem[i]);
    }
    L->length=n;
}

//��Ԫ��e���뵽��k��Ԫ��֮ǰ
Status Listinsert(Sqlist *L, int k, int e)
{
    if(k<1||k>L->length+1) return ERROR; //�жϲ���λ�õĺϷ���
    int j;
    int pos=k;

    for(j=L->length-1;j>=pos-1;j--)
    {//�����һ��λ�ÿ�ʼ��λ������Ҫ�����λ�ÿճ�
        L->elem[j+1]=L->elem[j];
    }
    L->elem[pos-1]=e;
    L->length++;//ÿ����һ��Ԫ�أ�˳����ȼ�һ������
    return OK;
}


//��ӡ˳����Ԫ��
void Display(Sqlist *L)
{
//�����벹ȫ����
	int  i;
	for(i = 0; i < L->length ;i ++)
	{
		printf("%d ", L->elem[i]);
	}

}

//�ж���˳������Ƿ����ĳԪ�أ����ڷ���ֵTRUE�������ڷ���ֵFALSE��
Status isPresent(Sqlist L, int e)
{

//�����벹ȫ����
	int i;
	for(i = 0; i < L.length; i ++)
	{
		if(L.elem[i] == e)	return 1;
	 } 
	 return 0;

}

//ȡ˳���ĵ�i��Ԫ��
Status GetElem(Sqlist L,int i,Element *e)
{
  if(i<1 || i>=L.length)
      return ERROR;
    *e=L.elem[i-1];
    return OK;
}


//��L1��L2�Ľ��������������L3
void InterSection(Sqlist *L1, Sqlist *L2, Sqlist *L3)
{
//�����벹ȫ����
	int len1 = 0;
	int len2 = 0;
	int len3 = 0;
	for(; len1 < L1->length && len2 < L2->length ; )
	{
		if(L1->elem[len1] == L2->elem[len2])
		{
			Listinsert(L3, ++len3, L1->elem[len1]);
			len1 ++; len2++;
		}
		else if(L1->elem[len1] > L2->elem[len2])	len2 ++;
		else if(L1->elem[len1] < L2->elem[len2])	len1 ++;
	}
//	L3->length = len3;
}


int main()
{
    int m,n;
    Sqlist A,B,C;
    printf("�����������A�ͱ�B�е�Ԫ�ظ���\n");
    scanf("%d %d",&m,&n);
    Initlist(&A);
    Initlist(&B);
    Initlist(&C);
    printf("�����������A�е�Ԫ��\n");
    Createlist(&A,m);
    printf("�����������B�е�Ԫ��\n");
    Createlist(&B,n);
    InterSection(&A,&B,&C);
    printf("��A�ͱ�B�Ľ���Ϊ\n");
    Display(&C);
    return 0;

}
