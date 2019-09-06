//离散事件模拟，模拟银行营业时的排队情况  
//不考虑顾客中途离开，顾客到达事件随机，业务办理时间  
//长度随机，选择最短的队排队，不再换队  
//作者：nuaazdh  
//时间：2011年12月10日 08:52:37  
#include <stdio.h>  
#include <time.h>  
#include <stdlib.h>  
  
#define OK 1  
#define ERROR 0  
#define TRUE 1  
#define FALSE 0  
  
typedef int Status;  
typedef struct Event
{   //事件类型  
    int OccurTime;  //事件发生时刻  
    int NType;      //事件类型，0表示到达事件，1至4表示四个窗口的离开事件  
    struct Event *next;  
}Event,ElemType;  
  
typedef struct
{ //单向链表结构  
    ElemType *head;//头指针  
    ElemType *tail;//尾指针  
    int len;    //长度  
}LinkList;  
  
typedef LinkList EventList; //事件链表  
  
typedef struct QElemType
{ //队列元素  
    int ArriveTime;//到达时间  
    int Duration;//办理业务所需时间  
    struct QElemType *next;  
}QElemType;  
  
typedef struct
{//队列结构  
    QElemType *head;//头指针  
    QElemType *tail;//尾指针  
}LinkQueue;  
  
Event NewEvent(int occurT,int nType);  
    //根据OccurTime和NType值，创建新事件  
Status InitList(LinkList *L);  
    //初始化事件链表  
Status OrderInsert(LinkList *L,Event e);  
    //将事件e按发生时间顺序插入有序链表L中  
Status ListEmpty(LinkList *L);  
    //判断链表L是否为空，为空返回TRUE，否则返回FALSE  
Status DelFirst(LinkList *L,ElemType *e);  
    //链表L不为空，删除其首结点，用e返回，并返回OK；否则返回ERROR  
Status ListTraverse(LinkList *L);  
    //遍历链表  
Status InitQueue(LinkQueue *Q);  
    //初始化队列Q  
Status EmptyQueue(LinkQueue *Q);  
    //若队列Q为空，返回TRUE，否则返回FALSE  
Status DelQueue(LinkQueue *Q,QElemType *e);  
    //若队列Q不为空，首结点出队，用e返回，并返回OK；否则返回ERROR  
Status EnQueue(LinkQueue *Q,QElemType e);  
    //结点e入队Q  
int QueueLength(LinkQueue Q);  
    //返回队列Q的长度，即元素个数  
Status GetHead(LinkQueue *Q,QElemType *e);  
    //若队列Q不为空，用e返回其首结点，并返回OK,否则返回ERROR  
Status QueueTraverse(LinkQueue *Q);  
    //遍历队列Q  
  
//------------------//  
int Min(int a[],int n);  
    //返回长度为n的数组a第一个最小值的下标，从1开始  
int ShortestQueue();  
    //获取最短队列的编号  
void OpenForDay();  
    //初始化操作  
void CustomerArrived();  
    //顾客达到事件  
void CustomerDepature();  
    //顾客离开事件  
void Bank_Simulation();  
    //银行排队模拟  
void PrintEventList();  
    //输出事件队列  
void PrintQueue();  
    //打印当前队列  
//----全局变量-----//  
EventList ev;  
Event en;  
LinkQueue q[5];  
QElemType customer;  
int TotalTime,CustomerNum;  
int CloseTime=200;//关闭时间，即营业时间长度  
  
//--------------main()------------------//  
int main()  
{  
    Bank_Simulation();  
    return 0;  
}  
  
  
//--------------模拟排队----------------//  
void OpenForDay()
{  
    //初始化操作  
    int i;  
    TotalTime=0;    CustomerNum=0;  
    InitList(&ev);//初始化事件队列  
    en.OccurTime=0;  
    en.NType=0;  
    OrderInsert(&ev,en);  
    for(i=1;i<=4;i++)  
        InitQueue(&q[i]);//初始化四个窗口队列  
}//OpenForDay  
  
void CustomerArrived()
{  
    //顾客达到事件  
    int durtime,intertime,i,t;  
    QElemType e;  
    ++CustomerNum;  
    intertime=rand()%5+1;//间隔时间在5分钟内  
    durtime=rand()%30+1;//办理业务时间在30分钟内  
    t=en.OccurTime+intertime;  
    if( en.OccurTime<CloseTime){//银行尚未关门  
        printf("A new customer arrived at:%d,his durTime=%d,the next intertime=%d|\n",en.OccurTime,durtime,intertime);//下一位顾客达到时间  
        OrderInsert(&ev,NewEvent(t,0));  
        i=ShortestQueue();//最短队列  
        e.ArriveTime=en.OccurTime;  
        e.Duration=durtime;  
        EnQueue(&q[i],e);  
        if(QueueLength(q[i])==1)  
            OrderInsert(&ev,NewEvent(en.OccurTime+durtime,i));  
    }else{
        printf("maxinum exceed!stop,en.OccurTime=%d,intertime=%d\n",en.OccurTime,intertime);
    }  
}  
  
void CustomerDepature()
{  
    //顾客离开事件  
    int i=en.NType;  
    DelQueue(&q[i],&customer);  
    printf("A customer leaves at:%d\n",en.OccurTime);//输出顾客离开时间  
    TotalTime+=en.OccurTime-customer.ArriveTime;  
    if(!EmptyQueue(&q[i]))
	{  
        GetHead(&q[i],&customer);  
        OrderInsert(&ev,NewEvent(en.OccurTime+customer.Duration,i));  
    }  
}  
  
void Bank_Simulation(){  
    //银行排队模拟  
    OpenForDay();  
    srand((unsigned)time(NULL));  
    while(!ListEmpty(&ev))
	{  
        DelFirst(&ev,&en); 
        printf("--------action--------------------------\n"); 
        if(en.NType==0)  
            CustomerArrived();  
        else  
            CustomerDepature();  
        PrintQueue();  
        PrintEventList();
    }  
    printf("\nTotal time is: %d min,average time is: %g min.\n",TotalTime,(float)TotalTime/CustomerNum);  
}  
  
void PrintQueue()
{  
    //打印当前队列  
    int i;  
    for(i=1;i<=4;i++)
	{  
        printf("Queue %d have %d customer(s):",i,QueueLength(q[i]));  
        QueueTraverse(&q[i]);  
    }  
    printf("\n");  
}  
  
void PrintEventList()
{  
    //输出事件队列  
    printf("Current Eventlist is:\n");  
    ListTraverse(&ev);  
}  
int Min(int a[],int n)
{
  
    //返回长度为n的数组a第一个最小值的下标，从0开始  
    int i,tmp,ind=0;  
    tmp=a[0];  
    for(i=1;i<n;i++)
	{  
        if(a[i]<tmp)
		{  
            tmp=a[i];  
            ind=i;  
        }  
    }  
    return ind;  
}  
  
int ShortestQueue()
{  
    //获取最短队列的编号  
    int i,a[4];  
    for(i=1;i<=4;i++)
	{  
        a[i-1]=QueueLength(q[i]);  
        //printf("队%d的长度为%d\n",i,QueueLength(q[i]));  
    }  
    return Min(a,4)+1;//队列从1开始编号  
}  
  
//-----------队和链表操作--------------//  
Event NewEvent(int occurT,int nType)
{  
    //根据OccurTime和NType值，创建新事件  
    Event e;  
    e.OccurTime=occurT;  
    e.NType=nType;  
    return e;  
}  
  
Status InitList(LinkList *L)
{  
    //初始化事件链表  
    L->head=L->tail=(ElemType *)malloc(sizeof(ElemType));  
    if(!L->head){  
        printf("Apply for memory error.LinkList initialize failed.\n");  
        exit(0);  
    }  
    L->head->next=NULL;  
    return OK;  
}  
  
Status OrderInsert(LinkList *L,Event e)
{  
    //将事件e按发生时间顺序插入有序链表L中  
    ElemType *p,*q,*newptr;  
    newptr=(ElemType *)malloc(sizeof(ElemType));  
    if(!newptr)
	{  
        printf("Apply for memory error，new node can't insert intot the Eventlist.\n");  
        exit(0);  
    }  
    *newptr=e;  
    if(TRUE==ListEmpty(L)){//链表为空  
       L->head->next=newptr;  
       L->tail=newptr;  
       L->tail->next=NULL;  
       return OK;  
    }  
    q=L->head;  
    p=L->head->next;  
    while(p)
	{//遍历整个链表  
        if(p->OccurTime>=newptr->OccurTime)  
            break;  
        q=p;  
        p=p->next;  
    }  
    q->next=newptr;  
    newptr->next=p;  
    if(!p)//插入位置为链表尾部  
        L->tail=newptr;  
    return OK;  
}  
  
Status ListEmpty(LinkList *L)
{  
    //判断链表L是否为空，为空返回TRUE，否则返回FALSE  
    if((L->head==L->tail)&&(L->head!=NULL))  
        return TRUE;  
    else  
        return FALSE;  
}  
  
Status DelFirst(LinkList *L,ElemType *e)
{  
    //链表L不为空，删除其首结点，用e返回，并返回OK；否则返回ERROR  
    ElemType *p=L->head->next;  
    if(!p)  
        return ERROR;  
    L->head->next=p->next;  
    *e=*p;  
    free(p);  
    if(L->head->next==NULL)  
        L->tail=L->head;  
    return OK;  
}  
  
Status ListTraverse(LinkList *L)
{  
    //遍历链表  
    Event *p=L->head->next;  
    if(!p)
	{  
        printf("List is empty.\n");  
        return ERROR;  
    }  
    while(p!=NULL)
	{  
        printf("OccurTime:%d,Event Type:%d\n",p->OccurTime,p->NType);  
        p=p->next;  
    }  
    printf("\n");  
    return OK;  
}  
  
Status InitQueue(LinkQueue *Q){  
    //初始化队列Q  
    Q->head=Q->tail=(QElemType *)malloc(sizeof(QElemType));  
    if(!Q->head)
	{  
        printf("Apply for memory error.LinkQueue initialize failed.\n");  
        exit(0);  
    }  
    Q->head->next=NULL;  
    return OK;  
}  
  
Status EmptyQueue(LinkQueue *Q){  
    //若队列Q为空，返回TRUE，否则返回FALSE  
    if(Q->head==Q->tail&&Q->head!=NULL)  
        return TRUE;  
    else  
        return FALSE;  
}  
  
Status DelQueue(LinkQueue *Q,QElemType *e){  
    //若队列Q不为空，首结点出队，用e返回，并返回OK；否则返回ERROR  
    QElemType *p=Q->head->next;  
    if(!p)  
        return ERROR;  
    *e=*p;  
    Q->head->next=p->next;//修正队首指针  
    free(p);  
    if(!Q->head->next)//队空  
        Q->tail=Q->head;  
    return OK;  
}  
  
Status EnQueue(LinkQueue *Q,QElemType e){  
    //结点e入队Q  
    QElemType *p=(QElemType *)malloc(sizeof(QElemType));  
    if(!p)
	{  
        printf("Apply for memory error,new element can't enqueue.\n");  
        exit(0);  
    }  
    *p=e;  
    p->next=NULL;  
    Q->tail->next=p;//插入队尾  
    Q->tail=p;//修改队尾指针  
    return OK;  
}  
  
int QueueLength(LinkQueue Q)
{  
    //返回队列Q的长度，即元素个数  
    int count=0;  
    QElemType *p=Q.head->next;  
    while(p)
	{  
        p=p->next;  
        count++;  
    }  
    return count;  
}  
  
Status GetHead(LinkQueue *Q,QElemType *e)
{  
    //若队列Q不为空，用e返回其首结点，并返回OK,否则返回ERROR  
    if(EmptyQueue(Q))  
        return ERROR;  
    *e=*(Q->head->next);  
        return OK;  
}  
  
Status QueueTraverse(LinkQueue *Q)
{  
    //遍历队列Q  
    QElemType *p=Q->head->next;  
    if(!p)
	{  
        printf("--Is empty.\n");  
        return ERROR;  
    }  
    while(p)
	{  
        printf("(%d,%d) ",p->ArriveTime,p->Duration);  
        p=p->next;  
    }  
    printf("\n");  
    return OK;  
} 
