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
	printf("�����������:\n");
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
int Du_BT(BT *root)//���Ϊ2�Ľڵ����
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
void ChangeBT(BT *root)//�������������ڵ����������
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
void PreOrder(BT *root)//�������
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

void Findk(BT *root)//��α������������Ĳ��
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

void AllPath(BT *b,ElementType path[ ],int pathlen)//����Ӹ��ڵ㵽Ҷ�ӽڵ�·��
//��ʼ����ʱpath����Ԫ��Ϊ�գ�pathlenΪ0��b

{
 //Ϊ���ڵ�ָ��

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
//����ǰ�ڵ����·����

          pathlen++;
//·��������1

        AllPath(b->Lchild,path,pathlen);
//�ݹ�ɨ��������

        AllPath(b->Rchild,path,pathlen);
//�ݹ�ɨ��������

       pathlen--;
//�ָ�����

}

}

}

 int node_depth(BT *root, BT *node)
 {
int d;
if(root==NULL)
return(0);
if(root->data==node->data) //�ڸ��ڵ㴦������1��
return(1);
d = node_depth(root->Lchild, node);//����ڵ�
if(d>0)
return(d+1); //���ص�ǰ����+1
d = node_depth(root->Rchild, node); //���ҽڵ�
if(d>0)
return(d+1); //���ص�ǰ����+1

}
