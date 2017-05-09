#include <stdio.h>
#include <stdlib.h>
 struct st *create(int n);
 
 struct st *delate (struct st *s);
void output(struct st *head);

struct st{
	int data;
	struct st *next;
};
void main()
{
   
    struct st *head,*s,*p;
	 int n;
	printf("ÇëÊäÈën:");
	scanf("%d",&n);
	head=create(n);
   p=head->next;
   head=delate(p);
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
	  p->next=head;
	  return(head);
 }

struct st *delate (struct st *s)
{
 struct st *p,*q;
    p=s;
 while(p->next->next!=s)
 {
  p=p->next;
 }
 q=p->next;
 p->next=s;
 free(q);
return(p);

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