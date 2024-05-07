#include<stdio.h>

#include<malloc.h>

#define OK 1
#define ERROR 0


typedef char TElemType;
typedef int Status;


typedef struct Tnode{

TElemType data;

struct Tnode *leftchild;

struct Tnode *rightchild;

}TNode, *BiTree;  



//����������չ���й�����������

//a[ ]Ϊ������չ�������飬nΪ���鳤��

//

int count=0;

Status CreateBiTree1(BiTree *T, char a[], int n)

{
	if(count >= n)	return OK;
	if(a[count] == '#')
	{
		*T = NULL;
		count ++;
	}
	else
	{
		(*T) = (BiTree)malloc(sizeof(TNode));
		(*T)->data = a[count ++];
		CreateBiTree1(&(*T)->leftchild,a,n);
		CreateBiTree1(&(*T)->rightchild,a,n);
	}
	return OK;

} 



//��ӡ������

void PrintBiTree(BiTree T)

{
	if(T)
	{
		printf("%c",T->data);
		PrintBiTree(T->leftchild);
		PrintBiTree(T->rightchild);
	 } 
}

void PrintPath(char *Path,int pathlen)
{
	int i = 0;
	for(; i < pathlen; i ++)
	{
		printf("%c",Path[i]);
	}
	printf("\n");
}


void printAllPaths(BiTree T, char *path, int pathlen)
{
	if(!T)	return ;
	path[pathlen ++] = T->data;
	if(T->leftchild == NULL && T->rightchild == NULL)
	{
		PrintPath(path, pathlen);
	}
	else
	{
		printAllPaths(T->leftchild, path, pathlen);
		printAllPaths(T->rightchild, path, pathlen);
	}
}



int main()

{
	char arr[1000],len = 0;
	while(scanf("%c",&arr[len]) != EOF)
	{
		if(arr[len] == '\n') // �����뻻�з��������ѭ��
            break;
        len ++;      
	}
	
	BiTree T = NULL;
	CreateBiTree1(&T,arr,len);
	
	//PrintBiTree(T);
	
	char path[1000]; // �洢��ǰ·��
    int pathLen = 0; // ��ǰ·������
    printAllPaths(T, path, pathLen);
	
	return 0;

}
