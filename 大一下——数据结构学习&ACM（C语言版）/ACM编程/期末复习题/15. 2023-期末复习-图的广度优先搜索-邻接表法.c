/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */


#include "stdio.h"

#include "stdlib.h"


#define OK 1

#define ERROR 0

#define TRUE 1

#define FALSE 0



#define MAXSIZE 8 /* �洢�ռ��ʼ������ */

#define MAXEDGE 9 /* �洢�ռ��ʼ������ */


#define MAXVEX 8


typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */


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

    VertexNode adjList[MAXVEX];//��4��VertexNode�������͵Ķ��㣬����һ������adjList[4]��ÿ��Ԫ����VertexNode����

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

Status DeQueue(Queue* Q, int* e)

{

	if (Q->front == Q->rear)/* ���пյ��ж� */
		
		return ERROR;
	
	*e = Q->data[Q->front];/* ����ͷԪ�ظ�ֵ��e */
	
	Q->front = (Q->front + 1) % MAXSIZE;/* frontָ�������һλ�ã� */
	
	/* ���������ת������ͷ�� */
	
	return  OK;

}

/* ****************************************************** */


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void BFSTraverse(GraphAdjList G)
{
   /*�벹�����*/
   int i , j ;
   int visit[MAXVEX] ;
   for(i = 0; i < MAXVEX; i++)
   {
   		visit[i] = FALSE;
   }
   Queue Q;
   InitQueue(&Q);
   for(i = 0; i < G.numVertexes; i ++)
   {
   		if(visit[i] == FALSE)
   		{
   			printf("%c ",G.adjList[j].data);
			visit[j] = TRUE;
   			EnQueue(&Q, i);
			while(!QueueEmpty(Q))
			{
				int j;
				DeQueue(&Q, &j);
				EdgeNode *p = G.adjList[j].firstedge;
                while (p)
                {
                    if (!visit[p->adjvex])
                    {
                        visit[p->adjvex] = TRUE;
                        printf("%c ", G.adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }
                    p = p->next;
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

    BFSTraverse(p);//����ı���˳����ADCB

	printf("\n");

    return 0;

}


/* PRESET CODE END - NEVER TOUCH CODE ABOVE */


