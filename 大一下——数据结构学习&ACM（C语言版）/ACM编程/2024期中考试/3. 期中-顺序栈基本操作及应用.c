#include "stdio.h"

#include "stdlib.h"

#define OK 1

#define ERROR 0

#define TRUE 1

#define FALSE 0

#define MAXSIZE  20   //��ջ���������

typedef int Status;

typedef char ElemType;

 

//˳��ջ�Ľṹ����

typedef struct

{

         ElemType data[MAXSIZE]; //��Ŷ�ջԪ�ص�����

         int top;                 //topָ��ջ��Ԫ�أ�top=-1����ʾ��ջ

} SqStack;

 

//��ʼ��һ����ջ

void InitStack(SqStack *S)

{

         S->top = -1;

}

Status Push(SqStack *S, ElemType e)

{

//�����벹ȫ����
	if((S->top + 1) > MAXSIZE) return ERROR;
	S->top ++;
	S->data[S->top] = e;


 

 

return OK;

}

 

Status Pop(SqStack *S, ElemType *e)

{

//�����벹ȫ����
		if(S->top == -1)	return ERROR;
		*e = S->data[S->top];
		S->top--;
         return OK;

}

 

//����ǿ�ջ������1�����򷵻�0

Status StackEmpty(SqStack S)

{

         return S.top == -1;

}

 

char GetTop(SqStack S, ElemType *e)

{

//�����벹ȫ����
	if(S.top == -1)	return ERROR;
	*e = S.data[S.top];
	return *e;
 

    
}

 

int main()

{

         char a[21], b[21];// ����1����Ӧgets������'\0'��β

         char temp;

         SqStack Stack;

         InitStack(&Stack);

         printf("Please enter a string with a length no longer than 20:\n");

         gets(a);

        int i = 0;
        char e;
        for(;a[i] != '\0';i ++)
        {
        	if(StackEmpty(Stack) || GetTop(Stack,&e) != a[i])
        	{

        		Push(&Stack,a[i]);
			}
			else 
			{
		   		if(a[i] == a[i + 1])	continue;
				Pop(&Stack,&e);
			}
		}
		int j = 0;
		while(StackEmpty(Stack) == 0)
		{
			Pop(&Stack,&b[j++]);
		}
		printf("The resulting string is: ");
		for(j = j - 1;j >= 0;j --)
		{
			printf("%c",b[j]);
		}

//�����벹ȫ����

 

         return 0;

}
