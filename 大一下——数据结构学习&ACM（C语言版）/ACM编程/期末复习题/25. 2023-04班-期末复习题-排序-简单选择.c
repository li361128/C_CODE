#include <stdio.h>



int SelectMinKey(int A[], int i,int n) //A Ϊ�����е����飬iΪ���ŵ�����nΪ����ĳ���

{ 

    //ѧ����ӳ���// ������A[i..n]��key��С�ļ�¼�����
	int min = A[i], min_n = i;
	for(;i < n;i ++)
	{
		if(A[i] < min)
		{
			min = A[i];
			min_n = i;
		}
	}
	return min_n;

}



void SelectSort(int A[], int n)

{ 

   // ��A����ѡ������

   int i,j;

   int temp;

    for(i=0;i<n;i++)

    {

     //  ѡ���iС�ļ�¼����������λ

j=SelectMinKey(A, i, n); // ��A[i..n]��ѡ��key��С�ļ�¼

if(i!=j) 

{

temp=A[i];

A[i]=A[j];

A[j]=temp; // ���i����¼����

}

}

}







int main()

{

int A[20];

int n;

int i;

scanf("%d",&n);

for(i=0;i<n;i++)

{

scanf("%d",&A[i]);

}

SelectSort(A,n);

printf("ѡ�������:\n");

for (i = 0; i<n; i++)

{

printf("%d ", A[i]);

}

printf("\n");

return 1;

}



