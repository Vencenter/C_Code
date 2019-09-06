#include<stdio.h> 
#include<stdlib.h> 
#define typeElem int
typedef struct Node
{
	struct Node *next;
	typeElem data;
	
}SetNode,*LinkSet;



void InitList(LinkSet &s)
{
	s=(SetNode*)malloc(sizeof(SetNode));
	s->next=NULL;
}


void InsertElem(LinkSet &s,typeElem e)
{
	
		SetNode *p,*t=s,*tail;
		p=(SetNode*)malloc(sizeof(SetNode));
		p->data=e;
		p->next=NULL;
		
		while(t->next!=NULL)
		{
			if(t->next->data==e)
			{
				return;
			}
			t=t->next;
		}
		t->next=p;
	 
}

void PrintSet(LinkSet s)
{
	while(s->next!=NULL)
	{
		printf("%d \n",s->next->data); 
		s->next=s->next->next;
	}	
	 
}

void MergeSet(LinkSet la,LinkSet lb,LinkSet &lc)
{
	while(la->next!=NULL)
	{
		//printf("%d \n",la->data->data); 
		InsertElem(lc,la->next->data);
		la->next=la->next->next;
	}
	
	while(lb->next!=NULL)
	{
		//printf("%d \n",lb->data->data);
		InsertElem(lc,lb->next->data);
		lb->next=lb->next->next;
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
	InsertElem(la,2);
	
	InsertElem(lb,3);
	InsertElem(lb,2);
	InsertElem(lb,1);
	InsertElem(lb,6);
	InsertElem(lb,8);

	
	//PrintSet(la);
	printf("\n"); 
	//PrintSet(lb);
	
	
	MergeSet(la,lb,lc);
	printf("****************\n"); 
	PrintSet(lc);
	printf("****************\n"); 

}
