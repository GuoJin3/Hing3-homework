#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
# define SNAKE_MAX_LENGTH 100
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'
char map[12][13] = {
    "************",
    "*H         *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "************",
};

void snakeMove()
{
    char control = _getch();
    int preSnakeHeadX = snakeHeadX;
    int preSnakeHeadY = snakeHeadY;
    switch (control)
    {
        case 'w':
            snakeHeadX--;
            break;
        case 'a':
            snakeHeadY--;
            break;
        case 's':
            snakeHeadX++;
            break;
        case 'd':
            snakeHeadY++;
            break;
        default:
            break;
    }
    if (map[snakeHeadX][snakeHeadY] == WALL_CELL||map[snakeHeadX][snakeHeadY]==SNAKE_BODY)
        gameover();
    map[snakeHeadX][snakeHeadY] = SNAKE_HEAD;
    map[preSnakeHeadX][preSnakeHeadY] = BLANK_CELL;
    if (snakeHeadX == FoodX && snakeHeadY == FoodY)
    {
        snakeBodyX[snakeBodyLen] = preSnakeHeadX;
        snakeBodyY[snakeBodyLen] = preSnakeHeadY;
        snakeBodyLen++;
        map[preSnakeHeadX][preSnakeHeadY] =SNAKE_BODY;
        putFood();
        return;
    }
    if (snakeBodyLen <= 0)
        return;
    int i;
    for (i = 0; i < snakeBodyLen-1; i++)
    {
        snakeBodyX[i] = snakeBodyX[i + 1];
        snakeBodyY[i] = snakeBodyY[i + 1];
    }
    snakeBodyX[snakeBodyLen - 1] = preSnakeHeadX;
    snakeBodyY[snakeBodyLen - 1] = preSnakeHeadY;
    int j;
    for (j = 0; j < snakeBodyLen; j++)
        map[snakeBodyX[j]][snakeBodyY[j]] = SNAKE_BODY;
    map[snakeBodyX[0]][snakeBodyY[0]] = BLANK_CELL;
}
