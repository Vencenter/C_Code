#include<stdio.h>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;

#define Max_vexs 25
#define status int
#define Max_type -1

typedef struct 
{
	status arcs[Max_vexs][Max_vexs];
	status vexnum,arcnum;
}graph;

status createUDG(graph *G)
{
	int i,j,w;
    
    printf("辺と点の数量を輸入してください：\n");
    scanf("%d %d",&G->vexnum,&G->arcnum);
	
	for(i=1;i<G->vexnum+1;i++) 
	{
		for(j=1;j<G->vexnum+1;j++) 
		{ 	
		if(i==j)
		{
			G->arcs[i][j]= 0; 
		}
		else
		{
			G->arcs[i][j]= Max_type; 
		}

		}
	}

	cout<<"请输入边（vi, vj)和权值w,三个变量空格分隔即可："<<endl;
	for(int k=1;k<G->arcnum+1;k++) 
	{
		cin>>i>>j>>w;
		G->arcs[i][j]=w;
	}	
	
}
status printUDG(graph *G)
{
	int i,j;
    printf("辺と点の数量を輸出します：\n");
    printf("%d %d\n",G->vexnum,G->arcnum);
	
	printf("全て点の連絡の数字を輸出します：\n");
	for(i=1;i<G->vexnum+1;i++) 
	{
		for(j=1;j<G->vexnum+1;j++) 
		{ 
		printf("%5d",G->arcs[i][j]);
		}
		printf("\n");
	}
	
	
	
}
void Graph_Dfs(graph M, int visiting_Node)
{
	int isVisited[M.vexnum+1]={0};
	int visited_count=0;//记录已经访问过的节点
    stack<int> p;
    
    while(visited_count<M.vexnum)
   	{
   		if(isVisited[visiting_Node]==0)
		{
            cout<<"--->"<<visiting_Node<<" \n";
            visited_count++;
        }

   		p.push(visiting_Node);
        isVisited[visiting_Node]=1;
        
        int j;
        for(j=1;j<M.vexnum+1;j++)
		{
            if(M.arcs[visiting_Node][j]!=0 && isVisited[j]==0 && M.arcs[visiting_Node][j]!=Max_type )
			{
				break;
            }
  	    }
  	    
  	    
  	    if(j==M.vexnum+1)
  	    {
  	    	p.pop();
            if(!p.empty())
			{
				
                visiting_Node=p.top();
                //cout<<"---+"<<visiting_Node<<" \n";
                p.pop();//出队2次，原因上层的节点会再次入队 
            }
            else
            {
            	break;
			}
  	    	
		}
		else
		{
			visiting_Node=j;	
		}
    		
	}
        
}

int main()
{
	graph gh;
	
	createUDG(&gh);
	printUDG(&gh); 
	cout<<"\n该图的深度遍历为：\n"<<endl;
    Graph_Dfs(gh,1);
    
 
	
	
	return 0;
}
