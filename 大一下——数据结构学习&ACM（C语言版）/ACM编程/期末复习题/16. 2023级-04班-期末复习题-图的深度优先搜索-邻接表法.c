/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */



#include "stdio.h"

#include "stdlib.h"



typedef struct EdgeNode//�߱�ڵ�

{

   int adjvex;//�洢�ö����Ӧ���±�

   struct EdgeNode *next;//ָ��ö������һ���ڽӵ�

}EdgeNode;



typedef struct VertexNode//�������

{

   char data;//����

   EdgeNode *firstedge;//�߱�ͷָ��

}VertexNode;



typedef struct//ͼ���ڽӱ�洢�ṹ

{

   VertexNode adjList[4];//��4��VertexNode�������͵Ķ��㣬����һ������adjList[4]��ÿ��Ԫ����VertexNode����

   int numVertexes,numEdges;//ͼ�ж������ͱ�����������4,5

}GraphAdjList;



void CreateALGraph(GraphAdjList *p)//����ͼ���ڽӱ���

{

int k;

int i;

int j;

   GraphAdjList *Gp=(GraphAdjList *)malloc(sizeof(GraphAdjList));

   EdgeNode *pe;

printf("�����붥�����ͱ���:\n");

scanf("%d %d",&(Gp->numVertexes),&(Gp->numEdges));

printf("�����붥����������:\n");

getchar();

   for (k = 0; k < Gp->numVertexes; k++)

{

scanf("%c",&(Gp->adjList[k].data));

getchar();

Gp->adjList[k].firstedge = NULL;//���߱�ͷָ��ָ��NULL������Ϊ0

   }

printf("������ߵ�����:\n");

for (k = 0; k <  Gp->numEdges; k++)//�����߱�

{

scanf("%d %d",&i,&j);

getchar();

       pe = (EdgeNode *)malloc(sizeof(EdgeNode));

       pe->adjvex = j;// �ڽ����Ϊj

       pe->next = Gp->adjList[i].firstedge;//��pe��ָ��ָ��ǰ����ָ��Ľ��

       Gp->adjList[i].firstedge = pe;//����ǰ�����ָ��ָ��pe



       pe = (EdgeNode *)malloc(sizeof(EdgeNode));

       pe->adjvex = i;

       pe->next = Gp->adjList[j].firstedge;

       Gp->adjList[j].firstedge = pe;//����ͼ�ظ����沽��

   }

*p=*Gp;

}



/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void DFSTraverse(GraphAdjList G)
{
   /*�벹�����*/
   int stack[G.numVertexes];
   int top = -1;
   int visit[G.numVertexes];
   int i;
   for(i = 0 ;i <G.numVertexes ;i ++)
   {
   		visit[i] = 0;
   }
   for(i = 0; i < G.numVertexes ;i ++)	
   {
   		if(visit[i] == 0){
   			printf("%c ", G.adjList[i].data);
   			visit[i] = 1;
   			stack[++top] = i;
   			while(top != -1){
   				int u = stack[top --];
   				EdgeNode *p = G.adjList[u].firstedge;
				if(visit[p->adjvex] == 0){
					printf("%c ", G.adjList[p->adjvex].data);
					visit[p->adjvex] = 1;
					stack[++top] = p->adjvex;
				   }
			   }
		   }
	} 
   
   
}
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */



int main(void)

{

   GraphAdjList p;

   CreateALGraph(&p);

   DFSTraverse(p);//����ı���˳����ADCB
	
	printf("\n");

   return 0;

}



/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
