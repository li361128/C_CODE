#include <stdio.h>   

#include <stdlib.h>   



#define ERROR 0

#define OK 1

#define TRUE 1

#define FALSE 0

#define MAXSIZE 20



typedef struct

{

    char *ch;       //�����ǿ�,�򰴴�������洢��

    int  length;    //������

}HString;



int InitString(HString *T) 

{

    T->ch=(char*)malloc(sizeof(char)*MAXSIZE);

    if(!T->ch)

        return ERROR;

    T->length=0;

    return OK;

}



//���ַ�����chars��ֵ����T

//��������ɹ�������OK�����򷵻�ERROR

int StrAssign(HString *T,char *chars)

{

//�����벹ȫ����
	int i = 0;
	for(;chars[i] !='\0';i++)
	{
	}
	if(!i)
	{
		T->ch = NULL;
		T->length = 0;
	}
	else
	{
		int j = 0;
		for(j = 0;chars[j] != '\0';j ++)
		{
			T->ch[j] = chars[j];
			T->length ++;
		}
		
	}
	return OK;


}



   

// �Ƚ��ַ�����С

//��1�����������������ȣ���ÿһ����Ӧλ���ϵ��ַ���һ��������Ϊ0��

//��2��������������Ȳ���ȣ������Ե�һ������ͬ���ַ���Ϊ��׼�����ص�һ������ͬ���ַ�ASCII��ֵ��

//��3��������������Ȳ���ȣ���������Ӧλ���ϵ��ַ���һ�����򷵻������ַ����ĳ���֮�

int StrCompare(HString S,HString T)

{

  //�����벹ȫ����
  int i = 0;
  while(i < S.length && i < T.length)
  {
  		if(S.ch[i] != T.ch[i])	return (S.ch[i] - T.ch[i]);
  		i++; 
  }
  return S.length - T.length;



}//StrCompare    



int main()

{

    HString S;

    HString T;

    char mainstr[20];

    char substr[10];

    int index;

    InitString(&S);

    InitString(&T);

    gets(mainstr);

    gets(substr);

    StrAssign(&S,mainstr);

    StrAssign(&T,substr);

    printf("%d\n",StrCompare(S,T));

    return 1;

}
