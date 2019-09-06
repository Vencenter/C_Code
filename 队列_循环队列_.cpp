#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
#define ElemType int
#define Status int
typedef struct
{
	ElemType *base;
	int front,rear;
}Queueptr;

Status InitQueue(Queueptr &Q) 
{
	Q.base=(ElemType*)malloc(MaxSize*sizeof(ElemType));
	if(!Q.base)
	{
		exit(-1);
	}
	Q.front=Q.rear=0;
}
Status QueueEmpty(Queueptr Q) 
{
	if(Q.front==Q.rear)
	{
		return NULL;
	}
}
Status QueueLength(Queueptr Q) 
{
	return (Q.rear-Q.front+MaxSize)%MaxSize;
}
Status GetHead(Queueptr Q,ElemType &e) 
{
	e=Q.base[Q.front];
	return e;
}
Status EnQueue(Queueptr &Q,ElemType e) 
{
	if((Q.rear+1)%MaxSize==Q.front)
	{
		return -1;
	}
	Q.base[Q.rear]=e;
	printf("Queue-->%d\n",Q.base[Q.rear]);
	Q.rear=(Q.rear+1)%MaxSize;
	return 0;
}
Status DeQueue(Queueptr &Q,ElemType &e) 
{
	if(Q.rear==Q.front)
	{
		return -1;
	}
	e=Q.base[Q.front];
	
	Q.front=(Q.front+1)%MaxSize;
	printf("Queue<--%d\n",e);
	return e;
}
Status ClearQueue(Queueptr &Q) 
{
	
}
Status DestoryQueue(Queueptr &Q) 
{
	
}
int main()
{
	Queueptr Q;
	int e;
	InitQueue(Q) ;
	for(int i=1;i<20;i++)
	{
		EnQueue(Q,i);
	}
	printf("Queue_length->%d\n",QueueLength(Q));
	printf("Queue_header->%d\n",GetHead(Q,e) );
	while(QueueEmpty(Q)!=NULL)
	{
		DeQueue(Q,e);
	}
	return 0;

}
 
