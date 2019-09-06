#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define Max 100
typedef struct
{
	int *elem;
	int length;
	
}sqlist;

int init_list(sqlist &l)
{
	l.elem=(int *)malloc(Max*sizeof(int));
	l.length=0;
	return 0;
}
int create_list(sqlist &l,int i,int e)
{
	int *newbase;
	if(i<1||i>l.length+1)
	{
		return -1;
	}
	if(l.length>=Max-1)
	{
		newbase=(int *)realloc(l.elem,Max*sizeof(int));
		if(!newbase)
		{
			return -1;
		}
		l.elem=newbase;
	}
	//cout<<"*****************"<<endl;
	for(int j=l.length-1;j>=i-1;j--)
	{
		l.elem[j+1]=l.elem[j];
	}
	l.elem[i-1]=e;
	l.length++;
	return 0;
}
int print_list(sqlist &l)
{
	for(int i=1;i<l.length+1;i++)
	{
		cout<<l.elem[i-1]<<endl;
	}
	return 0;
}
int find_list(sqlist &l)
{
	int c,t=0;
	printf("input selct a num:\n");
	cin>>c;
	for(int i=1;i<l.length+1;i++)
	{
		if(c==l.elem[i-1])
		{
			cout<<l.elem[i-1]<<endl;
			t=1;
			break;
		}
			
	}
	if(c==0)
	{
	printf("connot fint it\n");	
	}
	return 0;
}
int del_list(sqlist &l)
{
	int c,t=0;
	printf("input selct a num:\n");
	cin>>c;
	for(int i=1;i<l.length+1;i++)
	{
		if(c==l.elem[i-1])
		{
			l.elem[i-1]=l.elem[i];
			t=1;
		}

		if(t==1)
		{
			l.elem[i-1]=l.elem[i];
		}
			
	}
	l.length--;
	if(c==0)
	{
	printf("connot find it to del\n");	
	}
	return 0;
}
int mermg(sqlist &l,sqlist &l1,sqlist &m)
{
	if (l.length==0|| l1.length==0)
	{
		return -1; 
	} 
	init_list(m);
	for(int i=1;i<l.length+1;i++)
	{
		//cout<<l.elem[i-1]<<endl; 
		create_list(m,i,l.elem[i-1]);
	}
	for(int j=l.length+1;j<l.length+l1.length+1;j++)
	{
		//cout<<l1.elem[j-l.length-1]<<"---"<<(j-l.length-1)<<"-----"<<endl; 
		create_list(m,j,l1.elem[j-l.length-1]);
	}
	return 0;
	
}
int main()
{
	sqlist p1,p2,p3;
	init_list(p1);
	init_list(p2);
	init_list(p3);
	for(int i=1;i<10;i++)
	{
		create_list(p1,i,i+1);	
	}
	for(int j=1;j<4;j++)
	{
		create_list(p2,j,j+2);	
	}
	create_list(p1,3,1);	
	print_list(p1);
	
	printf("*****************\n");	
    //find_list(p1);
    //del_list(p1);
	print_list(p2);
	
	printf("*****************\n");	
	mermg(p1,p2,p3);
	print_list(p3);
	return 0;
	
}
