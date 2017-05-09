#include<stdio.h>
#include<stdlib.h>

#define maxsize 100

int row = 0;                        //Ŀ�ĵ�������
int line = 0;                       //Ŀ�ĵ�������

typedef struct position{            //�Թ��е�λ������
    int x;                          //������
    int y;                          //������
}Position;

typedef struct node{
    Position    seat;               //��ǰλ�����Թ��е�����
    int         direction;
    /*���嵱ǰλ��������һ��λ�õķ���
     *1,2,3,4�ֱ��Ӧ�ϡ��ҡ��¡����λ
     *��,����������λ�ñ任��ֻ��Ҫ��1
    */
    struct node * next;
}LStack;

void InitStack(LStack ** Stacktop)
{
    *Stacktop = (LStack *)malloc(sizeof(LStack));
    (*Stacktop)->next = NULL;
}

int Empty(LStack * Stacktop)
{
    if(Stacktop->next == NULL)
        return 1;
    else
        return 0;

}

int pop(LStack * Stacktop, LStack ** p)                 //��ջ����,�ɹ�����0,������-1,pΪҪ����ջ��ֵ���ڴ�ռ�
{
    if(Empty(Stacktop))
    {
        return -1;
    }
    else
    {
        * p = Stacktop->next;
        Stacktop->next = Stacktop->next->next;
        return 0;
    }
}

int push(LStack * Stacktop, int x, int y, int direction)     //��ջ������x, y, direction�ֱ�Ϊ��ջԪ�ص�λ������ͷ���
{
    LStack * p;
    p = (LStack *)malloc(sizeof(LStack));
    p->seat.x = x;
    p->seat.y = y;
    p->direction = direction;
    p->next = Stacktop->next;
    Stacktop->next = p;
    return 0;
}

void print_stack(LStack * Stacktop)
{
    int i, j;
    LStack * p, *head;
    int map[100][100] = {0};
    head = (LStack *)malloc(sizeof(LStack));
    head->next = NULL;
    while(Stacktop->next != NULL)           //��ͬ�ڽ�ջ�������ת��Ϊ����
    {
        p = Stacktop->next;
        Stacktop->next = p->next;
        p->next = head->next;
        head->next = p;
    }
    p = head->next;
    while(p)
    {
        map[p->seat.x][p->seat.y] = 1;
        printf("(%d,%d)\t", p->seat.x, p->seat.y);
        if(p->next)
        {
            switch(p->next->direction)
            {
                case 1:
                printf("����\n");
                break;
                case 2:
                printf("����\n");
                break;
                case 3:
                printf("����\n");
                break;
                case 4:
                printf("����\n");
                break;
            }
        }
        p = p->next;
    }
    printf("\n");
    printf("�����ͼʾ����:\n");
    for(i = 1; i <= row; i++)
    {
        for(j = 1; j <= line; j++)
        {
            if(map[i][j] == 1)
            {
                printf("\033[42m * \033[0m");
            }
            else{
                printf(" 1 ");
            }
        }
        printf("\n");
    }
}

int Gettop(LStack *Stacktop, LStack ** p)
{
    if(Empty(Stacktop))
    {
        return -1;
    }
    else
    {
        *p = Stacktop->next;
        return 0;
    }
}

void InitMaze_static_array(int maze[][maxsize])
{
    int i, j;
    for(i = 0; i < line + 2; i++)
    {
        maze[0][i] = 1;
    }
    for(i = 0; i < line + 2; i++)
    {
        maze[row + 1][i] = 1;
    }
    for(i = 0; i < row + 2; i++)
    {
        maze[i][0] = 1;
    }
    for(i = 0; i < row + 2; i++)
    {
        maze[i][line + 1] = 1;
    }
    printf("�������Թ�1�����ϰ���0����ͨ·��ÿ������һ���ÿո������\n");
    for(i = 1; i <= row; i++) 
    {
        for(j = 1; j <= line; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }
}

void print_maze(int maze[][maxsize])
{
    int i, j;
    for(i = 1; i <= row; i++)
    {
        for(j = 1; j <= line; j++)
        {
            printf("%3d", maze[i][j]);
        }
        printf("\n");
    }
}


void path(int maze[][maxsize], LStack * Stacktop, int start_x, int start_y, int end_x, int end_y)
{
    LStack * p;                                                 //�������ջ������
    int cx = start_x, cy = start_y;                             //cx, cy����ǰλ��
    int direction = 1;
    p = (LStack*)malloc(sizeof(LStack));
    push(Stacktop, cx, cy, 2);
    while(cx != end_x || cy != end_y)
    {
        Gettop(Stacktop, &p);
        direction = p->direction;
        if(maze[cx - 1][cy] == 0 && direction != 3)
        {
            push(Stacktop, cx - 1, cy, 1);
            cx = cx - 1;
            continue;
        }
        else if(maze[cx][cy + 1] == 0 && direction != 4)
        {
            push(Stacktop, cx, cy + 1, 2);
            cy = cy + 1;
            continue;
        }
        else if(maze[cx + 1][cy] == 0 && direction != 1)
        {
            push(Stacktop, cx + 1, cy, 3);
            cx = cx + 1;
            continue;
        }
        else if(maze[cx][cy - 1] == 0 && direction != 2)
        {
            push(Stacktop, cx, cy - 1, 4);
            cy = cy - 1;
            continue;
        }
        else{                                               //����ǰλ�����ܶ����谭ʱ������һ������ջ
            pop(Stacktop, &p);
            direction = p->direction;
            if(direction == 1){
                maze[p->seat.x][p->seat.y] = 1;
                cx = p->seat.x + 1;
                cy = p->seat.y;
            }else if(direction == 2){
                maze[p->seat.x][p->seat.y] = 1;
                cx = p->seat.x;
                cy = p->seat.y - 1;
            }else if(direction == 3){
                maze[p->seat.x][p->seat.y] = 1;
                cx = p->seat.x - 1;
                cy = p->seat.y;
            }
            else if(direction == 4){
                maze[p->seat.x][p->seat.y] = 1;
                cx = p->seat.x;
                cy = p->seat.y + 1;
            }
            free(p);
        }
    }
}

int main(void)
{
    int start_x, start_y, end_x, end_y;
    LStack * Stacktop;                                  //ջ��
    int maze[maxsize][maxsize];
    printf("input row and line(eg: 6,8):");
    scanf("%d,%d", &row, &line);
    InitStack(&Stacktop);                                //��ʼ��ջ
    InitMaze_static_array(maze);                                    //��ʼ���Թ�
    printf("������Թ����£�\n");
    print_maze(maze);
    setbuf(stdin, 0);
    while(1)
    {
        printf("��������ʼλ������(eg:  1,1 ) :\n");
        scanf("%d,%d", &start_x, &start_y);
        if(start_x >= 1 && start_x <= row && start_y >= 1 && start_y <= line)
            break;
        else
            printf("�������\n");
    }
    setbuf(stdin, 0);
    while(1)
    {
        printf("������Ŀ��λ������(eg:  9,8 ) :\n");
        scanf("%d,%d", &end_x, &end_y);
        if(end_x <= row && end_x >= 1 && end_y >= 1 && end_y <= line)
            break;
        else
            printf("�������\n");
    }
    path(maze, Stacktop, start_x, start_y, end_x, end_y);
    printf("����·������ :\n");
    print_stack(Stacktop);
    return 0;
}
