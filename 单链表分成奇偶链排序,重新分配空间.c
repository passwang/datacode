#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}Lnode,*Linklist;
Linklist create_Linklist(int n);
void output(Linklist H);
void part(Linklist H,Linklist H1,Linklist H2);
void sort(Linklist H,int m);
void main()
{
	Linklist H,H1,H2;
	int n;
	printf("ÇëÊäÈën:");
	scanf("%d",&n);
	H=create_Linklist(n);
	H1=(Linklist)malloc(sizeof(Lnode));
	H2=(Linklist)malloc(sizeof(Lnode));
	part(H,H1,H2);
}
Linklist create_Linklist(int n)
{
	Linklist H=(Linklist)malloc(sizeof(Lnode));
	Lnode *p,*q;
	int i=0;
	p=(Linklist)malloc(sizeof(Lnode));
	printf("ÇëÊäÈëdata:");
	scanf("%d",&p->data);
	H->next=p;
	p->next=NULL;
	while(1)
	{
		i++;
		if(i==n)
			break;
		if(i<n)
		{
			q=(Linklist)malloc(sizeof(Lnode));
         	printf("ÇëÊäÈëdata:");
	         scanf("%d",&q->data);
			 p->next=q;
			 p=q;
		}
	}
		p->next=NULL;
		return(H);
	}

void part(Linklist H,Linklist H1,Linklist H2)
{
	Lnode *p,*q,*r;
	int m,n;
	m=0;
	n=0;
	r=H->next;
	p=H1;
	q=H2;
	p->next=NULL;
	q->next=NULL;
	 while(r)
	 {
		 if(r->data%2!=0)
		 {

			 m++;
			 p->next=r;
			 p=r;
             r=r->next;
           p->next=NULL;
		 }
		 else
		 {
			 n++;
			q->next=r;
			q=r;
			r=r->next;
		  q->next=NULL;
		 }
	 }
	 sort(H1,m);
	 sort(H2,n);
	 output(H1);
	 output(H2);
}
void sort(Linklist H,int m)
{
	Lnode *p;
	int i,j,t;
	p=H->next;
    for(i=0;i<m;i++)
	{
	   for(j=0;j<m-1-i;j++,p=p->next)
	   {
		   if(p->data>p->next->data)
		   {
                 t=p->data;
				 p->data=p->next->data;
				 p->next->data=t;
		   }
        
	   }
	     p=H->next;
	}
	   
}

void output(Linklist H)
{
	Lnode *p;
	p=H->next;
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("\n");
}

