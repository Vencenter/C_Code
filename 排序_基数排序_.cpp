#include<iostream>
using namespace std;
int max(int date[],int n){//此函数用于求解所给数组中最大数有几位
	int max=0;
	for(int i=0;i<n;i++){
		int count=1,tem=date[i];
		while(tem/10!=0){//计算每个数的位数，用count计数
			tem=tem/10;
			count++;
		}
		if(count>max)
			max=count;//把最大位数赋值max
	}
	return max;
}
void basesort(int date[],int n){
	int maxx=max(date,n);//取得最大位数
	int num=1;
	for(int i=0;i<maxx;i++){//位数决定排序循环次数
		int count[10];//声明count为了统计每个桶放了几个数
		int temp[10]['n'];//temp相当于桶，前一个数标记第几个篮子，后一个为了标记放的个数
		for(int f=0;f<10;f++){//对声明数组初始化
			count[f]=0;
		}
		for(int g=0;g<10;g++){//对声明数组初始化
			for(int z=0;z<n;z++){
				temp[g][z]=0;
			}
		}
		for(int j=0;j<n;j++){
			int fg=date[j]/num;//num是变量，因为每次循环比较的位是不同的
			int k=fg%10;
			count[k]++;
			int te=count[k]-1;
			temp[k][te]=date[j];//把数据放k桶的te位上存储
		}
		int b=0;
		for(int h=0;h<10;h++){
			if(count[h]>0){//h>0说明h桶内有数字存储
				for(int v=0;v<count[h];v++){//count[h]是h桶的存储个数
					date[b]=temp[h][v];//把桶内排好的数全都倒给要排序的数组，进行下轮排序
					b++;
				}
			}
		}
		num=num*10;
	}
}
 
void print(int date[],int n){//打印排好序的数组
	for(int i=0;i<10;i++){
		cout<<date[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int date[10]={16,21,5,49,33,456,327,56,65,234};
	basesort(date,10);
	print(date,10);
	return 0;
}
