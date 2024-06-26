/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "stdio.h"

#include "stdlib.h"

#include "string.h"

#define TRUE 1

int visited[4];

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

visited[k]=0;

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

int LocateVex(GraphAdjList G,char u)

{ // ��ʼ����: ͼG����,u��G�ж�������ͬ����

  // �������: ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1

  int i;

  for(i=0;i < G.numVertexes;i ++)
  {
  		if(G.adjList[i].data == u)	return i;
  }

    return -1;

}

int NextAdjVex(GraphAdjList G,int v,int w)

{ // ��ʼ����: ͼG����,v��G��ĳ������,w��v���ڽӶ���

  // �������: ����v��(�����w��)��һ���ڽӶ������š�

  // ��w��v�����һ���ڽӵ�,�򷵻�-1

  EdgeNode *p;

  p=G.adjList[v].firstedge;

  while(p&&p->adjvex!=w)  

  {

  p=p->next;

  }

  if(!p||!p->next)  //û�ҵ�w��w�����һ���ڽӵ�

    return -1;

  else   //p->adjvex==w

    return p->next->adjvex;

}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

//���亯������

void isConnected(GraphAdjList G, int v1, int v2, int *flag)
{
	if(v1 == v2)	
	{
		*flag = TRUE;
		return ;
	}
	EdgeNode *p;
	p=G.adjList[v1].firstedge;
	while(p)
	{
		int res = NextAdjVex(G, p->adjvex, v2);
		if(res == -1)
			p = p->next;
		else
		{
			*flag = 1;
			return;
		}
	}	
}



/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

int main(void)

{

   GraphAdjList p;

char u1;

char u2;

int v1;

int v2;

int flag=0;

   CreateALGraph(&p);

printf("������������:\n");

scanf("%c %c",&u1,&u2);

v1=LocateVex(p,u1);

v2=LocateVex(p,u2);

isConnected(p,v1,v2,&flag);

if(flag)

{

printf("������ͨ\n");

}

else

{

printf("���㲻��ͨ\n");

}

   return 0;

}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
