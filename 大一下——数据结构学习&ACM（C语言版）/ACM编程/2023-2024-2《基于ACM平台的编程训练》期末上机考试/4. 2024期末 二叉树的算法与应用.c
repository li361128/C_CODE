#include<stdio.h> 
#include<stdlib.h>


//�������״̬����

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1


typedef char ElemType;
typedef int Status;

//�������Ķ�������洢��ʾ

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;//���Һ���ָ�� 
}BiTNode,*BiTree; 

//����Ԫ������ΪBiTree�Ķ���

typedef struct QNode{
    BiTree Qdata;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//����һ���ն���Q

Status InitQueue(LinkQueue *Q)
{
	(*Q).front=(QueuePtr)malloc(sizeof(QNode));
	if(!(*Q).front) exit(OVERFLOW);
	(*Q).front->next=NULL;
	(*Q).rear=(*Q).front;
	
	return OK;
}

//̽�գ�ǰ��Q����

Status QueueEmpty(LinkQueue Q)
{

	if(Q.front==Q.rear)
	    return TRUE;
	else
	    return FALSE;
}

//����Ԫ��e��Ϊ�µĶ�βԪ�أ�ǰ��Q����

Status EnQueue(LinkQueue *Q,BiTree e)
{

	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));//�����½��
	
	if(!p) exit(OVERFLOW);
	
	p->Qdata=e;
	p->next=NULL;
	(*Q).rear->next=p;
	(*Q).rear=p;
	
	return OK;

}

//�����в��գ�ɾ����ͷԪ�أ���e������ֵ��ǰ��Q����
Status DeQueue(LinkQueue *Q,BiTree *e)
{

	if((*Q).front==(*Q).rear)
	    return ERROR;
	
	QueuePtr p=(*Q).front->next;
	*e=p->Qdata;
	
	(*Q).front->next=p->next;
	if((*Q).rear==p)
	    (*Q).rear=(*Q).front;
	
	free(p);
	return OK;

}


//�������������������
Status CreateBiTree(BiTree *T)
{
	char ch = getchar();//����һ���ַ�
	if(ch == '.') //��.��ʾ�սڵ�
	{
	    *T = NULL;

	}

	else
	
	{
	
		*T = (BiTree)malloc(sizeof(BiTNode));
		
		if(!(*T))
		
			exit(OVERFLOW);
		
		(*T)->data = ch;
		
		CreateBiTree(&(*T)->lchild);
		
		CreateBiTree(&(*T)->rchild);
		
	}
	
	return OK;

}


/*
�����������޵к���ʦ������
���˺þã��������ݶ����ˣ����� 
��С���ܲ�������㣬�����������Ӱɣ�����
С��ʵ��ʵ���ǿ۲����ˣ�������ô�û����۵ģ����� 
��֪����һ����ȫ������õ���ʦ������ 
*/



//���ض����������
int BiTreeDepth(BiTree T)

{

      //�벹�����
	if(!T)
		return 0;
		
	int height_left = BiTreeDepth(T->lchild);
	int height_right = BiTreeDepth(T->rchild);
	
	return (height_left > height_right ? height_left : height_right )+ 1;


}



//�������������
Status InOrderTraverse(BiTree T)
{

    //�벹ȫ����
    if(T)
    {
    	InOrderTraverse(T->lchild);
    	printf("%c ",T->data);
    	InOrderTraverse(T->rchild);
	}
	return OK;

}


//�������������
Status LevelOrderTraverse(BiTree T)
{

	if(!T)
	    return ERROR;
	
	LinkQueue Q;
	InitQueue(&Q);
	
	BiTree p;
	
	EnQueue(&Q,T);
	
	while(QueueEmpty(Q)==FALSE)
	{
		DeQueue(&Q,&p);
		
		printf("%c ",p->data);
		
		if(p->lchild)
		    EnQueue(&Q,p->lchild);
		
		if(p->rchild)
		    EnQueue(&Q,p->rchild);
	
	}
	
	return OK;
}



//���������ָ����n������нڵ�
Status LevelNodeOutput(BiTree T,int n)
{

    //�������
    if(!T)
    	return ERROR;
    	
    if(n == 1)
	{//�ݹ����ֹ�������պ�T���ǵ�n��Ľ�� 
		printf("%c ",T->data);
		return OK;
	 } 
	LevelNodeOutput(T->lchild, n - 1);
	LevelNodeOutput(T->rchild, n - 1);

	return OK;
}



int main()
{

    BiTree T;

    printf("Create BiTree,please input\n");

    //ABC..DE.G..F...          ���Կ���������̨

    //ABE.L...DHM..I..J..      ���Կ���������̨

    CreateBiTree(&T);//�������������չ���д���������

    int ceng;

    scanf("%d",&ceng);

    

    printf("\nInorder traversal ");//�������������

    InOrderTraverse(T);

    printf("\ndeepth of the BiTree  %d\n",BiTreeDepth(T));//��ӡ�������
    

    printf("the node of the %d level is ",ceng);

    LevelNodeOutput(T,ceng);//���ָ����Ľڵ�

    return 0; 

}
