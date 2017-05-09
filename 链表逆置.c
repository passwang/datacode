#include <stdio.h>
#include <stdlib.h>
 struct st *create(int n);
struct st *change(struct st *head);
void output(struct st *head);

struct st{
	int data;
	struct st *next;
};
void main()
{
   
    struct st *head;
	 int n;
	printf("ÇëÊäÈën:");
	scanf("%d",&n);
	head=create(n);
	head=change(head);
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
			  scanf("%d",&q->data);
			  p->next=q;
			  p=q;
		  }
	  }
	  p->next=NULL;
	  return(head);
 }
 struct st *change(struct st *head)
 {
	 struct st *p,*q;
	 p=head->next;
	 head->next=NULL;
	 while(p)
	 {
		 q=p;
		 p=p->next;
		 q->next=head->next;
		 head->next=q;
	 }
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

