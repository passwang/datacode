#include <stdio.h>
#include <stdlib.h>
 struct st *create(int n);
struct st *delate(struct st *head,int n,int x);
void output(struct st *head);

struct st{
	int data;
	struct st *next;
};
void main()
{
   
    struct st *head;
	 int n,x;
	printf("ÇëÊäÈën:");
	scanf("%d",&n);
	head=create(n);
	printf("ÇëÊäÈëÉ¾³ýdata:");
	scanf("%d",&x);
	head=delate(head,n,x);
	output(head);
}
 struct st *create(int n)
 {
      struct st *head,*p,*q;
	  int i=0;
	  head=(struct st *)malloc(sizeof(struct st));
	  p=(struct st *)malloc(sizeof(struct st));
	  printf("ÇëÊäÈëdata:");
	  scanf("%d",&p->data);
	  head->next=p;
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
 struct st *delate(struct st *head,int n,int x)
 { struct st *p,*q;
    int k;
   p=head;
   k=n;
   while(p->next!=NULL)
   {
	   if(p->next->data==x)
	   {
		   q=p->next;
		   p->next=q->next;
		   free(q);
		   n--;
	   }
	   else
		   p=p->next;
   }
   if(k==n)
	   printf("²»´æÔÚx\n");
   return(head);
 }

void output(struct st *head)
 {
	 struct st *p;
	 p=head->next;
	 while(p)
	 {
		 printf("%2d",p->data);
		 p=p->next;
	 }
	 printf("\n");
 }

