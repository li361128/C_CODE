//��дð������BubbleSort����


#include <stdio.h>

void BubbleSort(int A[], int n)

{

	//�벹ȫ����
	int i,j;
	for(i = 0;i < n; i ++)
	{
		for(j = 0;j < n - i - 1;j ++)
		{
			if(A[j] > A[j + 1])
			{
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}

}

int main()

{

	int A[] = { 4, 8, 3, 9, 6, 5, 12, 1, 10, 7 };

	BubbleSort(A, sizeof(A)/sizeof(A[0]));

	printf("ð�������:\n");
	
	int i;

	for (i = 0; i<sizeof(A) / sizeof(A[0]); i++)

	{

		printf("%d ", A[i]);

	}

	printf("\n");

	return 1;

}
