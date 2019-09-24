#include<stdio.h>
#include<stdlib.h>

#define MAX  256 
typedef char TElemType;
typedef struct BiTNode
{
	
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*Bitree;
Bitree  CreateBitree(Bitree &r)
{
	

	char ch;
	scanf("%c",&ch); 
	printf("顺序表 %c\n",ch);
	if (ch=='#')
	{
		r= NULL;
		
	}
	else
	{
			//printf("顺序表*****************0\n");
	if(!(r=(BiTNode *)malloc(sizeof(BiTNode))))
	{
		exit(-1);
	};
	r->data=ch;
	CreateBitree(r->lchild);
	
	//printf("顺序表*****************1\n");
	CreateBitree(r->rchild);
	//printf("顺序表*****************2\n");
	}

	
	return 0;
}
void Prefirst(Bitree r) 
{
	if(r!=NULL)
	{
		printf("%c ",r->data);
		Prefirst(r->lchild);
		Prefirst(r->rchild);
	}
	
} 

Bitree D_serach(Bitree r,char key) 
{
	if(r==NULL)
	{
		return NULL;
	}
	if(key==r->data)
	{
		printf("successful->%c",r->data);
		return r;
	}
	else if(key<r->data)
	{;
		return D_serach(r->lchild,key); 
	}
	else if(key>r->data)
	{
		return D_serach(r->rchild,key); 
	}
	
}
Bitree C_serach(Bitree r,char key) 
{
	while(r!=NULL)
	{
		if(key==r->data)
		{
		
		printf("successful->%c",r->data);
		return r;	
		}
		else if(key<r->data)
		{
			r=r->lchild;
		}
		else if(key>r->data)
		{
			r=r->rchild;
		}
		
	}
	return NULL;
	
}

int main()
 {

    int i,a[]={'5','1','8','0','3','7','9','#','#','2','4','#','#','#','#','#','#','#'}; 
    char c;
    Bitree r;
	printf("input顺序表的结构，\n结束 ：\n");
	CreateBitree(r);
	printf("顺序表的结构，成功 ！\n");
	
	printf("二叉树，先序遍历结果： \n");
	Prefirst(r) ;
	printf("\n ");
	//printf("查找结果：%d \n",C_serach(r,7)->data);
	
	C_serach(r,'7');
	printf("\n ");
	D_serach(r,'7');
	
	
	//54##87##9## 先序的方法创建 















	return 0;
}


