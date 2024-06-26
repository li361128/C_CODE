#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

#define STUDENT_NUMBER 5//����������

 

#define NAME_ASCEND    0//����������(�ǵݼ���˳������

#define NUMBER_ASCEND  1//��ѧ�ŵ���(�ǵݼ���˳������

#define SCORE_ASCEND   2//���ɼ�����(�ǵݼ���˳������

 

typedef struct STUDENT_STRU

{

    char name[10];//����

    char num[6];  //ѧ��

    int score;    //�ɼ�

}STUDENT_STRU;

 

 

/**************************************************************************/

/*�۰�������򷨣�����SortType��ȡֵѡ������Ĺؼ���                          */

/**************************************************************************/

void BinaryInsertionSort(STUDENT_STRU a[], int n, int SortType)

{

    int i, j;

    int low, high;

    int m;

    switch (SortType)

    {

        case NAME_ASCEND:

        {

           //�벹�����
           
           for(i = 2;i <= n; i ++)
           {
           		a[0] = a[i];
           		low = 1, high = i - 1;
           		while(low <= high)
           		{
           			int mid = (low + high) /2;
           			if(strcmp(a[mid].name, a[0].name) <= 0)	low = mid + 1;
           			else high = mid - 1;
				}
				for(j = i - 1; j >= low; j --)
				{
					a[j + 1] = a[j];
				 } 
				a[low] = a[0];
		   }
           
	        break;

        }

 

 

        case NUMBER_ASCEND:

        {

           

          //�벹�����
          	for(i = 2; i <= n; i ++)
          	{
          		a[0] = a[i];
          		low = 1, high = i - 1;
          		while(low <= high)
          		{
          			int mid = (low + high)/ 2;
          			if(strcmp(a[mid].num, a[0].num) < 0)	low = mid + 1;
          			else high = mid - 1;
				  }
				  for(j = i - 1; j >= low; j --)
				  {
				  	a[j + 1] = a[j];
				  }
				  a[low] = a[0];
			  }
          	
	        break;
        }       

       

        case SCORE_ASCEND:

        {

         //�벹�����
         	for(i = 2; i <= n; i ++)
         	{
         		a[0] = a[i];
         		low = 1, high = i - 1;
         		while(low <= high)
         		{
         			int mid = (low + high) / 2;
         			if(a[mid].score <= a[0].score)	low = mid + 1;
         			else high = mid - 1;
				 }
				 for(j = i - 1; j >= low; j --)
				 {
				 	a[j + 1] = a[j];
				 }
				 a[low] = a[0];
			 }
         	
         	
		     break;

        }

       

        default:

            break;

    }

}


//�������ж���ѧ���ṹ��������Ϣ�������������㷨��������ÿ��������ӡ������бȶ�

//ע��ÿһ������������һ��������������ԭʼ���ݣ��Ļ����Ͻ��е�

int main(void)

{

    int i;

   

    //ѧ����Ϣ�Ľṹ�����飬ע����ѧ��������/�ɼ�����ͬ�ģ���ϸ��������㷨���ȶ���

    //ע��Ԥ��������0��λ�����ڵ����ڱ�ʹ�ã�ʵ�����ݴ�1��ʼ

    STUDENT_STRU StudentStru[STUDENT_NUMBER+1] =

    {

        {"","",0},

        {"James", "00007", 85},

        {"Amy",   "00010", 90},

        {"Zoe",   "00001", 60},

        {"Tom",   "00005", 85},

              {"Tom",   "00015", 70},

    };

 

    //��ӡ�������

    printf("��ʼ����Ϊ��\n");

    for(i = 1; i <=STUDENT_NUMBER; i++)

    {

 

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

 

    //�����ǵݼ�������������

    BinaryInsertionSort(StudentStru, STUDENT_NUMBER, NAME_ASCEND);

    //��ӡ������

    printf("�����ǵݼ�����������������ݣ�\n");

    for(i = 1; i <=STUDENT_NUMBER; i++)

    {

 

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

 

       //ѧ�ŵ�������

    BinaryInsertionSort(StudentStru, STUDENT_NUMBER, NUMBER_ASCEND);

    //��ӡ������

    printf("ѧ�ŵ�����������ݣ�\n");

    for(i = 1; i <=STUDENT_NUMBER; i++)

    {

 

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

 

       //�ɼ��ǵݼ�������������

       BinaryInsertionSort(StudentStru, STUDENT_NUMBER, SCORE_ASCEND);

    //��ӡ������

    printf("�ɼ��ǵݼ�����������������ݣ�\n");

    for(i = 1; i <=STUDENT_NUMBER; i++)

    {

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

       return 0;

}
