#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20  //��󶥵���
#define TH 4  // ���ζ���ֵ
#define OVERFLOW -1
#define ERROR 0
#define OK 1

typedef int Status;
typedef int QElemType;
// �ڽӾ���
typedef struct ArcCell
{
    unsigned int weight;  //Ȩֵ
}AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

// ������
typedef struct MGraph
{
    AdjMatrix arcs;  //�ڽӾ���
    int vexnum, arcnum;  //������������
}MGraph;

// �����н��
typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
   QueuePtr front,rear; /* ��ͷ����βָ�� */
}LinkQueue;

int visited[MAX_VERTEX_NUM]; // �����Ƿ񱻷��ʹ�
int credit[MAX_VERTEX_NUM]; // ���������ֵ
int times[MAX_VERTEX_NUM]; // �����յ�ҥ��ʱ��

Status InitQueue(LinkQueue *Q)
{ /* ����һ���ն���Q */
    (*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(QNode));
    if(!(*Q).front)
        exit(OVERFLOW);
    (*Q).front->next=NULL;
    return OK;
}

Status QueueEmpty(LinkQueue Q)
{ /* ��QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE */
    return(Q.front==Q.rear);
}

Status EnQueue(LinkQueue *Q,QElemType e)
{ /* ����Ԫ��eΪQ���µĶ�βԪ�� */
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
    if(!p) /* �洢����ʧ�� */
        exit(OVERFLOW);
    p->data=e;
    p->next=NULL;
    (*Q).rear->next=p;
    (*Q).rear=p;
    return OK;
}

Status DeQueue(LinkQueue *Q,QElemType *e)
{ /* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
    QueuePtr p;
    if((*Q).front==(*Q).rear)
        return ERROR;
    p=(*Q).front->next;
    *e=p->data;
    (*Q).front->next=p->next;
    if((*Q).rear==p)
        (*Q).rear=(*Q).front;
    free(p);
    return OK;
}

/* �����罻���� */
void CreateUDN(MGraph *G)
{
    scanf("%d %d",&G->vexnum, &G->arcnum);
    int i, j;
    //��ʼ���ڽӾ��� 
    for(i = 0; i < G->vexnum; i++)
    {
        for(j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].weight = 0;
        }
    }
    
    for(i = 0; i < G->arcnum ;i ++)
    {
        int v1, v2, weight;
        getchar();
        scanf("%d %d %d",&v1, &v2, &weight);
        G->arcs[v1 - 1][v2 - 1].weight = weight;
        G->arcs[v2 - 1][v1 - 1].weight = weight;
    }
}

/* ��������������磬����ҥ�Դ���·�������ζȡ�����ʱ�� */
/* �������ڽӾ���ͼ������ҥ�ԵĶ����� */
void BFSGraph(MGraph G, int v)
{
    int i, j;
    LinkQueue Q; // ��������
    InitQueue(&Q);
    for(i = 0; i < G.vexnum; i++)
    {
        visited[i] = 0;
        credit[i] = 0;
        times[i] = 0; // ��ʼ��Ϊ-1��ʾδ������
    }
    visited[v] = 1;
    credit[v] = 0;
    times[v] = 1;
    printf("%d ", v + 1);
    EnQueue(&Q, v);

    while(!QueueEmpty(Q))
    {
        int u;
        DeQueue(&Q, &u);

        for(j = 1; j < G.vexnum; j++)
        {
            if(G.arcs[u][j].weight != 0 && !visited[j])
            {
                credit[j] += G.arcs[u][j].weight;
                
                if (!visited[j] && credit[j] >= TH)
                {
                    visited[j] = 1;
                    times[j] = times[u] + 1;
                    EnQueue(&Q, j);
                    printf("%d ", j + 1);
                }
            }
        }
    }
}

int main()
{
    MGraph G;
    int i,j;
    /* �������� */
    CreateUDN(&G);
    /* ����ڽӾ��� */
    for(i=0; i< G.vexnum; i++){
        for(j=0; j< G.vexnum; j++)
            printf("%d ", G.arcs[i][j].weight);
        printf("\n");
    }
    /* ������ȱ����������� */
    BFSGraph(G, 0);
	printf("\n");
    /* ����������ҥ�����ζ� */
    for(i = 0; i< G.vexnum; i++)
    {
        printf("%d ", credit[i]);
    }
    printf("\n");
    /* ����������ҥ�Դ���ʱ�� */
    for(i = 0; i< G.vexnum; i++)
    {
        printf("%d ", times[i]);
    }
    printf("\n");
    return 0;
}

