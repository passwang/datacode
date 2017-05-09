#include <stdio.h>
#include <malloc.h>
#define datatype int
#define MAXSIZE  5
typedef struct{
	datatype data[MAXSIZE];
	int rear,quelen;
}Sequeue;
Sequeue *Initqueue();
int Inqueue(Sequeue *s,datatype x);
int Outqueue(Sequeue *s,datatype x);
int Emptyqueue(Sequeue *s);
int Fullqueue(Sequeue *s);
void main()
{
    int a[MAXSIZE],i,k;
	Sequeue *s;
	s=(Sequeue *)malloc(sizeof(Sequeue));
    s=Initqueue(s);
	for(i=0;i<MAXSIZE;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<MAXSIZE;i++)
	{
	
         Inqueue(s,a[i]);
	}
	for(i=0;i<1;i++)
	{
        k=Outqueue(s,a[i]);
	}
	   printf("%d\n",k);
		 
	}




Sequeue *Initqueue(Sequeue *s)//�ÿն�
{

	s->rear=MAXSIZE-1;
	s->quelen=0;
	return(s);
}
int Inqueue(Sequeue *s,datatype x)//���
{
	if(Fullqueue(s))
		return(0);
	else{
		s->quelen++;
		s->rear=(s->rear+1)%MAXSIZE;
		s->data[s->rear]=x;
		return(1);
	}
}
int Outqueue(Sequeue *s,datatype x)//����
{
	int front;
	if(Emptyqueue(s))
		return(0);
	else{
		s->quelen--;
	    front=(s->rear + MAXSIZE-s->quelen)%MAXSIZE;
	     return(s->data[front]);
	}
}
int Emptyqueue(Sequeue *s)//�ж��Ƿ�Ϊ��
{
	if(s->quelen==0)
		return(1);
	else
		return(0);
	
}
int Fullqueue(Sequeue *s)//�ж��Ƿ���
{

	if(s->quelen==MAXSIZE)
		return(1);
	else
		return(0);
}

