//����ֵ����δ��ȷ������ȷ�ռ䣬 ��2��
//���뺯���ͷź�δ����ռ䣬 ��2��
#include <stdio.h>
#include <stdlib.h>


typedef struct{
   char *ch;       //�����ǿ�,�򰴴�������洢��,
                   //����chΪNULL
   int  length;    //������
}HString;

typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

Status InitString(HString *T) {
	(*T).length=0;
	(*T).ch=NULL;
	return OK;
}


Status ClearString(HString *S){
//��S��Ϊ�մ�
	if((*S).ch) {
		free((*S).ch); 
	}
	(*S).ch = NULL;
	(*S).length=0;
	return OK;
}//ClearString

Status StrAssign(HString *T,char *chars){

//*************��ȫ����*************
	int i = 0;
//	T->ch = (char*)malloc(100 *sizeof(char));
    int len = 0;
	for(; chars[len] != '\0'; len ++){}
		 
	T->ch = (char*)malloc(len *sizeof(char));
	for(;chars[i] != '\0';i ++)
	{
		(*T).ch[i] = chars[i];
	} 
	(*T).length = i;
	return OK;

}//StrAssign    


int StrLength(HString S){
//����S��Ԫ�ظ���,��Ϊ���ĳ���
	return S.length;
}//StrLength

int StrCompare(HString S,HString T){
//��S=T,����ֵ=0;
	
	//*****��ȫ����********
	int i = 0;
	for(;i < S.length && i < T.length;i++)
	{
		if(S.ch[i] != T.ch[i])	return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
	

}//StrCompare    

Status StrInsert(HString *S,int pos,HString T){

 //*********��ȫ����***********
 	int i = 0;
 	if(pos > S->length + 1 || pos < 1)		return ERROR;
 	
 	for(i = S->length;i >= pos;i --)
 	{//��S->ch�е�posλ���Ժ���ܼ�S->length - pos + 1���ַ�������T->length������
 		S->ch[i + T.length - 1] = S->ch[i - 1];
	}
	for(i = 0;i < T.length ;i ++)
	{//��S->ch�е�posλ���Ժ��ܼ�T->length���ַ�replace��T->ch�е��ַ�
		S->ch[i + pos - 1] = T.ch[i];
	}
	S->length += T.length; //����S->length
    S->ch[S->length] = '\0';  // ȷ���ַ�����NULL��β
	return OK;

	
}//StringInsert    


void StrTravel(HString S)
{
	int i;
	for(i=0;i<S.length;i++)
	{
		printf("%c",S.ch[i]);
	}
	printf("\n");
}

int main()
{
	HString S1,S2,S3;
	InitString(&S1);//��ʼ����1
	InitString(&S2);//��ʼ����2
	InitString(&S3);//��ʼ����3
	char str1[100],str2[100],str3[100];
	scanf("%s",str1);
	scanf("%s",str2);
	scanf("%s",str3);
	StrAssign(&S1,str1);//��1��ֵ
	StrAssign(&S2,str2);//��2��ֵ
	StrAssign(&S3,str3);//��3��ֵ
	int pos;
	scanf("%d",&pos);

	StrTravel(S1);
	StrTravel(S2);
	StrTravel(S3);
	if(StrInsert(&S1,pos,S2)==OK)//������
	{
		StrTravel(S1);//����ӡ���
	}
	else
	{
		printf("insert fail\n");
	}
	int cmp = StrCompare(S1,S3);
	if(cmp == 0)
		printf("equal\n");
	else
		printf("not equal\n");
	ClearString(&S1);
	ClearString(&S2);
	ClearString(&S3);
	return 0;
}

