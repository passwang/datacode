#include <stdio.h>
#include <stdlib.h>
struct st *create(int n);
void output(struct st *head);
struct st *add(struct st *A,struct st *B);
struct st{
	int data;
    int exp; 
	struct st *next;
};
void main()
{  
    struct st *A,*B,*C;
	 int n,m;
	printf("������A������n:");
	scanf("%d",&n);
     A=create(n);
     printf("������B������m:");
	scanf("%d",&m);
	 B=create(m);
	output(A);
	output(B);
    C=add(A,B);
	 output(C);
}
struct st *create(int n)
 {
      struct st *head,*p,*q;
	  int i=0;
	  head=(struct st *)malloc(sizeof(struct st));
	  p=(struct st *)malloc(sizeof(struct st));
	  printf("������ϵ��:");
	  scanf("%d",&p->data);
      printf("������ָ��:");
	  scanf("%d",&p->exp);
	  head->next=p;
	  p->next=NULL;
	  while(1)
	  {
		   i++;
		  if(i==n)
			  break;
		  if(i<n){
			  q=(struct st *)malloc(sizeof(struct st));
			  printf("������ϵ��:");
			  scanf("%d",&q->data);
			  printf("������ָ��:");
			  scanf("%d",&q->exp);
			  p->next=q;
			  p=q;
		  }
	  }
	  p->next=NULL;
	  return(head);
 }
struct st *add(struct st *A,struct st *B)
{
	struct st *pa,*pb,*temp,*pc;
	int sum;
	pa=A->next;
	pb=B->next;
	pc=A;
	while(pa->next||pb->next)
	{  
   
		if(pa->exp==pb->exp)
		{  
			sum=pa->data+pb->data;
			if(sum!=0)
                   {
                        pa->data=sum;
                        pc->next=pa;pc=pc->next;pa=pa->next;
                        temp=pb;pb=pb->next;free(temp);
                    }
                  else     /*���ϵ����Ϊ�㣬��ɾ�����p��q������ָ��ָ����һ�����*/
                 {
                       temp=pa->next;free(pa);pa=temp;
                       temp=pb->next;free(pb);pb=temp;
				  }
		}
		if(pa->exp<pb->exp)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		if(pa->exp>pb->exp)
		{
			pc->next=pb;
            pc=pb;
			pb=pb->next;
		}
	
	}

		   
	if(pa->exp==pb->exp)
	{
		pa->data=pa->data+pb->data;
	   pc->next=pa;
	}
else
{
   if(pa)
	   pc->next=pa;
   if(pb)
	   pc->next=pb;
}
	

   return(A);
}




void output(struct st *head)
{
	struct  st *p;
	int x;
	p=head->next;
	while(p)
	{
		printf("%2d*x^%2d\n",p->data,p->exp);
		p=p->next;
	}
	printf("\n");
}