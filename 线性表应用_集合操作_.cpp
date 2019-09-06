#include<stdio.h> 
#include<stdlib.h> 
#define typeElem int
typedef struct Node
{
	struct Node *next;
	typeElem data;
	
}SetNode;

typedef struct{
	SetNode *first;
}LinkSet;// 链式集合名称指针 
 


void InitList(LinkSet &s)
{
	s.first=NULL;
}

int numSet(LinkSet s,typeElem e)
{
	while(s.first!=NULL)
	{
		if(s.first->data==e)
		{
			//printf("%d \n",s1.first->data); 
			return 0;
		}
		s.first=s.first->next;
	}
	 return 1;
}

void InsertElem(LinkSet &s,typeElem e)
{
	if(numSet(s,e))
	{

		SetNode *p,*tail;
		LinkSet  t;
	
		p=(SetNode*)malloc(sizeof(SetNode));
		p->data=e;
		//printf("%d ",e); 
		p->next=NULL;
		if(s.first==NULL)
		{
		
			s.first=p;
		}
		else
		{
			tail->next=p;
			//t.first=p;
		}
		tail=p;

	}
	
	 
}

void PrintSet(LinkSet s)
{
	while(s.first!=NULL)
	{
		printf("%d \n",s.first->data); 
		s.first=s.first->next;
	}	
	 
}

void MergeSet(LinkSet la,LinkSet lb,LinkSet &lc)
{
	while(la.first!=NULL)
	{
		//printf("%d \n",la.first->data); 
		InsertElem(lc,la.first->data);
		la.first=la.first->next;
	}
	
	while(lb.first!=NULL)
	{
		//printf("%d \n",lb.first->data);
		InsertElem(lc,lb.first->data);
		lb.first=lb.first->next;
	}
	
	 
}
int main()
{
	LinkSet la,lb,lc;
	InitList(la);
	InitList(lb);
	InitList(lc);
	
	InsertElem(la,3);
	InsertElem(la,2);
	InsertElem(la,4);
	InsertElem(la,7);
	InsertElem(la,5);

	InsertElem(lb,3);
	InsertElem(lb,2);
	InsertElem(lb,1);
	InsertElem(lb,6);
	InsertElem(lb,8);

	
	//PrintSet(la);
	//printf("\n"); 
	//PrintSet(lb);
	
	
	MergeSet(la,lb,lc);
	printf("\n"); 
	PrintSet(lc);
	//printf("%d ",1); 
}
