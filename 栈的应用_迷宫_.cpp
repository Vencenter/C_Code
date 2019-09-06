#include <stdio.h>
#include <stdlib.h>
 
#define ROW 10
#define COL 10
#define Max 100
#define True 1
#define False 0


typedef struct 
{
	int pos_x;
	int pos_y;
}pos;

typedef struct 
{
	pos data[Max];
	int top;
}stack,*stk;

int init_stack(stack &s)
{
	s.top=-1;
	return 0;	
}
int push_stack(stack &s,pos &e)
{
	if(s.top>Max-1)
	{
		return False;
	}
	
	s.data[++s.top]=e;
	//printf("-->%d,%d\n",e.pos_x,e.pos_y);
	return True;
}

pos pop_stack(stack &s,pos &e)
{
	if(s.top>-1)
	{
	    e=s.data[s.top--];
	    //printf("-->%d,%d\n",e.pos_x,e.pos_y);

	    
	    return e;
	}

}

pos top_stack(stack s)
{
	if(s.top>-1)
	{
	    return s.data[s.top];
	}

}


int empty_stack(stack s)
{
	if(s.top==-1)
	{
	    return NULL;
	}
	return True;
	
}
int miwu[12][12]=
	{
		1,1,1,1,1,1,1,1,1,1,1,1,
		1,0,1,1,1,1,1,1,1,1,0,1,
		1,0,1,0,1,0,1,0,1,1,0,1,
		1,0,0,1,1,0,1,0,0,1,0,1,
		1,0,0,0,1,0,0,0,0,0,0,1,
		1,0,0,1,1,0,1,0,0,1,0,1,
		1,1,0,0,1,0,1,0,1,1,0,1,
		1,0,1,0,0,0,1,0,1,1,0,1,
		1,1,0,1,0,0,1,0,1,0,0,1,
		1,1,1,1,0,0,1,0,0,1,0,1,
		1,1,1,1,1,1,1,1,1,1,0,1,
		1,1,1,1,1,1,1,1,1,1,1,1,
	};
int curstep=1;
int migong()
{

	int i,j;
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			if(miwu[i][j]==1)
			{
				printf("■" );
			}
			else
			{
				printf("  " );
			}
		}
		printf("\n");
	}	
	/*printf("\n\n");
	printf("----------------------------------\n");
	printf("----------------------------------\n");
	printf("该迷宫起始坐标(%d，%d).\n",1,1);
	printf("该迷宫终点坐标(%d，%d).\n",10,10);
	printf("----------------------------------\n");
	printf("----------------------------------\n");*/
	printf("\n\n");
} 
int migong1()
{

	int i,j;
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			if(miwu[i][j]==1)
			{
				printf("■" );
			}
			else if(miwu[i][j]==0)
			{
				printf("  " );
			}
			else
			{
				//printf("%2d" ,miwu[i][j]-1);
				printf("〇" );
			}
		}
		printf("\n");
	}	
	printf("\n\n");

} 
int migong2()
{

	int i,j;
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			if(miwu[i][j]==1)
			{
				printf("■" );
			}
			else if(miwu[i][j]==0)
			{
				printf("  " );
			}
			else
			{
				printf("%2d" ,miwu[i][j]-1);
				//printf("〇" );
			}
		}
		printf("\n");
	}	
	printf("\n\n");

} 
/*判断当前位置是否可行，即判断是路，还是墙*/
int pass(pos p)
{
	if (miwu[p.pos_x][p.pos_y]==1)
		return 0;
	else
		return 1;
}
/*将当前的步数填写在走的每一步正确的路上，当发现走不通时，会把当时写的信息
用‘1’抹掉，代表走不通。*/
void footPrint(pos p)
{
	miwu[p.pos_x][p.pos_y] = curstep;
	
}
pos nextPos(pos &curpos, int e)
{
	if(e==1)
	{
		curpos.pos_x+=0;
		curpos.pos_y+=1;
	}
	else if(e==2)
	{
		curpos.pos_x+=1;
		curpos.pos_y+=0;
	}
	else if(e==3)
	{
		curpos.pos_x-=0;
		curpos.pos_y-=1;
	}
	else if(e==4)
	{
		curpos.pos_x-=1;
		curpos.pos_y-=0;	
	}
	return curpos;
}

void markPrint(pos p)
{
	miwu[p.pos_x][p.pos_y] = 1;
}
int game_ways(pos start,pos end,stack &s)
{
	int i,way=1,tmp=0;
	
	pos cur_node;
	stk correct_path;
	push_stack(s,start);
	curstep++;
	footPrint(start);
	//miwu[start.pos_x][start.pos_y]=curstep;
	
	cur_node=start;
	//printf("-->%d\n",miwu[start.pos_x][start.pos_y]);
	while(s.top>=0)
	{
		cur_node=top_stack(s);
        if(cur_node.pos_x == end.pos_x && cur_node.pos_y == end.pos_y)
		{ 
			
            while(s.top >= 0)
			{
                pop_stack(s, correct_path->data[s.top]);
            }
            //correct_path->top = i; 
            return 0;
		}
		else
		{
			way=1;
			while(way<=4)
			{
				if(way==1 && miwu[cur_node.pos_x][cur_node.pos_y+1]==0)
				{
					cur_node.pos_y+=1;
					tmp=1;	
					break;
				}
				else if(way==1 && miwu[cur_node.pos_x+1][cur_node.pos_y]==0)
				{
					cur_node.pos_x+=1;	
					tmp=1;	
					break;
				}
				else if(way==1 && miwu[cur_node.pos_x][cur_node.pos_y-1]==0)
				{
					cur_node.pos_y-=1;	
					tmp=1;	
					break;
				}
				else if(way==1 && miwu[cur_node.pos_x-1][cur_node.pos_y+1]==0)
				{
					cur_node.pos_x-=1;	
					tmp=1;	
					break;
				}
				way++;
			}
			if(tmp==1)
			{
				curstep++;
				footPrint(cur_node);
				//printf("--+++++>%d\n",miwu[cur_node.pos_x][cur_node.pos_y]);
			 	push_stack(s,cur_node);
			 	
			 	tmp=0;
			}
			else
			{
				//printf("--+++++>%d\n",miwu[cur_node.pos_x][cur_node.pos_y]);
				
				
				
				//curstep++;
				//footPrint(cur_node);
				cur_node=pop_stack(s, correct_path->data[s.top]);
			
			}
			
			
		}
	}
	
	
	return 0;
}

int main()
{
	migong();
	pos start={1,1};
	pos end  ={10,10};
	
	stack s;
	init_stack(s);
	
	game_ways(start,end,s);
	migong1();
	migong2();
	
	return 0;	
}
