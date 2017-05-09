#include <stdio.h>
#include <malloc.h>
#define N 20
#define MAXSIZE 20
#define INFINTY 100
typedef struct node{
	int arcs[N][N];
	char  vex[N];//顶点信息
	int vexnum;//顶点数目
	int arcnum;//边数目
}adjMatrix;
typedef struct {
int  data[MAXSIZE];
int front,rear;
}Squeue;


void create(adjMatrix *G);
void output(adjMatrix *G);

int outcount(adjMatrix *G,int i);

int incount(adjMatrix *G,int j);
void TraverseD(adjMatrix *G);
void DFS(adjMatrix *G,int v);
void visit(adjMatrix *G,int v);
int FirstAdj(adjMatrix *G,int v);
int NextAdj(adjMatrix *G,int v,int w);
void TraverseB(adjMatrix *G);
void BFS(adjMatrix *G,int v);
Squeue  *Initqueue();
void Enterqueue(Squeue *Q,int x);
int Outqueue(Squeue *Q);
int Empty(Squeue *Q);

void qiudu(adjMatrix *G);

int visited[N]={0};

void main()
{

	adjMatrix *G;
   G=(struct node *)malloc(sizeof(struct node));
	create(G);
	output(G);
	qiudu(G);
	printf("DFS为:\n");
	TraverseD(G);
  	printf("\n");
    printf("BFS为:\n");
    TraverseB(G);
	printf("\n");
	

	


	
}
void create(adjMatrix *G)
{
	int i,j,k,vex1,vex2;
	
	printf("请输入顶点数,边数目:");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	for(i=1;i<=G->vexnum;i++)
		for(j=1;j<=G->vexnum;j++)
			G->arcs[i][j]=0;
		printf("请输入有向图中%d个顶点信息:\n",G->vexnum);
		for(i=1;i<=G->vexnum;i++)
		{
			printf("请输入第%d个顶点:",i);
			fflush(stdin);
			scanf("%c",&G->vex[i]);
		}
		printf("请输入%d条边 :\n",G->arcnum);
			for(k=0;k<G->arcnum;k++)
			{
				printf("请输入第%d条边:\n 顶点V",k+1);
                scanf("%d",&vex1);
				printf("<---->顶点V");
				scanf("%d",&vex2);
				G->arcs[vex1][vex2]=1;

			}
}

void output(adjMatrix *G)
{
	int i,j;
	for(i=1;i<=G->vexnum;i++)
           G->arcs[i][0]=G->vex[i];
   	for(j=1;j<=G->vexnum;j++)
           G->arcs[0][j]=G->vex[j];

	for(i=0;i<=G->vexnum;i++)
	{
		for(j=0;j<=G->vexnum;j++)
		{
			 if(i==0&&j==0)
				printf("   ");
			else if(i==0||j==0)
				printf("%3c",G->arcs[i][j]);
			
			else
            printf("%3d",G->arcs[i][j]);
		}
		printf("\n");
	}

}

int outcount(adjMatrix *G,int i)
{
	int j,count=0;
    
	
		for(j=1;j<=G->vexnum;j++)
		{
			if(G->arcs[i][j]==1)
				count++;
		}
		return(count);
	
}






int incount(adjMatrix *G,int j)
{
	int i,count=0;
	

       	for(i=1;i<=G->vexnum;i++)
		{
			if(G->arcs[i][j]==1)
				count++;
		}
			return(count);
	
	
}

void qiudu(adjMatrix *G)
{
    int i,chu,du,ru;
	printf("\t");
	printf("出度\t");
	printf("入度\t");
   	printf("度\n");
	for(i=1;i<=G->vexnum;i++)
	{
		printf("%5c:",G->vex[i]);
		chu=outcount(G,i);
		printf("%5d",chu);
		ru=incount(G,i);
		printf("%8d",ru);
        du=chu+ru;
       printf("%8d\n",du);




	}
}
void TraverseD(adjMatrix *G)
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

void DFS(adjMatrix *G,int v)
{
	int w;
	visit(G,v);
	visited[v]=1;
	w=FirstAdj(G,v);
	while(w!=6)
	{
		
		if(!visited[w])
			DFS(G,w);
		w=NextAdj(G,v,w);
		if(w>5||w==4)  break;
	}
}
void visit(adjMatrix *G,int v)
{
   printf("%3c",G->vex[v]);
  
}

int FirstAdj(adjMatrix *G,int v)
{
	int j,count;
	count=1;
	for(j=1;j<=G->vexnum;j++)
	{
		if(G->arcs[v][j]==0)
		{
			count++;
		    
		}
		else if(G->arcs[v][j]==1)
			return(count);

		
	}
	
}

int NextAdj(adjMatrix *G,int v,int w)
{
	int j,count;
	count=1;
	for(j=1;j<=G->vexnum;j++)
	{
		
		if(G->arcs[v][j]==0||count==w)
		{
			count++;
			
		}
		
	}
	return(count);
}

void TraverseB(adjMatrix *G)
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


void BFS(adjMatrix *G,int v)
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
		while(w!=6)
		{
			if(!visited[w])
			{
				visit(G,w);
				visited[w]=1;
				Enterqueue(Q,w);
			}
			w=NextAdj(G,v,w);
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


