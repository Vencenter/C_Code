#include<stdio.h>
#include<iostream>
using namespace std;
#include<stack>
#include<queue>
#define Max_vexs 25
#define status int
#define Max_type 50
typedef struct 
{
	char vexs[Max_vexs];
	status arcs[Max_vexs][Max_vexs];
	status vexnum,arcnum;
  
	
}graph;

status createUDG(graph *G)
{
	int i,j,w;
	
	bool isDirected=1;
    
    //printf("辺と点の数量を輸入してください：\n");
    //scanf("%d %d",&G->vexnum,&G->arcnum);
	G->vexnum=5;
	G->arcnum=7;
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
	

	
	/*cout<<"请输入边（vi, vj)和权值w,三个变量空格分隔即可："<<endl;
	for(int k=1;k<G->arcnum+1;k++) 
	{
		cin>>i>>j>>w;
		G->arcs[i][j]=w;
		if(not isDirected)
		{
			G->arcs[j][i]=w;
		}
	}*/
	
	G->arcs[1][2]=5;
	G->arcs[1][3]=3;
	G->arcs[1][5]=8;
	G->arcs[2][3]=2;
	G->arcs[2][4]=1;
	G->arcs[3][5]=4;
	G->arcs[4][3]=1;
	
	
	
}
status printUDG(graph *G)
{
	int i,j;
    printf("辺と点の数量を輸出します：\n");
    printf("%d %d\n",G->vexnum,G->arcnum);
	
	//printf("インプート　頂点のデータ：\n");
	
	printf("全て点の連絡の数字を輸出します：\n");
	/*for(i=1;i<G->vexnum+1;i++) 
	{
		printf("%5c",G->vexs[i]);
	}*/
		printf("\n");
	for(i=1;i<G->vexnum+1;i++) 
	{
		for(j=1;j<G->vexnum+1;j++) 
		{ 
		printf("%5d",G->arcs[i][j]);
		}
		printf("\n");
	}
	
}
void Dijkstar(graph *G,int visit_node)
{
	
	   int min_weight[G->vexnum+1];
	   int path[G->vexnum+1];
	   int from_adjvex[G->vexnum+1];
	   
	   for(int i=1;i<G->vexnum+1;i++)
	   {
	   	 min_weight[i]=G->arcs[visit_node][i];
	   	 path[i]=0;
	   	 if(G->arcs[visit_node][i]==0 || G->arcs[visit_node][i]==Max_type)
	   	 {
	   	 	from_adjvex[i]=0;
		 }
		 else
		 {
		 	from_adjvex[i]=visit_node;
		 }
	   } 
	   path[visit_node]=1;
	   int min_arc,min_vex;
	   for(int i=1;i<G->vexnum+1;i++)
	   {
	   	    min_arc=Max_type;
		    for(int j=1;j<G->vexnum+1;j++)
		    {
		    	if(min_arc>min_weight[j] && min_weight[j]!=0&&path[j]!=1)
		    	{
		    		min_arc=min_weight[j];
		    		min_vex=j;
				}
			}
			//printf("%d %d\n",min_vex,path[min_vex]);
			path[min_vex]=1;
			for(int j=1;j<G->vexnum+1;j++)
		    {
		    	if(G->arcs[min_vex][j]+min_weight[min_vex]<min_weight[j]&&min_weight[j]!=0)
		    	{
		    		min_weight[j]=G->arcs[min_vex][j]+min_weight[min_vex];
		    		from_adjvex[j]=min_vex;
				}
			}
			
	   }


	/*for(int i=1;i<G->vexnum+1;i++)
	{
	   	printf("%d\n",from_adjvex[i]);
	}*/
	
	    printf(" \n");
		for(int i=1;i<G->vexnum+1;i++) 
		{
			if(i!=visit_node)
			{
				printf("%d,%d = %d\n",visit_node,i,min_weight[i]);
				int t=from_adjvex[i];
				
				printf("%d",i);
				while(t!=0)
				{
					printf("-->%d",t);
					t=from_adjvex[t];
					
					
				}
				
				printf(" \n");
			}
		}

   	
			
	
		   

   		
	
}

int main()
{
	graph gh;
	
	createUDG(&gh);
	printUDG(&gh); 
	Dijkstar(&gh,1);
	
	return 0;
}
