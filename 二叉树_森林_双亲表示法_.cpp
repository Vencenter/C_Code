#include<stdio.h>
#include<stdlib.h>
#define max 40
#define  ElemType char
//typedef  char ElemType;
typedef struct
{
	ElemType data;
	int parent;
}TNode;
typedef struct TreeNode
{
	TNode nodes[max];
	int n;
}TreeNode;

int createTree(TreeNode &T)
{
	printf("请输入森林节点数量:\n");
	int i,j,n,num;
	char name;
	scanf("%d",&n);
	T.n=n; 
	//根节点parent设为-1 
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个节点名称及父节点的序号:\n",i);
		scanf("%c",&name);
		while(name=='\n')
		{
			scanf("%c",&name);	
		}
		scanf("%d",&num);
		T.nodes[i].data=name;
		T.nodes[i].parent=num;
	}	
	T.nodes[0].parent=-1;
}
int printTree(TreeNode T)
{
	printf("一共%d个节点名:\n",T.n);
	for(int i=0;i<T.n;i++)
	{
		printf("第%d个节点:\n",i);
		printf("[%d]-->%c->%d\n",i,T.nodes[i].data,T.nodes[i].parent);
	}
}

int FindChild(TreeNode T)
{
	char node_name; 
	printf("请输入要寻找的孩子节点的父节点的名称:\n");
	scanf("%c",&node_name);
	while(node_name=='\n')
	{
		scanf("%c",&node_name);	
	}
	int tag;
	for(int i=0;i<T.n;i++)
	{
		if(T.nodes[i].data==node_name)
		{
			tag=i;
			break;
		}
	}
	for(int i=0;i<T.n;i++)
	{
		if(T.nodes[i].parent==tag)
		{
			printf("孩子节点为:%c\n",T.nodes[i].data);
		}
	}
	return 0;
}

int FindParent(TreeNode T)
{
	char node_name; 
	printf("请输入要寻找的父节点节点的名称:\n");
	scanf("%c",&node_name);
	while(node_name=='\n')
	{
		scanf("%c",&node_name);	
	}
	for(int i=0;i<T.n;i++)
	{
		if(T.nodes[i].data==node_name)
		{
			printf("父节点为:%c\n",T.nodes[T.nodes[i].parent].data);
			break;
		}
		
	}
	return -1;
}

int main()
{	
	TreeNode T;
	createTree(T);
	printTree(T);
	FindChild(T);
	FindParent(T);

	return 0;
} 
