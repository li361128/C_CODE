#include <stdio.h>

#define MVNum 100                    //��󶥵���
#define OK 1
#define ERROR 0
#define OVERFLOW -2
 
typedef int VerTexType;              //���趥�����������Ϊ���� 

//ͼ���ڽӾ���洢��ʾ
typedef struct{ 
	VerTexType vexs[MVNum];            //����� 
    int arcs[MVNum][MVNum];            //�ڽӾ��� 
    int vexnum,arcnum;                 //ͼ�ĵ�ǰ�����ͱ��� 
}AMGraph;

//ȷ����v��G�е�λ��
int LocateVex(AMGraph G , VerTexType v){
	int i;
	for(i = 0; i < G.vexnum; ++i)
	    if(G.vexs[i] == v)
	        return i;
    return -1;
}


/*
�����������޵к���ʦ������
���˺þã��������ݶ����ˣ����� 
��С���ܲ�������㣬�����������Ӱɣ�����
С��ʵ��ʵ���ǿ۲����ˣ�������ô�û����۵ģ����� 
��֪����һ����ȫ������õ���ʦ������ 
*/


//�����ڽӾ����ʾ��������������G 
int CreateUDN(AMGraph *G)
{ 

 //�����벹ȫ����
 	printf("Please input the total number of vertices and the total number of edges, separated by a space:\n");
 	scanf("%d %d", &G->vexnum, &G->arcnum);
 	int i = 0,j = 0;
 	getchar();
 	printf("Please input the names of the vertices, such as 1:\n");
 	for(i = 0;i < G->vexnum;i ++)
 	{
 		scanf("%d",&G->vexs[i]);
	 }
	 
	 //�ڽӾ���ĳ�ʼ�� 
	 for(i = 0;i < G->vexnum;i ++)
	 	for(j = 0;j < G->vexnum;j ++)
	 		G->arcs[i][j] = 0;
	
	printf("Please input the vertices to which the edge is attached, such as 1 2:\n");
	
 	for(i = 0;i < G->arcnum;i ++)
 	{
 		getchar();
 		int v1, v2;
 		scanf("%d %d", &v1, &v2);
 		
 		int a1 = LocateVex(*G, v1);
 		int a2 = LocateVex(*G, v2);
 		
 		G->arcs[a1][a2] = 1;
 		G->arcs[a2][a1] = 1;//����ͼ���ظ����� 
 		
	 }

	return OK;
} 

//���������G���ڽӾ��� 
void OutputAdjMatrix(AMGraph G)
{ 
 //�����벹ȫ����
	int i ,j;
	printf("\nThe adjacency matrix of the undirected network G is:\n");
	for(i = 0;i < G.vexnum;i ++)
	{
		for(j = 0;j < G.vexnum;j ++)
		{
			printf("%d  ",G.arcs[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//���������G�ĸ�����Ķ� 
void OutputDegree(AMGraph G)
{ 
 //�����벹ȫ����

	int total, i, j;
	for(i = 0;i < G.vexnum;i ++)
	{
		total = 0;//��ÿ������Ķȵļ�������ÿ��ѭ��������һ�� 
		for(j = 0;j < G.vexnum;j ++)
		{
			if(G.arcs[i][j] != 0)//����������1 
				total ++;
		}
		printf("The degree of vertex %d is %d\n", G.vexs[i], total);
	}


}

int main(){
    AMGraph G;
    CreateUDN(&G);
    OutputAdjMatrix(G);
    OutputDegree(G);
    return 0;
}
