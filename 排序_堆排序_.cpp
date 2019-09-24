#include<stdio.h>
#include<iostream>
using namespace std;
void sift(int a[],int low,int high)
{
	int i=low;
	int j=2*i+1;
	int temp=a[i];
	while(j<=high)
	{
		if(j<high && a[j]<a[j+1]) 
		{
			j++;
		}
		if(temp<a[j])
		{
			a[i]=a[j];
			i=j;
			j=2*i+1;
		}
		else
		{
			break; 
		}
	}
	a[i]=temp;
	
}
void heapSort(int a[],int n)
{
	int i,j;
	for(i=n/2-1;i>=0;i--)
	{
		sift(a,i,n-1);
	}
	int temp;
	
	for(i=n-1;i>0;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		sift(a,0,i-1);
	}
	
	for(int t=0;t<n;t++)
	{
		cout<<a[t]<<" ";
	}
}
int main()
{
	int a[]={49,38,65,97,76,13,27,49,100};
	int n=9;
	heapSort(a,n);
	
	
	return 0;
} 
