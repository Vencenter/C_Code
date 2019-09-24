# include <stdio.h>
# include <string.h>
int Bf(char s[],char t[],int pos)
{
	int j=0,i=pos;
	
	
	int s_len=strlen(s);  
	int t_len=strlen(t);  
	printf("%d:%d\n",s_len,t_len);
	while(i<s_len && j<t_len)
	{
		if(s[i]==t[j])
		{
			printf("-->%c:%c\n",s[i],t[j]);
			++i;
			++j;
		}
		else
		{
			//printf("-->%d:%d\n",i,j);
			i=i-j+1;
			j=0;
			
		}
	}
	printf("%d:%d\n",i,j);
	if(j>t_len-1)
	{
		return i-t_len+1;
	} 
	else
	{
	 	return 0;
	}
	
	
} 
int main()
{
	int pos;
    char s[] ="abffseghsfnrSEFvbnbacsxrdacbhhdrsdcbacba";
    char t[]="acba";
    pos=Bf(s,t,0);
    printf("最终串的所在位置为:%d\n",pos);

    return 0;
}
