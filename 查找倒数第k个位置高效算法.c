#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}Lnode,*Linklist;

Linklist create_Linklist();
int find(Linklist list,int k);
void output(Linklist head);
void main()
{
	int k;
	Linklist list;
	list=create_Linklist();
	printf("������k��ֵ:");
	scanf("%d",&k);
	find(list,k);
	
}
Linklist create_Linklist()
{
	Linklist list=(Linklist)malloc(sizeof(Lnode));
	Lnode *p,*q;
	int num;
	p=(Linklist)malloc(sizeof(Lnode));
	printf("������data:");
	scanf("%d",&p->data);
    list->link=p;
	p->link=NULL;
	while(1)
	{
		printf("�������Ƿ����:0-��,1-��:");
		scanf("%d",&num);
         
		if(num==1)
		{
			q=(Linklist)malloc(sizeof(Lnode));
         	printf("������data:");
	         scanf("%d",&q->data);
			 p->link=q;
			 p=q;
		}
		else
			break;
	}
		p->link=NULL;
		return(list);
	}
int find(Linklist list,int k)
{
	Lnode *p,*q;
	int i=0;
	p=list;
     q=list;
	while(p)
	{
		if(i<k)
		{
		p=p->link;
		i++;
		if(p==NULL)
		{
			printf("����ʧ��!\n");
			return(0);
		}
		}
		else
		{
			p=p->link;
			q=q->link;
		}
	}
     printf("���ҳɹ�!\n");
	printf("%d\n",q->data);
	return(1);
	
	
}
	


void output(Linklist head)
{
	Lnode *p;
	p=head->link;
	while(p)
	{
		printf("%d\n",p->data);
		p=p->link;
	}
	printf("\n");
}