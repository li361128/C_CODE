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

typedef int EdgeType; /* ���ϵ�Ȩֵ���� */


#define MAXSIZE 9 /* �洢�ռ��ʼ������ */

#define MAXEDGE 15

#define MAXVEX 9


typedef struct

{

	VertexType vexs[MAXVEX]; /* ����� */
	
	EdgeType arc[MAXVEX][MAXVEX];/* �ڽӾ��󣬿ɿ����߱� */
	
	int numVertexes, numEdges; /* ͼ�е�ǰ�Ķ������ͱ��� */

}MGraph;


/* �õ��Ķ��нṹ�뺯��********************************** */


/* ѭ�����е�˳��洢�ṹ */

typedef struct

{

	int data[MAXSIZE];
	
	int front;    	/* ͷָ�� */
	
	int rear;/* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */

}Queue;


/* ��ʼ��һ���ն���Q */

Status InitQueue(Queue* Q)

{

	Q->front = 0;

	Q->rear = 0;

	return  OK;

}


/* ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */

Status QueueEmpty(Queue Q)

{

	if (Q.front == Q.rear) /* ���пյı�־ */
	
		return TRUE;
	
	else
	
		return FALSE;

}


/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */

Status EnQueue(Queue* Q, char e)

{

	if ((Q->rear + 1) % MAXSIZE == Q->front)/* ���������ж� */

		return ERROR;

	Q->data[Q->rear] = e;/* ��Ԫ��e��ֵ����β */

	Q->rear = (Q->rear + 1) % MAXSIZE;/* rearָ�������һλ�ã� */

/* ���������ת������ͷ�� */

	return  OK;

}


/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */

Status DeQueue(Queue* Q, char* e)

{

	if (Q->front == Q->rear)/* ���пյ��ж� */
	
		return ERROR;
	
	*e = Q->data[Q->front];/* ����ͷԪ�ظ�ֵ��e */
	
	Q->front = (Q->front + 1) % MAXSIZE;/* frontָ�������һλ�ã� */
	
	/* ���������ת������ͷ�� */
	
	return  OK;

}

/* ****************************************************** */



void CreateMGraph(MGraph* G)

{

	int i, j;


	G->numEdges = 15;

	G->numVertexes = 9;


/* ���붥����Ϣ����������� */

	G->vexs[0] = 'A';

	G->vexs[1] = 'B';

	G->vexs[2] = 'C';

	G->vexs[3] = 'D';

	G->vexs[4] = 'E';

	G->vexs[5] = 'F';

	G->vexs[6] = 'G';

	G->vexs[7] = 'H';

	G->vexs[8] = 'I';



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

	G->arc[1][8] = 1;

	G->arc[1][6] = 1;


	G->arc[2][3] = 1;

	G->arc[2][8] = 1;


	G->arc[3][4] = 1;

	G->arc[3][7] = 1;

	G->arc[3][6] = 1;

	G->arc[3][8] = 1;

	G->arc[4][5] = 1;

	G->arc[4][7] = 1;

	G->arc[5][6] = 1;

	G->arc[6][7] = 1;

	for (i = 0; i < G->numVertexes; i++)	
	{	
		for (j = i; j < G->numVertexes; j++)		
		{		
			G->arc[j][i] = G->arc[i][j];		
		}	
	}
}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void BFSTraverse(MGraph G)
{
   /*�벹�����*/
  int i;
  Queue Q;
  InitQueue(&Q);
  int visit[G.numVertexes];
  for(i = 0; i < G.numVertexes ;i ++)
  {
  	visit[i] = FALSE;
  }
  
  for(i = 0 ;i < G.numVertexes ;i ++)
  {
  	if(!visit[i])
	  {
	  	printf("%d ", G.vexs[i]);
	  	visit[i] = TRUE;
	  	EnQueue(&Q, i);
	  	while(!QueueEmpty(Q))
	  	{
	  		char j;
	  		DeQueue(&Q, &j);
	  		int k = 0;
	  		for(;k < G.numVertexes ;k ++)
			  {
	  				if(G.arc[j][k] != 0 && visit[k] == FALSE)
	  				{
	  					printf("%c ", G.vexs[k]);
	  					visit[k] = TRUE;
	  					EnQueue(&Q, k);
					  }
			  }
		  }
	   } 
  }
}
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


int main(void)

{

	MGraph G;

	CreateMGraph(&G);

	printf("��ȱ�����");

	BFSTraverse(G);

	printf("\n");

	return 0;

}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */


