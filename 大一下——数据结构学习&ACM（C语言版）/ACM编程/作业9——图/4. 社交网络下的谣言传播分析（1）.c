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
	int i, w, a1, a2;
	for(i = 1;i <= G->vexnum;i ++)
		G->vertices[i].firstarc = NULL;
	
	for(i = 1; i <= G->arcnum ;i ++)
	{
		getchar();
		scanf("%d %d %d",&a1, &a2, &w);
		if(a1 <= 0 || a1 > G->vexnum || a2 <= 0 || a2 > G->vexnum)
			return;
		
		ArcNode *p1 = (ArcNode*)malloc(sizeof(ArcNode));
		p1->adjvex = a2;
		p1->info = w;
		p1->nextarc = G->vertices[a1].firstarc;
		G->vertices[a1].firstarc = p1->nextarc;
		
		ArcNode *p2 = (ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex = a1;
		p2->info = w;
		p2->nextarc = G->vertices[a2].firstarc;
		G->vertices[a2].firstarc = p2->nextarc;
		
	}
}

/* ͳ�ƶ���ıߵ�Ȩֵ֮�� */
/* �������Ϊͼ�ʹ�ͳ�ƵĶ����� */
/* ��������ֵΪ�ö���ı�Ȩֵ֮��  */
int VexCount(ALGraph G, int v)
{
    // �벹ȫ���´���
    int sum = 0;
    ArcNode *p = G.vertices[v].firstarc;
    while (p != NULL) 
	{
        sum += p->info;
        p = p->nextarc;
    }
    return sum;
    

}

int main()
{
    ALGraph G;
    int choice, i;
    static int count = 0;
    CreateUDN(&G);

    for(i=0; i<G.vexnum; i++)
    {
        printf("%d ", VexCount(G, i+1));
    }
    printf("\n");
    return 0;
}

