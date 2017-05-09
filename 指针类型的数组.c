#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 20
typedef char datatype;

typedef struct Node{
	datatype data;
	struct Node *Lchild;
	struct Node *Rchild;
}BT;

typedef struct{
    BT *data[MAXSIZE];        //�ɽṹ�������Ϊ�ṹ��ָ������ ��¼��ַ
	int top;
}SeqStack;

int count = 0;

BT *CreatBT();
void PrintTree(BT *root,int h);
void visit(BT *root);
void PostOrderf(BT *root);
SeqStack *Initstack();
void push(SeqStack *s,BT *x);
BT *pop(SeqStack *s);         //����ֵ��ΪBT*
int Isempty(SeqStack *s);
BT *Top(SeqStack *s);         //����ֵ��ΪBT*

 char *ch;
void main()
{
   int k;
    char p[64];

	BT *root;
	printf("�����������:\n");
    scanf("%s",p);
    ch = &p[0];
    root=CreatBT();
    //PrintTree(root, 1);
	PostOrderf(root);

   
   
   
}

BT *CreatBT() //����������
{
	
    BT *root;
    if(*(ch)=='#')
    {
        ch++;
        root=NULL;
    }
    else
    {
        root=(BT*)malloc(sizeof(BT));
        root->data=*(ch++);
        root->Lchild=CreatBT();
        root->Rchild=CreatBT();
    }
    return(root);
}

void visit(BT *root)
{
	
	printf("%c",root->data);
}

void PrintTree(BT *root,int h)//��ӡ������
{
	int i;
	if(root==NULL)
		return;
	PrintTree(root->Rchild,h+1);
	for(i=0;i<h;i++)
		printf("  ");
	printf("%2c\n",root->data);
	PrintTree(root->Lchild,h+1);
}

void PostOrderf(BT *root)//����ǵݹ�
{
    
	BT *p,t,k,*q;
   	SeqStack *s;
    int i ;
	p=root;
	q=NULL;
	s=Initstack();
	while(p!=NULL||!Isempty(s))
	{
	  while(p!=NULL)
		{
			push(s,p);
			p=p->Lchild;
		}
     if(!Isempty(s))
		{
		    p=Top(s);
			if(p->Rchild==NULL||p->Rchild==q)
			{
				p=pop(s);
				visit(p);
				q=p;
				p=NULL;
			}
			else
			p=p->Rchild;
		}
	 }
}
 BT *Top(SeqStack *s)//ȡջ��Ԫ��
{
	 return (s->data[s->top]); // ����ָ��
 }


SeqStack *Initstack()//�ÿ�ջ
{
	SeqStack *s;
	s=(SeqStack *)malloc(sizeof(SeqStack));
	s->top=-1;
	return(s);
}
void push(SeqStack *s,BT *x)//��ջ
{
	s->top++;
    s->data[s->top]=x;              //��ֵʱ��ָ����ָ�����鱣��
}

BT *pop(SeqStack *s)//��ջ
{
	return (s->data[s->top--]);     // ����ָ�� 
}
int Isempty(SeqStack *s)//�п�
{
	if(s->top==-1)
		return(1);
	else
		return(0);
}

