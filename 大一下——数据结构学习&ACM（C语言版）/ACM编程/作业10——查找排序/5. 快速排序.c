#include<stdio.h>

#include<stdlib.h>

#include<string.h>


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

 

 
// ���ɼ��ֿ麯��
int PartitionScore(STUDENT_STRU a[], int low, int high)
{
	STUDENT_STRU temp = a[low];
	while(low < high)
	{
		while(low < high && a[high].score >= temp.score)	--high;
		a[low] = a[high];
		while(low < high && a[low].score <= temp.score)		++low;
		a[high] = a[low];
		
	}
	a[low] = temp;
	return low;
}
 

//�������ֿ麯��

int PartitionName(STUDENT_STRU a[], int low, int high)

{

    //�벹�����
    STUDENT_STRU temp = a[low];
    while(low < high)
    {
    	while(low < high && strcmp(a[high].name, temp.name) >= 0)	--high;
    	a[low] = a[high];
    	while(low < high && strcmp(a[low].name, temp.name) <= 0)	++low;
    	a[high] = a[low];
	}
	a[low] = temp;
	return low;

}

 

//��ѧ�ŷֿ麯��

int PartitionNum(STUDENT_STRU a[], int low, int high)

{

    //�벹�����
    STUDENT_STRU temp = a[low];
    while(low < high)
    {
    	while(low < high && strcmp(a[high].num, temp.num) >= 0 )	--high;
    	a[low] = a[high];
    	while(low < high && strcmp(a[low].num, temp.num) <= 0)	++low;
    	a[high] = a[low];
	}
	a[low] = temp;
	return low;

}

 

 

void QSort(STUDENT_STRU a[], int low, int high,int sortNum)

{

switch (sortNum)

       {

              case NAME_ASCEND:

              {

                     if (low < high)

                     {

                            int pivotloc = PartitionName(a, low, high);

                            QSort(a, low, pivotloc-1, NAME_ASCEND);

                            QSort(a, pivotloc+1, high, NAME_ASCEND);

                     }

 

                     break;

              }

                    

 

              case NUMBER_ASCEND:

              {

                     if (low < high)

                     {

                            int pivotloc = PartitionNum(a, low, high);

                            QSort(a, low, pivotloc-1, NUMBER_ASCEND);

                            QSort(a, pivotloc+1, high, NUMBER_ASCEND);

                     }

 

                     break;

              }

 

              case SCORE_ASCEND:

              {

                     if (low < high)

                     {

                            int pivotloc = PartitionScore(a, low, high);

                            QSort(a, low, pivotloc-1, SCORE_ASCEND);

                            QSort(a, pivotloc+1, high, SCORE_ASCEND);

                     }

 

                     break;

              }

 

              default:

                     break;

       }// end of switch()

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

    QSort(StudentStru, 0, STUDENT_NUMBER-1, NAME_ASCEND);

    //��ӡ������

    printf("�����ǵݼ�����������������ݣ�\n");

    for (i = 0; i < STUDENT_NUMBER; i++)

    {

 

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

 

       //ѧ�ŵ�������

    QSort(StudentStru, 0, STUDENT_NUMBER-1, NUMBER_ASCEND);

    //��ӡ������

    printf("ѧ�ŵ�����������ݣ�\n");

    for (i = 0; i < STUDENT_NUMBER; i++)

    {

 

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

 

       //�ɼ��ǵݼ�������������

       QSort(StudentStru, 0, STUDENT_NUMBER-1, SCORE_ASCEND);

    //��ӡ������

    printf("�ɼ��ǵݼ�����������������ݣ�\n");

    for (i = 0; i < STUDENT_NUMBER; i++)

    {

 

        printf("%s %s %d\n", StudentStru[i].name, StudentStru[i].num, StudentStru[i].score);

    }

       return 0;

}
