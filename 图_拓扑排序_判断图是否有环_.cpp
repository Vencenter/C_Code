#include<stdio.h>
#include<stdlib.h>
#include<stack>
#define ElenType int
#define Max 20
using namespace std;

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *next;
	int info;//weight 
}ArcNode;
typedef struct VexNode
{
	int data;
	struct ArcNode *first;
}VexNode,AdjList[20];//1,2,3,4,5
typedef struct
{
	AdjList vertices;
	int vernum,arcvem;
}Graph; 


int indegree[Max];
int createAdj(Graph &p)
{
	printf("请输入顶点个数，边的个数：\n");
	scanf("%d%d",&p.vernum,&p.arcvem);
	//printf("%d,%d",p.vernum,p.arcvem);
	printf("请输入顶点信息，1,2,3...：\n");
	for(int i = 0; i < 20; i++)    
    {
        p.vertices[i].first = NULL;   
    }
    
	for(int i=0;i<p.vernum;i++)
	{
		scanf("%d",&p.vertices[i].data);
		p.vertices[i].first=NULL;
	}
	printf("请输入有向图相连的边：\n");
	int l,r,w;
	ArcNode *T;
	for(int j=0;j<p.arcvem;j++)
	{
		//scanf("%d%d%d",&l,&r,&w);
		scanf("%d%d",&l,&r);
		T=(ArcNode*)malloc(sizeof(ArcNode));
		T->adjvex=r;
		T->info=w;
		T->next=p.vertices[l].first;
		p.vertices[l].first=T;
	}
}
void PrintfGraph(Graph G)
{
	 for(int i = 0; i < G.vernum; i++)
    {
    	int index=G.vertices[i].data;
        ArcNode *p = G.vertices[index].first;
        printf("%d->",G.vertices[i].data);
        while(p)
        {
            printf("%d->",p->adjvex);  
            p = p->next;
        }
        printf("NULL\n");
    }
   
}
void FindInDegree( Graph g, int indegree[])
{                                     //求每个顶点的入度
    int i;
    ArcNode *p;
    for (i=0;i<g.vernum;i++)
    {
    	int index=g.vertices[i].data;
    	indegree[index]=0;
	}
        
    for (i=0;i<g.vernum;i++)
    {
    	int index=g.vertices[i].data;
	    p=g.vertices[index].first;
	    while(p)
	    {
	        indegree[p->adjvex]++;
	        p=p->next;
	    }
    }
}
void TopuSort(Graph  g)
{
	int count;
    int k,i;
    ArcNode *p;
    stack<int>s;
    FindInDegree(g,indegree) ;   //对各顶点求入度
	
    for(i=0;i<g.vernum;i++ )  //将入度为0的顶点压入栈
    {
    	int index=g.vertices[i].data;
    	if(!indegree[index])
    	{
    		s.push(index);
		}   
	}
    count=0; 
    printf ("\n");
	while(!s.empty())
    {
        i=s.top();
        s.pop();
        printf ("%d \n",i);   //输出拓扑排序序列
        count++;
        for(p=g.vertices[i].first;p;p=p->next)
        {
            k=p->adjvex;
            //printf ("+%d \n",k);
            if (!(--indegree[k]))
            {
            	s.push(k);
			}     
        }
    }
    if(count<g.vernum)
	{
    	printf("\n该图有回路\n");
    }
    else
    {
    	printf ("\n该图无回路\n");  
	}
         
}
int main()
{
	Graph p;
	createAdj(p);
	PrintfGraph(p);
	TopuSort(p);
	return 0;
}
