#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define N 60

typedef struct{
	char ch;
	int weight;
	int parent,lchild,rchild;
}HTNode,HuffmanTree[N+1];
 
typedef	char *HuffmanCode[N+1];//
void createHuffmanTree(	HuffmanTree ht,int n);
void select(HuffmanTree ht,int n,int *s1,int *s2);
void HuffmanCode1(HuffmanTree ht,HuffmanCode hc,int n);
void  HuffmandeCode1(HuffmanTree ht,int n);

void main()
{
	HuffmanTree ht;
   HuffmanCode hc;
	int n,i;
	printf("请输入结点个数:");
	scanf("%d",&n);
    getchar();
	for(i=1;i<=n;i++)
	{
	    scanf("%c,%d",&ht[i].ch,&ht[i].weight);
		
        fflush(stdin);
     
	}

	createHuffmanTree(ht,n);
    HuffmanCode1(ht,hc,n);//编码
    HuffmandeCode1(ht,n);//译码
                                                                                                                                                                                                                    
}
void createHuffmanTree(	HuffmanTree ht,int n)
{
	int m=2*n-1;
	int i;
	int s1,s2;
	for(i=1;i<=n;i++)
	{
		ht[i].lchild=0;
		ht[i].parent=0;
		ht[i].rchild=0;
	}


	for(i=n+1;i<=m;i++)
	{
		ht[i].lchild=0;
		ht[i].parent=0;
		ht[i].rchild=0;
		ht[i].weight=0;
	}
	
	for(i=n+1;i<=m;i++)
	{
		select(ht,i-1,&s1,&s2);
	
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[i].lchild=s1;
		ht[i].rchild=s2;
		ht[s1].parent=i;
		ht[s2].parent=i;

	}
}
void select(HuffmanTree ht,int n,int *s1,int *s2)
{
	int i,min1,min2;

	min1=N;
	min2=N;
	for(i=1;i<=n;i++)
	{
		if(min1>ht[i].weight&&ht[i].parent==0)
		{
			*s1=i;
			min1=ht[i].weight;
		}
	}
     	for(i=1;i<=n;i++)
		{
		   if(min2>ht[i].weight&&ht[i].parent==0&&(*s1!=i))
		   {        
			*s2=i;
			min2=ht[i].weight;
		   }
		}
	

}

void HuffmanCode1(HuffmanTree ht,HuffmanCode hc,int n)//编码
{
    char *cd;
	int start,i,c,p;
	 
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
   for(i=1;i<=n;i++)
   {
	   start=n-1;
	   c=i;
	   p=ht[i].parent;
	   while(p!=0)
	   {
		   --start;
		   if(ht[p].lchild==c)
			   cd[start]='0';
		   else
			   cd[start]='1';
		   c=p;
		   p=ht[p].parent;
	   }
	   hc[i]=(char *)malloc((n-start)*sizeof(char));
	  
	   strcpy(hc[i],&cd[start]);
	   printf("%3c:",ht[i].ch);
	   printf("%s\n",hc[i]);//%s输出
	   
   }
   free(cd);
}

void  HuffmandeCode1(HuffmanTree ht,int n)//译码
{

	char d[50];
	int m,i,j=0;
  
	printf("请输入你要译码的二进制数以#结尾:");
	scanf("%s",d);
	getchar();
	m=2*n-1;
   	i=m;
		while(d[j]!='#')
		{
		       
			
				if(d[j]=='0')
				i=ht[i].lchild;
				else
				i=ht[i].rchild;

				if(ht[i].lchild==0&&ht[i].rchild==0)
				{
					printf("%c",ht[i].ch);
					i=m;
				}
			
			j++;
		}
		printf("\n");
	if(ht[i].lchild!=0&&d[j]!='#')
	printf("error\n");
		
	
}



