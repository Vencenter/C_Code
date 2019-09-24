
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct BTreeNode
{
	char data;
	struct BTreeNode* lchild;
	struct BTreeNode* rchild;
} BTNode;
 
int calcula(BTNode* T)
{
	if(T==NULL)
		return 0;
	if(T->data <='9'&&T->data >='0')
		return (T->data-'0');
	else
	{
		switch(T->data)            //因为这一步的T->data必为运算符，则必有左右孩子节点且不空
		{
     		case'+':  return calcula(T->lchild) + calcula(T->rchild); break;
			case'-':  return calcula(T->lchild) - calcula(T->rchild); break;
			case'*':  return calcula(T->lchild) * calcula(T->rchild); break;
			case'/':  return calcula(T->lchild) / calcula(T->rchild); break;
		}
	}
}
 
char* input_cheak_str()            //字符串动态输入与检测函数
{
	printf("请输入一个简单算术表达式(一位正整数且只有+-*/无括号,输入空格结束):\n");
	int ch_num=0;
	char ch,*str;
	str=(char*)malloc(sizeof(char));
	while((ch=getchar())!='\n')    //设置按照输入字符数变化的字符数组(内存足够则不受数组长度影响)
	{
		if(ch_num%2==1)            //下标为奇数，字符应为运算符号
		{
			if(ch!='+' && ch!='-' && ch!='*' && ch!='/')
			{
				printf("第%d个字符输入不合法!应为“+-*/”之一",ch_num+1);
				return '\0';
			}
		}
		else                       //下标为偶数，字符应为数字
		{
			if(!(ch>='0' && ch<='9'))
			{
				printf("第%d个字符输入不合法!应为0至9数字之一",ch_num+1);
				return '\0';
			}
		}
		str[ch_num]=ch;
		str=(char*)realloc(str,(++ch_num+1)*sizeof(char));   //∵ch_num为字符数组下标,而realloc参数为字符个数
	}                                                        //∴新开数组长度参数为下标+2,相当于参数为num++后的num+1
	if(str[ch_num-1]=='+' || str[ch_num-1]=='-' || str[ch_num-1]=='*' || str[ch_num-1]=='/')
	{                                                        //若最后一个字符为运算符则输入不合法
		printf("最后一个字符输入不合法!应为数字!",ch_num+1);
		return '\0';
	}
	str[ch_num]='\0';    //串结尾设置串结束符
	return str;
}
 
/*构建二叉树算法主体思路是将正确(输入时经过检测)的一位正整数无括号的简单表达式字符串，以加减法为分界线(因为会先计算乘除法)
将表达式分割成若干个加减项后再将已生成的加减项节点与加减符号项节点交替连接成树，其中每个加减项节点都是其子树。
*/
 
//本可以用数组表示指针数组ASItem,ASSign,因编译器不支持C99故无法用变量定义数组长,故只能用二级指针和malloc构造指针数组
BTNode* creat_tree(char *str)
{
	int itemCount=0,ASCount=0,len=strlen(str),i; //AS意为addSub加减法,前者为加减项计数,后者为加减符号计数,用于数组下标
	BTNode **ASItem,**ASSign,*root,*p;           //ASItem指针数组存放加减项节点指针,ASSign指针数组存放加减符号节点指针
	ASItem=(BTNode**)malloc((len/2+1)*sizeof(BTNode*));
	ASSign=(BTNode**)malloc((len/2)*sizeof(BTNode*)); 
	if(str[0]=='\0')                             //加减符号节点数必为加减项节点数+1.既itemCount==ASCount+1
		return NULL;
	for(i=0;i<len/2;i++)               //指针数组置空
		ASSign[i]=NULL;
	for(i=0;i<len/2+1;i++)
		ASItem[i]=NULL;
	for(i=0;i<len;i++)                 //读取str字符数组
	{
		if(str[i]<='9' && str[i]>='0')
		{
			p=(BTNode*)malloc(sizeof(BTNode));
			p->data=str[i];
			p->lchild=p->rchild=NULL;
		}
		else if(str[i]=='+'||str[i]=='-')
		{
			ASItem[itemCount++]=p;     //将p节点放入加减项数组
			p=(BTNode*)malloc(sizeof(BTNode));
			p->data=str[i];
			ASSign[ASCount++]=p;
		}   //将加减符号节点指针放入ASSign数组,因有符号节点的孩子必不为空且创建过程不会访问其孩子节点,故无需置空
		else                           //str[i]符号为乘除的情况
		{
			root=(BTNode*)malloc(sizeof(BTNode));
			root->data=str[i];         //将*,/作为数据存入根节点数据域
			root->lchild=p;            //p一定为数字或*,/节点(都是已构造好的)
			p=(BTNode*)malloc(sizeof(BTNode));
			p->data=str[++i];          //此时p为当前节点的下一个节点,此时str[++i]必为数字,且下一个访问的str必为符号
			p->lchild=p->rchild=NULL;
			root->rchild=p;            //根节点的右孩子连上此节点
			p=root;                    //整个根节点构造完毕，传入p
		}
	}
	ASItem[itemCount]=p;
	ASSign[0]->lchild=ASItem[0];       //第一个符号节点左孩子连第一个项节点
	ASSign[0]->rchild=ASItem[1];
	for(i=1;i<ASCount;i++)             //以加减法符号节点作为子树根节点，加减法之间的项的节点为子树根节点的孩子节点
	{                                  //加减符号节点数必为加减项节点数+1.既itemCount==ASCount+1,这里构造时ASCount已自增一次
		ASSign[i]->lchild=ASSign[i-1]; //除第一个节点以外的加减符号节点左孩子都连上一个符号节点
		ASSign[i]->rchild=ASItem[i+1]; //右孩子都连项节点
	}
	return ASSign[ASCount-1];
}
 
int main ()
{
	printf("%d\n",calcula(creat_tree(input_cheak_str())));
	return 0;
}

