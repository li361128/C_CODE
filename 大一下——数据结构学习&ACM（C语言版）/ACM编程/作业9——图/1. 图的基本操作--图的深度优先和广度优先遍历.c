//
// Created by lct2023 on 2024/5/26.
//
#include <stdio.h>

#include <stdlib.h>

#define max_vertex_num 100 //��ඥ�����

typedef char VertexData;

typedef int AdjType;

typedef int OtherInfo;

int visisted[max_vertex_num] = {0}; //��������ȱ���ʹ��

int visisted1[max_vertex_num] = {0};//��������ȱ���ʹ��


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


typedef struct
{

    VertexNode vertex;
	int vexnum, arcnum;

} AdjList;  //�����ڽӱ�



int LocateVertex(AdjList *G, VertexData v)  //�󶥵��λ��

{

    int j = -1, k, i;

    for (k = 0; k < G->vexnum; k++)
    {
    	if(G->vertex[k].data == v)	return k;
	}

    return (j);

}


void CreateList(AdjList *G) //���ڽӱ�������ͼ

{

    int i, j, k, weight;

    char v1, v2;

    printf("���ڽӱ�������ͼ\n������ͼ�Ķ�������ͻ���\n");

    scanf("%d%d", &G->vexnum, &G->arcnum);

    printf("����һ������ͼ�ĸ�������,���ö��Ÿ���\n");

    getchar();

    for (i = 0; i < G->vexnum; i++)
    {

        scanf("%c", &G->vertex[i].data); //����ͼ�ĸ�������

        G->vertex[i].firstarc = NULL;

    }

    printf("����һ������ͼ������������֮��Ļ������磬a,b b,c b,d\n");

    int a1, a2;

    for (i = 0; i < G->arcnum; i++)
    {

        getchar();

        scanf("%c,%c", &v1, &v2);

        a1 = LocateVertex(G, v1);
        a2 = LocateVertex(G, v2);
        if(a1 == -1 || a2 == -1)	return ;
        
        Node* p1 = (Node*)malloc(sizeof(Node));
        p1->adjvex = a2;
        p1->nextarc = G->vertex[a1].firstarc;
        G->vertex[a1].firstarc = p1;
        
        Node* p2 = (Node*)malloc(sizeof(Node));
		p2->adjvex = a1;
		p2->nextarc = G->vertex[a2].firstarc;
		G->vertex[a2].firstarc = p2; 

    }


}


void print(AdjList *G)  //��ӡ�ڽӱ�����ͼ

{

    int i;

    printf("��ӡ�����ڽӱ���������ͼ\n");

    for (i = 0; i < G->vexnum; i++)
    {

        printf("%c---->", G->vertex[i].data);

        Node *t;

        t = G->vertex[i].firstarc;

        while (t != NULL)
        {

            printf(" %c ", G->vertex[t->adjvex].data);

            t = t->nextarc;

        }

        printf("\n");

    }

}


void DFS(AdjList *g, int i)
{//�����ڵ㿪ʼ����������ȱ���

    Node *t;

    printf("%c", g->vertex[i].data);

    visisted[i] = 1;

    t = g->vertex[i].firstarc;

    while (t)
    {

        int w = t->adjvex;
        if(!visisted[w])
        	DFS(g, w);
        t = t->nextarc;

    }

}


//void BFS(AdjList *g, int i)
//{//�����ڵ㿪ʼ���й�����ȱ���
//
//    int q[max_vertex_num];//����ģ����ʹ����Ķ���
//
//    int front, rear;//frontΪ���е�ͷ����rearΪ���е�β��
//
//    int temp;//�ñ������ڽ��ܳ��ӵ�Ԫ��
//
//    front = 0;
//
//    rear = 0;
//
//    printf("%c", g->vertex[i].data);
//
//    visisted1[i] = 1;
//
//    q[rear++] = i;//ģ�����
//
//    Node *p;
//
//    while (rear > front)
//    {
//
//        temp = q[front++];//ģ�����
//
//        p = g->vertex[temp].firstarc;
//
//        if(!visisted1[temp])
//        {
//        	visisted1[temp] = 1;
//        	printf("%c", g->vertex[temp].data);
//        	q[rear++] = temp;//ģ�����
//		}
//
//    }
//}

void BFS(AdjList *g, int i)
{
    int q[max_vertex_num]; // ����ģ����ʹ����Ķ���
    int front = 0, rear = 0; // frontΪ���е�ͷ����rearΪ���е�β��

    printf("%c", g->vertex[i].data);
    visisted1[i] = 1;
    q[rear++] = i; // ģ�����

    Node *p;

    while (rear > front)
    {
        int temp = q[front++]; // ģ�����
        p = g->vertex[temp].firstarc;

        while (p != NULL)
        {
            int neighbor = p->adjvex;
            if (!visisted1[neighbor])
            {
                printf("%c", g->vertex[neighbor].data);
                visisted1[neighbor] = 1;
                q[rear++] = neighbor; // ģ�����
            }
            p = p->nextarc;
        }
    }
}


int main()
{

    AdjList GG;

    CreateList(&GG);

    print(&GG);

    printf("��A��ʼ��������ȱ���(DFS):\n");

    DFS(&GG, 0);

    printf("\n��A��ʼ�Ĺ�����ȱ���(BFS):\n");

    BFS(&GG, 0);

    printf("\n");

    return 0;

}
