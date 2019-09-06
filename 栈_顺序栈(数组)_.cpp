
#include<stdio.h>
#include<stdlib.h>

#define Max 100
#define False -1
#define True 1

typedef struct Stack
{
	int data[Max];
	int top;
}stack;

int init_stack(stack &s)
{
	s.top=-1;
	return 0;	
}
int push_stack(stack &s,int e)
{
	if(s.top>Max-1)
	{
		return False;
	}
	s.data[++s.top]=e;
	printf("pop-->%d\n",e);
	return True;
}

int pop_stack(stack &s,int e)
{
	if(s.top>-1)
	{
	    e=s.data[s.top--];
	    printf("push-->%d\n",e);
	    return True;
	}
	return False;
}

int top_stack(stack s)
{
	if(s.top>-1)
	{
	    return s.data[s.top];
	}
	return False;
}
int print_stack(stack s,int e)
{
	while(s.top!=-1)
	{
	    e=s.data[s.top--];
	    printf("push-->%d\n",e);
	}
	return True;
	
}
int len_stack(stack s)
{
	return s.top+1;
}
int empty_stack(stack s)
{
	if(s.top!=-1)
	{
	    return NULL;
	}
	return True;
	
}
int main()
{
	stack s;
	init_stack(s);
	int i,j,e;
	for(i=0;i<5;i++)
	{
	push_stack(s,i);
	}
	printf("top_pos--->%d\n",top_stack(s));
	printf("push_len-->%d\n",len_stack(s));
	while(empty_stack(s)!=NULL)
	{
	pop_stack(s,e);
	}
	print_stack(s,e);
	return 0;
}
