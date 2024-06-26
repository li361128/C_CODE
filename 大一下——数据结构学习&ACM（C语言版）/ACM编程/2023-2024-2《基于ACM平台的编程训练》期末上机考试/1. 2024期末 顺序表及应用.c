#include <stdio.h>
#include <stdlib.h>
#define List_init_size 10
#define OK 1
#define ERROR -1
 
 
typedef int Elem;
 
typedef struct
{
    int *elem;
    int length;
    int listsize;
}Sqlist;
 
int Initlist(Sqlist *L)
{
    L->elem=(Elem *)malloc(List_init_size*sizeof(Elem));
    if(!L->elem)return ERROR;
    L->length=0;
    L->listsize=List_init_size;
    return OK;
}
 
//��������m��Ԫ�ص������ 
int Createlist(Sqlist *L, int m)
{
    if(m>L->listsize ||m==0) 
        return ERROR;
    int i;
    
    for(i=0;i<m;i++)
    {
        scanf("%d",&L->elem[i]);
    }
    
    L->length=m;
    return OK;
}


/*
�����������޵к���ʦ������
���˺þã��������ݶ����ˣ����� 
��С���ܲ�������㣬�����������Ӱɣ�����
С��ʵ��ʵ���ǿ۲����ˣ�������ô�û����۵ģ����� 
��֪����һ����ȫ������õ���ʦ������ 
*/
 
//�������L1��L2�Ľ����������L3�С�
void Intersection(Sqlist *L1, Sqlist *L2, Sqlist *L3)
{
    //�����벹ȫ����
    int len1 = 0,len2 = 0, len3 = 0;
    //����һ�㣬��Ϊ��ȡ��������L3�������������������������ݵ����� 
    while(len1 < L1->length && len2 < L2->length)
    {
    	if(L1->elem[len1] == L2->elem[len2])
    	{
    		L3->elem[len3 ++]  = L1->elem[len1];//����������L3�� 
    		L3->length ++;//����L3�ĳ���
			 
    		len1 ++;
    		len2++;
		}
		else if(L1->elem[len1] < L2->elem[len2])
		{
			len1++;
		}
		else 
			len2 ++;
	}


}


//���Ա�L��ǰm��Ԫ���Ƶ���β������nΪ��L�ĳ���
//���m>n,����ERROR�����������ɣ�����OK  
int Move(Sqlist *L, int n, int m)
{
    //�����벹ȫ����
    if(m >n)
    {//���m���ڱ���ִ�и��ƶ�����
    	return ERROR;
	}
	
	int i = 0;
	for(i = 0;i < m;i ++)
	{
		int temp = L->elem[i];
		L->elem[i] = L->elem[n + i - m];
		L->elem[n + i - m] = temp;
	}
    return OK;
}
 
 
 
void Display(Sqlist *L)
{
    int i;
    for(i=0;i<L->length;i++)
    {
        printf(i==(L->length-1)?"%d\n":"%d ",L->elem[i]);
    }
}
 
 
int main()
{
  int m,n,x;
     int i,j;
    Sqlist A,B,C;
    scanf("%d%d",&m,&n);
    Initlist(&A);
    Initlist(&B);
    Initlist(&C);
    i=Createlist(&A,m);
    if(i==-1)
    {
         printf("The number of elements is illegal!\n");
         exit(0);
    }
   
    j=Createlist(&B,n);
    if(j==-1)
    {
         printf("The number of elements is illegal!\n");
         return 0;
    }
    
    scanf("%d",&x);
    printf("Table A is: ");
    Display(&A);
    Intersection(&A,&B,&C);
    printf("\nThe intersection of Table A and Table B is: ");
    Display(&C);
    Move(&C,C.length,x);
    printf("\nThe Table C whose elements have been moved is: ");
    Display(&C);
    return 0;
}
