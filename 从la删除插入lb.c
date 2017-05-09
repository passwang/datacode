#include <stdio.h>
#include <stdlib.h>
 struct st *create(int n);
struct st *delate(struct st *la,int i,int len,int j);
void output(struct st *head);
struct st *insert(struct st *lb,int j,int m,struct st *la);

struct st *del(struct st *p);
struct st{
	int data;
	struct st *next;
};
void main()
{
   
    struct st *la,*lb;
	 int n,i,j,len,m;
	printf("ÇëÊäÈëm:");
	scanf("%d",&m);
	la=create(m);
   
	printf("ÇëÊäÈën:");
    scanf("%d",&n);
	lb=create(n);
	printf("ÇëÊäÈëj:");
	scanf("%d",&j);
	lb=insert(lb,j,m,la);
	output(lb);
	 printf("ÇëÊäÈëi:");
	scanf("%d",&i);
	printf("ÇëÊäÈëlen:");
	scanf("%d",&len);
    lb=delate(lb,i,len,j);
	output(lb);
}
 struct st *create(int n)
 {
      struct st *head,*p,*q;
	  int i=0;
	  head=(struct st *)malloc(sizeof(struct st));
	  p=(struct st *)malloc(sizeof(struct st));
	  printf("ÇëÊäÈëdata:");
	  scanf("%d",&p->data);
	  head=p;
	  p->next=NULL;
	  while(1)
	  {
		   i++;
		  if(i==n)
			  break;
		 if(i<n){
			  q=(struct st *)malloc(sizeof(struct st));
			   printf("ÇëÊäÈëdata:");
			  scanf("%d",&q->data);
			  p->next=q;
			  p=q;
		  }
	  }
	  p->next=NULL;
	  return(head);
 }
struct st *delate(struct st *lb,int i,int len,int j)
{
	struct st *p,*q;
	int count,k;
	p=lb;
	for(count=0;count<j-1;count++)
	p=p->next;
    for(count=0;count<i-1;count++)
		p=p->next;
   for(k=0;k<len;k++)
   {
	   q=del(p);
	 
   }
   return(lb);
}

struct st *del(struct st *p)
{
	struct st *q;
		q=p->next;
		p->next=q->next;
		return(q);
}


struct st *insert(struct st *lb,int j,int m,struct st *la)
{
	struct st *p,*t;
	int count;
	p=lb;
	for(count=0;count<j-1;count++)
		p=p->next;
		  t=p->next;
		   p->next=la;
		   while(m)
		   {
			  p=p->next;
		     m--;
		   }
		    p->next=t;
	  return(lb);
}

 void output(struct st *head)
 {
	 struct st *p;
	 p=head;
	 while(p)
	 {
		 printf("%2d",p->data);
		 p=p->next;
	 }
	 printf("\n");
 }