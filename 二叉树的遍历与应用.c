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
    BT *data[MAXSIZE];        //由结构体数组改为结构体指针数组 记录地址
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
	printf("请输入二叉树:\n");
    scanf("%s",p);
    ch= &p[0];
    root=CreatBT();
    select(root);
   
   
}

BT *CreatBT() //建立二叉树
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
	printf("\t               欢迎使用                      \n");
	printf("\t       ************************               \n");
   	printf("\t           0----------层次遍历                \n");
	printf("\t           1----------递归先序遍历                \n");
    printf("\t           2----------递归中序遍历                \n");
	printf("\t           3----------递归后序遍历                \n");
    printf("\t           4----------非递归先序遍历                \n");
    printf("\t           5----------非递归中序遍历                \n");
	printf("\t           6----------非递归后序遍历                \n");
	printf("\t           7----------计算二叉树的高度        \n");
	printf("\t           8----------统计叶子节点            \n");
	printf("\t           9----------k层叶子总数              \n");
	printf("\t           10----------打印二叉树                \n");
	printf("\t           11----------结束                      \n");
    printf("\n");
	printf("请输入选项:");
	scanf("%d",&i);
	switch(i){
	case(0):Findk(root);f(i,root);break;
	case(1):PreOrder(root);f(i,root);break;
	case(2):InOrder(root);f(i,root);break;
	case(3):PostOrder(root);f(i,root);break;
   	case(4):PreOrderf(root);f(i,root);break;
	case(5):InOrderf(root);f(i,root);break;
	case(6):PostOrderf(root);f(i,root);break;
	case(7):h=PostTreeDepth(root);printf("二叉树的高度为%d\n",h);f(i,root);break;
	case(8):num=leafnum(root);printf("二叉树的叶子节点总数为%d\n",num);f(i,root);break;
    case(9):find(root,k);f(i,root);break;
    case(10): H=read_file();PrintTree(root,H);f(i,root);break;
	default:printf("结束\n");
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
	   printf("结束\n");
   }
}


void PreOrder(BT *root)//先序遍历
{
	if(root!=NULL)
	{
		visit(root);
        PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
}
void InOrder(BT *root)//中序
{
	if(root)
	{
       InOrder(root->Lchild);
	   visit(root);
	   InOrder(root->Rchild);
	   }
}
void PostOrder(BT *root)//后序
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
int PostTreeDepth(BT *root)//求树的高度
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



void PrintTree(BT *root,int h)//打印二叉树
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
int leafnum(BT *root)//求叶节点总数
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
/*void leafnum(BT *root)//求节点数目另一种方式
{
  if(root!=NULL)
  {
	  leafnum(root->Lchild);
	  leafnum(root->Rchild);
 
  if(root->Lchild==NULL&&root->Rchild==NULL)
	  num++;
  }
}*/
Squeue *Initqueue()//初始化队列
{
	Squeue *s;
	s=(Squeue *)malloc(sizeof(Squeue));
	s->front=s->rear=MAXSIZE;
    return(s);
}
void InSqueue(Squeue *s,BT *x)//入队
{
   s->rear=(s->rear+1)%MAXSIZE;
   s->data[s->rear]=*x;
}

	

BT OutSqueue(Squeue *s)//出队
{
    
    s->front=(s->front+1)%MAXSIZE;
   return(s->data[s->front]);

}
int Empty_Squeue(Squeue *s)//判队空
{
    if(s->front==s->rear)
		return(1);
	else
		return(0);
}

void Findk(BT *root)//层次遍历
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
int getNodeNumsKthLevel(BT *root,int k)//求k层叶子总数
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
	printf("请输入k的值:\n");
	scanf("%d",&k);
    leafnum=getNodeNumsKthLevel(root,k);
	printf("二叉树k层叶子节点总数为%d\n",leafnum);
}






void save_file(int h)//保存文件
{
	FILE *fp;
	int i=1;
   	if((fp = fopen("data.txt","w")) == NULL) {
	printf("不能打开数据文件。\n");
		
	}
	fprintf(fp,"%d",h);
	fclose(fp);
}
int read_file()//读文件
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
 
void InOrderf(BT *root)//中序非递归遍历
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
void PreOrderf(BT *root)//先序非递归
{
	BT *p;
   	SeqStack *s;
	p=root;
	s=Initstack();
	if(root==NULL)
	{
		printf("空树\n");
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

void PostOrderf(BT *root)//后序非递归
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
 BT *Top(SeqStack *s)//取栈顶元素
{
	 return (s->data[s->top]); // 返回指针
 }


SeqStack *Initstack()//置空栈
{
	SeqStack *s;
	s=(SeqStack *)malloc(sizeof(SeqStack));
	s->top=-1;
	return(s);
}
void push(SeqStack *s,BT *x)//进栈
{
	s->top++;
    s->data[s->top]=x;              //赋值时将指针用指针数组保存
}

BT *pop(SeqStack *s)//出栈
{
	return (s->data[s->top--]);     // 返回指针 
}
int Isempty(SeqStack *s)//判空
{
	if(s->top==-1)
		return(1);
	else
		return(0);
}

