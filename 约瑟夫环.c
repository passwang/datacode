#include <stdio.h>
#include <stdlib.h>
 struct st *create(int n);
int find(struct st *head,int m);
struct st *delate(struct st *head,int m);
void output(struct st *head);

struct st{
	int id;
    int password; 
	struct st *next;
};
void main()
{
   
    struct st *head;
	 int n,m,ps,max;
	printf("������max:");
	scanf("%d",&max);
	printf("������n:");
	scanf("%d",&n);
	while(n>max||n==0)
	{
		printf("�������,����������!\n");
		printf("������n:");
	   scanf("%d",&n);
	   }
	head=create(n);
    printf("������m:");
	scanf("%d",&m);
	while(head->next->password!=head->password)
	{
	ps=find(head,m);
	head=delate(head,m);
	m=ps;
   
	}
   
	output(head);
	
	
}
 struct st *create(int n)
 {
      struct st *head,*p,*q;
	  int i=0;
	  head=(struct st *)malloc(sizeof(struct st));
	  p=(struct st *)malloc(sizeof(struct st));
	  printf("������password:");
	  scanf("%d",&p->password);
	  p->id=1;
	  head=p;
	  p->next=NULL;
	  while(1)
	  {
		   i++;
		  if(i==n)
			  break;
		 if(i<n){
			  q=(struct st *)malloc(sizeof(struct st));
			 
              printf("������password:");
	           scanf("%d",&q->password);
			   q->id=i+1;
			  p->next=q;
			  p=q;
		  }
	  }
	  p->next=head;
	  return(head);
 }
 int find(struct st *head,int m)
{
	struct st *p;
	int i;
	p=head;
	for(i=0;i<m-1;i++)
    {
		
       p=p->next;
	   
	   }
	return(p->password);
}
struct st *delate(struct st *head,int m)
{
	struct st *p,*q;
	int i;
	p=head;

	for(i=1;i<m-1;i++)
		p=p->next;
    printf("%5d,%5d\n",p->next->id,p->next->password);//*��������*/
	q=p->next;
	p->next=q->next;

	p = p->next;
	q = q->next; 


return(p);
}  


 void output(struct st *p)
 { 
	 printf("%5d,%5d\n",p->next->id,p->next->password);
     printf("���һ����id��:%2d,������:%2d\n",p->id,p->password);
	 printf("\n");
 }

