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
}TNode,*BitTree;


/**
expr:指向表达式字符串的指针
start:为要装换的表达式字符串的起始位置
end:为要装换的表达式字符串的结束位置的后一位
root_pos:记录当前要转化的表达式生成二叉树的根节点操作符的位置
flag:记录是否是当前搜索在括号里面
multiplication_division_pos:记录当前表达式中括号外面最右端的*、/、^位置
plus_minus_pos:记录当前表达式中括号外面最右端的+、-位置
**/
BitTree buildTree(char expr[],int start,int end)
{
	//printf("输入的表达式:%s\n",expr);
	//printf("表达式长度:%d\n",end-start);
	if(end-start==1)
	{
		BitTree T=(BitTree)malloc(sizeof(TNode));
		T->data=expr[start];
		//printf("[%c]\n",T->data);
		T->lChild=NULL;
		T->rChild=NULL;
		return T;
	}
	
	int root_pos = 0;
    int flag = 0;
    int plus_minus_pos = 0;
    int multiplication_division_pos = 0;
    
    for(int i=start;i<end;i++)
    {
    	if(expr[i]=='(' || expr[i]=='[')
    	{
    		flag++;	
		}
		if(expr[i]==')' || expr[i]==']')
		{
			flag--;
		}
		if(flag==0)
		{
			if(expr[i]=='*' || expr[i]=='/' || expr[i]=='^')
			{
				multiplication_division_pos = i;
			}
			else if(expr[i]=='+' || expr[i]=='-')
			{
				plus_minus_pos=i;
			}
		}
	}

	if((plus_minus_pos==0) && (multiplication_division_pos == 0))
	{
		buildTree(expr,start+1,end-1);
	}
    else
    {
    	if(plus_minus_pos>0)
    	{
    		root_pos=plus_minus_pos;
		}
		else if(multiplication_division_pos>0)
		{
			root_pos=multiplication_division_pos;
		}
		BitTree T=(BitTree)malloc(sizeof(TNode));
		T->data=expr[root_pos];
		//printf("%d\n",root_pos);
		cout<<start<<" "<<root_pos<<endl;
		T->lChild=buildTree(expr,start,root_pos);
    	T->rChild=buildTree(expr,root_pos+1,end);
    	return T;
	}
}
int visit(TNode *&T) 
{
	printf("%c",T->data);
}
int PreOrderTraverse(BitTree T) 
{
	if(T)
	{
		visit(T);
		PreOrderTraverse(T->lChild);
		PreOrderTraverse(T->rChild);
	}
}

int InOrderTraverse(BitTree T) 
{
	if(T)
	{
		InOrderTraverse(T->lChild);
		visit(T);
		InOrderTraverse(T->rChild);
	}
}

int PostOrderTraverse(BitTree T) 
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
    BitTree T;
    T=buildTree(expr,start,end);
    
    printf("\n\n");
    printf("先序序列:\n");
    PreOrderTraverse(T);
    printf("\n\n:");
    printf("中序序列:\n");
    InOrderTraverse(T);
    printf("\n\n");
    printf("后序序列:\n");
    PostOrderTraverse(T);
    //printf("Your result is %d\n",cal(b));   

}
