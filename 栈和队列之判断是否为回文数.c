#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define datatype char
#define MAXSIZE 20
typedef struct{
	datatype data[MAXSIZE];
    int top;
}Seqstack;
Seqstack *nullSeqstack(Seqstack *s);
int push(Seqstack *s,datatype x);    
datatype pop(Seqstack *s,datatype x);
int Empty_Seqstack(Seqstack *s);
void out_Seqstack(Seqstack *s,int n);

void main()
{
	Seqstack *s;
	int i,k,count=0;
	char a[MAXSIZE];
	s=(Seqstack *)malloc(sizeof(Seqstack));
    s=nullSeqstack(s);
	printf("请输入字符串:");
	gets(a);
    k=strlen(a);
		for(i=0;i<k;i++)
		{
			push(s,a[i]);
		}

      	for(i=0;i<k;i++)
		{
	
		if(pop(s,a[i])==a[i])
		    count++;

		}
		if(count==k)
			printf("是回文数\n");
		else
			printf("不是回文数\n");
	
	}
Seqstack *nullSeqstack(Seqstack *s)
{
	

	s->top=-1;
	return(s);
}
int push(Seqstack *s,datatype x)//入栈
{
	if(s->top==MAXSIZE-1)
		return(0);
	else
	{
		s->top++;
		s->data[s->top]=x;
		return(1);
	}
}
 datatype pop(Seqstack *s,datatype x)//出栈
{
	if(Empty_Seqstack(s))
		return(0);
	else
	{
		x=s->data[s->top];
		s->top--;
		return(x);
	}
}
int Empty_Seqstack(Seqstack *s)
{
	if(s->top==-1)
		return(1);
	else
		return(0);
}
void out_Seqstack(Seqstack *s,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%s",s->data);
	}
}