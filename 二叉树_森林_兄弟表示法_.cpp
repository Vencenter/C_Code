#include<stdio.h>
#include<stdlib.h>
#define max 40
#define  ElemType char
//typedef  char ElemType;
typedef struct TNode
{
	ElemType data;
	struct TNode *child, *brother;
}TNode,*Tree;

void PreOrder(TNode *head)		// 前序遍历
{
	if(head==NULL)
	{
		return;
	}
	printf("%c ",head->data);
	PreOrder(head->child);
	PreOrder(head->brother);
}
 
void InOrder(TNode *head)		// 中序遍历
{
	if(head==NULL)return;
	InOrder(head->child);
	printf("%c ",head->data);
	if(head->child)
	{
		InOrder(head->child->brother);
	}
}
 
void PostOrder(TNode *head)		// 后序遍历
{
	if(head==NULL)
	{
		return;
	}
	PostOrder(head->child);
	printf("%c ",head->data);
	PostOrder(head->brother);
}


void addNode(TNode *parent,TNode *child)		
{
	if(parent->child!=NULL)	
	{
		parent->child->brother=child;
	}			
	else 
	{
		parent->child = child;		
	}		
}

int createTree(TNode *&T)
{
	int n;
	printf("请输入森林节点数量:\n");
	scanf("%d",&n);
	printf("请依次输入节点名称:\n");
	char node_name; 
	T = (TNode*)malloc(n*sizeof(TNode));
	for(int i=0;i<n;i++)
	{
		scanf("%c",&node_name);
		while(node_name=='\n') 
		{
			scanf("%c",&node_name);
		}
		T[i].data=node_name;
		T[i].child=NULL;
		T[i].brother=NULL;
	}
	printf("请输入父子节点下标:\n");
	int parent,child;
	while(true)
	{
		scanf("%d %d",&parent,&child);
		if(parent==-1 || child== -1)
		{
			break;
		}
		addNode(&T[parent],&T[child]);	
	} 
	
	
}
int FindChild(TNode *T)
{
	char node_name; 
	printf("请输入要寻找孩子节点的父节点的名称:\n");
	scanf("%c",&node_name);
	while(node_name=='\n')
	{
		scanf("%c",&node_name);	
	}
	int tag=-1;
	for(int i=0;i<20;i++)
	{
		if(node_name==T[i].data)
		{
			tag=i;
			break;
		}
	}
	if(tag==-1)
	{
		return -1;
	}
	printf("%c的孩子节点为：",T[tag].data);
	while(T[tag].child)
	{
		printf("-->%c",T[tag].child->data);
		T[tag].child=T[tag].child->child;	
	}
	printf("\n");
}
void Find(TNode *T,TNode *p,char node_name)
{
	TNode *T1=T,*p1=p;
	if(p==NULL)
	{
		return;
	}
	
	if(p->data==node_name)
	{
		if(T->child==p)
		{
			printf("父节点为:%c ",T->data);
			return;
		}
		else
		{
			Find(T1->child,p1->child,T->data);
			Find(T1->child,p1->brother,T->data);
			return;
		}
		
		
	}
	
	Find(T->child,p->child,node_name);
	Find(T->child,p->brother,node_name);
	
}
int FindParent(TNode *T)
{
	TNode *p=T->child;
	char node_name; 
	printf("请输入要寻找父节点的孩子节点的名称:\n");
	scanf("%c",&node_name);
	while(node_name=='\n')
	{
		scanf("%c",&node_name);	
	}
	Find(T,p,node_name);
}
int n=0;
int yenum(TNode *head)		// 前序遍历
{
	if(head)
	{
		if(head->child==NULL )
		{
			printf("-->%c\n",head->data);
			n++;
		}
		
	}	
	if(head==NULL)
	{
	
		return 0;
	}
	yenum(head->child);
	yenum(head->brother);
	return n;
}
int main()
{	
	TNode *T;
	
	createTree(T);

	printf("前序遍历： ");
	PreOrder(&T[0]);
	printf("\n");
 
	printf("中序遍历： ");
	InOrder(&T[0]);
	printf("\n");
 
 
	printf("后序遍历： ");
	PostOrder(&T[0]);
	printf("\n");
	
	FindChild(T);
	FindParent(T);//有问题，右孩子 找不到 
	printf("叶子节点数量:%d\n",yenum(T));;
	
	return 0;
} 

