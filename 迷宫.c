#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAZESIZE 17

struct ESWN
{
	short east;
	short south;
	short west;
	short north;
};
typedef struct node
{
	int x;  //横坐标
	int y;  //纵坐标
	struct ESWN d; 
	struct node *next;
}StructNode,*LinkStack;

void maze(LinkStack top,int a[][MAZESIZE])   //画迷宫
{
	int i,j;
	for(i=0;i<MAZESIZE;i++)
	{
		for(j=0;j<MAZESIZE;j++)
		{
			if(a[i][j]==1)
				printf("* ");
			else
				if(top->next->x==i&&top->next->y==j)
					printf("# ");
				else
					printf("  ");
		}
		printf("\n");
	}
}

int compare(LinkStack top)
{
	LinkStack r;
	if(top->next!=NULL)
	{
		if(top->next->x==top->x&&top->next->y==top->y)
			return 1;		// 已到终点
		else
		{
			r=top->next->next;
			if(r!=NULL)
				while(r!=NULL)
				{
					if(r->x==top->next->x&&r->y==top->next->y)
					{
						top->next->d.east=1;
						top->next->d.north=1;
						top->next->d.south=1;
						top->next->d.west=1;
					}
					r=r->next;
				}
				return 0;
		}
	}
	else return 2;			// 死胡同  
}

void search(LinkStack top,int a[][MAZESIZE])  //搜寻路径
{
	LinkStack temp;
	while(1)
	{
		if(top->next->d.east!=1)
		{//判断东
			top->next->d.east=1;  //把上一个位置向东方向标记为已搜寻
			if(a[top->next->x][top->next->y-1]!=1)
			{
			/*if(compare(top,top->next->x,top->next->y-1))   //判断新位置是否为 栈第二节点位置 即是否为路过位置
				return;  //若是返回*/
				temp=(LinkStack)malloc(sizeof(StructNode));  //临时节点  保存当前位置
				temp->x=top->next->x;
				temp->y=top->next->y-1;  //新位置的坐标
				temp->d.west=1;  //把上新位置向西方向标记为已搜寻  因为从西边过来
				temp->d.east=0;
				temp->d.south=0;
				temp->d.north=0;
				temp->next=top->next;
				top->next=temp;
				return;
			}
		}
		if(top->next->d.south!=1)
		{//判断南
			top->next->d.south=1;
			if(a[top->next->x+1][top->next->y]!=1)
			{
			/*if(compare(top,top->next->x+1,top->next->y))   //判断新位置是否为 栈第二节点位置 即是否为路过位置
				return;  //若是返回*/
				temp=(LinkStack)malloc(sizeof(StructNode));  //临时节点  保存当前位置
				temp->x=top->next->x+1;
				temp->y=top->next->y;
				temp->d.north=1;  //把上新位置向北方向标记为已搜寻  因为从北边过来
				temp->d.east=0;
				temp->d.south=0;
				temp->d.west=0;
				temp->next=top->next;
				top->next=temp;
				return;
			}
		}
		if(top->next->d.west!=1)
		{//判断西
			top->next->d.west=1;
			if(a[top->next->x][top->next->y+1]!=1)
			{
			/*if(compare(top,top->next->x,top->next->y+1))   //判断新位置是否为 栈第二节点位置 即是否为路过位置
				return;  //若是返回*/
				temp=(LinkStack)malloc(sizeof(StructNode));  //临时节点  保存当前位置
				temp->x=top->next->x;
				temp->y=top->next->y+1;
				temp->d.east=1;  //把上新位置向东方向标记为已搜寻  因为从东边过来
				temp->d.south=0;
				temp->d.west=0;
				temp->d.north=0;
				temp->next=top->next;
				top->next=temp;
				return;
			}
		}
		if(top->next->d.north!=1)
		{//判断北
			top->next->d.north=1;
			if(a[top->next->x-1][top->next->y]!=1)
			{
			/*if(compare(top,top->next->x-1,top->next->y))   //判断新位置是否为 栈第二节点位置 即是否为路过位置
				return;  //若是返回*/
				temp=(LinkStack)malloc(sizeof(StructNode));  //临时节点  保存当前位置
				temp->x=top->next->x-1;
				temp->y=top->next->y;
				temp->d.south=1;  //把上新位置向南方向标记为已搜寻  因为从南边过来
				temp->d.east=0;
				temp->d.west=0;
				temp->d.north=0;
				temp->next=top->next;
				top->next=temp;
				return;
			}
		}
		temp=top->next;
		top->next=top->next->next;
		free(temp);
		return;
	}
}


main()
{
	LinkStack top,start; 
	int mark;
	/*int a[MAZESIZE][MAZESIZE]={
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
	};  //定义迷宫大小
	int a[MAZESIZE][MAZESIZE]={
	{1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,1,1,1,0,0,1,1,1,1,1,0,1},
	{1,1,0,1,0,0,0,0,0,0,1,0,1},
	{1,1,0,1,1,1,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,1,1,1,1,0,1,1,1,1,0,0,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,1,1,1,1,1,0,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1},
	{1,1,1,0,1,0,1,1,0,1,1,0,1},
	{1,0,0,0,1,0,1,0,0,0,1,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1}
};*/
	int a[MAZESIZE][MAZESIZE]={
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1},
		{1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,1,0,0,1,0,1,1,1,1,0,1,0,1},
		{1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1},
		{1,0,1,0,1,0,0,1,0,0,0,0,1,1,1,0,1},
		{1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1},
		{1,0,1,0,1,0,0,1,1,1,1,0,1,0,1,0,1},
		{1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,1,0,1,0,0,1,1,1,1,1,0,0,1,0,1},
		{1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1},
		{1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1},
		{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	top=(LinkStack)malloc(sizeof(StructNode));
	top->next=NULL;   //定义  栈 头结点
	top->x=1;
	top->y=16;  //将终点坐标(8,8)放在头结点中
	start=(LinkStack)malloc(sizeof(StructNode));
	start->x=16;  //起点x坐标
	start->y=1;  //起点y坐标
	start->d.east=0;
	start->d.south=1;
	start->d.west=0;
	start->d.north=0;
	start->next=top->next;
	top->next=start;      //开始坐标 节点
	
	while(1)
	{
		maze(top,a); //画路径(附带迷宫)
		mark=compare(top);
		if(1==mark)
		{
			printf("恭喜,走出迷宫!!!\n");
			break;
		}
		if(2==mark)
		{
			printf("该迷宫为死胡同!!!\n");
			break;
		}
		search(top,a);  //搜索路径
		//getch();  //按键单步走
		system("cls");
	}
	
}