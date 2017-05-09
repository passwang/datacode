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
	int x;  //������
	int y;  //������
	struct ESWN d; 
	struct node *next;
}StructNode,*LinkStack;

void maze(LinkStack top,int a[][MAZESIZE])   //���Թ�
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
			return 1;		// �ѵ��յ�
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
	else return 2;			// ����ͬ  
}

void search(LinkStack top,int a[][MAZESIZE])  //��Ѱ·��
{
	LinkStack temp;
	while(1)
	{
		if(top->next->d.east!=1)
		{//�ж϶�
			top->next->d.east=1;  //����һ��λ���򶫷�����Ϊ����Ѱ
			if(a[top->next->x][top->next->y-1]!=1)
			{
			/*if(compare(top,top->next->x,top->next->y-1))   //�ж���λ���Ƿ�Ϊ ջ�ڶ��ڵ�λ�� ���Ƿ�Ϊ·��λ��
				return;  //���Ƿ���*/
				temp=(LinkStack)malloc(sizeof(StructNode));  //��ʱ�ڵ�  ���浱ǰλ��
				temp->x=top->next->x;
				temp->y=top->next->y-1;  //��λ�õ�����
				temp->d.west=1;  //������λ������������Ϊ����Ѱ  ��Ϊ�����߹���
				temp->d.east=0;
				temp->d.south=0;
				temp->d.north=0;
				temp->next=top->next;
				top->next=temp;
				return;
			}
		}
		if(top->next->d.south!=1)
		{//�ж���
			top->next->d.south=1;
			if(a[top->next->x+1][top->next->y]!=1)
			{
			/*if(compare(top,top->next->x+1,top->next->y))   //�ж���λ���Ƿ�Ϊ ջ�ڶ��ڵ�λ�� ���Ƿ�Ϊ·��λ��
				return;  //���Ƿ���*/
				temp=(LinkStack)malloc(sizeof(StructNode));  //��ʱ�ڵ�  ���浱ǰλ��
				temp->x=top->next->x+1;
				temp->y=top->next->y;
				temp->d.north=1;  //������λ���򱱷�����Ϊ����Ѱ  ��Ϊ�ӱ��߹���
				temp->d.east=0;
				temp->d.south=0;
				temp->d.west=0;
				temp->next=top->next;
				top->next=temp;
				return;
			}
		}
		if(top->next->d.west!=1)
		{//�ж���
			top->next->d.west=1;
			if(a[top->next->x][top->next->y+1]!=1)
			{
			/*if(compare(top,top->next->x,top->next->y+1))   //�ж���λ���Ƿ�Ϊ ջ�ڶ��ڵ�λ�� ���Ƿ�Ϊ·��λ��
				return;  //���Ƿ���*/
				temp=(LinkStack)malloc(sizeof(StructNode));  //��ʱ�ڵ�  ���浱ǰλ��
				temp->x=top->next->x;
				temp->y=top->next->y+1;
				temp->d.east=1;  //������λ���򶫷�����Ϊ����Ѱ  ��Ϊ�Ӷ��߹���
				temp->d.south=0;
				temp->d.west=0;
				temp->d.north=0;
				temp->next=top->next;
				top->next=temp;
				return;
			}
		}
		if(top->next->d.north!=1)
		{//�жϱ�
			top->next->d.north=1;
			if(a[top->next->x-1][top->next->y]!=1)
			{
			/*if(compare(top,top->next->x-1,top->next->y))   //�ж���λ���Ƿ�Ϊ ջ�ڶ��ڵ�λ�� ���Ƿ�Ϊ·��λ��
				return;  //���Ƿ���*/
				temp=(LinkStack)malloc(sizeof(StructNode));  //��ʱ�ڵ�  ���浱ǰλ��
				temp->x=top->next->x-1;
				temp->y=top->next->y;
				temp->d.south=1;  //������λ�����Ϸ�����Ϊ����Ѱ  ��Ϊ���ϱ߹���
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
	};  //�����Թ���С
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
	top->next=NULL;   //����  ջ ͷ���
	top->x=1;
	top->y=16;  //���յ�����(8,8)����ͷ�����
	start=(LinkStack)malloc(sizeof(StructNode));
	start->x=16;  //���x����
	start->y=1;  //���y����
	start->d.east=0;
	start->d.south=1;
	start->d.west=0;
	start->d.north=0;
	start->next=top->next;
	top->next=start;      //��ʼ���� �ڵ�
	
	while(1)
	{
		maze(top,a); //��·��(�����Թ�)
		mark=compare(top);
		if(1==mark)
		{
			printf("��ϲ,�߳��Թ�!!!\n");
			break;
		}
		if(2==mark)
		{
			printf("���Թ�Ϊ����ͬ!!!\n");
			break;
		}
		search(top,a);  //����·��
		//getch();  //����������
		system("cls");
	}
	
}