#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAXN 15		//顶点个数的最大值
#define MAXM 40		//边的个数的最大值
struct edge			//边
{
	int a, b, w;
}edges[MAXM];		//边的数组

int parent[MAXN];	//parent[i]为顶点i所在集合对应的树中的根结点
int n, m;			//顶点个数、边的个数
int i, j;			//循环变量

void UFset()		//初始化 
{
	for(i = 1; i <= n; i++)
	{
		parent[i] = -1;
	} 
}
int Find(int x)		//查找并返回结点x所属集合的根结点
{
	int s;			//查找位置
	for(s = x; parent[s] >=0; s = parent[s]) ;
	while(s != x)	//优化方案——压缩路径，使后续的查找操作加速
	{
		int tmp = parent[x];
		parent[x] = s;
		x = tmp;
	}
	return s;
}

//运用并查集，将两个不同集合的元素进行合并，使两个集合中任意两个元素都连通
void Union(int R1, int R2)
{
	int r1 = Find(R1), r2 = Find(R2);		//r1和r2分别为R1和R2的根结点
	int tmp = parent[r1] + parent[r2];		//两个集合结点数之和（负数）
	//如果R2所在树结点个数 > R1所在树结点个数（注意parent[r1]是负数）
	if(parent[r1] > parent[r2])
	{
		parent[r1] = r2;
		parent[r2] = tmp;
	}
	else
	{
		parent[r2] = r1;
		parent[r1] = tmp;
	}
}
int cmp(const void *a, const void *b)		//实现从小到大的比较函数
{
	edge aa = *(const edge *)a, bb = *(const edge *)b;
	return aa.w-bb.w;
}
void Kruskal()
{
	
	int sumweight = 0;		//生成树的权值
	int num = 0;			//已选用的边的数目
	UFset();
	for(i = 0; i < m; i++)
	{   
	    printf("(%d , %d) -> %d\n", edges[i].a, edges[i].b, edges[i].w);	
		if(Find(edges[i].a) != Find(edges[i].b))
		{
			printf("\t\t%d %d %d\n", edges[i].a, edges[i].b, edges[i].w);
			sumweight += edges[i].w; 
			num++;
			Union(edges[i].a, edges[i].b);
		}
	
	}
	printf("The weight of MST is : %d\n", sumweight);		

}


int main()
{
	
	m=7;
	n=5;

	edges[0].a=1;
	edges[0].b=2;
	edges[0].w=3;
	edges[1].a=1;
	edges[1].b=3;
	edges[1].w=7;
	edges[2].a=1;
	edges[2].b=5;
	edges[2].w=1;
	edges[3].a=2;
	edges[3].b=3;
	edges[3].w=9;
	edges[4].a=2;
	edges[4].b=4;
	edges[4].w=7;
	edges[5].a=2;
	edges[5].b=5;
	edges[5].w=5;	
	edges[6].a=3;
	edges[6].b=4;
	edges[6].w=6;	
	
	printf("The edges chosen are :\n");
	qsort(edges, m, sizeof(edges[0]), cmp);	//对边按权值从小到大排序
	
	
	//for(int i = 0; i < m; i++)
		//printf("(%d , %d) -> %d\n", edges[i].a, edges[i].b, edges[i].w);	//读入边的起点和终点
		
	
	


	Kruskal();
}

/*kural(Graph &G,Edge *edge,int *parent)
{
	head_sort(edge);
	Initial(parent)
	for(int i=0;i<G.arcnum;i++)
	{
		if(Find(parent[i].a)!=Find(parent[i].b))
		{
			Union(parent,a,b) ;
		}
	}
}*/
