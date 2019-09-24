#include<stdio.h>
#include<stdlib.h>
#define MAX 50  

typedef struct TreeNode
{
	char data;
	struct TreeNode *lchild,*rchild;
}TreeNode;

int createTree(TreeNode *&T)
{
	char ch;
	scanf("%c",&ch);
	printf("-->%c",ch);
	if(ch==' ')
	{
		T=NULL;
	}
	else
	{
		T=(TreeNode*)malloc(sizeof(TreeNode));
		if(!T)
		{
			exit(-1); 
		} 
		T->data=ch;
		createTree(T->lchild);
		createTree(T->rchild);
	}
	return 0;
}
int visit(TreeNode *&T)
{
	printf("%c",T->data);
}
int firstPrint(TreeNode *&T)
{
	if(T)
	{
		visit(T);
	firstPrint(T->lchild);
	firstPrint(T->rchild);
	}
	
}
int centerPrint(TreeNode *&T)
{
	if(T)
	{	
	centerPrint(T->lchild);
	visit(T);
	centerPrint(T->rchild);
	}
	
}
int behindPrint(TreeNode *&T)
{
	if(T)
	{
		
	behindPrint(T->lchild);
	behindPrint(T->rchild);
	visit(T);
	}
	
}
int main()
{	
	TreeNode *T;
	
	printf("请先序输入二叉树,' '代表NULL:\n");//12 6  43 7  ;
	createTree(T);
	printf("\n先序遍历：\n");
	firstPrint(T);
	printf("\n中序序遍历：\n");
	centerPrint(T); 
	printf("\n后序遍历：\n");
	behindPrint(T); 
	/*
     1
    / \
   2   4
   \  / \
   6 3  7
	*/
	return 0;
} 
