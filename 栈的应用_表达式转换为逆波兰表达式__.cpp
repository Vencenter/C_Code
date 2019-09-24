#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 50
#define ElemType char
#define STACKINCEMENT 20
#define STACK_INIT_SIZE 50

#define Status int
#define OK 1
#define ERROR 0
#define OVERFLOW -2


typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}stack;

typedef struct
{
	ElemType *base;
	int front,rear;
}Queueptr;

Status InitQueue(Queueptr &Q) 
{
	Q.base=(ElemType*)malloc(MaxSize*sizeof(ElemType));
	if(!Q.base)
	{
		exit(-1);
	}
	Q.front=Q.rear=0;
}
Status QueueEmpty(Queueptr Q) 
{
	if(Q.front==Q.rear)
	{
		return true;
	}
	return false;
}
Status QueueLength(Queueptr Q) 
{
	return (Q.rear-Q.front+MaxSize)%MaxSize;
}
Status GetHead(Queueptr Q,ElemType &e) 
{
	e=Q.base[Q.front];
	return e;
}
Status EnQueue(Queueptr &Q,ElemType e) 
{
	if((Q.rear+1)%MaxSize==Q.front)
	{
		return -1;
	}
	Q.base[Q.rear]=e;
	//printf("Queue-->%d\n",Q.base[Q.rear]);
	Q.rear=(Q.rear+1)%MaxSize;
	return 0;
}
Status DeQueue(Queueptr &Q,ElemType &e) 
{
	if(Q.rear==Q.front)
	{
		return -1;
	}
	e=Q.base[Q.front];
	
	Q.front=(Q.front+1)%MaxSize;
	//printf("Queue<--%d\n",e);
	return e;
}

Status Initstack(stack &s)
{
	s.top=s.base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!s.top)
	{
		exit(OVERFLOW);
	}
	s.stacksize=STACK_INIT_SIZE;
	
}
Status push(stack &s,ElemType e)
{
	if(s.top-s.base>=s.stacksize)
	{
		s.top=(ElemType *)realloc(s.base,(s.stacksize+STACKINCEMENT)*sizeof(ElemType));
		s.top=s.base+s.stacksize;
		s.stacksize+=STACKINCEMENT;
	}
	*s.top++=e;
	return OK;
	
}

Status pop(stack &s,ElemType &e)
{
	if(s.top-s.base==0)
	{
		return ERROR;
	}
	e=*--s.top;
	return OK;	
}

ElemType get_top(stack &s)
{
	if(s.top-s.base==0)
	{
		return ERROR;
	}

	return *(s.top-1);;
	
}

Status empty(stack s)
{
	if(s.top==s.base)
	{
		return true;
	}
	return false;
	
}

Status stacklen(stack s)
{

	return s.top-s.base;
	
}

int main()
{
	//Expression_eval();
	char ch,e;
	int data;
	
	stack s,expr;
	Queueptr str;
	int i,index=0;
	
	char sttr[150];
	Initstack(s);
	Initstack(expr);
	InitQueue(str);
	
	printf("请输入表达式：\n");
	ch=getchar();
	while(ch!='\n')
	{
		i=0;
		while(ch>='0' && ch<='9')
		{
			data=0;
			sttr[i++]=ch;	
			ch=getchar();
			if(!(ch>='0' && ch<='9'))
			{
				
				for(int j=0;j<i;j++)
				{
					data=data*10+sttr[j];
				}
				EnQueue(str,data);
				push(expr,data);
			}
		
		}
		
	    if(ch==')')
		{
			pop(s,e);
			while(e!='(')
			{
				EnQueue(str,e);
				push(expr,e);
				pop(s,e);
			}
		}
		else if(ch=='+' || ch=='-')
		{
			
			if(empty(s) )
			{
				push(s,ch);
				
			}
			else
			{
				do
				{
					pop(s,e);
					if( e=='(') 
					{
						push(s,e);
					}
					else
					{
						EnQueue(str,e);
						push(expr,e);	
					}
					
				}while(!empty(s) && e!='(');
				push(s,ch);
			}
		}
		else if(ch=='*' || ch=='/' || ch=='(')
		{	
			push(s,ch);
		}
		else if(ch=='\n')
		{
			break;
		}
		else
		{
			return -1;
		}
		
		ch=getchar();	
	} 
	while(!empty(s))
	{
		pop(s,e);
		EnQueue(str,e);
		push(expr,e);		
	}
	printf("\n");
	while(!empty(expr))
	{
		pop(expr,e);
		printf("%c ",e);			
	}
	printf("\n");
	while(!QueueEmpty(str))
	{
		DeQueue(str,e);
		printf("%c ",e);			
	}

	return 0;
} 
