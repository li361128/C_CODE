#define BASE 17

#include <stdio.h>
#include <stdlib.h>

#define Status int
#define SElemType char

#define STACK_INIT_SIZE 100        //�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT  10          //�洢�ռ�ķ�������
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

//ջ���ݽṹ
typedef struct Stack 
{
    SElemType *base;    //ջ��ָ��
    SElemType *top;     //ջ��ָ��
    int stacksize;      //ջ���õ��������
} SqStack;

//��ʼ������
Status InitStack(SqStack *S) 
{
    S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base) 
    {
        printf("init fail\n");
        return ERROR;
    }
    S->top = S->base;     //ջ��ָ����ջ����ͬ
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

//���� 
Status DestroyStack(SqStack *S) 
{
    //��ȫ����
	free(S->base);
	S->base = NULL;
	S->top = NULL;  
	S->stacksize = 0;
	if(S->base)	
	{
		printf("Fail Destroy");
		return ERROR;
	}
	return OK;
}

//��� 
Status ClearStack(SqStack *S) 
{
    S->top = S->base;
    return OK;
}

//�ж��Ƿ�Ϊ�� 
Status StackEmpty(SqStack S) 
{
    if (S.top == S.base) 
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack S) 
{
    return S.top - S.base;
}

//�õ�ջ��Ԫ�أ����޸�ָ��
Status GetTop(SqStack S, SElemType *e) 
{ 
    if (S.top == S.base) 
        return ERROR;
    *e = *(S.top - 1);
    return OK;
}

//��ջ
Status Push(SqStack *S, SElemType e) 
{
    if (S->top - S->base >= S->stacksize) 
    {  //ջ��,׷�Ӵ洢�ռ�
        S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S->base) 
            return ERROR;
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top++ = e;
    return OK;
}

//��ջ
Status Pop(SqStack *S, SElemType *e) 
{
    if (S->top == S->base) 
        return ERROR;    //ջ��
    *e = *--S->top;
    return OK;
}

//����ջ
Status StackTraverse(SqStack S) 
{
    if (S.base == NULL)
        return ERROR;
    if (S.top == S.base)
        printf("empty\n");
    SElemType *p;
    p = S.top;
    while (p > S.base) 
    {
        p--;
        printf("%c", *p);//��ջ����ʼ��ӡ������δ�޸�ջ��ָ�� 
    }
    return OK;
}

void conversion(SqStack *S) 
{
    //��ȫ����
    int decimal = 0;
    scanf("%d",&decimal);
    char base17[20] = "0123456789ABCDEFG";
    while(decimal)
    {
    	int index = decimal % 17;
    	Push(S,base17[index]);
    	decimal /=17;
	}
	StackTraverse(*S);
}

//������
int main() 
{
    SqStack S;
    InitStack(&S);
    conversion(&S);
    DestroyStack(&S);
    return 0;
}

