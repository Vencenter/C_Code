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
void Dijkstar(graph *G,int u)
{
	
	int A[G->vexnum+1][G->vexnum+1];
	int i,j,k;
	for(i=1;i<G->vexnum+1;i++) 
	{
		for(j=1;j<G->vexnum+1;j++) 
		{ 
		A[i][j]=G->arcs[i][j];
		}
	}
		for(k=1;k<G->vexnum+1;k++) 
		{
			for(i=1;i<G->vexnum+1;i++) 
			{
				for(j=1;j<G->vexnum+1;j++) 
				{ 
				
					printf("%5d , %5d + %5d  \n",A[i][k],A[k][j],A[i][j]);
					if(A[i][j]>A[i][k]+A[k][j])
					{
						//printf("%5d , %5d + %5d ,  %5d,%5d,%5d \n",A[i][j],A[i][k],A[k][j],i,j,k);
						A[i][j]=A[i][k]+A[k][j];
					}
					//printf("\n");
				}
			}
		}
	
	printf("\n");

	
	for(i=1;i<G->vexnum+1;i++) 
	{
		for(j=1;j<G->vexnum+1;j++) 
		{ 
		printf("%5d",A[i][j]);
		}
		printf("\n");
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
