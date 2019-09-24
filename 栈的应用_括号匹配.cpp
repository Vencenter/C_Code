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

char pop_stack(stack &s,char &e)
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
	    return true;
	}
	return false;
	
}
int main()
{
	stack s;
	init_stack(s);
	int i=0, flag=0;
	
	char e,str[100];
	printf("«Î ‰»Î“ª¥Æ◊÷∑˚¥Æ:\n");
	scanf("%s",str);
	while(str[i] != '\0')
		{
			switch(str[i])
			{
				case '(':
					{
						push_stack(s,str[i]);
						break;
					}		
				case '[':
					{
						push_stack(s,str[i]);
						break;
					}
				case ')':
						{
						  pop_stack(s,e);
						  if(e != '(') 
						  {
						     flag=1;
						  }		  
						}
						break;
				case ']':
						{
						  pop_stack(s,e);
						  if(e!='[')
						  {
						     flag=1;
						  }		  
						}
						break;
				default:
					{
						break;	
					}		
			}
			if(flag)
			{
				break;
			}			
			i++;
	}
 
   if(!flag && empty_stack(s))
   {
   		printf("∆•≈‰≥…π¶!\n");
   } 	
   else
   {
   		printf("∆•≈‰ ß∞‹!\n");
   } 
	return 0;
	
}
