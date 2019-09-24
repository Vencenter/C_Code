/*Shell排序数组
? version: Shell插入排序
*/
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#ifndef N
#define N 100
#endif // N
 
 

 
inline int Shell_Sort(int arr[],int n)
{
    int i, j, k, tmp;
    int incre;  //选择一个增量，这里我们用简单的二分法
 
    for(incre=n/2;incre>0;incre/=2)
    { 
    	printf("%4d,%d\n", tmp,incre);
    	for(i=incre;i<n;i++)
    	{
    		tmp=arr[i];
    		
    		for(j=i;j>=incre&&arr[j-incre]>tmp;j-=incre)
    		{
    			arr[j]=arr[j-incre];
			}
			arr[j]=tmp;
    		
		}
  
         for(int s = 0;s < 10;s++)
		    {
		        printf("%4d", arr[s]);
		 
		    }
	        printf("\n");
    }
}
 
int main( )
{
    int i;
 
     int arr[10]={5,4,5,6,8,9,1,4,3,2};    /*定义数组及变量为基本整型*/
    //printf("please enter 10 numbers: \n");
 
    //for(i = 0;i < N/10;i++)
    //{
     //   scanf("%d", &arr[i]);
    //}
 
    Shell_Sort(arr,10);
 
    printf("\n");
    printf("the ordered array is: \n");
 
    for(i = 0;i < 10;i++)
    {
        printf("%4d", arr[i]);
 
    }
}
    
   
