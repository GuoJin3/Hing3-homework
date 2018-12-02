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

    void put_food(void)
    {
        srand(time(NULL));
        if (foodYes == 1)
        {
            foodX = rand() % 10 + 1;
            foodY = rand() % 10 + 1;
            while ((map[foodY][foodX] == SNAKE_BODY) || (map[foodY][foodX] == SNAKE_HEAD))
            {
                foodX = rand() % 10 + 1;
                foodY = rand() % 10 + 1;
            }
            map[foodY][foodX] = SNAKE_FOOD;
            foodYes = 0;
        }
        if (map[foodY][foodX] != SNAKE_FOOD)
        {
            if (snakeLength < SNAKE_MAX_LENGTH)
            {
                snakeLength++;
                lenthchange = 1;
            }
            foodYes = 1;
        }
    }