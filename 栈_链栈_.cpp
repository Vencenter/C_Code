#include<stdlib.h>
#include<stdio.h>
#define SElemType int
#define STACK_INIT_SIZE 50
typedef struct stack
{
	SElemType *top,*base;
	int stacksize;
}SqStack;

void InitStack(SqStack &S)
{
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType ));
	if(!S.base)
	{
		exit(-1);
	}
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
}
int Push(SqStack &S,int e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType *)realloc(S.base,STACK_INIT_SIZE*sizeof(SElemType ));
		if(!S.base)
		{
			exit(-1);
		}
		S.top=S.base+S.stacksize;
		S.stacksize+=S.stacksize;
	}
	
	*S.top++=e;
	printf("----> %d\n",e);
	return 0;
}
int GetTop(SqStack S)
{
	if(S.top==S.base)
	{
		return -1;
	}
	
	return *(S.top-1);
}
int StackLength(SqStack S)
{
	return S.top-S.base;
}
int StackEmpty(SqStack S)
{
	if(S.top==S.base)
	{
		return 1;
	}
	return 0;
}
int Pop(SqStack &S,int &e)
{
	if(S.top==S.base)
	{
		return -1;
	}
	
	e=*--S.top;
	printf("<---- %d\n",e);
	return e;
	
}
int main()
{
	SqStack p;
	int i,e;
	InitStack(p);
	for(i=0;i<10;i++)
	{
	 Push(p,i);	
	}
	
	printf("stack_len->%d,stack_top->%d\n",StackLength(p),GetTop(p));
	while(not StackEmpty(p))
	{
		Pop(p,e);
	}
	

	return 0;
}
