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

void output(adjMatrix *G);
void create(adjMatrix *G);
void Dijkstra(adjMatrix *G,int start,int dist[],int path[][MAXSIZE]);


int dist[N];
int path[N][MAXSIZE];
void main()
{

	adjMatrix *G;
	int i,j;
   G=(struct node *)malloc(sizeof(struct node));
	create(G);
	output(G);
	Dijkstra(G,1,dist,path);
     for(i=1; i<=G->vexnum; i++)  
    {  
        for(j=1; j<=G->vexnum;j++)  
            printf("%3d",path[i][j]); 
		printf("\n");
        
    }  
	 printf("\n");
	 printf("%3c到各点的最短路径及长度为:\n",G->vex[1]);
	  for(i=1; i<=G->vexnum; i++)  
    {  
        if(i!=1 && dist[i]!=INFINTY)  
        {  
             
			printf("%c到%c的最短路径长度为%d:\n",G->vex[1],G->vex[i],dist[i]);
            printf("最短路径为:");  
            for(j=1; j<=G->vexnum; j++)  
            {  
                if(path[i][j]>0)  
                    
				printf("%3c",G->vex[path[i][j]]);
            }  
			printf("\n");
                         
        }  
        else if(dist[i]==INFINTY)  
            printf("%c到%c不可达\n",G->vex[1],G->vex[i]); 
    }  
  
}

void create(adjMatrix *G)
{
	int i,j,k,vex1,vex2,weight;
	
	printf("请输入顶点数,边数目:");
	scanf("%d,%d",&G->vexnum,&G->arcnum);
	for(i=1;i<=G->vexnum;i++)
		for(j=1;j<=G->vexnum;j++)
			G->arcs[i][j]=INFINTY;
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
				printf("请输入权值:\n");
				scanf("%d",&weight);
				G->arcs[vex1][vex2]=weight;

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
				printf("%10c",G->arcs[i][j]);
			
			else
            printf("%8d",G->arcs[i][j]);
		}
		printf("\n");
	}

}
void Dijkstra(adjMatrix *G,int start,int dist[],int path[][MAXSIZE])
{
	int mindist,i,j,k,t=1;
	for(i=1;i<=G->vexnum;i++)
	{
		dist[i]=G->arcs[start][i];
		if(G->arcs[start][i]!=INFINTY)
			path[i][1]=start;
	}
	path[start][0]=1;
	for(i=2;i<=G->vexnum;i++)
	{
		mindist=INFINTY;
		for(j=1;j<=G->vexnum;j++)
		{
			if(!path[j][0]&&dist[j]<mindist)
			{
				k=j;
				mindist=dist[j];
			}
			if(mindist==INFINTY)
				return;
			path[k][0]=1;
			for(j=1;j<=G->vexnum;j++)
			{
              if(!path[j][0]&&G->arcs[k][j]<INFINTY&&dist[k]+G->arcs[k][j]<dist[j])
			  {
				  dist[j]=dist[k]+G->arcs[k][j];
				  t=1;
				  printf("%d",dist[j]);
				  while(path[k][t]!=0)
				  {
					  path[j][t]=path[k][t];
					  t++;
				  }
				  path[j][t]=k;
				  path[j][t+1]=0;
			  }
			}
		}
	}
 



}
	