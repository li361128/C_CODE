/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */



#include "stdio.h"    

#include "stdlib.h"  



#include "math.h"  

#include "time.h"



#define OK 1

#define ERROR 0

#define TRUE 1

#define FALSE 0



typedef int Status; /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

typedef char VertexType; /* �������� */

typedef int EdgeType; /* ���ϵ�Ȩֵ */


#define MAXSIZE 9 /* �洢�ռ��ʼ������ */

#define MAXEDGE 6

#define MAXVEX 6

int visited[MAXVEX]; /* ���ʱ�־������ */ 
int parent[MAXVEX]; /*�����ӽ��*/


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



G->numEdges = MAXEDGE;

G->numVertexes = MAXVEX;



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

G->arc[0][4] = 1;

G->arc[0][5] = 1;

G->arc[1][2] = 1;

G->arc[2][3] = 1;

G->arc[3][4] = 1;





for (i = 0; i < G->numVertexes; i++)

{

for (j = i; j < G->numVertexes; j++)

{

G->arc[j][i] = G->arc[i][j];

}

}

}



int LocateVex(MGraph G, VertexType e)

{

// ��ʼ����:ͼG����,u��G�ж�������ͬ����

// �������:��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1

//���亯��
	
	int i = 0;
	for(;i < G.numVertexes;i ++)
	{
		if(G.vexs[i] == e)	return i;
	 } 
	 return -1;

}


Status FindCycle(MGraph G, int v0) 
{
	int i = 0;
	for(i = 0;i < G.numVertexes;i ++)
	{
		visited[i] = 0;
		parent[i] = 0;
	}
	int stack[MAXSIZE];
	int top = -1;
	
	for(i = 0;i < G.numVertexes;i ++)
	{
		if(visited[i] == 0)
		{
			stack[++top] = i;
			while(top != -1)
			{
				int u = stack[top --];
				visited[u] = 1;
				int k = 0;
				for(;k < G.numVertexes; k++)
				{
					if(G.arc[u][k] != 0)
					{
						if(visited[u] == 0)
						{
							stack[++top];
							parent[k] = u;
						}
						else if(k != parent[u])
							return TRUE;
					}
				}
			}
		}
	}
	return 0;
}

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */



int main(void)

{

MGraph G;

int flag=0;

int i;

CreateMGraph(&G);

for(i=0;i< MAXVEX ;i++)

{

visited[i]=0;

parent[i]=-1;

}

flag=FindCycle(G,0);

if(!flag)

{

printf("ͼû�л�·\n");

}

else

{

printf("ͼ�л�·\n");

}

return 0;

}



/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
