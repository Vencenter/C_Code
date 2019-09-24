#include <stdio.h>
int main()
{
   int i,j,k,m;
   int a[8]={49,38,65,97,49,13,27,76};
   int b=0;
 
   for(i=0;i<8;i++)
	{
		for(j=0;j<i+1;j++)
		{
			
			if(i!=j)
			{
				//b++;
			   // printf("%d\n",b);
				if(a[i]<a[j])
				{
					k=a[i];
					a[i]=a[j];
					a[j]=k;
				}
			}
				
			
		 
		}
		// for(m=0;m<8;m++)
		  // {
		  // 	printf("%d  ",a[m]);
		 //  }
		  // printf("\n");
		
	
	}
   
   for(i=0;i<8;i++)
   {
   	printf("%d  ",a[i]);
   }
   

}

