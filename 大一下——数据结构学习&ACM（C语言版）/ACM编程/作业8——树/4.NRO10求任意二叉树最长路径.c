#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef struct TNode
{
	char data;
	struct TNode *lchild;
	struct TNode *rchild;
}TNode, *BiTree;

void CreateBiTree(BiTree *T)
{
	char ch;
	ch = getchar();//ѹ��û�л��У�������putchar(ch)��һ�� �������Զ��ݹ���ֹ 
	//if(ch == '\n')	return;
	if(ch == '0')	*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(TNode));
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

int Height_BiTree(BiTree T)
{
	if(!T)	return 0;
	return Max(Height_BiTree(T->lchild), Height_BiTree(T->rchild))+ 1;
	
}

void PrintBiTree(BiTree T)
{
    if(T)
    {    
        PrintBiTree(T->lchild); // �ݹ��ӡ������
        printf("%c", T->data); // ��ӡ��ǰ����ֵ
        PrintBiTree(T->rchild); // �ݹ��ӡ������
    }
}

void PrintPath(char *Path, int Pathlen)
{
	int i = 0;
	//printf("%d",Pathlen); 
	for(i = 0;i < Pathlen;i ++)
	{
		printf("%c->",Path[i]);
	}
	printf("NULL");
}


void printLongestPath(BiTree T,char* path, int pathlen, int count)
{
	if(!T)	return ;
	path[count ++] = T->data;
	if(T->lchild == NULL && NULL == T->rchild && count == pathlen)
	{
		PrintPath(path,pathlen);
		exit(1);
	}
	else
	{
		printLongestPath(T->lchild, path, pathlen, count);
		printLongestPath(T->rchild, path, pathlen, count);
	}
}

void Destroy_BiTree(BiTree *T)
{
	if(*T)
	{
		Destroy_BiTree(&(*T)->lchild);
		Destroy_BiTree(&(*T)->rchild);
		free(*T);
		*T = NULL;
	}
}

int main()
{
	BiTree T;
	
	CreateBiTree(&T);
	
	int pathlen = Height_BiTree(T);
	
	char path[1000];
	
	printLongestPath(T, path, pathlen, 0);
	
	Destroy_BiTree(&T);
	
	return 0;
}
