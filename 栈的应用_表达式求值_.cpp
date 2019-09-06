#include <stdio.h>
#include <stdlib.h>


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
	//printf("%d\n",e);
	return OK;
	
}

Status pop_stack(stack &s,ElemType &e)
{
	if(s.top-s.base==0)
	{
		return ERROR;
	}
	e=*--s.top;
	//printf("%d\n",e);
	return e;
	
}

ElemType get_stack_top(stack &s)
{
	if(s.top-s.base==0)
	{
		return ERROR;
	}
	//printf("%d\n",*(s.top-1));
	return *(s.top-1);;
	
}

//确定输入的字符如果是操作符的话判断在二维数组中的下标 若是数字的话就另外与操作符区分开 便于在输入表达式时是入哪个栈 
int Index(char c){
	switch(c){
		case '+': return 0;
		case '-': return 1;
		case '*': return 2;
		case '/': return 3;
		case '(': return 4;
		case ')': return 5;
		case '#': return 6;
		default:  return 7;
	}
}
//判断优先级,返回大小 < > = !
char Priority(char a,char b){
	int x,y;
	x = Index(a); y = Index(b);
	if(x!=7&&y!=7)
		return prior[x][y];
	else
		return '!';
}

ElemType Operate(ElemType a, ElemType x, ElemType b){
    switch (x){
    case '+':
        return a  + b;
    case '-':
        return a  - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}//Operator

Status isdigit(char ch){
	if(ch>='0'&&ch<='9') 
	{
		return OK;
	}
	return ERROR;
} 
int Expression_eval()
{

	char c[1000];
	char  result;
	stack num;
	stack ope;
	init_stack(num); 
	init_stack(ope); 
	push_stack(ope,'#');//将结束符置于操作符的底端  
	char ct,ch = getchar();
	//gets(c);
	while(ch!='#'||get_stack_top(ope)!='#') 
	{
		
		if(isdigit(ch))
		{
			
			int data[10];
			int i,re;
			i = re =0;
			while(isdigit(ch))
			{
				data[i] = ch-'0';
				i++;
				
				ch = getchar();
				if(ch=='\n')
				 {
				     ch='#';
				 }


			}
			for(int j=0;j<i;j++)
			{
				re = re*10+data[j];
			}

			push_stack(num,re);
			
		}
		else
		{
			ElemType a,b,theta;//a b theta是用来返回操作数栈和操作符栈里的元素的
			switch(Priority(get_stack_top(ope),ch))
			{//比较即将入栈的字符与栈顶 操作符的优先级关系 
			
				case '<':
						 push_stack(ope,ch); 
						 ch = getchar();
						 if(ch=='\n')
						 {
						 	ch='#';
						 }	
						 break;
				case '>':
						 
						 pop_stack(num,b);
						 pop_stack(num,a);
						 //printf("---->%c%c\n",a,b);
						 pop_stack(ope,theta);
						 push_stack(num,Operate(a,theta,b));
						 //printf("---------------------\n");
						 break;//将结果入栈 
				case '=':
						 pop_stack(ope,theta);
						 //printf("---------------------\n");
						 ch = getchar();
						 if(ch=='\n')
						 {
						 	ch='#';
						 }
						 break;//说明括号相遇 删除栈内括号即可 
				default:break;
			}
		}
	}
	int num1;
	num1=get_stack_top(num);
	printf("结果是：%d\n",num1);

	return 0;
}

int main()
{
	stack l;
	//char e;
	//init_stack(l); 
	printf("请输入表达式：\n");
	Expression_eval();
	//push_stack(l,1);
	//get_stack_top(l);
	//e=pop_stack(l,e);
	//printf("%d",e);
	return 0;
} 
