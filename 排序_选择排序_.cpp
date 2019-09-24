
#include <stdio.h>
#include <stdlib.h> 

void SelectSort(int a[],int n)
{

	int i,j,k,temp;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[k]>a[j])
			{
				k=j;
			}	
		}
		printf("min:%d  \n",a[k]);
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;
		
		for(int s=0;s<n;s++)
		{
			printf("%d ",a[s]);
		}
		printf(" \n");
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d \n",a[i]);
	}
	
}

int main()
{
	
	int a[10]={1,9,5,2,3,6,7,4,8,10};
	int n=10; 
	//printf("please input 10 sum:\n");
	
	
	
	SelectSort(a,n);
	//for(i=0;i<10;i++) 
   	//printf("max:%d  \n",a[i]);

 
}
