#include <iostream>
using namespace std;


void merge(int arr[],int l,int mid,int r)
{
	
	
    int aux[r-l+1];//开辟一个新的数组，将原数组映射进去 
    for(int m=l;m<=r;m++)
    {
        aux[m-l]=arr[m];
    }
    
    int i=l,j=mid+1;//i和j分别指向两个子数组开头部分
    
    for(int k=l;k<=r;k++)
    {
        if(i>mid)
        {
            arr[k]=aux[j-l];
            j++;
        }
        else if(j>r)
        {
            arr[k]=aux[i-l];
            i++;
        }
                else if(aux[i-l]<aux[j-l])
                {
                    arr[k]=aux[i-l];
                    i++;    
                }
                else
                {
                    arr[k]=aux[j-l];
                    j++;
                }
    } 
   

} 
//递归的使用归并排序，对arr[l....r]排序 
void merge_sort(int arr[],int l,int r)
{
	

    if(l >=r)
        return ;
    int mid=(l+r)/2; 
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);
    merge(arr,l,mid,r);
     
     for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void my_merge_sort(int arr[],int n)
{
    merge_sort(arr,0,n-1);    
} 
int main()
{
    int a[]={4,2,8,5,9,3,0,10,6,1};
    int n=10; 

    my_merge_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
