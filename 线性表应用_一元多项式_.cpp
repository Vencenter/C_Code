#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
#define LEN sizeof(Poly)
 
typedef struct term{
    float coef;  //系数
    int expn;  //指数
    struct term *next;
}Poly,*Link;

int LocateElem(Link p, Link s, Link &q);
void CreatePolyn(Link &p,int m); //创建多项式
void PrintPolyn(Link p);   //打印多项式（表示）   
int cmp(Link a, Link b);
Link AddPolyn(Link pa, Link pb); //多项式相加
Link SubPolyn(Link pa, Link pb); //多项式相减
Link Reverse(Link p);    //逆置多项式
Link MultiplyPolyn(Link A,Link B); //多项式相乘
void Calculate(Link p,float x);  //多项式求值

int main()
{
	 Link P1,P2,P3; //多项式
	 int L1,L2;  //多项式长度
	 printf("     --------------------------------------------------------------------\n");
	 printf("      |==================      一元多项式的运算        =================|\n");
	 printf("      |==================          1.相加（+）         =================|\n");
	 printf("      |==================          2.相减（-）         =================|\n");
	 printf("      |==================          3.相乘（*）         =================|\n");
	 printf("     --------------------------------------------------------------------\n\n");
 
	 printf("请输入第一个多项式的项数：");
	 scanf("%d",&L1);
	 CreatePolyn(P1,L1);
	 printf("第一个多项式为：");
	 printf("P1(X)=");
	 PrintPolyn(P1);
	 printf("请输入第二个多项式的项数：");
	 scanf("%d",&L2);
	 CreatePolyn(P2,L2);
	 printf("第二个多项式为：");
	 printf("P2(X)=");
	 PrintPolyn(P2);
	 printf("\n");
	 
 	 printf("请输入要选择的运算(+ , - , *): ");
	 char ch1;
	 getchar();  //清除掉缓冲区的回车符
	 scanf("%c",&ch1);
	 getchar();  //清除掉缓冲区的回车符
	 
	 switch(ch1)
	 {
	   case '+':
		{
			printf("两个一元多项式相加：  ");
			printf("P1(X)+P2(X)=");
			P3=AddPolyn(P1, P2);
			PrintPolyn(P3);
		}
		   break;
	   case '-':
	   	{
		    printf("两个一元多项式相减：  ");
		    printf("P1(X)-P2(X)=");
		    P3=SubPolyn(P1, P2);
		    PrintPolyn(P3);
	   	}
		   break;
	   case '*':
	    {
		    printf("两个一元多项式相乘：  ");
		    printf("P1(X)*P2(X)=");
		    P3=MultiplyPolyn(P1, P2);
		    PrintPolyn(P3);
	    }
	   		break;
	   default:
	   	{
	   		printf("您输入了错误指令 %c ！",ch1);	
		}
	   	
	  }
	 
	 char ch2;
	 printf("\n是否代入X进行求值？(Y/N): ");
	 ch2=getchar();  //清除掉缓冲区的回车符 
	 getchar();
	 
	 switch(ch2)
	 {
	  case 'Y':
	   {
		   float x;
		   printf("\n请输入多项式中X的值：");
		   scanf("%f",&x);
		   Calculate(P3,x);
		   break; 
	   }
	  case 'N':
	  	{
	  		break;
	 	}
	  default:
	 	{
	  		printf("你输入了错误指令 %c ！",ch2);
	  	}
	 }
	 return 0;
}

int LocateElem(Link p, Link s, Link &q)
{
/*遍历链表p，每一个结点与s比较指数，
若相同,q指向相同指数项的结点，返回1，
若不相同，根据s所指指数大小在链表p中的位置来确定q的指向结点，返回0
*/
	 Link p1 = p->next;
	 Link p2 = p;
	 while(p1)
	 {
		  if(s->expn > p1->expn)
		  {
		   p1 = p1->next;
		   p2 = p2->next;
		  }
		  else if(s->expn == p1->expn)
		  {
		   q = p1;
		   return 1;
		  }
		  else
		  {
		   q = p2;
		   return 0;
		  }
	 }
	 if(!p1)
	 {
		  q = p2;
		  return 0;
	 }
}
 
void CreatePolyn(Link &p,int m)
/*创建带头结点的链表(多项式)
且无论按什么顺序输入，或是有相同指数项
最终在多项式中都是升幂顺序！
*/
{
	 Link s,q;
	 int i;
	 p=(Link)malloc(LEN);
	 p->next=NULL;
	 for(i=0;i<m;i++)
	 {
		  s=(Link)malloc(LEN);
		  printf("输入系数和指数（以空格隔开）:");
		  scanf("%f %d", &s->coef, &s->expn);
		  if(!LocateElem(p, s, q))
		  { //若没有相同指数项，则链入
			   s->next = q->next;
			   q->next = s;
		  }
		  else
		  {      //若有相同指数项，则系数相加      
		  	   q->coef+=s->coef;
		  }
	 }
}



void PrintPolyn(Link p)
//打印显示多项式
{
	 Link s;
	 s = p->next;
	 while(s)
	 {
	    printf(" %.2f X^%d", s->coef, s->expn);
	    s = s->next;
	    if(s!=NULL) 
	    {
	    	if(s->coef>=0) 
	        {
	        	printf(" +");
			}
		}
	        
			
	    //若下一项系数为正，则打印'+',否则不打印
	 }
	 printf("\n");
}



int cmp(Link a, Link b)
//比较两结点指数大小，根据情况返回不同值
{
	 if (a->expn<b->expn) 
	 {
	 	return -1;
	 }
	 else if(a->expn == b->expn) 
	 {
	 	return 0;
	 }
	 else 
	 {
	 	return 1;
	 }
}
 
Link AddPolyn(Link pa, Link pb)//pa,pb均指向头结点
//两个多项式相加得一个新多项式，并且返回新多项式的头结点的指针 
{
	 Link newp, p, q, s, pc;
	 float sum;
	 p = pa->next;
	 q = pb->next;
	 newp=(Link)malloc(LEN); //新多项式的头结点
	 pc = newp; //pc指向新多项式的头结点
	 while(p&&q)
	 {
	  switch(cmp(p, q))
	   {
	   case -1:// //若指数：p<q,则将p所指结点链入头结点为newp的链表中，且p向后遍历 
		    s = (Link)malloc(LEN);
		    s->coef = p->coef;
		    s->expn = p->expn;
		    pc->next = s;
		    pc = s;
		    p = p->next;
		    break;
	   case 0://若比较两项的指数相等，则将两项系数相加后得到的项放入头结点为newp的链表中 ，且p,q同时向后遍历 
		    sum = p->coef+q->coef;
		    if(sum!=0.0)//若两项系数相加为0，则不放入头结点为newp的链表中
		    {
			     s = (Link)malloc(LEN);
			     s->coef = sum;
			     s->expn = p->expn;
			     pc->next = s;
			     pc = s;
		    }
		    p = p->next;
		    q = q->next;
		    break;
	   case 1://若指数：q<p,则将q所指结点链入头结点为newp的链表中，且q向后遍历  
		    s = (Link)malloc(LEN);
		    s->coef = q->coef;
		    s->expn = q->expn;
		    pc->next = s;
		    pc = s;
		    q = q->next;
		    break;
	   }
	 }
	 pc->next=p?p:q;//链入pa或pb的剩余项
	 return newp;//返回新多项式的头指针
}
Link SubPolyn(Link pa, Link pb)
/*两个多项式相减得一个新多项式，并且返回新多项式的头结点的指针
相减就是先将减数中每一项的系数变为负，再将两个多项式相加
*/
{
	 Link newp, p, q, s, pc;
	 float sum;
	 newp=(Link)malloc(LEN);
	 pc = newp;
	 p = pa->next;
	 q = pb->next;
	 while(q)
	 {// 将pb中每一项的系数变为负
	  q->coef=0-q->coef;
	  q=q->next;
	 }
 	 q=pb->next;
	 while(p&&q)
	 {
	  switch(cmp(p, q))
	  {
	   case -1: 
		    s = (Link)malloc(LEN);
		    s->coef = p->coef;
		    s->expn = p->expn;
		    pc->next = s;
		    pc = s;
		    p = p->next;
		    break;
	   case 0:
		    sum = p->coef-q->coef;
		    if(sum!=0.0)
		    {
		     s = (Link)malloc(LEN);
		     s->coef = sum;
		     s->expn = p->expn;
		     pc->next = s;
		     pc = s;
		    }
		    p = p->next;
		    q = q->next;
		    break;
	   case 1:  
		    s = (Link)malloc(LEN);
		    s->coef = q->coef;
		    s->expn = q->expn;
		    pc->next = s;
		    pc = s;
		    q = q->next;
		    break;
	    }
	 }
	 pc->next=p?p:q;
	 return newp;
}



Link Reverse(Link p)
/*用头插法逆置链表，
使多项式由降幂变成升幂顺序
或使多项式由升幂变成降幂顺序
*/
{
	 Link head=p;
	 Link q1,q2;
	  q2=head->next;
	  head->next=NULL;//断开头结点与第一个结点
	  while(q2)
	  {
	    q1=q2;   
	    q2=q2->next;
	  	q1->next=head->next; //头插
	  	head->next=q1; 
	  }   
	  return head;//返回链表逆置后的头结点
}
Link MultiplyPolyn(Link A,Link B)
/*两个多项式相乘得一个新多项式，并且返回新多项式的头结点的指针
 相乘前，A，B两个多项式均是升幂排序
 相乘时，A为降幂排序，B为升幂排序 
*/
{
	 Link pa,pb,pc,s,head;
	 int k,maxExpn,minExpn;
	 float coef;
	
	 head=(Link)malloc(LEN);//头结点
	 head->next=NULL;
	
	 if(A->next!=NULL&&B->next!=NULL)
	 {
		  minExpn=A->next->expn+B->next->expn; //minExpn为两个多项式中指数和的最小值
		  A=Reverse(A);//将A降幂排列
		  B=Reverse(B);//将B降幂排列
		  maxExpn=A->next->expn+B->next->expn; //maxExpn为两个多项式中指数和的最大值
	 }
	 else
	 {
	   	 return head;
	 }   
	 pc=head;
	 B=Reverse(B);//将B升幂排列
 
   for(k = maxExpn;k>=minExpn;k--)
	{ //多项式的乘积指数范围为：minExpn~maxExpn
	   //根据两项的指数和使每一次循环都得到新多项式中一项 
	   pa = A->next;
	   while(pa !=NULL&&pa->expn>k)
	   { //找到pa的位置
	      pa = pa->next;
       }
   	   pb = B->next;
       while(pb!=NULL&&pa!=NULL&&pa->expn+pb->expn<k)
	   {//如果指数和和小于k，pb后移结点
         pb = pb->next;
       }
  		coef=0.0;
		while(pa!=NULL&&pb!=NULL)
		{
		   if(pa->expn+pb->expn==k)
		   { //如果指数和等于k,系数和累加，且pa，pb均后移结点
		    	coef+=pa->coef*pb->coef;
		        pa=pa->next;
		        pb=pb->next;
		   }
		   else if(pa->expn+pb->expn>k)
		   {//如果指数和大于k，pb后移结点
		    	pa = pa->next;
		   }
		   else
		   {//如果指数和和小于k，pb后移结点
		    	 pb = pb->next;
		   } 
		}
		if(coef!=0.0)
		{
		  //如果系数和不为0，则生成新结点，将系数和指数赋给新结点后插入到新多项式中
	   	  s=(Link)malloc(LEN);
	      s->coef=coef;
	      s->expn=k;
	      s->next=pc->next;
	      pc->next=s;
	      pc=s;
	    }
 	}
	 B = Reverse(B);
	 head=Reverse(head);
	 return head; //返回新多项式的头结点
}



void Calculate(Link p,float x)
//代入确定的x到多项式中求值
{
	 Link q=p->next;
	 float sum;
	 float result=0;//求的结果
	 while(q)
	 {
		  sum=1.0;
		  for(int i=1;i<=q->expn;i++)
		  {//先求每一项的 X^expn 的值
		     sum=sum*x;
		  }
		  result+=sum*q->coef; //再使系数与sum相乘后求每一项的值，最后累加
		  q=q->next;
	 }
	 printf("将X的值代入多项式中计算的结果为：%.5f\n",result);
}

