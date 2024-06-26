#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
typedef int Status;
typedef char SElemType;
 
 
typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}LNode,*LinkList;
 
typedef struct{
    LinkList Head;
    int length;
          
}LinkStack;
 
Status InitStack(LinkStack *S)
{
   S->Head = (LinkList)malloc(sizeof(LNode));
   if(S->Head==NULL)
             return ERROR;
   S->Head->next = NULL;
   S->length = 0;
  
   return OK;
}
Status StackEmpty(LinkStack *S)
{
   if(S->length==0)
             return TRUE;
   else
             return FALSE;
}

/*
�����������޵к���ʦ������
���˺þã��������ݶ����ˣ����� 
��С���ܲ�������㣬�����������Ӱɣ�����
С��ʵ��ʵ���ǿ۲����ˣ�������ô�û����۵ģ����� 
��֪����һ����ȫ������õ���ʦ������ 
*/

//��ջ����
Status Push(LinkStack *S,SElemType e)
{   
     //�벹ȫ����
     if(S->length >= MAXSIZE)//�����궨����������������MAXSIZE������ 
     	return ERROR;
     	
    //�����µ������� 
     LinkList p;
	 p = (LinkList)malloc(sizeof(LNode));
	 if(!p)
	 	return ERROR; 
	p->data = e;
	
	p->next = S->Head->next;
	S->Head->next = p;
	
	S->length ++;//����ջ�ĳ���
	 
	return OK;	
}

//��ջ����
Status Pop(LinkStack *S,SElemType *e)
{
	if(S->length==0)
		return ERROR;
	LinkList p;
	p = S->Head->next; 
	*e=p->data;
	S->Head->next = p->next;
	free(p);
	S->length--;
	return OK;
}

//ȡջ��Ԫ��
Status GetTop(LinkStack *S,SElemType *e)
{
	*e=S->Head->next->data;
	return OK;
}

// �ж������ַ� element_l �� element_r �Ƿ���ԣ�����ǣ�����TRUE���������FALSE. 
Status match(char element_l, char element_r)
{
  //�벹ȫ����
	if((element_l == '(' && element_r == ')' )
	|| (element_l == '{' && element_r == '}' )
	|| (element_l == '[' && element_r == ']'))
		return TRUE;

		
	return FALSE;
  
}

//ʹ����ջS�����ַ���str�е��ַ���������ƥ���飬���ȫ����ԣ����ӡYes, ������ִ������ӡNo, �������Ӻ������ء�
void match_check(char str[], LinkStack *S)
{
   //�벹ȫ����
   int i =0;
   for(;str[i] != '\0';i ++)
   {
   		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
   			Push(S, str[i]);
   			
   		else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
   		{
   			char temp;
   			if(StackEmpty(S))
   			{
   				printf("No");
   				return ;	
			}
   			GetTop(S, &temp);
   			if(match(temp, str[i]) == TRUE)
   				Pop(S, &temp);
   			else
   			{
   				printf("No");
   				return ;
			}
		}
   }
   
   if(StackEmpty(S))
   		printf("Yes");
   	else
   		printf("No");
}
 
 
int main(){
	LinkStack S;
	char str[MAXSIZE];
	InitStack(&S);
	scanf("%s", str);
	match_check(str,&S);
	return 0;
}
