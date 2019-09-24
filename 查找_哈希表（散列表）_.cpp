#include <stdio.h>   
#include <stdlib.h>   

#define ElemType int
#define NULLKEY -1000
#define HASHSPACE 25
#define HASHSIZE 13


typedef struct
{
	ElemType *elem;
	int count;
	int sizeindex;
}HashTable;
void Initial(HashTable &T)
{
	T.elem=(ElemType*)malloc(HASHSPACE*sizeof(ElemType));
	T.sizeindex=HASHSPACE;
	T.count=0;
	for (int i=0;i<HASHSPACE;i++) 
	{ 
	    T.elem[i]=NULLKEY; 
	} 
}
int hash(int key)
{
	return key%HASHSIZE;
}
int InsertTable(HashTable &T,int key)
{
	int key_pos;
	key_pos=hash(key);
	if(T.count==T.sizeindex)
	{
		printf("space not enough\n");
		return -1;
	}

	while(T.elem[key_pos]!=NULLKEY)
	{
		//key_pos=(++key_pos)%HASHSIZE;
		key_pos=hash(++key_pos);
	}
	printf("--->%d %d\n",key_pos,key);
	T.elem[key_pos]=key;
	T.count++;
	
	
}
int DelNumTable(HashTable &T,int key)
{
	int key_pos;
	key_pos=hash(key);
	while(T.elem[key_pos]!=NULLKEY)
	{
		if(T.elem[key_pos]==key)
		{
			printf("del->%d %d\n",key,key_pos);
			T.elem[key_pos]=NULLKEY; 
			T.count--;
			return 0;
		}
		else
		{
			key_pos=(++key_pos)%HASHSIZE;
		}
	}
	printf("%d,not find,so not del\n",key);
	return -1;
}
int SerachTable(HashTable &T,int key)
{
	int key_pos;
	key_pos=hash(key);
	while(T.elem[key_pos]!=NULLKEY)
	{
		if(T.elem[key_pos]==key)
		{
			printf("find->%d %d\n",key,key_pos);
			return 0;
		}
		else
		{
			key_pos=(++key_pos)%HASHSIZE;
		}
	}
	printf("%d,not find\n",key);
	return -1;
}
int main()
{
	
	HashTable T;
	int arr[]={5,21,34,8,6,32,48}; 
	Initial(T);
	for(int i=0;i<7;i++) 
  	{ 
		InsertTable(T,arr[i]);
	}
	SerachTable(T,21);
	DelNumTable(T,6);
	SerachTable(T,8);
	printf("T->len=%d\n",T.count);
	return 0;
}
