#include<stdio.h>
#include<stdlib.h>

#define MAX  256 
typedef char TElemType;
typedef struct BiTNode
{
	
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*Bitree;
Bitree  CreateBitree(char nodes[],int n)
{
	
	BiTNode *r;
	if (nodes[n]=='#')
	{
		return NULL;
		
	}
	r=(BiTNode *)malloc(sizeof(BiTNode));
	r->data=nodes[n];
	r->lchild=CreateBitree(nodes,2*n);
	r->rchild=CreateBitree(nodes,2*n+1);
	return r;
}
void Prefirst(Bitree r) 
{
	if(r!=NULL)
	{
		printf("%c",r->data);
		Prefirst(r->lchild);
		Prefirst(r->rchild);
	}
	
}
void Precenter(Bitree r) 
{
	if(r!=NULL)
	{
		
		Precenter(r->lchild);
		printf("%c",r->data);
		Precenter(r->rchild);
	}
	
}
void Prebehind(Bitree r) 
{
	if(r!=NULL)
	{
		
		Prebehind(r->lchild);
		Prebehind(r->rchild);
		printf("%c",r->data);
		
	}
	
}
int main()
 {

    int i; 
    char c;
    char nodes[MAX];
    Bitree r;
    for(i=0;i<MAX;i++)
    {
    	nodes[i]='#';
	}


	printf("input顺序表的结构，\n结束 ：\n");
    for(i=1;i<MAX;i++)
    {
    	c=getchar();
    	if(c=='\n')
    	{
    		break;
		}
		nodes[i]=c; 
	}
	r=CreateBitree(nodes,1);
	printf("顺序表的结构，成功 ！\n");
		printf("二叉树，先序遍历结果： \n");
	Prefirst(r) ;
	printf("\n");
	printf("二叉树，中序遍历结果：\n");
	Precenter(r) ;
	printf("\n");
	printf("二叉树，后序遍历结果：\n");
	Prebehind(r) ;
	printf("\n");
	


	return 0;
}


