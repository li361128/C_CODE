#include <stdio.h>

#include <string.h>

#include<malloc.h>

typedef struct node         //������������͵Ķ���

{

    char data;

    struct node *lchild;      //�����������ָ��

    struct node *rchild;      //��������Һ���ָ��

} BinTNode;


BinTNode *CreateBinTree()  //���������������������У�������������

{

    BinTNode *t;

    char ch;

    ch = getchar();

    if (ch == '0')             //�������0����������

        t = NULL;

    else
    {
		t = (BinTNode*)malloc(sizeof(BinTNode));
		//if(!t)	exit(-1);
		t->data = ch;
		t->lchild = CreateBinTree();
		t->rchild = CreateBinTree(); 

    }


    return t;

}


void ListBinTree(BinTNode *t)                  //�ù�����ʾ������

{

    if (t != NULL)
    {

        printf("%c", t->data);                //��ӡ����

        if (t->lchild != NULL || t->rchild != NULL)
        {

            printf("(");                      //��ӡ������������

            ListBinTree(t->lchild);           //�ù�����ʾ������

            if (t->rchild != NULL)

                printf(",");                    //��ӡ��������������֮��Ķ���

            ListBinTree(t->rchild);         //�ù�����ʾ������

            printf(")");                    //��ӡ������������

        }

    }

}


void preorder(BinTNode *t)   //�Զ����������������  ע��: �μ��е�Visit(T->data)�ڴ�

//���� printf("%3c",t->data),��ͬ��

{


 	if(t)
	{
		printf("%3c",t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}



}


void inorder(BinTNode *t) //�Զ����������������

{
	if(t)
	{
		inorder(t->lchild);
		printf("%3c",t->data);
		inorder(t->rchild);
	}

}


void postorder(BinTNode *t) //�Զ��������к������

{
	if(t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%3c",t->data);
	}



}


int Height(BinTNode *t)//�ڵ����

{
    if(!t)	return 0;
    return (Height(t->lchild) > Height(t->rchild) ? Height(t->lchild) : Height(t->rchild)) + 1;


}





//���������ܽ����

int Size(BinTNode *t)
{


    if(!t)	return 0;
	return 1 + Size(t->lchild) + Size(t->rchild);


}



//��������Ҷ�ӽ����

int Leaf(BinTNode *t)
{

	if(!t)	return 0;
	if(t->lchild == NULL && NULL == t->rchild)	return 1;
	return 	Leaf(t->lchild) + Leaf(t->rchild);
    

}



//�����������ֵ

int Max(BinTNode *t)
{

    if (t == NULL) return 0;

    if (t->lchild == NULL && t->rchild == NULL)

        return t->data;

    int l = Max(t->lchild);

    int r = Max(t->rchild);

    return l > r ? l : r;

}


int main()
{

    BinTNode *t = NULL;

    //int TreeHeight;

    printf("��������������,������0��ʾ��\n");

    t = CreateBinTree();

    printf("������ʾ�Ķ������������\n");

    ListBinTree(t);                          //���ö������Ĺ�����ʾ����

    printf("\n��������ǰ��������Ϊ:\n");

    preorder(t);                             //���ö����������������

    printf("\n������������������Ϊ:\n");

    inorder(t);                              //���ö����������������

    printf("\n�������ĺ���������Ϊ:\n");

    postorder(t);                            //���ö����������������

    printf("\n");

    printf("�������ĸ߶�Ϊ��%d\n", Height(t));

    printf("���������ܽ����Ϊ��%d\n", Size(t));

    printf("��������Ҷ�ӽ����Ϊ��%d\n", Leaf(t));

    printf("�����������ֵΪ��%c\n", Max(t));
    
    return 0;

}
