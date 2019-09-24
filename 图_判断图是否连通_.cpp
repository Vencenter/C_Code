#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_VER 100//最大顶点数

typedef struct edgnode
{//邻接点域
	int vertex;
	struct edgnode *next;
}enode;

typedef struct vnode
{
	char data;
	enode *link;
}vlist[MAX_VER];

typedef struct node2
{
  int v;    
  struct node2 *next;
}qnode;

typedef struct 
{
  qnode *front,*rear;
}linkQueue;

int n;
int visited[MAX_VER];//用于标志顶点是否被访问过
vlist g;
linkQueue queue;

void Init(linkQueue *q)
{
	q->front=q->rear=NULL;
}

void InsertQueue(linkQueue * &q,int e)
{
	qnode * node;
	node=(qnode*)malloc(sizeof(qnode));
	node->v=e;
	node->next=NULL;
	if(NULL==q->front)
	{
		q->front=q->rear=node;
	}
	else
	{
		q->rear->next=node;
		q->rear=node;
	}
}

int outQueue(linkQueue * &q)
{
	int e;
	qnode *temp;
	if(NULL==q->front)
		e=NULL;
	else
	{
		temp=q->front;
		e=temp->v;
		q->front=temp->next;
		free(temp);
	}
	return e;
}

//创建无向图
void createGraphic(vlist g)
{
	int e,i=1,start,end;
	enode *p;
	printf("请输入顶点数(n)和边数(e):\n");
	scanf("%d%d",&n,&e);
	while(i<=n) //初始化顶点表
	{
		fflush(stdin);
		printf("请输入第 %d 个顶点:",i);
		g[i].data=getchar();
		g[i].link=NULL;
		i++;
	}
	i=1;
	while(i<=e)//采用头插法初始化邻接点域
	{
		fflush(stdin);
		printf("请输入第 %d 条边的起点和终点:",i);//无向图是双向的 1-2 2-1
		scanf("%d%d",&start,&end);
		p=(enode *)malloc(sizeof(enode));
		p->vertex=end;
		p->next=g[start].link;
		g[start].link=p;
		p=(enode *)malloc(sizeof(enode));
		p->vertex=start;
		p->next=g[end].link;
		g[end].link=p;
		i++;
	}
}

//Breadth First Search 广度优先搜索 相当于树的层次遍历
void BFS(linkQueue *queue,int i)
{
	int temp;
	enode *p;
	InsertQueue(queue,i);
	while(NULL!=queue->front)
	{
		temp=outQueue(queue);
		if(!visited[temp])
		{
			printf("%d ",temp);
			visited[temp]=1;
		}
		p=g[temp].link;
		while(NULL!=p)
		{
			if(!visited[p->vertex])
			{
				InsertQueue(queue,p->vertex);
			}
			p=p->next;
		}
	}
}

//Depth First Search 深度优先搜索 相当于树的先序遍历
void DFS(vlist g,int i)
{
	enode *p;
	printf("%c ",g[i].data);
	visited[i]=1;
	p=g[i].link;
	while(NULL!=p)
	{
		if(!visited[p->vertex])
		{
			DFS(g,p->vertex);
		}
		p=p->next;
	}
}

//遍历每个顶点
void DFSGraphic(vlist g)
{
	int i;
	memset(visited,0,n);
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			//DFS(g,i);
			BFS(&queue,i);
		}
	}
	printf("\n");	
}

int main()
{
	Init(&queue);
	createGraphic(g);
	DFSGraphic(g);
	return 0;
}
