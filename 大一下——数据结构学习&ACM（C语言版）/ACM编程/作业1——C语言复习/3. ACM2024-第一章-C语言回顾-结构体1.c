#include "stdio.h"
#include "malloc.h"
#include "string.h"

struct STUDENT
{
       char STU_ID[8];
       char STU_NAME[10];
       int STU_AGE;
       int STU_SCORE;
}; 

int main(int argc, char* argv[])
{
      printf("������������䣬�Զ��Ÿ���\n");
       int AGE[5];
      //����5������
      scanf("%d,%d,%d,%d,%d",&AGE[0],&AGE[1],&AGE[2],&AGE[3],&AGE[4]);
      struct STUDENT (*p_stu)[5]=(struct STUDENT (*)[5])malloc(5*sizeof(struct STUDENT));
	//struct STUDENT (*p_stu)[5]��ʾ����ָ��һ��Ԫ��Ϊ5��struct STUDENT�����ָ�� 

	//�ڴ˴����һ��forѭ����ʹ��p_stuָ�뽫����AGE��ֵ���Σ���AGE[0]��AGE[4]����ֵ���ṹ���STU_AGE�ֶ�

		int i;
       for(i=0;i<5;i++)
       {
			p_stu[i]->STU_AGE = AGE[i];      
       		printf("%d\n",p_stu[i]->STU_AGE);
       }
       return 0;
}
