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

 

//��������ṹ�壨��ȫ���������Ļ���

void SwapStu(STUDENT_STRU *StucA, STUDENT_STRU *StucB)

{

    //�벹�����
    STUDENT_STRU temp = *StucA;
    *StucA = *StucB;
    *StucB = temp;
    

}

 

 

 

 

//������ѡ��

int SelectNameMinKey(STUDENT_STRU a[], int h, int i)

 { // ������L.r[i..L.length]��key��С�ļ�¼�����

  //�벹�����
  	int min = i;
  	for(i = i + 1; i <= h ; i ++)
  	{
  		if(strcmp(a[i - 1].name, a[min - 1].name) < 0 )
  		{
  			min = i;
		  }
	  }
  
	return min;
 }

 

//���ɼ�ѡ��

int SelectScoreMinKey(STUDENT_STRU a[], int h, int i)

 { // ������L.r[i..L.length]��key��С�ļ�¼�����

   //�벹�����
     	int min = i;
  	for(i = i + 1; i <= h ; i ++)
  	{
  		if(a[i - 1].score < a[min - 1].score )
  		{
  			min = i;
		  }
	  }
  
	return min;

 }

 

//��ѧ��ѡ��

int SelectNumberMinKey(STUDENT_STRU a[], int h, int i)

 { // ������L.r[i..L.length]��key��С�ļ�¼�����

    //�벹�����
      	int min = i;
  	for(i = i + 1; i <= h ; i ++)
  	{
  		if(strcmp(a[i - 1].num, a[min - 1].num) < 0 )
  		{
  			min = i;
		  }
	  }
  
	return min;

 }

 

 

 

/**************************************************************************/

/*ѡ�����򷨣�����SortType��ȡֵѡ������Ĺؼ���                            */

/**************************************************************************/

 

 

void SelectSort(STUDENT_STRU a[], int n, int SortType)

 { // ��˳���L����ѡ������

  int i, j;

    struct STUDENT_STRU t;

    switch (SortType)

    {

        case NAME_ASCEND:

        {

         for(i=1;i<n;++i)

               {

            //  ѡ���iС�ļ�¼����������λ

        j=SelectNameMinKey(a, n, i); // ѡ��key��С�ļ�¼

        if(i!=j)   SwapStu(&a[i-1], &a[j-1]);  // ���i����¼����

            }

        break;

        }

 

      case NUMBER_ASCEND:

        {

         for(i=1;i<n;++i)

               {

            //  ѡ���iС�ļ�¼����������λ

        j=SelectNumberMinKey(a,n, i); // ѡ��key��С�ļ�¼

        if(i!=j)   SwapStu(&a[i-1], &a[j-1]);  // ���i����¼����

            }

        break;

        }

 

      case SCORE_ASCEND:

        {

         for(i=1;i<n;++i)

               {

            //  ѡ���iС�ļ�¼����������λ

        j=SelectScoreMinKey(a,n, i); // ѡ��key��С�ļ�¼

        if(i!=j) SwapStu(&a[i-1], &a[j-1]); // ���i����¼����

            }

        break;

        }

 

 }

 

}

 

 

//�������ж���ѧ���ṹ��������Ϣ�������������㷨��������ÿ��������ӡ������бȶ�

//ע��ÿһ������������һ��������������ԭʼ���ݣ��Ļ����Ͻ��е�

int main(void)

{

    int i;

 

    STUDENT_STRU StudentStru[STUDENT_NUMBER] =

    {

        {"James", "00007", 85},

        {"Amy",   "00010", 90},

        {"Zoe",   "00001", 60},

        {"Tom",   "00005", 85},

              {"Tom",   "00015", 70},

    };//ѧ����Ϣ�Ľṹ�����飬ע����ѧ��������/�ɼ�����ͬ�ģ���ϸ��������㷨���ȶ���

 

    //��ӡ�������

    printf("��ʼ����Ϊ��\n");

    for (i = 0; i < STUDENT_NUMBER; i++)

    {

 

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

 

    //�����ǵݼ�������������

    SelectSort(StudentStru, STUDENT_NUMBER, NAME_ASCEND);

    //��ӡ������

    printf("�����ǵݼ�����������������ݣ�\n");

    for (i = 0; i < STUDENT_NUMBER; i++)

    {

 

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

 

       //ѧ�ŵ�������

    SelectSort(StudentStru, STUDENT_NUMBER, NUMBER_ASCEND);

    //��ӡ������

    printf("ѧ�ŵ�����������ݣ�\n");

    for (i = 0; i < STUDENT_NUMBER; i++)

    {

 

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

 

       //�ɼ��ǵݼ�������������

       SelectSort(StudentStru, STUDENT_NUMBER, SCORE_ASCEND);

    //��ӡ������

    printf("�ɼ��ǵݼ�����������������ݣ�\n");

    for (i = 0; i < STUDENT_NUMBER; i++)

    {

 

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

 

       return 0;

}
