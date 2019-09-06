#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
#define ElemType int
#define Status int
typedef struct QNode
{
	ElemType data;
	struct QNode *next;
}QNode,*Queueptr;
typedef struct
{
	Queueptr front;
	Queueptr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q) 
{
	Q.front=Q.rear=(QNode*)malloc(sizeof(QNode));
	if(!Q.front)
	{
		exit(-1);
	}
	Q.front->next=NULL;
	return 0;
}
Status QueueEmpty(LinkQueue Q) 
{
	if(Q.front==Q.rear)
	{
		return NULL;
	}
	
}
Status QueueLength(LinkQueue Q) 
{
	int i;
	while(Q.front->next!=NULL)
	{
		i++;
		Q.front=Q.front->next;
	} 
	return i;
	
}
Status GetHead(LinkQueue Q,ElemType &e) 
{
	e=Q.front->next->data;
	return e;
}
Status EnQueue(LinkQueue &Q,ElemType e) 
{
	Queueptr p;
	p=(QNode*)malloc(sizeof(QNode));
	p->data=e;
	printf("----->%d\n",e);
	p->next=NULL;

	Q.rear->next=p;
	//Q.rear=Q.rear->next;
	Q.rear=p;
	
	
}
Status DeQueue(LinkQueue &Q,ElemType &e) 
{
	if(Q.front==Q.rear)
	{
		return -1;
	}
	Queueptr p;
	p=Q.front->next;
	e=p->data;
	printf("<-----%d\n",e);
	Q.front->next=p->next;
	if(Q.rear==p)
	{
		Q.rear=Q.front;
	}
	free(p);
}
Status ClearQueue(LinkQueue &Q) 
{
    if (Q.front == Q.rear)
    {
    	return -1;
    }
    QNode *node = Q.front->next;//队头元素
    while (node)
    {
	    Q.front->next = node->next;//指向新的队头结点
	    if (Q.rear == node)//当删除的是队尾元素时，将队尾指针指向头结点
	    {
	    Q.rear = Q.front;
	    }
	    free(node);//释放旧的队头结点
	    node = Q.front->next;
    }
    return 0;
}
Status DestoryQueue(LinkQueue &Q) 
{
	
}
int main()
{
	LinkQueue Q;
	int e;
	InitQueue(Q) ;
	for(int i=0;i<10;i++)
	{
		EnQueue(Q,i) ;
	}
	printf("Queue_head->%d\n",GetHead(Q,e) );
	printf("Queue_len->%d\n",QueueLength(Q) );
	while(QueueEmpty(Q)!=NULL)
	{
		DeQueue(Q,e);
	}
	
	return 0;
}
 
