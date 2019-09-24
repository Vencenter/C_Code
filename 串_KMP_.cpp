#include<stdio.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 255
typedef int Status;
typedef char ElemType; 
//定义模式串的顺序表 
typedef struct
{
	char ch[MAXSIZE+1];
	int next[MAXSIZE+1];
	int nextval[MAXSIZE+1];
	int length;
}S1String;
//定义主串的顺序表 
typedef struct
{
	char ch[MAXSIZE+1];
	int length;
}S2String;
//初始化模式串 
Status Init_S1(S1String &S1)
{
	S1.length=0;
	return OK;
}
//初始化主串 
Status Init_S2(S2String &S2)
{
	S2.length=0;
	return OK;
}
//求的模式串的next 
Status Get_S1_next(S1String &S1)
{
	int i=1;
	S1.next[1]=0;
	int j=0;
	while(i<S1.length)
	{
		if(j==0||S1.ch[i]==S1.ch[j])
		{
			i++;
			j++;
			S1.next[i]=j;
		}
		else
		{
			
			j=S1.next[j];
			
		}
	}
	return OK;
}
//求得模式串的nextval 
Status Get_S1_nextval(S1String &S1)
{
	int i=1;
	S1.nextval[1]=0;
	int j=0;
	while(i<S1.length)
	{
		if(j==0||S1.ch[i]==S1.ch[j])
		{
			i++;
			j++;
			if(S1.ch[i]!=S1.ch[j])
			{
				S1.nextval[i]=j;
			}
			else
			{
				S1.nextval[i]=S1.nextval[j];
			}
		}
		else
		{
			j=S1.nextval[j];
		}
	}
	return OK;
}
//进行比较求出结果 
Status Compare(S1String &S1,S2String &S2)
{
	int i=1;
	int j=1;
	int result;
	result=1;
	while(1)
	{
		if(S1.next[i]==0&&S1.ch[i]!=S2.ch[j])
		{
			j++;
			result=j;
		}
		else
		{
			if(S1.ch[i]==S2.ch[j])                 
			{                                      
				i++;
				j++;
			}
			else
			{
				i=S1.next[i];
				result=j-i+1;	
			}
			if(i>S1.length)
			{
				return result;	
			} 
		}
	}
}
int main()
{
	char s1[]="abffseghsfnrSEFvbnbacsxrdacbhhdrsdcbacba\0";
	char s2[]="acba\0";
	int result;
	S1String S1;
	S2String S2;
	Init_S1(S1);
	Init_S2(S2);
	//printf("请输入模式串:");
	//scanf("%s",&s1);
	//printf("请输入主串:");
	//scanf("%s",&s2);
	//字符数组进入主串和模式串 
	for(int i=0;i<=strlen(s1)-1;i++)
	{
		S1.ch[i+1]=s1[i];
		S1.length++;
	}
	for(int j=0;j<=strlen(s2)-1;j++)
	{
		S2.ch[j+1]=s2[j];
		S2.length++;
	}
	//求结果 
	Get_S1_next(S1);
	Get_S1_nextval(S1);
	result=Compare(S1,S2);
	printf("结果是:%d\n",result);	
}
