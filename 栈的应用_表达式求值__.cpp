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
char prior[7][7]=
{
{'>','>','<','<','<','>','>'},
{'>','>','<','<','<','>','>'},
{'>','>','>','>','<','>','>'},
{'>','>','>','>','<','>','>'},
{'<','<','<','<','<','=','!'},
{'>','>','>','>','!','>','>'},
{'<','<','<','<','<','!','='}
};//定义算符之间优先关系的二维数组 

Status init_stack(stack &s)
{
	s.top=s.base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!s.top)
	{
		exit(OVERFLOW);
	}
	s.stacksize=STACK_INIT_SIZE;
	
}
Status push_stack(stack &s,ElemType e)
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

Status pop_stack(stack &s,ElemType &e)
{
	if(s.top-s.base==0)
	{
		return ERROR;
	}
	e=*--s.top;
	return e;
	
}

ElemType get_stack_top(stack &s)
{
	if(s.top-s.base==0)
	{
		return ERROR;
	}

	return *(s.top-1);;
	
}


Status isdigit(char ch)
{
	if(ch>='0'&&ch<='9') 
	{
		return OK;
	}
	return ERROR;
} 

char index(char c)
{
	switch(c)
	{
		case '+':
			return 0;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 3;
		case '(':
			return 4;
		case ')':
			return 5;
		case '#':
			return 6;
		default:
			return 7;
	}
}
ElemType Operate(ElemType a, ElemType b, ElemType ch)
{
    switch (ch)
	{
    case '+':
    	{
    		return a  + b;
		} 
    case '-':
    	{
    	return a  - b;	
		} 
    case '*':
    	{
    		return a * b;
		}
    case '/':
    	if(b!=0)
    	{
    		return a / b;	
		}
		else
		{
			printf("分母不能为零！\n");
		}
        
    }
}//Operator
char Priority(ElemType a,ElemType b)
{
	int pos_x,pos_y;
	pos_x=index(a);
	pos_y=index(b);
	if(pos_x!=7&&pos_y!=7)
	{
		return prior[pos_x][pos_y];
	}
	else
	{
		return '!';
	}
	
}
void Expression_eval()
{
	char str[100];
	char  result,ch;
	stack operate,number;//操作符栈，数据栈； 
	init_stack(number);
	init_stack(operate);
	printf("请输入表达式：\n");
	//scanf("%s",str);
	//printf("%s",str);
	push_stack(operate,'#');
	ch=getchar();
	
	while(ch!='#' ||  get_stack_top(operate)!='#')
	{
		if(isdigit(ch))
		{
			char data[14];
			int i=0;
			int rea_num=0;
			while(isdigit(ch))
			{
					data[i++] = ch-'0';
					ch = getchar();
					if(ch=='\n')
					 {
					     ch='#';
					 }
			}
			for(int j=0;j<i;j++)
			{
				rea_num = rea_num*10+data[j];
			}
			push_stack(number,rea_num);
		}
		else
		{
			ElemType num_a,num_b,ope_ch;
			switch(Priority(get_stack_top(operate),ch))
			{
				case '<'://+- 遇到*/，乘除优先级 较大，不能计算，*/入栈 
					{
						push_stack(operate,ch);
						ch = getchar();
						if(ch=='\n')
						 {
						     ch='#';
						 }
						break;
					}
				case '>'://按优先级，计算操作 
					{
						pop_stack(number,num_a);
						pop_stack(number,num_b);
						pop_stack(operate,ope_ch);
						push_stack(number,Operate(num_b,num_a,ope_ch));
						break;
					}
				case '='://括号相遇 
					{
						pop_stack(operate,ope_ch);
						ch = getchar();
						if(ch=='\n')
						 {
						     ch='#';
						 }
						break;
					}
				default:
					{
						printf("error!\n");
					}
				 
			}
		}
	}
	result=get_stack_top(number);
	printf("该表达式值为：%d\n",result);
	
	
	
}
int main()
{
	Expression_eval();
	return 0;
} 
