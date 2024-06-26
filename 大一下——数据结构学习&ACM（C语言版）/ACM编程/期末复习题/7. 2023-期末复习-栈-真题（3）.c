#include "stdio.h"
#include "stdlib.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE  100  //��ջ���������
typedef int Status;
typedef int ElemType;

//˳��ջ�Ľṹ����
typedef struct
{
    ElemType data[MAXSIZE]; //��Ŷ�ջԪ�ص�����
    int top;                //topָ��ջ��Ԫ�أ�top=-1����ʾ��ջ
}SqStack;

//��ʼ��һ����ջ
void InitStack(SqStack *S)
{
    S->top=-1;
}
Status Push(SqStack *S, ElemType e)
{
    if(S->top == MAXSIZE -1)
    {
        return ERROR;
    }
    S->top++;
    S->data[S->top]=e;
    return OK;
}

Status Pop(SqStack *S, ElemType *e)
{
//�����벹ȫ����
	if(S->top == -1)	return ERROR;
	*e = S->data[S->top--];
	return OK;

}

//����ǿ�ջ������1�����򷵻�0
Status StackEmpty(SqStack S)
{
//�����벹ȫ����
	return S.top == -1 ? 1 : 0;
	

}


int main()
{
    SqStack Stack;
    ElemType temp;
    InitStack(&Stack);
	printf("������һ��Ҫ��ջ��Ԫ��(-1��ʾ����):\n");
	scanf("%d",&temp);
	while(temp!=-1)
	{
		Push(&Stack,temp);
		scanf("%d",&temp);
	}

	printf("��ջ��Ԫ�����ν��г�ջ����:\n");

    while (!StackEmpty(Stack))
    {
        if (OK==Pop(&Stack, &temp))
        {
            printf("%d ",temp);
        }
    }
    return 0; 
}
