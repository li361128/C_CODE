#include <stdio.h>

#include <stdlib.h>

#define OK 1

#define ERROR 0



typedef struct

{

	int *elem;

	int length;

	int listsize;

} sqlist;



//��ʼ��һ���յ�˳���

int initlist(sqlist *l)

{

	l->elem = (int *)malloc(100 * sizeof(int));

	if (!l->elem)

		return ERROR;

	l->length = 0;

	l->listsize = 100;

	return OK;

}



//���ݳ���Ϊn������x������˳���L   

//����ɹ�����OK�����򷵻�ERROR

int insertlist(sqlist *l, int a[], int n)

{
	int i; 
	for (i = 0; i < n; i++)

	{

		l->elem[i] = a[i];

	}

	l->length = n;

	return OK;

}



//��˳���a�д���t��Ԫ�ش���˳���b��

void getb(sqlist *b, sqlist a, int t)

{

	//�����벹ȫ����
	int i = 0,j = 0;
	for(;i < a.length;i ++)
	{
		if(a.elem[i] > t)	
		{
			b->elem[j + b->length] = a.elem[i];	
			j ++;
		}
	} 
	b->length += j;







}



// ��b�е�Ԫ�����ã�����ӡ������ú�b������Ԫ��

void  reverselist(sqlist *b)

{

	//�����벹ȫ����
	int i = 0;
	for(;i * 2 < b->length;i ++)
	{
		int temp = b->elem[i];
		b->elem[i] = b->elem[b->length - i - 1];
		b->elem[b->length - i - 1] = temp;
		
	}

}



int main()

{

	sqlist a,b;

	initlist(&a);

	initlist(&b);

	int x[100];

	int n,i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)

	{

		scanf("%d", &x[i]);

	}

	insertlist(&a, x, n);

	int t;

	scanf("%d", &t);

	getb(&b, a, t);

	reverselist(&b);
	
	for(i = 0;i < b.length;i ++)
	{
		printf("%d ",b.elem[i]);
	}

	return 0;

}


