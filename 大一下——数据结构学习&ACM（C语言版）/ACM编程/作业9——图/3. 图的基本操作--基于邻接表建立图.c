#include <stdio.h>

#include <stdlib.h>

#define max_vertex_num 100 //��ඥ�����

typedef char VertexData;

typedef int AdjType ;

typedef int OtherInfo ;


typedef struct Node

{

       int adjvex;  //����û�ָ�򶥵��λ��

       struct Node *nextarc; //������һ��������ָ��

} Node;

 

typedef struct VVertexNode

{

       char data; //���嶥�������

       Node *firstarc;  //����ö����һ������ָ��

} VertexNode[max_vertex_num];

 

typedef struct{

       VertexNode vertex;
       int vexnum, arcnum;

} AdjList;  //�����ڽӱ�

 

int LocateVertex(AdjList  *G,VertexData v)  //�󶥵��λ��

{

       int j=-1,k,i;

       for(k=0;k<G->vexnum;k++)
     		if(G->vertex[k].data == v)	return k; 

       return (j);

}

 

 

void CreateList(AdjList *G) //���ڽӱ�������ͼ

{

       int i,j,k,weight;

       char v1,v2;

       printf("���ڽӱ�������ͼ\n������ͼ�Ķ�������ͻ���\n") ;

       scanf("%d%d",&G->vexnum,&G->arcnum);

       printf("����һ������ͼ�ĸ�������,���ö��Ÿ���\n");

       getchar();

       for(i=0;i<G->vexnum;i++)

    	{

	        scanf("%c",&G->vertex[i].data); //����ͼ�ĸ�������
	
	        G->vertex[i].firstarc=NULL;

    	}

       printf("����һ������ͼ������������֮��Ļ������磬a,b b,c b,d\n");

       int a1,a2;

       for(i=0;i<G->arcnum;i++)

       {

             getchar();

              scanf("%c,%c",&v1,&v2);

              a1 = LocateVertex(G, v1);
              a2 = LocateVertex(G, v2);
              if(a1 == -1 || -1 == a2)	return;
              
              Node *p1 = (Node*)malloc(sizeof(Node));
              p1->adjvex = a2;
              p1->nextarc = G->vertex[a1].firstarc;
              G->vertex[a1].firstarc = p1;
              
              Node *p2 = (Node*)malloc(sizeof(Node));
              p2->adjvex = a1;
              p2->nextarc = G->vertex[a2].firstarc;
              G->vertex[a2].firstarc = p2;
              

       }
       return ;

 

}

 

void print(AdjList *G)  //��ӡ�ڽӱ�����ͼ

{

	int i;
	
	printf("��ӡ�����ڽӱ���������ͼ\n");

    for(i=0;i<G->vexnum;i++)

    {

        printf("%c---->",G->vertex[i].data);

        Node *t;

        t=G->vertex[i].firstarc;

        while(t!=NULL)

        {

            printf(" %c ",G->vertex[t->adjvex].data);

            t=t->nextarc;

        }

      printf("\n");

    }

}

 

 

int main()

{

       AdjList GG;

       CreateList(&GG);

       print(&GG);

       return 0;

}
