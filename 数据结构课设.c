#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define N 100

typedef struct node{
    char ch;
    int weight;
    int parent,lchild,rchild;
}htNode,HuffmanTree[512];

typedef char *HuffmanCode[N+1];//
void createHuffmanTree( HuffmanTree ht,int n);
void select(HuffmanTree ht,int n,int *s1,int *s2);
void HuffmanCode1(HuffmanTree ht,HuffmanCode hc,int n);
void  HuffmandeCode1(HuffmanTree ht,int n,char d[]);
void cre(HuffmanTree ht,char ch,int w);

void menu(HuffmanTree ht,HuffmanCode hc,int n);
int  compress(HuffmanTree ht,HuffmanCode hc);
void decompress(HuffmanTree ht,HuffmanCode hc,int n);
void Print(HuffmanTree ht,int n);
void line();

int y=1;
char orgin[N]={0};
char translate[N][N]={0};
char  regin[N]={0};     

void main()
{
	int  n;
	HuffmanTree ht;
    HuffmanCode hc;
    n=compress(ht,hc);
	menu(ht,hc,n);
	
	
	
}

void menu(HuffmanTree ht,HuffmanCode hc,int n)
{
	int p;
	printf("\n");                       
    printf("\n"); 
	printf("\t       ************************              \n");
	printf("\t               欢迎使用系统                      \n");
	printf("\t       ************************               \n");
	printf("\n");
	printf("\n");
	printf("\t         1-----------编码器                 \n");
	printf("\t         2---------- 译码器                 \n");
	printf("\t         3----------打印哈夫曼树                 \n");
	printf("\t         4----------退出                       \n");
	printf("\n");
    printf("\n");
    printf("\n");       
    printf("\n");                       
    printf("\n");      
	
	printf("\tplase input 选择序号:");
	scanf("%d",&p);
	
	switch(p)
	{
		
	case 1:printf("\t编码方式为:\n");HuffmanCode1(ht,hc,n);menu(ht,hc,n);break;
	case 2:decompress(ht,hc,n);menu(ht,hc,n);break;
	case 3:Print(ht,n);menu(ht,hc,n);break;
	case 4:printf("\t退出!\n");break;
	}
}
int compress(HuffmanTree ht,HuffmanCode hc)
{

	
	char  str[300];
	FILE *fp;
	char  filename[]="data.source";
	char file[100]={0};
    int hist[256]={0};
	
	int  i=0,choice,n=0;
	printf("\t请选择是否存在data.source文件,0-否,1-是:\n\t");
	scanf("%d",&choice);
	
	if(choice==0)
	{
		printf("\t请输入您要编码的文件内容(西文	):\n\t");
		fflush(stdin);
		gets(str);
		if((fp = fopen(filename,"w")) == NULL) 
		{
			printf("cannot open file.\n");
			return;
		}
		fputs(str,fp);
		fclose(fp);
	}
	if((fp = fopen(filename,"r")) == NULL) 
	{
		printf("cannot open file.\n");
		
		
	}
	while(!feof(fp))
		fread(&file[i++],1,1,fp);
	fclose(fp);
	
	i=0;
	while (file[i] != 0)    
	{
		orgin[i]=file[i];
		
		hist[file[i]]++; 
		
		i++;
		if(file[i]<0)
			printf("\terror\n");
    }
	
	printf("\t文件中的字符及频率如下:\n");
    for (i=0;i<256;i++)
    {
        if (hist[i] == 0)
        {
            continue;
        }
        else
        {
			
            printf("\t'%c':%d\n",i,hist[i]);
            cre(ht,i,hist[i]);
        }
    }
    printf("\n");
	n=y-1;

    createHuffmanTree(ht,n);
	return n;
    
}

void decompress(HuffmanTree ht,HuffmanCode hc,int n)//
{
	
	char filename[]="data.code";
	FILE *fp;
	int i=0;
	char str[N];
	HuffmanCode1(ht,hc,n);
	if((fp = fopen(filename,"r")) == NULL) 
	{
		printf("cannot open file.\n");
		return;
	}
    
	fgets(str,N,fp);
	fclose(fp);                                                                                                                                                                                                                                                                                                                            
  
	printf("\t译码结果为:\n\t");
	HuffmandeCode1(ht,n,str); //译码
	
	
	
	
}

void cre(HuffmanTree ht,char ch,int w)
{
	
    ht[y].ch=ch;
    ht[y].weight=w;
    y++;
	
}




void createHuffmanTree( HuffmanTree ht,int n)
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
	char file[100]={0};
    char *cd;
    int start,i,c,p,j;
	int temp = 0;
	FILE *fp;
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
		printf("\t'%c':",ht[i].ch);
		printf("\t%s\n",hc[i]);//%s输出
	}
	free(cd);    
	i=0;
    while(orgin[i])
	{
		for(j=1;j<=n;j++)
		{
			if(ht[j].ch==orgin[i])
			{
				
				strcpy(translate[temp],hc[j]);
				temp++;
			}
			
		}
        
		i++;
	}
	
	printf("\t编码结果为:\n\t");
	for( i =0; i < temp; i++ )
	{
		printf("%s", translate[i]);
	}
	printf("\n");
	if((fp = fopen("data.code","w")) == NULL) 
	{
		printf("cannot open file.\n");
	}
	for( i =0; i < temp; i++ )
	{
		fprintf(fp,"%s", translate[i]);
	}
	fclose(fp);
	
	
}

void  HuffmandeCode1(HuffmanTree ht,int n,char d[])//译码
{
	
    int m,i,j=0,temp=0;
    FILE *fp;
    m=2*n-1;
    i=m;
	
	while(d[j]!='\0')
	{
		if(d[j]=='0')
			i=ht[i].lchild;
		else
			i=ht[i].rchild;
		
		if(ht[i].lchild==0&&ht[i].rchild==0)
		{
			printf("%c",ht[i].ch);
			regin[temp++]=ht[i].ch;
			i=m;
			
			
		}
		
		j++;
	}
	printf("\n");
    if(ht[i].lchild!=0&&d[j]!='\0')
		printf("error\n");
	if((fp = fopen("data.decode","w")) == NULL) 
	{
		printf("cannot open file.\n");
		
	}
	for(i=0;i<temp;i++)
		fprintf(fp,"%c",regin[i]);
	fclose(fp);
	
    
}

void Print(HuffmanTree ht,int n)
{
	int i;
    printf("\t打印的哈夫曼树如下:\n");
	printf("\t   weight    parent  lchild rchild\n");
    for(i=1;i<2*n;i++)
	{   
	 printf("\t%8d%8d%8d%8d\n",ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);  
        
    }
}
