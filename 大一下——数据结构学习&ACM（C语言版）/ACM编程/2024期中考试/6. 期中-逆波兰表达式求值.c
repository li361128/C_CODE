#include<stdio.h>
#include<malloc.h>

#define OK 1
#define ERROR 0

typedef int SElemType;

typedef int Status;

typedef struct Lnode{
	SElemType data;
	struct Lnode *next;
	
}LNode,*LinkList;

typedef struct{
	LinkList Head;
	int length;
	
}LinkStack;

Status InitLinkStack(LinkStack *S)
{
	S->Head = (LinkList)malloc(sizeof(LNode));
	if(!S->Head)
		return ERROR;
	
	S->Head->next = NULL;
	S->length = 0;
	
	return OK;
} 


Status StackEmpty(LinkStack S)
{

	return (S.Head->next == NULL);
	
}

Status Push(LinkStack *S, SElemType e)
{
	LinkList p;
	
	p = (LinkList)malloc(sizeof(LNode));
	if(!p)
		return ERROR;
	
	p->data = e;
	p->next = S->Head->next;
	S->Head->next = p;
	S->length++;
	
	return OK;
	
}

Status GetTop(LinkStack S, SElemType *e)
{
	if(!S.Head->next )
		return ERROR;
	
	*e = S.Head->next->data;
	
	return OK;
	
}

Status Pop(LinkStack *S, SElemType *e)
{
	
	LinkList p;
	
	p = S->Head->next;
	
	if(!p)
		return ERROR;

	*e = p->data;
	
	S->Head->next = p->next;
	free(p);
	
	S->length--;
	
	return OK;
	
}

int StackLength(LinkStack S)
{
	return S.length;
	
}

/* �������㺯�����壺
  * ���������������n1,n2,�����op,������ָ��out��
  * ������򼰷���ֵ������n1 op n2�Ľ���������������*out��
  *                ������ֳ��㣬����ERROR�����򷵻�OK��*/
 Status Operate(int n1,char op,int n2,int *out){
     switch (op) {
         case '+':
             *out = n1 + n2;
             return OK;
         case '-':
             *out = n1 - n2;
             return OK;
         case '*':
             *out = n1 * n2;
             return OK;
         case '/':
             if(n2 == 0)
                 return ERROR;
             else{
                 *out = n1 / n2;
                 return OK;
             }
     }
 }
 
 /* �沨�����ʽ���㺯�����壺
  * ������������ʽ�ַ���ָ��s,������ָ��res��
  * ������򼰷���ֵ��������ʽ*s��ֵ�������������*out��
  *               ��������沨�����ʽ���󣬷���ERROR�����򷵻�OK��*/
Status calculate_RP(char *s, int *res){

  //=============================
  //�벹������
  //=============================
	  int i = 0,n1,n2;
	  LinkStack S;
	  InitLinkStack(&S);
	  for(;s[i] != '\0';i ++)
	  {
	  	if(s[i] <= '9' && s[i] >= '0')	
		{
			if(s[i + 1] <= '9' && s[i + 1] >= '0')				
				{
					if(s[i + 2] <= '9' && s[i + 2] >= '0')				
					{
						Push(&S,(s[i] - '0') * 100 + (s[i + 1] - '0') *10 + s[i + 2] - '0');
						i += 2; 	
					}
					else
					{
						Push(&S,(s[i] - '0') * 10 + s[i + 1] - '0');
						i ++;
					}
				}
			else	Push(&S,s[i] - '0');
		}
		else if(s[i] != ' ')
		{
			if(Pop(&S,&n1) == ERROR)	return ERROR;
			if(Pop(&S,&n2) == ERROR)	return ERROR;
			if(Operate(n2,s[i],n1,res) == ERROR)	return ERROR;
			Push(&S,*res);
		}
			
	   } 
	   if(S.length != 1)	return ERROR;
	return OK;
}

int main() {
    int result = 0;
    char notation[100];
    gets(notation);
    //puts(notation);
    //�����沨�����ʽ��ֵ
    if(calculate_RP(notation,&result)){
        printf("%d\n",result);
    }
    else{
        printf("Wrong notation!\n");
    }

    return 0;
}
