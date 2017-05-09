#include <stdio.h>
#define HASHSIZE 11
#define N 20
typedef struct
{
	int key;

}Datatype;
typedef struct
{
	Datatype data;
	int times;
}Hashtable;

void createht(Hashtable ht[],Datatype L[],int n);
void  HashInsert(Hashtable ht[],Datatype x,int y);
int HashFunc(int key);
void output(Hashtable ht[],int n);
 int sum(Hashtable ht[],int n);

Hashtable ht[HASHSIZE];


void main()
{
	
	Datatype L[N];
	int n,i,length,a,suma;
	printf("请输入n:");
	scanf("%d",&n);
	printf("请输入key:\n");
	for(i=0;i<n;i++)
	scanf("%d",&L[i].key);
	createht(ht,L,n);
	output(ht,n);
	suma=sum(ht,n);
	length=suma/HASHSIZE;
	if(length<=2)
			printf("成功!\n");
		else{
			printf("失败,是否继续?1-是,0-否:\n");
			scanf("%d",&a);
			if(a==0)    printf("\n");
			else{

	while(length>2)
	{
			createht(ht,L,n);
	         output(ht,n);
             suma=sum(ht,n);
	         length=suma/HASHSIZE;
	}
			}
		}
			


}
void createht(Hashtable ht[],Datatype L[],int n)
{
	int i;
	for(i=0;i<HASHSIZE;i++)
	{
		ht[i].data.key=0;
		ht[i].times=0;
	}
	for(i=0;i<n;i++)
	{
		HashInsert(ht,L[i],L[i].key);
	}
}

void HashInsert(Hashtable ht[],Datatype x,int y)
{
	
	int i,k=0;
	i=HashFunc(x.key);
	
	while(ht[i].times)
	{
		k++;
		i=(++i)%HASHSIZE;
		
	}
     ht[i].times=k;
	ht[i].data.key=y;
	ht[i].times++;


	
}
int HashFunc(int key)
{

	return(key%HASHSIZE);
}

 void output(Hashtable ht[],int n)
 {
	 int i;
	 for(i=0;i<HASHSIZE;i++)
	 {
		 printf("%5d",ht[i].data.key);
	 }
	 printf("\n");
      for(i=0;i<n;i++)
	 {
		 printf("%5d",ht[i].times);
	 }
	  printf("\n");
 }
 int sum(Hashtable ht[],int n)
 {
	 int i,sum=0;
	 
	 for(i=0;i<n;i++)
	 {
		 sum+=ht[i].times;
	 }
	 return(sum);
 }






	 