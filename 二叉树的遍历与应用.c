#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 20
typedef char datatype;

typedef struct Node{
	datatype data;
	struct Node *Lchild;
	struct Node *Rchild;
}BT;
typedef BT sdatatype;
typedef struct {
	sdatatype data[MAXSIZE];
	int front,rear;
}Squeue;

typedef struct{
    BT *data[MAXSIZE];        //�ɽṹ�������Ϊ�ṹ��ָ������ ��¼��ַ
	int top;
}SeqStack;


BT *CreatBT();
int leafnum(BT *root);
void PrintTree(BT *root,int h);
void visit(BT *root);
void PreOrder(BT *root);
void InOrder(BT *root);
void PostOrder(BT *root);
int PostTreeDepth(BT *root);
void select(BT *root);
void f(int i,BT *root);
void save_file(int h);
int read_file();
void visit(BT *root);
Squeue  *Initqueue();
void InSqueue(Squeue *s,BT *x);
BT  OutSqueue(Squeue *s);
int Empty_Squeue(Squeue *s);
void Findk(BT *root);
void InOrderf(BT *root);
void PreOrderf(BT *root);
void PostOrderf(BT *root);
SeqStack *Initstack();
void push(SeqStack *s,BT *x);
BT *pop(SeqStack *s);
int Isempty(SeqStack *s);
BT *Top(SeqStack *s);
int getNodeNumsKthLevel(BT *root,int k);
void find(BT *root,int k);
char *ch;
void main()
{
  
    char p[64];
	BT *root;
	printf("�����������:\n");
    scanf("%s",p);
    ch= &p[0];
    root=CreatBT();
    select(root);
   
   
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

void select(BT *root)
{
	int k,i,h,H,num=0;
    printf("\n");
	printf("\n");
    printf("\t       ************************              \n");
	printf("\t               ��ӭʹ��                      \n");
	printf("\t       ************************               \n");
   	printf("\t           0----------��α���                \n");
	printf("\t           1----------�ݹ��������                \n");
    printf("\t           2----------�ݹ��������                \n");
	printf("\t           3----------�ݹ�������                \n");
    printf("\t           4----------�ǵݹ��������                \n");
    printf("\t           5----------�ǵݹ��������                \n");
	printf("\t           6----------�ǵݹ�������                \n");
	printf("\t           7----------����������ĸ߶�        \n");
	printf("\t           8----------ͳ��Ҷ�ӽڵ�            \n");
	printf("\t           9----------k��Ҷ������              \n");
	printf("\t           10----------��ӡ������                \n");
	printf("\t           11----------����                      \n");
    printf("\n");
	printf("������ѡ��:");
	scanf("%d",&i);
	switch(i){
	case(0):Findk(root);f(i,root);break;
	case(1):PreOrder(root);f(i,root);break;
	case(2):InOrder(root);f(i,root);break;
	case(3):PostOrder(root);f(i,root);break;
   	case(4):PreOrderf(root);f(i,root);break;
	case(5):InOrderf(root);f(i,root);break;
	case(6):PostOrderf(root);f(i,root);break;
	case(7):h=PostTreeDepth(root);printf("�������ĸ߶�Ϊ%d\n",h);f(i,root);break;
	case(8):num=leafnum(root);printf("��������Ҷ�ӽڵ�����Ϊ%d\n",num);f(i,root);break;
    case(9):find(root,k);f(i,root);break;
    case(10): H=read_file();PrintTree(root,H);f(i,root);break;
	default:printf("����\n");
    }
}

void f(int i,BT *root)
{
   if(i!=8)
   {
	   select(root);

   }
   else
   {
	   printf("����\n");
   }
}


void PreOrder(BT *root)//�������
{
	if(root!=NULL)
	{
		visit(root);
        PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
}
void InOrder(BT *root)//����
{
	if(root)
	{
       InOrder(root->Lchild);
	   visit(root);
	   InOrder(root->Rchild);
	   }
}
void PostOrder(BT *root)//����
{
	if(root)
	{
      PostOrder(root->Lchild);
	  PostOrder(root->Rchild);
	  visit(root);
	}
}
void visit(BT *root)
{
	
	printf("%3c",root->data);
}
int PostTreeDepth(BT *root)//�����ĸ߶�
{
	int h1,h2,h;
	if(root==NULL)
		return(0);
	else
	{
		h1=PostTreeDepth(root->Lchild);
		h2=PostTreeDepth(root->Rchild);
		h=h1>h2?h1:h2;
		h=h+1;
		save_file(h);
		return(h);
	}
}



void PrintTree(BT *root,int h)//��ӡ������
{
	int i;
	if(root==NULL)
		return;
	PrintTree(root->Rchild,h+1);
	for(i=0;i<h;i++)
		printf("     ");
	printf("%3c\n",root->data);
	PrintTree(root->Lchild,h+1);
}
int leafnum(BT *root)//��Ҷ�ڵ�����
{                                                                                                                                                                                       
	int n1,n2;
	if(root==NULL)
		return(0);
		if(root->Lchild==NULL&&root->Rchild==NULL)
			return(1);
		n1=leafnum(root->Lchild);
		n2=leafnum(root->Rchild);
		return(n1+n2);
}
/*void leafnum(BT *root)//��ڵ���Ŀ��һ�ַ�ʽ
{
  if(root!=NULL)
  {
	  leafnum(root->Lchild);
	  leafnum(root->Rchild);
 
  if(root->Lchild==NULL&&root->Rchild==NULL)
	  num++;
  }
}*/
Squeue *Initqueue()//��ʼ������
{
	Squeue *s;
	s=(Squeue *)malloc(sizeof(Squeue));
	s->front=s->rear=MAXSIZE;
    return(s);
}
void InSqueue(Squeue *s,BT *x)//���
{
   s->rear=(s->rear+1)%MAXSIZE;
   s->data[s->rear]=*x;
}

	

BT OutSqueue(Squeue *s)//����
{
    
    s->front=(s->front+1)%MAXSIZE;
   return(s->data[s->front]);

}
int Empty_Squeue(Squeue *s)//�жӿ�
{
    if(s->front==s->rear)
		return(1);
	else
		return(0);
}

void Findk(BT *root)//��α���
{
  Squeue *s;
    BT *p,t;
	int i=0;
	p=root;
    s=Initqueue();
    InSqueue(s,p);
	while(!Empty_Squeue(s))
	{
	
	
		t=OutSqueue(s);
		p=&t;
		visit(p);
		if(p->Lchild!=NULL)
            InSqueue(s,p->Lchild);
		if(p->Rchild!=NULL)
            InSqueue(s,p->Rchild);
	
	}

		
    
}
int getNodeNumsKthLevel(BT *root,int k)//��k��Ҷ������
{

	if(root==NULL||k<=0)
		return(0);
	if(root!=NULL&&k==1)
	{
		if(root->Lchild==NULL&&root->Rchild==NULL)
		return(1);
		else
			return(0);
	}
   
	return(getNodeNumsKthLevel(root->Lchild,k-1)+getNodeNumsKthLevel(root->Rchild,k-1));
}
void find(BT *root,int k)
{
	int leafnum;
	printf("������k��ֵ:\n");
	scanf("%d",&k);
    leafnum=getNodeNumsKthLevel(root,k);
	printf("������k��Ҷ�ӽڵ�����Ϊ%d\n",leafnum);
}






void save_file(int h)//�����ļ�
{
	FILE *fp;
	int i=1;
   	if((fp = fopen("data.txt","w")) == NULL) {
	printf("���ܴ������ļ���\n");
		
	}
	fprintf(fp,"%d",h);
	fclose(fp);
}
int read_file()//���ļ�
{
	int H;
	FILE *fp;

	if((fp = fopen("data.txt","r")) == NULL) {
     return(-1);
		
	}
  fscanf(fp,"%d",&H);
  fclose(fp);
  return(H);
 
}
 
void InOrderf(BT *root)//����ǵݹ����
{
    BT *p;
	SeqStack *s;
	p=root;
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
		   
			p=pop(s);
			visit(p);
			p=p->Rchild;
		}
	 }
}
void PreOrderf(BT *root)//����ǵݹ�
{
	BT *p;
   	SeqStack *s;
	p=root;
	s=Initstack();
	if(root==NULL)
	{
		printf("����\n");
		return;
	}
	while(p!=NULL||!Isempty(s))
	{
	  while(p!=NULL)
		{
			push(s,p);
            visit(p);
			p=p->Lchild;
		}
     if(!Isempty(s))
		{
		   
			p=pop(s);
			p=p->Rchild;
		}
	 }
}

void PostOrderf(BT *root)//����ǵݹ�
{
    
	BT *p,*q;
   	SeqStack *s;
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

