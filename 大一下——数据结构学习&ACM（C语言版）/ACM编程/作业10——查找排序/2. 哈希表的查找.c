#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR -1

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��TRUE�� */

#define ITEMNO 12
#define HASHSIZE 13 // �����ϣ��Ϊ����ĳ���
#define NULLKEY -32768 // �չؼ���

typedef struct{
    int* elem; // ����Ԫ�ش洢��ַ����̬��������
    int count; //  ��ǰ����Ԫ�ظ���
}HashTable;

Status initHashTable(HashTable* hash)
{
    int i;
    hash->count = 0;
    hash->elem = (int*)malloc(HASHSIZE * sizeof(int));
    if(!hash->elem)
        return ERROR;
    for (i = 0; i < HASHSIZE; i++)
        hash->elem[i] = NULLKEY;
    return OK;
}

// �����ϣ����
int hashFun(int key)
{
    return key % HASHSIZE; // ���췽��Ϊ����������
}

// ����ؼ��ֽ���ϣ��
int InsertHash(HashTable* hash, int key)
{
    int addr = hashFun(key); // ���ϣ��ַ
    while (hash->elem[addr] != NULLKEY) // �����Ϊ�գ����ͻ
    {
        addr = (addr + 1) % HASHSIZE; // ���Ŷ�ַ��������̽��
        if (addr > HASHSIZE)
            return ERROR;
    }

    hash->elem[addr] = key; // ֱ���п�λ�����ؼ���
    hash->count++;
    return OK;
}
/* ������ϣ�������壬Ҫ��
 * �����ӿڶ���Ϊ��Status SearchHash(HashTable hash, int key, int &addr)
 * ���������hash ��������ϣ��key Ŀ��ؼ��֣� addr Ŀ��ؼ����ڹ�ϣ���еĴ洢λ��
 * ������򼰷���ֵ����������̽����ʽ����key�ڹ�ϣ���е�λ�á�
 *                ���ҳɹ�����OK�����ɹ�����ERROR*/
Status SearchHash(HashTable hash, int key, int *addr)
{
    int ad = hashFun(key), i = 0;
	for(i = 0; i < HASHSIZE; i ++)
	{
		ad = (ad + i) % HASHSIZE;
		if(hash.elem[ad] == key)	
		{
			*addr = ad ;
			return OK;
		}
	 } 
    
    return ERROR;
    //���ú�����������
    
    
}

int main()
{
    int arr[HASHSIZE] = { 12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34 };
    int key;
    int addr;
    int i;
    HashTable hash;
    //��ʼ����ϣ��
    initHashTable(&hash);
    //����ؼ��ֵ���ϣ��
    for (i = 1; i <= ITEMNO; i++)
    {
        if (ERROR == InsertHash(&hash, arr[i-1]))
            printf("Item No %d is already exist.\n", i);
    }
    scanf("%d", &key);
    if (ERROR != SearchHash(hash, key, &addr))
        printf("The hash address of %d is %d.\n", key, addr);
    else
        printf("%d is not in the table.\n", key);

    return 0;
}
