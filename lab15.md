## 字符游戏 - 智能蛇


### 一、实验目的

1. 了解 算法 与 “智能” 的关系
2. 通过算法赋予蛇智能
3. 了解 Linux IO 设计的控制

### 二、实验环境

### 三、控制输入/输出设备

**1、VT 100 终端标准**
##### （1）.设定光标位置
```C
void set_cursor(int x, int y)
{
    printf("\033[%d;%dH", x, y);
}
```
##### （2）.清屏
```C
void clear()
{
    printf("\033[2J");
    set_cursor(1, 1);
}
```
**2、实现 kbhit()**

### 四、编写智能算法
 [智能蛇](智能蛇)

**1、决定蛇行走的方向函数**
```C
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
```
**2、智能蛇的程序框架**
```C
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
```
**3、函数设计**
```C
int eatfood(int x, int y)
int is_ok(int x,int y)
void snakeMove(int x,int y)
void Creat_Food()
void find_head()
void find_way()
void count_distance()
void SmartSnake()
```

### 五、评价
虽说是智能蛇，但还是会做出一些不明智的决定。所以，还需要学习更先进的算法，来让智能蛇在这个游戏中做到完美。