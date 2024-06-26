#include <stdio.h>
#include <stdlib.h>

//�۰���Һ���
//int a[ ]:���ұ�int n: ���ұ��ȣ� int target: �����ҵ�Ԫ��
//������ҳɹ�������Ԫ�������±꣨��0��ʼ�����������ʧ�ܣ�����-1
int BinarySearch(int a[ ],  int n,  int target) 
{
//�����벹ȫ����
	int l = 0, r = n;
	while(l <= r)
	{
		int mid = (r + l) / 2;
		if(a[mid] < target)	l = mid + 1;
		else if(a[mid] == target)	return mid;
		else r = mid - 1; 
	 } 
	 return -1;

}

int main( )
 {
	int a[10], n, i, m;
        scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	scanf("%d", &m);
	
	int q;
	q = BinarySearch(a, 10, m);
	if (q != -1) {
		printf("%d", q + 1);
	}
	else {
		printf("not found");
	}
	return 0;
}
