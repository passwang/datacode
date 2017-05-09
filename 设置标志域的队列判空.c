//循环队列
#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 5
#define datatype int
typedef struct{
	datatype data[MAXSIZE];
	int front,rear,tag;
}Squeue;

Squeue *Initqueue(Squeue *s);
void Inqueue(Squeue *s,datatype x);
void Outqueue(Squeue *s,datatype x);

void main()
{
   
	int a[MAXSIZE],i;
	Squeue *s;
	s=(Squeue *)malloc(sizeof(Squeue));
    s=Initqueue(s);
	for(i=0;i<6;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<6;i++)
	{
	
         Inqueue(s,a[i]);
	}
    	for(i=0;i<6;i++)
		{
			Outqueue(s,a[i]);
		}
    

}
Squeue *Initqueue(Squeue *s)//循环队列置空
{

	s->rear=s->front=MAXSIZE-1;
	s->tag=0;
	return(s);
}
void Inqueue(Squeue *s,datatype x)//入队
{
	if(s->tag==1&&s->rear==s->front)
	{
		printf("队满,不能入队");
	
	}
	else
	{
	    if(s->tag==0&&s->rear==s->front)
	    	s->tag=1;
		s->rear=(s->rear+1)%MAXSIZE;
		s->data[s->rear]=x;
		
	}
	
}
void Outqueue(Squeue *s,datatype x)
{
	if(s->tag==0&&s->rear==s->front)
	{
		printf("空队,不能出队");
		
	}
	else{


		s->front=(s->front+1)%MAXSIZE;
		x=s->data[s->front];
	
	   if(s->rear==s->front)
    	s->tag=1;
	}

}
