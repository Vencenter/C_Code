#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
#define ElemType int
#define Status int
typedef struct
{
	ElemType data[MaxSize];
	int front,rear;
}Queueptr;

Status InitQueue(Queueptr &Q) 
{
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
	return Q.rear-Q.front;
}
Status GetHead(Queueptr Q,ElemType &e) 
{
	e=Q.data[Q.front];
	return e;
}
Status EnQueue(Queueptr &Q,ElemType e) 
{
	printf("Queue-->%d\n",e);
	if(Q.rear>=MaxSize)
	{
		return -1;
	}
	Q.data[Q.rear++]=e;
	return 0;
}
Status DeQueue(Queueptr &Q,ElemType &e) 
{
	
	if(Q.rear==Q.front)
	{
		return -1;
	}
	e=Q.data[Q.front++];
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
	InitQueue(Q);
	for(int i=1;i<10;i++)
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
 
