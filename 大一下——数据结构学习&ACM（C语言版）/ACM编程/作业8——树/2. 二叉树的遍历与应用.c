#include <stdio.h>

#include <malloc.h>

#include <stdlib.h>

#define OVERFLOW 0

#define OK 1

typedef struct node         //������������͵Ķ���

{

    char data;

    struct node *lchild; //�����������ָ��

    struct node *rchild; //��������Һ���ָ��

} BinTNode, *BTNode;


BinTNode *CreateBinTree()  //���������������������У�������������

{

    BinTNode *t;

    char ch;

    ch = getchar();

    if (ch == '0')             //�������0����������

        t = NULL;

    else
    {

        t = (BinTNode *) malloc(sizeof(BinTNode)); //��������*t�ռ�

        if (!t) exit(OVERFLOW);

        t->data = ch;                                  //���������ch���������������

        t->lchild = CreateBinTree();                        //��������

        t->rchild = CreateBinTree();                        //��������

    }

    return t;

}


void preorder(BTNode t)   //�Զ��������������������ʾ����ӡ���� %3c

{

    if (t != NULL)
    {

        printf("%3c", t->data);  //��ӡ�ڵ�����

        preorder(t->lchild);   //�������������

        preorder(t->rchild);   //�������������

    }

}


void inorder(BTNode t) //�Զ��������������������ʾ����ӡ���� %3c

{

    //�����벹ȫ����
    if (t != NULL)
    {

        inorder(t->lchild);   //������������� 
        
        printf("%3c", t->data);  //��ӡ�ڵ�����

        inorder(t->rchild);   //�������������

    }

}



//��������Ҷ�ӽ����

int Leaf(BTNode t)
{

    //�����벹ȫ����
    if(!t)	return 0;
    if(t->lchild == NULL && NULL == t->rchild)		return 1;
	return Leaf(t->lchild) + Leaf(t->rchild);
}



//�����������ֵ

int Max(BTNode t)
{

    //�����벹ȫ����
    if(!t)	return 0;
    if(t->lchild == NULL && NULL == t->rchild)	return t->data;
    return Max(t->lchild) > Max(t->rchild) ? Max(t->lchild) : Max(t->rchild);

}


    int main()
    {

        BTNode t = NULL;

        //int TreeHeight;

        t = CreateBinTree();

        preorder(t);                             //���ö����������������

        printf("\n");

        inorder(t);                              //���ö����������������

        printf("\n");

        printf("%d\n", Leaf(t));

        printf("%c\n", Max(t));


    }
