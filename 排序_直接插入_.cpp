
#include <stdio.h>
#include <stdlib.h> 

void InsertSort(int a[],int n)
{

	int i,j,temp;
	for(i=1;i<n;i++)
	{
			
		temp=a[i];
		j=i-1;
		while(j>=0 && temp<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
		for(int t=0;t<n;t++)
		{
			printf("%d ",a[t]);
		}
		printf("\n");
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	
	
}

int main()
{
	
	int a[10]={1,9,5,2,3,6,7,4,8,10};
	int n=10; 
	//printf("please input 10 sum:\n");
	
	
	
	InsertSort(a,n);
	//for(i=0;i<10;i++) 
   	//printf("max:%d  \n",a[i]);

 
}
