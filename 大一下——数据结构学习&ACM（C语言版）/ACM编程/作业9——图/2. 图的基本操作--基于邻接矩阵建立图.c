#include <stdio.h>

#include <stdlib.h>

#define max_vertex_num 100 //��ඥ�����
#define OK 1
#define ERROR -1

typedef char VertexData;

typedef int AdjType ;

typedef int OtherInfo ;

typedef struct ArcNode

{

       AdjType adj; //������Ȩͼ ��1��ʾ���� 0��ʾ������ �����ڴ�Ȩͼ����ΪȨֵ����

    OtherInfo info;

} ArcNode;

typedef struct

{

  VertexData vertex[max_vertex_num]; //����洢���������

  ArcNode arcs[max_vertex_num][max_vertex_num];//�����ڽӾ���

  int vexnum, arcnum; //���嶥��ĸ����ͱߵĸ���

} AdjMatrix;   //�ڽӾ���Ľṹ��

 

int LocateVertex(AdjMatrix  *G,VertexData v)  //�󶥵��λ��

{

       int j=-1,k,i;

       for(k=0;k<G->vexnum;k++)
       {
       		if(G->vertex[k] == v)	return k;
	   }

       return (j);

}

 

void CreateMatrix(AdjMatrix *G) //���ڽӾ��󴴽�����ͼ

{

       int i,k,j;

       char v1,v2;

       printf("���ڽӾ���������ͼ\n������ͼ�Ķ�������ͻ���\n") ;

       scanf("%d%d",&G->vexnum,&G->arcnum);

  		for(i = 0;i < G->vexnum;i ++)
  		{
  			for(j = 0;j < G->vexnum; j ++)
  			{
  				G->arcs[i][j].adj = 0; 
			  }
		  }

       printf("����һ������ͼ�ĸ�������,���ö��Ÿ���\n");

       getchar();

       for(i=0;i<G->vexnum;i++)

              scanf("%c",&G->vertex[i]); //����ͼ�ĸ�������

       printf("����һ������ͼ������������֮��Ļ������磬a,b b,c b,d\n");

       for(k=0;k<G->arcnum;k++)

       {

              getchar();

              scanf("%c,%c",&v1,&v2);
              
              int a1 = LocateVertex(G, v1);
              int a2 = LocateVertex(G, v2);
              
              if(a1 == -1 || a2 == -1)	return;

			G->arcs[a1][a2].adj = 1;
			G->arcs[a2][a1].adj = 1;
       }

 

}

 

void print(AdjMatrix *G)  //��ӡ�ڽӾ�������ͼ

{

    int i,j;

     printf("��ӡ�����ڽӾ��󴴽�������ͼ\n");

       for(i=0;i<G->vexnum;i++)

    {

        for(j=0;j<G->vexnum;j++)

            printf("%d ",G->arcs[i][j].adj);

            printf("\n");

    }

}

 

 

 

int main()

{

       AdjMatrix G;

       CreateMatrix(&G);

       print(&G);

       return 0;

}


