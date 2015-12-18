#include <stdio.h>
#include <malloc.h>
#define INF 32767       //INF表示∞
typedef int InfoType;
typedef int Vertex;
#define MAXV 50     //最大顶点个数

//以下定义邻接矩阵类型
typedef struct
{
	int nunber;       //顶点编号
	InfoType info;     //顶点其他信息
} VertexType;      //顶点类型

typedef struct      //图的定义
{
	int edges[MAXV][MAXV];    //邻接矩阵
	int n, e;         //顶点数，弧数
	VertexType vexs[MAXV];   //存放顶点信息
} MGraph;       //图的邻接矩阵类型

//以下定义邻接表类型
typedef struct ANode           //弧的结点结构类型
{
	int adjvex;              //该弧的终点位置
	InfoType info;           //该弧的相关信息,这里用于存放权值
	struct ANode *nextarc;    //指向下一条弧的指针
} ArcNode;

typedef struct Vnode         //邻接表头结点的类型
{
	Vertex data;            //顶点信息
	int count;                //存放顶点入度,只在拓扑排序中用
	ArcNode *firstarc;        //指向第一条弧
} VNode;

typedef VNode AdjList[MAXV]; //AdjList是邻接表类型
typedef struct
{
	AdjList adjlist;         //邻接表
	int n, e;                 //图中顶点数n和边数e
} ALGraph;                   //图的邻接表类型

//将邻接矩阵g转换成邻接表G
void MatToList(MGraph g, ALGraph *&G)
{
	int i, j, n = g.n;       //n为顶点数
	ArcNode *p;
	G = (ALGraph *)malloc(sizeof(ALGraph));
	// for (i=0;i<n;i++)      //给邻接表中所有头结点的指针域置初值
	// G->adjlist[i].firstarc=NULL;
	for (i = 0; i < n; i++)      //检查邻接矩阵中每个元素
	for (j = n - 1; j >= 0; j--)
	if (g.edges[i][j] != 0)     //邻接矩阵的当前元素不为0
	{
		p = (ArcNode *)malloc(sizeof(ArcNode)); //创建一个结点*p
		p->adjvex = j;
		p->info = g.edges[i][j];
		p->nextarc = G->adjlist[i].firstarc;   //将*p链到链表后
		G->adjlist[i].firstarc = p;
	}
	G->n = n; G->e = g.e;
}

void ListToMat(ALGraph *G, MGraph &g)
//将邻接表G转换成邻接矩阵g
{
	int i, n = G->n;
	ArcNode *p;
	for (i = 0; i < n; i++)
	{
		p = G->adjlist[i].firstarc;
		while (p != NULL)
		{
			g.edges[i][p->adjvex] = p->info;
			p = p->nextarc;
		}
	}
	g.n = n; g.e = G->e;
}
void DispMat(MGraph g)
//输出邻接矩阵g
{
	int i, j;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
		if (g.edges[i][j] == INF)
			printf("%3s", "∞");
		else
			printf("%3d", g.edges[i][j]);
		printf("\n");
	}
}
void DispAdj(ALGraph *G)
//输出邻接表G
{
	int i;
	ArcNode *p;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%3d: ", i);
		while (p != NULL)
		{
			printf("%3d", p->adjvex); //输出该弧的终点位置
			p = p->nextarc;
		}
		printf("\n");
	}
}
//以下主函数用作调试
void main()
{
	int i, j;
	MGraph g, g1;
	ALGraph *G;
	int A[6][6] = {
		{ 0, 5, 0, 7, 0, 0 },
		{ 0, 0, 4, 0, 0, 0 },
		{ 8, 0, 0, 0, 0, 9 },
		{ 0, 0, 5, 0, 0, 6 },
		{ 0, 0, 0, 5, 0, 0 },
		{ 3, 0, 0, 0, 1, 0 } };
	g.n = 6; g.e = 10;
	for (i = 0; i < g.n; i++)
	for (j = 0; j < g.n; j++)
		g.edges[i][j] = A[i][j];
	printf("\n");
	printf(" 有向图G的邻接矩阵:\n");
	DispMat(g);
	G = (ALGraph *)malloc(sizeof(ALGraph));
	printf(" 图G的邻接矩阵转换成邻接表:\n");
	MatToList(g, G);
	DispAdj(G);
	printf(" 图G的邻接表转换成邻接邻阵:\n");
	for (i = 0; i < g.n; i++)
	for (j = 0; j < g.n; j++)
		g1.edges[i][j] = 0;
	ListToMat(G, g1);
	DispMat(g1);
	printf("\n");
}


