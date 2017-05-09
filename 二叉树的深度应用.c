#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 20
typedef char datatype;
typedef  char ElementType;
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

BT *CreatBT();
int Du_BT(BT *root);
int leafnum(BT *root);
void visit(BT *root);
void PreOrder(BT *root);
void ChangeBT(BT *root);
Squeue *Initqueue();
void InSqueue(Squeue *s,BT *x);
BT OutSqueue(Squeue *s);
int Empty_Squeue(Squeue *s);
void Findk(BT *root);
void AllPath(BT *root,ElementType path[MAXSIZE],int pathlen);
int node_depth(BT *root, BT *node);


char *ch;

void main()
{
  
    char p[64];
	ElementType path[60];
	int pathlen=0;
	//int num2;
	BT *root;
	printf("请输入二叉树:\n");
    scanf("%s",p);
    ch= &p[0];
    root=CreatBT();
    //num2=Du_BT(root);

//	printf("%d",num2);
//	ChangeBT(root);
	//PreOrder(root);
    Findk(root);
	 //AllPath(root,path,pathlen);
	 //preorder(root);

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
int Du_BT(BT *root)//求度为2的节点个数
 {
	int i=0,m,n;
    if(root)
	{
		if(root->Lchild!=NULL&&root->Rchild!=NULL)
			i++;

        m=Du_BT(root->Lchild);
		n=Du_BT(root->Rchild);
		return(i+m+n);
	}
	else
		return(0);
}
void ChangeBT(BT *root)//交换二叉树各节点的左右子树
{
    BT *p,*q;
	p=root;
	if(p)
	{
		q=p->Lchild;
		p->Lchild=p->Rchild;
		p->Rchild=q;
	}
	else
		return;
     ChangeBT(p->Lchild);
	 ChangeBT(p->Rchild);
}
void PreOrder(BT *root)//先序遍历
{
	if(root)
	{
	visit(root);
    PreOrder(root->Lchild);
	PreOrder(root->Rchild);
	}
}
void visit(BT *root)
{


	printf("%2c",root->data);
}


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

void Findk(BT *root)//层次遍历，输出各点的层次
{
  Squeue *s;
    BT *p,t;
	int i=0,n;
	p=root;
    s=Initqueue();
    InSqueue(s,p);
	while(!Empty_Squeue(s))
	{
	
	
		t=OutSqueue(s);
		p=&t;
		//visit(p);
		n=node_depth(root,p);
			//i++;
		printf("(%c,%d)",p->data,n);
		if(p->Lchild!=NULL)
            InSqueue(s,p->Lchild);
		if(p->Rchild!=NULL)
            InSqueue(s,p->Rchild);
	      i++;
	
	}

		
    
}

void AllPath(BT *b,ElementType path[ ],int pathlen)//输出从根节点到叶子节点路径
//初始调用时path所有元素为空，pathlen为0，b

{
 //为根节点指针

int i;

if(b!=NULL)

{

if(b->Lchild==NULL&&b->Rchild==NULL)

{

    printf("%c: ",b->data);

    for(i=0;i<pathlen;i++)

    printf("%c ",path[i]);

    printf("\n");

}

else

{

    path[pathlen]=b->data;
//将当前节点放入路径中

          pathlen++;
//路径长度增1

        AllPath(b->Lchild,path,pathlen);
//递归扫描左子树

        AllPath(b->Rchild,path,pathlen);
//递归扫描右子树

       pathlen--;
//恢复环境

}

}

}

 int node_depth(BT *root, BT *node)
 {
int d;
if(root==NULL)
return(0);
if(root->data==node->data) //在根节点处，即第1层
return(1);
d = node_depth(root->Lchild, node);//找左节点
if(d>0)
return(d+1); //返回当前层数+1
d = node_depth(root->Rchild, node); //找右节点
if(d>0)
return(d+1); //返回当前层数+1

}
