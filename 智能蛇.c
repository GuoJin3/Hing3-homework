//智能蛇
//compile and execute in Linux 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define SNAKE_FOOD '$'
#define WALL_CELL '*'
#define MAP_LENGTH 12
int snakeLength = 5;
int snakeX[SNAKE_MAX_LENGTH] = {1,2,3,4,5};
int snakeY[SNAKE_MAX_LENGTH] = {1,1,1,1,1};
char map[15][15] = 
{
    "************",
    "*XXXXH *",
    "* *",
    "* *",
    "* *",
    "* *",
    "* *",
    "* *",
    "* *",
    "* *",
    "* *",
    "************"
};
void Creat_Food();
void Print()
{
    system("clear");
    int i,j;
    for(i = 0; i < MAP_LENGTH; i++)
    {
        for(j = 0; j < MAP_LENGTH; j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

void Clear()
{
    int i,j;
    for(i = 1; i < MAP_LENGTH-1; i++)
        for(j = 1; j < MAP_LENGTH-1; j++)
        {
            if(map[i][j] != '$')
                map[i][j] = ' ';
        }
}

void Draw()
{
    int i;
    for(int i = 0; i < snakeLength-1; i++)
        map[snakeY[i]][snakeX[i]] = SNAKE_BODY;
    map[snakeY[snakeLength-1]][snakeX[snakeLength-1]] = SNAKE_HEAD;
}

int eatfood(int x, int y)
{
    int headX = snakeX[snakeLength-1]+x;
    int headY = snakeY[snakeLength-1]+y;
    if(map[headY][headX] == '$')
    {
        snakeLength++;
        snakeX[snakeLength-1] = headX;
        snakeY[snakeLength-1] = headY;
        return 1;
    }
    return 0;
}

int is_ok(int x,int y)
{
    int headX = snakeX[snakeLength-1]+x;
    int headY = snakeY[snakeLength-1]+y;
    int i;
    if(headX <= 0 || headX >= 11 || headY <= 0 || headY >= 11)
        return 0;
    if(map[headY][headX] == '*')
        return 0;
    for(i = 0; i < snakeLength; ++i)
    {
        int bodyX = snakeX[i];
        int bodyY = snakeY[i];
        if(headX == bodyX && headY == bodyY)
            return 0;
    }
    return 1;
}

void snakeMove(int x,int y)
{
    if(!is_ok(x,y))
    {
        getchar();
        printf("Sorry,GAME OVER! PUSH \"C\" TO CONTINUE\n");
        getchar();
        return ;
    }
    if(eatfood(x,y))
    {
        Creat_Food();
    }
    int i;
    for(i = 0; i < snakeLength-1; i++)
    {
        snakeX[i] = snakeX[i+1];
        snakeY[i] = snakeY[i+1];
    }
    snakeX[snakeLength-1] += x;
    snakeY[snakeLength-1] += y;
    Clear();
    Draw();
}

void Creat_Food()
{
    srand(time(0));
    int fx,fy;
    while(1)
    {
        fx = rand() % 12;
        fy = rand() % 12;
        if(map[fx][fy] == ' ')
        {
            map[fx][fy] = '$';
            break;
        }
    }
}
int headi,headj,foodi,foodj;

void find_head()
{
    int i, j;
    for(i = 0; i < 12; i++)
    {
        for(j = 0; j < 12; j++)
        {
            if(map[i][j] == 'H')
            {
                headi = i;
                headj = j;
                goto here;
            }
        }
    }
here:
    return ;
}

void find_food()
{
    int i,j;
    for(i = 0; i < 12; i++)
    {
        for(j = 0; j < 12; j++)
        {
            if(map[i][j] == '$')
            {
                foodi = i;
                foodj = j;
                goto here;
            }
        }
    }
here:
    return;
}
//a d w s
int movable[10];
void find_way()
{
    int i;
    for(i = 0; i < 10; i++)
        movable[i] = 0;
    if(is_ok(-1,0))
        movable[0] = 1;
    if(is_ok(1,0))
        movable[1] = 1;
    if(is_ok(0,-1))
        movable[2] = 1;
    if(is_ok(0,1))
        movable[3] = 1;
}

int distance[10];

void count_distance()
{
    int i = 0;
    for(i = 0; i < 10; i++)
        distance[i] = 0;
    distance[0] = abs(foodi - (headi)) + abs(foodj - (headj-1));
    distance[1] = abs(foodi - (headi)) + abs(foodj - (headj+1));
    distance[2] = abs(foodi - (headi-1)) + abs(foodj - (headj));
    distance[3] = abs(foodi - (headi+1)) + abs(foodj - (headj));
}
#define Min(a,b) a > b ? b : a
void SmartSnake()
{
// getchar();
    find_food();
    find_head();
    find_way();
    count_distance();
    int i;int t;
    int minn = 9999;
    for(i = 0; i < 4; i++)
    {
        if(movable[i] > 0)
        {
            if(minn > distance[i])
            {
                t = i;
                minn = distance[i];
            }
        }
    }
/* for(i = 0; i < 4; i++) printf("%d ",distance[i]); printf("\n"); for(i = 0; i < 4; i++) printf("%d ",movable[i]); printf("\n"); printf("t %d",t); getchar(); */  if(minn == 9999)
        return ;
    else
    {
        switch(t)
        {
            case 0:
                snakeMove(-1,0);
                Print();
                break;
            case 1:
                snakeMove(1,0);
                Print();
                break;
            case 2:
                snakeMove(0,-1);
                Print();
                break;
            case 3:
                snakeMove(0,1);
                Print();
                break;
        }
    }
}

int main()
{
    Creat_Food();
    Print();
    char c;
    printf("if you want to make your snake smart,Please press Z\n");
    printf("else press ADWS to play the game,enjoy yourself\n");
    while(scanf("%c",&c))
    {
        if(c == 'Z')
        {while(1)
            SmartSnake(); 
        break;}
        switch(c)
        {
            case 'W':
                snakeMove(0,-1);
                break;
            case 'A':
                snakeMove(-1,0);
                break;
            case 'S':
                snakeMove(0,1);
                break;
            case 'D':
                snakeMove(1,0);
                break;
        }
        Print();
    }
    return 0;
}