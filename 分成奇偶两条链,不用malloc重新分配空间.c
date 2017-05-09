#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}Lnode,*Linklist;
Linklist create_Linklist(int n);
void sort(Linklist head,int m);
void adjust(Linklist head);
void part(Linklist head);
void output(Linklist head);
void main()
{
	Linklist head;
	int n;
	printf("请输入n:");
	scanf("%d",&n);
	head=create_Linklist(n);
	adjust(head);

	//output(head);

}
Linklist create_Linklist(int n)
{
	Linklist head=(Linklist)malloc(sizeof(Lnode));
	Lnode *p,*q;
	int i=0;
	p=(Linklist)malloc(sizeof(Lnode));
	printf("请输入data:");
	scanf("%d",&p->data);
	head->next=p;
	p->next=NULL;
	while(1)
	{
		i++;
		if(i==n)
			break;
		if(i<n)
		{
			q=(Linklist)malloc(sizeof(Lnode));
         	printf("请输入data:");
	         scanf("%d",&q->data);
			 p->next=q;
			 p=q;
		}
	}
		p->next=NULL;
		return(head);
	}

void adjust(Linklist head)
{
	Lnode *p,*q;
	p=head->next;
	while(p->next)
	{
        if(p->next->data%2==0)
		{
           
			q=p->next;
			p->next=q->next;
			q->next=head->next;
			head->next=q;
		   
		    
		}
	
		else
		{
		
		    
			p=p->next;
		
		}
	
	
	}
	
   	part(head);
	

}
void part(Linklist head)
{
	Linklist L1,L2;
	Lnode *p,*q,*r;
	int m=0,n=0;
	int i=0;
	r=head->next;
	while(r)
	{
		if(r->data%2==0)
		{
			m++;
			r=r->next;
		}
		else
		{
			n++;
			r=r->next;
		}
	}
	p=head;
	q=head->next;
	while(q&&q->data%2==0)
	{
		p=q;
		q=q->next;
	}
	L2=p->next;//L2为奇数链
	p->next=NULL;
	L1=head->next;//L1为偶数链
	sort(L2,n);
	sort(L1,m);
	output(L1);
	output(L2);
}
    
    



	void sort(Linklist head,int m)
{
	Lnode *p;
	int i,j,t;
	p=head;
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
	     p=head;
	}
	   
}

void output(Linklist head)
{
	Lnode *p;
	p=head;
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("\n");
}