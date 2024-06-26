#include<stdio.h>

#include<stdlib.h>

 

typedef enum

{

    False,

    True

}Bool;

 

typedef struct Node

{

       int data;

       struct Node *lchild;

       struct Node *rchild;

}NODE,*BSTree;

/*

��ָ��pTree��ָ�Ķ����������еݹ���ҹؼ���Ϊkey��Ԫ�أ�

�����ҳɹ����򷵻�ָ���Ԫ�ؽڵ��ָ�룬���򷵻�NULL

*/

 

BSTree search(BSTree pTree,int key)

{

	if(!pTree)	return NULL;
	if(pTree->data == key)	return pTree;
	else if(pTree->data < key)	return search(pTree->rchild, key);
	else if(pTree->data > key)	return search(pTree->lchild, key); 
	return NULL;
}

 

Bool search_BSTree(BSTree pTree,int key,BSTree parent,BSTree *p)

{

       if(!pTree)         //���pTreeΪNULL������Ҳ��ɹ�                                                                                  

       {     //������������գ���pTreeΪNULL�����

              *p = parent;

              return False;

       }

       else             //���򣬼�������

       {                                                     

              if(key == pTree->data)                    //�����ȣ�����ҳɹ�                                  

              {

                     *p = pTree;

                     return True;

              }

              else if(key < pTree->data)        //���������еݹ����

                     return search_BSTree(pTree->lchild,key,pTree,p);   

              else                                           //���������еݹ����

                     return search_BSTree(pTree->rchild,key,pTree,p);

    }

}

/*

�ݹ���������������������õ�Ԫ�ش�С�����������е�����

*/

 

void in_traverse(BSTree pTree)

{

       if(pTree)

       {

              if(pTree->lchild)

                     in_traverse(pTree->lchild);

              printf("%d ",pTree->data);

              if(pTree->rchild)

                     in_traverse(pTree->rchild);      

       }

}

 

Bool insert(BSTree *pTree,int key)

{

       BSTree p;

       if(!search_BSTree(*pTree,key,NULL,&p))              //�������ʧ�ܣ���ִ�в������

       {

              //Ϊ�½ڵ����ռ䣬���Ը���ֵ
			
            BSTree res ;
			res = (BSTree)malloc(sizeof(NODE));
			if(!res)	return False;	
			res->data = key;
			res->lchild =NULL;
			res->rchild = NULL;
			if(!p)
			{
				//�����pTree�����滻��p 
				//�������ʹ�� p������ p �� NULL���޷��������ĸ��ڵ㡣 
				*pTree = res;// ������Ҫ�������ĸ��ڵ�ָ�� 
			}
			else if(p->data > key)	
			{
				p->lchild = res;
			}
			else 
			{
				p->rchild = res;
			}
			return True;
       }

       else

              return False;

}

/*

���������ĳ�Ϊlen��arr���飬��������Ԫ�ص�˳�򹹽�һ�ö���������

*/

 

BSTree create_BSTree(int *arr,int len)

{

       BSTree pTree = NULL;

       int i;

       //��˳������ڵ���뵽������������

       for(i=0;i<len;i++)

              insert(&pTree,arr[i]);

       return pTree;

}

 

int main()

{

       int i;

       int num;

       int key;

       int *arr;

       BSTree pTree;

       printf("������ڵ������\n");

       scanf("%d",&num);

 

       //����num������

       arr = (int *)malloc(num*sizeof(int));

       printf("������������%d�����������뻥����ȣ���\n",num);

       for(i=0;i<num;i++)

              scanf("%d",arr+i);

 

       //��������ö�����������ʹ���ݰ��մ�С�����˳�����

       pTree = create_BSTree(arr,num);

       printf("��������ö����������Ľ����");

       in_traverse(pTree);

       printf("\n");

 

       //���Ҹ���������

      

       printf("������Ҫ���ҵ�������\n");

       scanf("%d",&key);

       if(search(pTree,key))

              printf("���ҳɹ�\n");

       else

              printf("���Ҳ���������\n");

       return 0;

}
