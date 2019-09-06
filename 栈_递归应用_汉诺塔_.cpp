#include<stdio.h>
#include<stdlib.h>
void hanoi(int n, char a,char b,char c);
void move(int n, char c,char b);
long c1=0;
void hanoi(int n, char a,char b,char c)
{
	if(n==1)
	{
		move(n,a,b);
	}
	else
	{
		hanoi(n-1,a,c,b);
		move(n,a,b);
		hanoi(n-1,c,b,a);
	}
}
void move(int n, char a,char b)
{
	c1++;
	
	printf("move %d panzi %c -> %c : nums %ld \n",n,a,b,c1);
}
int main()
 {


 
    int n;
	printf("input panzi of number:\n");
	scanf("%d",&n);
	printf("move %d panzi a->b,use c as temp:\n",n);
	hanoi(n,'A','B','C');
	printf("move nums %ld \n",c1);
	return 0;
}


