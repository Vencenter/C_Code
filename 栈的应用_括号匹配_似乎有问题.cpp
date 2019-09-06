#include<stdio.h>
#include<stdlib.h>

#define Max 100
#define False -1
#define True 1

typedef struct Stack
{
	char data[Max];
	int top;
}stack;

int init_stack(stack &s)
{
	s.top=-1;
	return 0;	
}
char push_stack(stack &s,char e)
{
	if(s.top>Max-1)
	{
		return False;
	}
	s.data[++s.top]=e;
	//printf("pop-->%c\n",e);
	return True;
}

char pop_stack(stack &s,char e)
{
	if(s.top>-1)
	{
	    e=s.data[s.top--];
	    //printf("pop--%c ",e);
	    return e;
	}
	return False;
}

char top_stack(stack s)
{
	if(s.top>-1)
	{
	    return s.data[s.top];
	}
	return False;
}
char print_stack(stack s,char e)
{
	while(s.top!=-1)
	{
	    e=s.data[s.top--];
	    //printf("push-->%c\n",e);
	}
	return True;
	
}
int len_stack(stack s)
{
	int m=0;
	while(s.top!=-1)
	{
		s.data[s.top--];
	    //printf("push-->%c\n",s.data[s.top--]);
	    m++;
	}
	return m;
	
}
int empty_stack(stack s)
{
	if(s.top==-1)
	{
	    return NULL;
	}
	return True;
	
}
int main()
{
	stack s;
	init_stack(s);
	int i,j;
	
	char c,e,d;
	
	while((c=getchar())!='\n')
	{
		if(c=='(' || c=='[')
		{
		push_stack(s,c);	
		}
		else if (c==')' || c==']')
		{
		//printf("---------------\n ");
		e=pop_stack(s,e);
		printf("%c ",e);
		if (top_stack(s)==')' || top_stack(s)==']')
		{
		pop_stack(s,e);	
		}
		
		}
		else if (c=='+' || c=='-'|| c=='*'|| c=='/')
		{	
			e=top_stack(s);
			if(e=='*' || e=='/')
			{
				e=pop_stack(s,e);
				printf("%c ",e);
			}
			
		
			push_stack(s,c);		
			
			
		}
		else if (c>=48 && c<=57)
		{
		printf("%c ",c);
		}
		else
		{
		e=pop_stack(s,e);
		printf("%c ",e);
		} 
		
	}
	while(empty_stack(s)!=NULL)
	{
		if (top_stack(s)=='(' || top_stack(s)=='[')
		{
			e=pop_stack(s,e);
			//printf("%c ",e);
		}
		else
		{
		e=pop_stack(s,e);
		printf("%c ",e);		
		}
	
	}
	
	return 0;
}
