#include <stdio.h>
#include <malloc.h>
#define MAXVEX 20
#define N 20
#define MAXSIZE 20
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *next;
}ArcNode;
typedef struct VertexNode{
	char vexdata;
    ArcNode *head;
}VertexNode;
typedef struct node{

	VertexNode vertex[MAXVEX];
	int vexnum;//顶点数
	int arcnum;//边数
}AdjList;

typedef struct {
int  data[MAXSIZE];
int front,rear;
}Squeue;

void create(AdjList *G);
void output(AdjList *G);
void qiudu(AdjList *G);
int chudu(ArcNode *p);
int rudu(AdjList *G,int k);

void TraverseD(AdjList *G);
void DFS(AdjList *G,int v);
void visit(AdjList *G,int v);
int FirstAdj(AdjList *G,int v);
int NextAdj(AdjList *G,int v);
void TraverseB(AdjList *G);
void BFS(AdjList *G,int v);
Squeue  *Initqueue();
void Enterqueue(Squeue *Q,int x);
int Outqueue(Squeue *Q);
int Empty(Squeue *Q);
int visited[N]={0};

void main()
{
	AdjList *G;
	G=(struct node *)malloc(sizeof(struct node));
	create(G);
	output(G);
	qiudu(G);
   /* printf("DFS为:\n");
	TraverseD(G);
	printf("\n");*/
     printf("BFS为:\n");
    TraverseB(G);
    printf("\n");
}


void create(AdjList *G)
{
		int i,k,vex1,vex2;
		ArcNode *p;
	printf("请输入顶点数,边数目:");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	printf("下面请输入%d个顶点的信息\n",G->vexnum);
	for(i=1;i<=G->vexnum;i++)
	{
		printf("请输入第%d个顶点信息:",i);
		fflush(stdin);
		scanf("%c",&G->vertex[i].vexdata);
		G->vertex[i].head=NULL;

	}
		printf("请输入%d条边 :\n",G->arcnum);
			for(k=1;k<=G->arcnum;k++)
			{
				printf("请输入第%d条边:\n 顶点V",k);
                scanf("%d",&vex1);
				printf("<---->顶点V");
				scanf("%d",&vex2);
				p=(struct ArcNode *)malloc(sizeof(struct ArcNode));
			   p->adjvex=vex2;
               p->next=G->vertex[vex1].head;
               G->vertex[vex1].head=p;   

			}
}
void output(AdjList *G)
{
	int i;
    ArcNode *p;

  printf("邻接表输出结果如下:\n");
	for(i=1;i<=G->vexnum;i++)
	{
		printf("%3c",G->vertex[i].vexdata);
		p=G->vertex[i].head;
		while(p!=NULL)
		{
			printf("%2d",p->adjvex);
			p=p->next;
		}
		printf("\n");
	}
}

void qiudu(AdjList *G)
{
	int i,chu,du,ru;
	printf("\t");
	printf("出度\t");
	printf("入度\t");
   	printf("度\n");
	for(i=1;i<=G->vexnum;i++)
	{
		printf("%5c:",G->vertex[i].vexdata);
        chu=chudu(G->vertex[i].head);
		printf("%5d",chu);
        ru=rudu(G,i);
		printf("%8d",ru);
        du=chu+ru;
		printf("%8d\n",du);
	}
}

int chudu(ArcNode *p)
{
	 int count=0;
	 while(p!=NULL)
	 {
		 count++;
		 p=p->next;
	 }
	 return(count);
}
int rudu(AdjList *G,int k)
{
	int i,count=0;
    ArcNode *p;
    for(i=1;i<=G->vexnum;i++)
	{
		p=G->vertex[i].head;
		while(p!=NULL)
		{
			if(p->adjvex==k)
				count++;
			p=p->next;
		}
	}
	return(count);
}


void TraverseD(AdjList *G)
{
	int v;
	for(v=1;v<=G->vexnum;v++)
		visited[v]=0;
	for(v=1;v<=G->vexnum;v++)
	{
		if(!visited[v])
			DFS(G,v);
	}
}

void DFS(AdjList *G,int v)
{
	int w;
	visit(G,v);
	visited[v]=1;
	w=FirstAdj(G,v);
	while(w!=6)
	{
		
		if(!visited[w])
			DFS(G,w);
		w=NextAdj(G,v);
		if(w>5||w==4)  break;
	}
}
void visit(AdjList *G,int v)
{
   printf("%3c",G->vertex[v].vexdata);
  
}

int FirstAdj(AdjList *G,int v)
{
	
    ArcNode *p;
    p=G->vertex[v].head;
	if(p==NULL)
		return(6);
	else
	return(p->adjvex);
	
	
}

int NextAdj(AdjList *G,int v)
{
    ArcNode *p;
   p=G->vertex[v].head;
   if(p->next==NULL)
	   return(6);
   else
   	return(p->next->adjvex);

}

void TraverseB(AdjList *G)
{

   	int v;
	for(v=1;v<=G->vexnum;v++)
		visited[v]=0;
	for(v=1;v<=G->vexnum;v++)
	{
		if(!visited[v])
			BFS(G,v);
	}
}


void BFS(AdjList *G,int v)
{
	Squeue *Q;
	int w;
	visit(G,v);
	visited[v]=1;
	Q=Initqueue();
	Enterqueue(Q,v);
	while(!Empty(Q))
	{
		v=Outqueue(Q);
		w=FirstAdj(G,v);
		while(w!=2)
		{
			if(!visited[w])
			{
				visit(G,w);
				visited[w]=1;
				Enterqueue(Q,w);
			}
			w=NextAdj(G,v);
				if(w>5||w==4)  break;
	
		}
	}
}

Squeue  *Initqueue()//初始化，置空队
{
	Squeue *Q;
	Q=malloc(sizeof(Squeue));
	Q->rear=Q->front=MAXSIZE-1;
	return(Q);
}
void Enterqueue(Squeue *Q,int x)//入队
{
	if((Q->rear+1)%MAXSIZE==Q->front)
		printf("队满!\n");
	else
	{
		Q->rear=(Q->rear+1)%MAXSIZE;
		Q->data[Q->rear]=x;
	}
}
int Outqueue(Squeue *Q)//出队
{
	if(Q->rear==Q->front)
		printf("队空");
	else
	{
		Q->front=(Q->front+1)%MAXSIZE;
		return(Q->data[Q->front]);
	}
}
		
int Empty(Squeue *Q)
{
	if(Q->front==Q->rear)
		return(1);
	else
		return(0);
}


