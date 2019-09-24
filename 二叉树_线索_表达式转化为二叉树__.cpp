#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct  TNode
{
    char data;
    struct TNode * lChild;//左孩子 
    struct  TNode * rChild;//右孩子 
}TNode;


/**
expr:指向表达式字符串的指针
start:为要装换的表达式字符串的起始位置
end:为要装换的表达式字符串的结束位置的后一位
root_pos:记录当前要转化的表达式生成二叉树的根节点操作符的位置
flag:记录是否是当前搜索在括号里面
multiplication_division_pos:记录当前表达式中括号外面最右端的*、/、^位置
plus_minus_pos:记录当前表达式中括号外面最右端的+、-位置
**/
void buildTree(TNode *&T,char expr[],int start,int end)
{
	//printf("输入的表达式:%s\n",expr);
	//printf("表达式长度:%d\n",end-start);
	if(end-start==1)
	{
		//if(isdigit(expr[start]))
		{
		T=(struct TNode *)malloc(sizeof(struct TNode));
		T->data=expr[start];
		printf("%c->1->\n",T->data);
		T->lChild=NULL;
		T->rChild=NULL;
		return;
		}
	}
	else if (end-start==0)
	{
		T=NULL;
		return;
	}
	
	int root_pos = 0;
    int arc_pos_l = 0;
    int arc_pos_r = 0;
    int plus_minus_pos = 0;
    int multiplication_division_pos = 0;
    
    for(int i=start;i<end;i++)//l里面不冲突，可以全用if 
    {
	    	if(expr[i]=='(' || expr[i]=='[' )
	    	{
	    		arc_pos_l=i;
			}
			else if(expr[i]==')' || expr[i]==']')
	    	{
	    		arc_pos_r=i;
			}
			else if(expr[i]=='*' || expr[i]=='/' || expr[i]=='^')
			{
				multiplication_division_pos = i;
			}
			else if(expr[i]=='+' || expr[i]=='-')
			{
				plus_minus_pos=i;
			}
	}
	//cout<<" "<<plus_minus_pos<<" "<<multiplication_division_pos<<endl;
	if(arc_pos_r>0)//按照优先级）、+-、*/、（顺序
	{
		root_pos=arc_pos_r;
	}
    else if(plus_minus_pos>0)
    {
    	root_pos=plus_minus_pos;
	}
	else if(multiplication_division_pos>0)
	{
		root_pos=multiplication_division_pos;
	}
	else if(arc_pos_l>0)
	{
		root_pos=arc_pos_l;
	}
	
	T=(struct TNode *)malloc(sizeof(struct TNode));
	T->data=expr[root_pos];
	printf("%c--\n",T->data);
	buildTree(T->lChild,expr,start,root_pos);
    buildTree(T->rChild,expr,root_pos+1,end);
	
}
int visit(TNode *&T) 
{
	printf("%c",T->data);
}
int PreOrderTraverse(TNode *&T) 
{
	if(T)
	{
		visit(T);
		PreOrderTraverse(T->lChild);
		PreOrderTraverse(T->rChild);
	}
}

int InOrderTraverse(TNode *&T) 
{
	if(T)
	{
		InOrderTraverse(T->lChild);
		visit(T);
		InOrderTraverse(T->rChild);
	}
}

int PostOrderTraverse(TNode *&T) 
{
	if(T)
	{
		PostOrderTraverse(T->lChild);
		PostOrderTraverse(T->rChild);
		visit(T);
	}
}
int main()
{
	char expr[200];
	int start,end;
    printf("请输入表达式:");
    scanf("%s", expr);
    
    start=0;
    end=strlen(expr);
    
    struct TNode* T;
    buildTree(T,expr,start,end);
    
    printf("\n\n");
    printf("先序序列:\n");
    PreOrderTraverse(T);
    printf("\n\n");
    printf("中序序列:\n");
    InOrderTraverse(T);
    printf("\n\n");
    printf("后序序列:\n");
    PostOrderTraverse(T);
    
    //printf("Your result is %d\n",cal(b));   

}
