#include <stdio.h>

#include <stdlib.h>

const int N=10010; 

void InversePrint(int a[], int n)

{
	if(n<=0)
	{
		return ;
	}
	else
	{
		printf("%d",a[n-1]);
		if(n!=1)
		{
			printf(",");
		}
		InversePrint(a,n-1);
	}


}

int main()

{
	int a[N],k=0,num;
    while (scanf("%d", &num) == 1 ) {  
        a[k++] = num;
//		getchar(); // ����ȡ��������������  
    }  
	
	InversePrint(a,k);
	
	return 0;
}
