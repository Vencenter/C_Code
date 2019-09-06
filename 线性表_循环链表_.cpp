#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	char name[30];
	char id[30];
	float score;
	int len;
	struct student *next;
}*Stu,stu;

void creatList(stu *&head)
{
	int n,i;
	stu *p,*tail;
	
	printf("请输入学生人数:\n");
	scanf("%d",&n);	
	
	head=NULL;
	for(i=0;i<n;i++)
	{
		printf("第%d个学生:\n",i+1);	
		p=(stu *)malloc(sizeof(stu));
		printf("请输入学生的姓名，学号，分数:\n");	
		scanf("%s %s %f",&p->name,&p->id,&p->score);
		p->next=NULL;
		if(head==NULL)
		{
			
			head=p;
			head->len=1;
		}
		else
		{
			tail->next=p;
			head->len=head->len+1;
		}
		
		tail=p;
	}
	tail->next=head;
	printf("创建成功！\n");	
}
void printList(stu *p )
{
	if(p==NULL)
	{
	printf("链表为空！\n");		
	}
	int i=0;
	
	printf("len-->%d\n",p->len);
	while(p!=NULL)
	{
		printf("学生的姓名，学号，分数为:\n");	
		printf("%s %s %.2f\n",p->name,p->id,p->score);
		p=p->next; 
		i++;
		if(i==p->len)
		{
			break;
		}
		
	}
} 

 void  select_data(stu *head)
{
	char n[40];
	int m;
	if(head==NULL)
	{
	printf("data no exists:\n");	
	}
	printf("intput student name:\n");
	scanf("%s",n);
	while(head!=NULL)
	{
		m=strcmp(n,head->name);
		if(m==0)
		{
		printf("%s,%s,%.2f \n",head->name,head->id,head->score);	
		break;
		}
		
		head=head->next;
	}
	
}
int main()
{
	
	Stu head;
	creatList(head);
	printList(head);
	select_data(head);
	return 0;
}
