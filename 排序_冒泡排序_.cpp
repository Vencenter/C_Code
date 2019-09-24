#include <stdio.h>
 
int main()  
{  
    int i,j,m; 
 	int a[10]={49,38,65,97,49,13,27,76};
	int n=8;
  
  
    for(i=0;i<n-1;i++)          //n个数要进行n-1趟比较
    {  
        for(j=0;j<n-1-i;j++)       //每趟比较n-i次  
            if(a[j]>a[j+1])      //依次比较两个相邻的数，将小数放在前面，大数放在后面  
            {  
                int temp=a[j];   //temp是局部变量
                a[j]=a[j+1];  
                a[j+1]=temp;  						  
            }  
		     for(m=0;m<8;m++)
			{
				printf("%d  ",a[m]);
			}
			printf("\n");
    }  
    printf("\n");
  
    for(i=0;i<8;i++)            //输出比较之后的数组  
        printf("%d ",a[i]); 
		
    getchar();                   //解决Microsoft Visual Studio运行完闪退，方便用户查看程序运行结果
    return 0;
}  
