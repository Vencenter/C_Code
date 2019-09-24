#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	
	stack s;
	Initstack(s);
	printf("请输入表达式：\n");
	ch=getchar();
	while(ch!='\n')
	{
		while(ch>='0' && ch<='9')
		{
			printf("%c",ch);	
			ch=getchar();
			if(!(ch>='0' && ch<='9'))
			{
				printf(" ");	
			}
		
		}
		
	    if(ch==')')
		{
			pop(s,e);
			while(e!='(')
			{
				printf("%c ",e);	
				pop(s,e);
			}
		}
		else if(ch=='+' || ch=='-')
		{
			
			if(empty(s))
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
						printf("%c ",e);	
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
		printf("%c ",e);			
	}
	
	return 0;
} 
