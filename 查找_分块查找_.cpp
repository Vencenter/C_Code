#include <stdio.h>
#include <stdlib.h> 


typedef struct
{
	int maxkey;
	int low,high;
}indexdata;


int insertSort(indexdata index[],int low,int high,int key)
{
	int count=0;
	int mid;
	while(low<=high) 
	{ 
		count++;
		mid=(low+high)/2;
		//printf("-->%d-->%d-->%d\n",low,high,mid);
		
		if(key==index[mid].maxkey) 
		{
			//printf("查找->%d，在%d个位置,次数-->%d  \n",key,mid+1,count);	
			return mid;
		}	
		else if(key>index[mid].maxkey) 
		{
			low=mid+1;
			
		}
		else if(key<index[mid].maxkey) 
		{
			high=mid-1;	
		}
		
		/*if(low>high) 
		{
			
		}	*/
			//return -1;
   	} 
   	return mid;

}
int areaSort(int data[],int low,int high,int key)
{
	int count=0;
	int i;
	for(i=low;i<=high;i++)
	{
		//printf("->%d \n",data[i]);
		if(key==data[i])
		{
			printf("查找->%d，在%d个位置 \n",key,i+1);
			return i;
		}
		
	}
	return -1;

}
int main()
{
	int data[15]={2,1,0,5,4,3,7,6,8,9,10,11,15,18,20};
	int i,j; 
	
	int num=sizeof(data)/sizeof(data[0]); 
	indexdata index[5];
	int max;
	for(i=0;i<5;i++)
	{
		max=data[j];
		//printf("%d-> %d\n",3*i,3*i+2);
		for(j=3*i;j<3*i+3;j++)
		{
			//printf("%d \n",data[j]);
			if(max<data[j])
			{
				max=data[j];
			}
			
		}
		index[i].maxkey=max;
		index[i].high=3*i+2;
		index[i].low=3*i;
		//printf("low->%d,high->%d,->%d\n",index[i].low,index[i].high,max);
	}
	int mid,pot,th;
	
	
	for(i=0;i<21;i++)
	{
	th=i;
	mid=insertSort(index,0,4,th);
	//printf("->%d %d\n",i,mid);
	//pot=areaSort(data,mid*3,mid*3+2,th);
	//printf("->%d %d %d\n",index[mid].maxkey,th,mid);
	if(index[mid].maxkey>=th)	
	{    
		//printf("->%d %d\n",mid*3,mid*3+2);
		pot=areaSort(data,mid*3,mid*3+2,th);
	}
	else 
	{    
		mid=mid+1;
		//printf("->%d %d\n",mid*3,mid*3+2);
		pot=areaSort(data,mid*3,mid*3+2,th);
	}
	
	
	}




	//areaSort();


	
	
 
}
