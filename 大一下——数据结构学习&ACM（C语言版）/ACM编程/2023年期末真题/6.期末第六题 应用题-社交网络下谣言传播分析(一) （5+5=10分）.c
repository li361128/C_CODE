#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20  //��󶥵���

typedef struct ArcNode
{
    int adjvex;  //�ñ������ӵĶ����λ�ã����ö���������±꣩
    struct ArcNode *nextarc;  //ָ����һ���ߵ�ָ��
    int info;  // �ߵ�Ȩֵ
} ArcNode;

typedef struct VNode
{
    int data;  //������Ϣ
    ArcNode *firstarc;  //ָ���һ�������ö���ıߵ�ָ��
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph
{
    AdjList vertices;
    int vexnum, arcnum;  //ͼ�ĵ�ǰ�������ͻ���
} ALGraph;

// ������ϵ�����ڽӱ����ݴ洢�ṹ
void CreateUDN(ALGraph *G)
{
    // �벹ȫ���´���
    scanf("%d %d",&G->vexnum, &G->arcnum);
	int i;
	for(i = 1;i <= G->vexnum ;i ++)
	{
		G->vertices[i].data = i;
		G->vertices[i].firstarc = NULL;	
	}
		
	for(i = 0 ;i < G->arcnum ;i ++)
	{
		int v1, v2,weight;
		getchar();
		scanf("%d %d %d",&v1, &v2, &weight);
		
		ArcNode *p1;
		p1 = (ArcNode*)malloc(sizeof(ArcNode));
		if(!p1)	return ;
		p1->adjvex = v2;
		p1->info = weight;
		p1->nextarc = G->vertices[v1].firstarc;
		G->vertices[v1].firstarc = p1;
		
		ArcNode *p2;
		p2 = (ArcNode*)malloc(sizeof(ArcNode));
		if(!p2)	return;
		p2->adjvex = v1;
		p2->info = weight;
		p2->nextarc = G->vertices[v2].firstarc;
		G->vertices[v2].firstarc = p2;
	 } 

}

/* ͳ�ƶ���ıߵ�Ȩֵ֮�� */
/* �������Ϊͼ�ʹ�ͳ�ƵĶ����� */
/* ��������ֵΪ�ö���ı�Ȩֵ֮��  */
int VexCount(ALGraph G, int v)
{
    // �벹ȫ���´���
	ArcNode *p = G.vertices[v].firstarc;
	int sum = 0;
	while(p)
	{
		sum += p->info;
		p = p->nextarc;
	}
	return sum;
}

int main()
{
    ALGraph G;
    int choice;
    static int count = 0;
    CreateUDN(&G);

	int i;
    for(i=0; i<G.vexnum; i++)
    {
        printf("%d ", VexCount(G, i+1));
    }
    printf("\n");
    return 0;
}

