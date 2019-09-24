#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 100
#define addsize 60
typedef int Status;
typedef char elemment;
typedef struct BitNode
{
	elemment data;
	struct BitNode *lchild ,*rchild;
 
}BitNode, *BitTree;

typedef struct {
	BitTree *base;
	BitTree *top;
	int stackSize;
} bitStack;
 

typedef struct {
	int *base;
	int *top;
	int stackSize;
} SqStack;

Status InitStack (SqStack &S)
{
	//S.base=new BitTree[STACK_INIT_SIZE];
	S.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!S.base)
	{
		exit(OVERFLOW);
	}
	*S.top=-1;
	S.base=S.top;
	S.stackSize=STACK_INIT_SIZE;
	return OK;
}
Status InitbitStack (bitStack &S)
{
	//S.base=new BitTree[STACK_INIT_SIZE];
	S.base=S.top=(BitTree *)malloc(STACK_INIT_SIZE*sizeof(BitTree));
	if(!S.base)
	{
		return OVERFLOW;
	}
	S.top=S.base;
	S.stackSize=STACK_INIT_SIZE;
	return OK;
}
Status push(int e,SqStack &S)
{
	if(S.base-S.top>=STACK_INIT_SIZE)
	{
		S.base= (int *)realloc(S.base,(S.stackSize+addsize)*sizeof(int));
		S.top=S.base+S.stackSize;
		S.stackSize=S.stackSize+addsize;
	}
	*S.top++=e;
	
	return OK;
}
Status pushTree(bitStack &S,BitTree e)
{
	if(S.base-S.top>=STACK_INIT_SIZE)
	{
		S.base= (BitTree *)realloc(S.base,(S.stackSize+addsize)*sizeof(BitTree));
		S.top=S.base+S.stackSize;
		S.stackSize=S.stackSize+addsize;
	}
	*S.top++=e;
	//printf("-->%c<--\n",e->data);
 
	return OK;
}

Status pop(SqStack  &S,int &e)
{
	if(S.top==S.base){
		return ERROR;
	}
	e=*--S.top;
 	
	return OK;
}
Status popTree(bitStack  &S,BitTree &e)
{
	if(S.top==S.base){
		return ERROR;
	}
	e=*--S.top;
 	//printf("<--%c-->\n",e->data);
	return OK;
}
Status getTop(bitStack S,BitTree &e)
{
	if(S.top==S.base)
	{
		return ERROR;
	}
	e=*(S.top-1);
	return OK;
}
Status StackEmpty(SqStack S)
{
	if(S.base==S.top)
	{
		return ERROR;
	}
	return OK;
}
Status bitStackEmpty(bitStack S)
{
	if(S.base==S.top)
	{
		return 1;
	}
	return 0;
}
 
void CreateBtree(BitTree &T )
{
    //创建二叉树
    char ch;
    scanf("%c",&ch);
    printf("-->%c\n",ch);
    if(ch==' ') 
	{
		T=NULL;
	} 
    else
	{
        if(!(T=(BitNode * )malloc(sizeof(BitNode)))) 
		{
			exit(OVERFLOW);
		} 
        T->data=ch;
        CreateBtree(T->lchild);
        CreateBtree(T->rchild);
    }
}
 
void fInOrder(BitTree p)
{
    ///非递归的中序遍历
    bitStack S;
	InitbitStack(S);
	while (p!=NULL|| !bitStackEmpty(S))
	{
		if (p!=NULL)
		{
			pushTree(S,p);
 
			p=p->lchild;
		}
		else{
            popTree(S,p);
            printf("%c",p->data);
            p=p->rchild;
		}
	}
}
void fPreOrder(BitTree b)
{
	///非递归的先序遍历
    bitStack bt;
    InitbitStack (bt);
    BitTree p=b;
    if(p!=NULL)
	{
		pushTree(bt,p);
        while(!bitStackEmpty(bt))
		{
            popTree(bt,p);
            printf("%c",p->data);
            if(p->rchild!=NULL)
			{
				pushTree(bt,p->rchild);
			}
            if(p->lchild!=NULL)
			{
				pushTree(bt,p->lchild);
			}
        }
 
    }
 
}

//后序的非递归
void postOrder(BitTree T)
{
	bitStack st;
	InitbitStack(st);
	BitTree e,p=NULL,r=T;
	while(r || !bitStackEmpty(st) )
	{
		if(r)
		{
		pushTree(st, r);
		r = r->lchild;	
		}
		else
		{
			getTop(st,r);
			if(r->rchild && r->rchild!=p)
			{
				r=r->rchild;
			}
			else
			{
			 	popTree(st,e);
			    printf("%c", r->data);
			    p = r;          //记录最近访问过的节点
			    r = NULL;    //节点访问完后，重置p指针
			}
		}
	}
  
}
int main()
{
	BitTree T;
	CreateBtree(T);
	printf("\n先序\n");
	fPreOrder(T);
    printf("\n中序\n");
	fInOrder(T);
	printf("\n后序\n");
	postOrder(T);
	// 采用先序输入，例如124  6  37   ； 

	
	
	
	return 0;
}

///递归方式遍历
 
void preOrder (BitTree T)
{
	if(T)
	{
		printf("%c",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
 
}
void inOrder(BitTree T)
{
    if(T)
	{
        printf("%c",T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
 
}
void baOrder(BitTree T)
{
    if(T)
	{
        printf("%c",T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
 
}
