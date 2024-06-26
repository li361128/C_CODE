#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

#define STUDENT_NUMBER 5//����������

 

#define NAME_ASCEND    0//����������(�ǵݼ���˳������

#define NUMBER_ASCEND  1//��ѧ�ŵ���(�ǵݼ���˳������

#define SCORE_ASCEND   2//���ɼ�����(�ǵݼ���˳������

 

struct STUDENT_STRU

{

    char name[10];//����

    char num[6];  //ѧ��

    int score;    //�ɼ�

};

 

//��������ṹ�壨��ȫ���������Ļ���

void SwapStu(struct STUDENT_STRU *StucA, struct  STUDENT_STRU *StucB)

{

//�벹�����
	struct STUDENT_STRU temp;
	temp = *StucA;
	*StucA = *StucB;
	*StucB = temp; 

}

 

 

/**************************************************************************/

/*ð�����򷨣�����SortType��ȡֵѡ������Ĺؼ���                            */

/**************************************************************************/

void BubbleSort(struct STUDENT_STRU a[], int n, int SortType)

{

    int i, j;

   

    switch (SortType)

    {

        case NAME_ASCEND:

        {

//�벹�����
			for(i = 0; i < n - 1; i ++)
			{
				for(j = 0; j < n - i - 1; j ++)
				{
					if(strcmp(a[j].name, a[j + 1].name) > 0)
					{
						SwapStu(&a[j + 1], &a[j]);
					}
				}
			}

 				break;

        }

       

        case NUMBER_ASCEND:

        {

//�벹�����
			for(i = 0; i < n - 1; i ++)
			{
				for(j = 0; j < n - i - 1; j ++)
				{
					if(strcmp(a[j].num, a[j + 1].num) > 0)
					{
						SwapStu(&a[j + 1], &a[j]);
					}
				}
			}
			
			
			break;

        }       

       

        case SCORE_ASCEND:

        {

         //�벹�����
        for(i = 0; i < n - 1; i ++)
			{
				for(j = 0; j < n - i - 1; j ++)
				{
					if(a[j + 1].score < a[j].score)
					{
						SwapStu(&a[j + 1], &a[j]);
					}
				}
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

 

    struct STUDENT_STRU StudentStru[STUDENT_NUMBER] =

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

    BubbleSort(StudentStru, STUDENT_NUMBER, NAME_ASCEND);

    //��ӡ������

    printf("�����ǵݼ�����������������ݣ�\n");

    for (i = 0; i < STUDENT_NUMBER; i++)

    {

 

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

 

       //ѧ�ŵ�������

    BubbleSort(StudentStru, STUDENT_NUMBER, NUMBER_ASCEND);

    //��ӡ������

    printf("ѧ�ŵ�����������ݣ�\n");

    for (i = 0; i < STUDENT_NUMBER; i++)

    {

 

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

 

       //�ɼ��ǵݼ�������������

       BubbleSort(StudentStru, STUDENT_NUMBER, SCORE_ASCEND);

    //��ӡ������

    printf("�ɼ��ǵݼ�����������������ݣ�\n");

    for (i = 0; i < STUDENT_NUMBER; i++)

    {

 

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

 

       return 0;

}
