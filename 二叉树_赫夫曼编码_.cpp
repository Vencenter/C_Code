#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned int weight;
    unsigned int parent,lchild,rchild;
}htnode,*huffmantree; 

typedef char **huffmancode;

int min1(huffmantree t,int i)
{
 int j,flag;
 unsigned int k=UINT_MAX; // 取k为不小于可能的值(即unsigned int类型的最大值)
    for(j = 1; j <= i; j++)
    {
   		if(t[j].weight < k && t[j].parent == 0)
    		k = t[j].weight,flag = j;    
	}
      
   t[flag].parent=1;
   return flag;
}
// s1为最小的两个值中序号小的那个
void select(huffmantree &t,int i,int &s1,int &s2)
{
  int j;
  s1=min1(t,i);
  s2=min1(t,i);
  if(s1 > s2)
    {
       j=s1;
       s1=s2;
       s2=j;
    }
}

void huffmancoding(huffmantree &HT,huffmancode &HC,int *w,int n)
{ 
	if(n<=1)
	{
		return;
	}
	int m,i,s1,s2,start;
    unsigned c,f;
    huffmantree p;
    char *cd;
    m=2*n-1;
    HT=(huffmantree)malloc((m+1)*sizeof(htnode));
    for(p=HT+1,i=1;i<=n;++i,++p,++w)   
    {
       	//*p={*w,0,0,0};
       (*p).weight=*w;
       (*p).parent=0;
       (*p).lchild=0;
       (*p).rchild=0;
 	}
 	for(;i<=m;++i,++p) 
	 {
	   (*p).weight=0;
       (*p).parent=0;
       (*p).lchild=0;
       (*p).rchild=0;
	 } 
    for(i=n+1;i<=m;++i) 
    {
        select(HT,i-1,s1,s2);
        printf("HT[%d] --> %d,&& HT[%d] --> %d\n",s1,HT[s1].weight,s2,HT[s2].weight);
        HT[s1].parent=HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
    HC=(huffmancode)malloc((n+1)*sizeof(char*));
    cd=(char*)malloc(n*sizeof(char));
    cd[n-1]='\0';
    for(i=1;i<=n;i++)
    {  
      start=n-1;
      for(c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent)
      {
      	//printf("%d , %d--->  %d\n",i,f,HT[f].lchild);   
      	if(HT[f].lchild==c)
         {
         	cd[--start]='0';
		 }   
         else
         {
        	cd[--start]='1';
	     }
	     printf("%d --->  %s\n",i,&cd[start]);   
	  }    
	//printf("%d --->  %s\n",i,&cd[start]);    
    HC[i]=(char*)malloc((n-start)*sizeof(char));
    strcpy(HC[i],&cd[start]);
   }
   free(cd);
    
     


}



int main()
{
    huffmantree HT;
    huffmancode HC;
    int *data,n,i;
    printf("请输入权值的个数(>1)：\n");
    scanf("%d",&n);
    data=(int*)malloc(n*sizeof(int));
    printf("请依次输入%d个权值(整型)：\n",n);
    for(i=0;i<=n-1;i++)
    {
		scanf("%d",data+i);
	} 
      
    huffmancoding(HT,HC,data,n);
    for(i=1;i<=n;i++)
	{
		puts(HC[i]);
	}
        
    return 0;
}
