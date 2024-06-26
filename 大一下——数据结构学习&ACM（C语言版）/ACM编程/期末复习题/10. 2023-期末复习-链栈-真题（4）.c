#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
typedef int SElemType;


//������ջ�ṹ
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode,*LinkStack;

//��ʼ����ջ
Status InitStack(LinkStack *S)
{
	LinkStack Head=(LinkStack)malloc(sizeof(StackNode));
	if(!Head)	return ERROR; 
	Head->next=NULL;
	(*S)=Head;
	return OK;
}

//�ж���ջ�Ƿ�Ϊ�գ����򷵻�TRUE�������򷵻�FALSE
Status StackEmpty(LinkStack S)
{
	if (NULL==S->next)
		return TRUE;
	else
		return FALSE;
}

//��Ԫ��e��ջ
Status Push(LinkStack *S, SElemType e)
{   
	StackNode *top=(*S)->next;
	StackNode *temp;
	temp = (LinkStack)malloc(sizeof(StackNode));
	temp->data = e;
	temp->next=(*S)->next;
	(*S)->next=temp;
	return OK;
}

//����ջ��Ԫ�أ���ֵ��e
Status GetTop(LinkStack S, SElemType *e)
{
	if (StackEmpty(S)==TRUE)
		return ERROR;
	*e = S->next->data;
	return OK;
}

//��ջ����ջԪ�ظ�ֵ��e
Status Pop(LinkStack *S, SElemType *e)
{
	StackNode *top=(*S)->next;
	if (StackEmpty(*S)==TRUE)
		return ERROR;
	*e = top->data;
	(*S)->next = top->next;
	free(top);
	return OK;
}

int main()
{
	LinkStack S;
//	int n=0;  //ͨ������nͳ����ͬ���ĸ���������ͬ����ÿ�ν�ջ��n+1
	InitStack(&S);  //��ʼ��ջ
	
	//�����벹ȫ����
	
//	int arr[MAXSIZE] ,i = 0, temp;
//	while(1)
//	{
//		scanf("%d", &temp);
//		if(temp == -1)	break;
//		arr[i ++] = temp;
//	}
	
	
	
	while(1)
	{
		int a = 0;
		scanf("%d", &a);
		if(a == -1)	break;
		Push(&S, a);
	 }
	 int e = -1, e_pre = -1;
	 while(!StackEmpty(S)) 
	 {
	 	Pop(&S, &e);
	 	GetTop(S, &e_pre);
	 	if(e != e_pre || StackEmpty(S))	
	 	{
	 		printf("%d ", e);
		}
		else
		{
			while(!StackEmpty(S) && e == e_pre)
			{
				Pop(&S, &e);
				if(!StackEmpty(S))	GetTop(S, &e);
			}
//			if(e != e_pre) Push(&S, e);
		}
	 }
	
	return 0;

}
