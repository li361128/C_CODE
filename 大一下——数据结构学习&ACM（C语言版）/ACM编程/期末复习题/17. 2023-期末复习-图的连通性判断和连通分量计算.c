/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


#include "stdio.h"    

#include "stdlib.h"   


#include "math.h"  

#include "time.h"


#define OK 1

#define ERROR 0

#define TRUE 1

#define FALSE 0


typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */


typedef char VertexType; /* �������� */

typedef int EdgeType; /* ���ϵ�Ȩֵ */


#define MAXSIZE 9 /* �洢�ռ��ʼ������ */

#define MAXEDGE 4

#define MAXVEX 6


typedef struct

{

VertexType vexs[MAXVEX]; /* ����� */

EdgeType arc[MAXVEX][MAXVEX];/* �ڽӾ��󣬿ɿ����߱� */

int numVertexes, numEdges; /* ͼ�е�ǰ�Ķ������ͱ��� */

}MGraph;


int count =0;//��ͨ�����ĸ�����ȫ�ֱ���


void CreateMGraph(MGraph* G)

{

int i, j;


	G->numEdges = 4;

	G->numVertexes = 6;


/* ���붥����Ϣ����������� */

	G->vexs[0] = 'A';

	G->vexs[1] = 'B';

	G->vexs[2] = 'C';

	G->vexs[3] = 'D';

	G->vexs[4] = 'E';

	G->vexs[5] = 'F';



for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */

{

for (j = 0; j < G->numVertexes; j++)

{

			G->arc[i][j] = 0;

}

}


	G->arc[0][1] = 1;

	G->arc[0][5] = 1;

	G->arc[1][2] = 1;

	G->arc[3][4] = 1;



for (i = 0; i < G->numVertexes; i++)

{

for (j = i; j < G->numVertexes; j++)

{

			G->arc[j][i] = G->arc[i][j];

}

}


}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

int DFSTraverse(MGraph G)
{
   /*�벹�����*/
	int i;
	int stack[G.numVertexes];
	int top = -1;
	int visit[G.numVertexes];
	for(i = 0;i < G.numVertexes ;i ++)
	{
		visit[i] = 0;
	}
	for(i = 0;i < G.numVertexes;i ++)
	{
		if(visit[i] == 0)
		{
			visit[i] = 1;
			stack[++top] = i;
			while(top != -1){
				int u = stack[top --];
				int k = 0;
				for(k = 0;k < G.numVertexes;k ++)
				{
					if(G.arc[u][k] != 0 && visit[k] == 0)
					{
						visit[k] = 1;
						stack[++top] = k;
					}
				}
			}  
			count++;
		}
	}
	return count > 1 ? 0 : 1 ;
}
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


int main(void)

{

MGraph G;

int connect;

CreateMGraph(&G);

	connect=DFSTraverse(G);

if(connect)

{

		printf("������ͼȫ��ͨ:\n");

}

else

{

		printf("������ͼ����ȫ��ͨ,����ͨ��������Ϊ��%d\n",count);

}

return 0;

}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
