#include <stdio.h>

#include <stdio.h>

 

 

//��ӡ���ֲ��ҹ��̵��м�λ��mid����Ӧ�����֣�ʹ��printf("%d\t", midVal)

 

int Search (int a[], int n, int key)
{
	int l = 0,r = n;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		printf("%d\t", a[mid]);
		if(a[mid] == key)	return mid;	
		if (a[mid] < key)	l = mid + 1;
		else 	r = mid - 1;
	}
	return -1;
}

 

int main(){

    int i, val;
	int a[15]={5,10,11,15,17,19,21,25,36,38,50,51,55,57,68};
	 

    for(i = 0; i < 15; i ++)
    {
    	printf("%d\t", a[i]);
	}

 

    printf("\n��������Ҫ���ҵ�Ԫ�أ�");

    scanf("%d",&val);

    int midVal = Search(a, 15, val);

  	if(midVal == -1)
        printf("����ʧ��\n");

    else		
        printf("���ҳɹ�\n");

       return 0;

}
