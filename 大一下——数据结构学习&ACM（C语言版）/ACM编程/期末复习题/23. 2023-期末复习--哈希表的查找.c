/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


#include <stdio.h>

#include <stdlib.h>

#define TRUE 1

#define FALSE 0

#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��TRUE�� */

#define HASHSIZE 12 // �����ϣ��Ϊ����ĳ���

#define NULLKEY -32768 // �չؼ���


typedef struct

{

int *elem; // ����Ԫ�ش洢��ַ����̬��������

int count; //  ��ǰ����Ԫ�ظ���

}HashTable;


int m = 0; // ��ϣ�����ȫ�ֱ���


Status initHashTable(HashTable *hash)

{

int i;

	m = HASHSIZE;

	hash->count = m;

	hash->elem = (int *)malloc(m*sizeof(int));

	for (i = 0; i < m; i ++)
		hash->elem[i] = NULLKEY;
	
	return TRUE;

}

// �����ϣ����

int hashFun(int key)

{

return key % m; // ���췽��Ϊ����������

}

// ����ؼ��ֽ���ϣ��

void insertHash(HashTable *hash, int key)

{

int addr = hashFun(key); // ���ϣ��ַ

while (hash->elem[addr] != NULLKEY) // �����Ϊ�գ����ͻ

{

		addr = (addr + 1) % m; // ���Ŷ�ַ��������̽��

}

	hash->elem[addr] = key; // ֱ���п�λ�����ؼ���

}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */


Status searchHash(HashTable hash, int key, int *addr)
{
	*addr = hashFun(key);
	while(hash.elem[*addr] != key && hash.elem[*addr] !=NULLKEY && (*addr + 1) != hashFun(key))
	{
		*addr = (*addr + 1) % m;
	}
	if(hash.elem[*addr] == key)
		return 1;
	return 0;
}



/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


int main()

{

int arr[HASHSIZE] = {12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34}; // Ҫ����ؼ���

int key; // �ؼ���

int addr; // ��ϣ��ַ

int i;

int result;

HashTable hash;

// ��ʼ����ϣ��

	initHashTable(&hash);

// ����ؼ��ֵ���ϣ��

for (i= 0; i< m; i++)

{

		insertHash(&hash, arr[i]);

}

// �������ҹؼ��֣�����ɹ���

	printf("����Ҫ���ҵ�keyֵ:\n");

	scanf("%d",&key);
	
//	printf("%d",key); 

	result=searchHash(hash, key, &addr);

if (result)

		printf("���� %d �Ĺ�ϣ��ַΪ��%d\n", key, addr);

else

		printf("���� %d ʧ��\n", key);

return 0;

}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
