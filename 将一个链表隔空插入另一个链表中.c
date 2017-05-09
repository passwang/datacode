#include <stdio.h>
#include <stdlib.h>
 struct st *create();
 int find(struct st *head);
struct st *And(struct st *A,struct st *B,int m);
void output(struct st *head);

struct st{
	int data;
	struct st *next;
};
void main()
{
   
    struct st *A,*B,*C;
	 int n,m;
	A=create();
	output(A);
	m=find(A);
	B=create();
	output(B);
	n=find(B);
	if(m<=n)
		C=And(A,B,m);
	else
		C=And(B,A,m);

	output(C);
}
 struct st *create()
 {
      struct st *head,*p,*q;
	  int num;
	  head=(struct st *)malloc(sizeof(struct st));
	  p=(struct st *)malloc(sizeof(struct st));
	  printf("请输入data:");
	  scanf("%d",&p->data);
	  head->next=p;
	  p->next=NULL;
	  while(1)
	  {

		printf("请输入是否继续,0-否,1-继续:");
		scanf("%d",&num);
		 if(num==1){
			  q=(struct st *)malloc(sizeof(struct st));
			  printf("请输入data:");
			  scanf("%d",&q->data);
			  p->next=q;
			  p=q;
		  }
		else if(num==0)
			break;
		else
		{
			printf("非法输入!\n");
			break;
		}

	  }
	  p->next=NULL;
	  return(head);
 }

 int find(struct st *head)
 {
	 struct st *p;
	 int count=0;
	 p=head->next;
	 while(p)
	 {
		 count++;
		 p=p->next;
	 }
	 return(count);
 }

struct st *And(struct st *A,struct st *B,int m)
{
	struct st *pa,*pb,*C,*pc,*qa,*qb;
	C=(struct st *)malloc(sizeof(struct st));
    pa=A->next;
    pb=B->next;
	C=pc=A;
	while(pa)
	{
		pc->next=pa;
		qa=pa->next;
		pc=pa;
		pc->next=pb;
		qb=pb->next;
		pc=pb;
		pb=qb;
		pa=qa;

	}

   pc->next=pb;
   return(C);
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

