//贪吃蛇
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define WIDTH 20   //边界宽度
#define HIGH 20    //边界高度
//蛇身蛇头
typedef struct Snack
{
    int x;
    int y;
    struct Snack* next;
    struct Snack* pre;
}Snack;
//食物
typedef struct Food
{
    int x;
    int y;
    char c;
}Food;
void PrintMap(Snack* head, Food* food) //绘制地图 蛇身蛇头 食物
{
    system("cls");
    printf("■■■■■■■■■■■■\n");      //绘制上边界
    for (int j = 0; j < HIGH; j++)
    {

        printf("■");                       //绘制左边界
        for (int i = 0; i < WIDTH; i += 2)
        {
            Snack* pt = head;
            int flag = 0;   //判断是否为蛇身蛇头
            while (pt)
            {
                if (i == pt->x && j == pt->y)
                {
                    if (pt == head)
                        printf("◎");   //绘制蛇头
                    else
                        printf("☆");   //绘制蛇身
                    flag = 1;
                    break;
                }
                pt = pt->next;
            }
            if (flag == 0)
            {

                if (i == food->x && j == food->y)      //绘制食物
                {
                    printf("%c", food->c);
                    printf("%c", food->c);

                }
                else

                    printf("  ");         //什么都不是打印空白
            }

        }
        printf("■\n");                //绘制右边界
    }
    printf("■■■■■■■■■■■■");        //绘制下边界
}
Snack* CreateSnack()      //初始化蛇头蛇身
{
    Snack* head = (Snack*)malloc(sizeof(Snack));
    Snack* st = (Snack*)malloc(sizeof(Snack));

    head->next = st;
    head->pre = NULL;
    head->x = 6;
    head->y = 5;
    st->pre = head;
    st->next = NULL;
    st->x = 4;
    st->y = 5;
    return head;
}
int GameOver(Snack* head)    //判断游戏结束   蛇头撞蛇身则游戏结束   蛇头撞边界则游戏结束
{
    int gameover = 0;
    Snack* pt = head;
    pt = pt->next;
    while (pt)
    {
        if (head->x == pt->x && head->y == pt->y)
        {
            gameover = 1;
            break;
        }
        pt = pt->next;
    }
    if (head->x < 0 || head->x == 20 || head->y < 0 || head->y == 20)
        gameover = 1;
    return gameover;
}
int SnackEatFood(Snack* head, Food* food)   //判断蛇是否吃到食物
{
    if (head->x == food->x && head->y == food->y)
        return 1;
    else
        return 0;
}
void CreateFood(Food* food, Snack* head)   //随机刷新食物
{
    int flag = 1;

    do {
        flag = 1;
        Snack* pt = head;
        srand(time(NULL));
        food->x = rand() % (WIDTH - 4) + 2;
        food->y = rand() % HIGH;
        while (food->x % 2 != 0)
        {
            food->x = rand() % (WIDTH - 2);
        }
        while (pt)
        {

            if (food->x == pt->x && food->y == pt->y)       //判断食物是否与蛇身蛇头重合
            {
                flag = 0;
                break;
            }
            pt = pt->next;

        }
    } while (flag == 0);
}
Snack* least(Snack* head)    //找到蛇尾
{
    while (head->next)
        head = head->next;
    return head;
}

void MoveSnack(Snack* head, Snack* last, char key)  //蛇移动
{

    switch (key)
    {
    case 'W':        //向上移动
    case 'w':
        while (last->pre)
        {
            last->x = last->pre->x;    //蛇身坐标等于上一个蛇身坐标
            last->y = last->pre->y;
            last = last->pre;
        }
        head->y -= 1;
        break;
    case 'S':         //向下移动
    case 's':

        while (last->pre)         //蛇身坐标等于上一个蛇身坐标
        {
            last->x = last->pre->x;
            last->y = last->pre->y;
            last = last->pre;
        }
        head->y += 1;
        break;
    case 'A':        //向左移动
    case 'a':

        while (last->pre)             //蛇身坐标等于上一个蛇身坐标
        {
            last->x = last->pre->x;
            last->y = last->pre->y;
            last = last->pre;
        }
        head->x -= 2;
        break;
    case 'D':          //向右移动
    case 'd':

        while (last->pre)              //蛇身坐标等于上一个蛇身坐标
        {
            last->x = last->pre->x;
            last->y = last->pre->y;
            last = last->pre;
        }
        head->x += 2;
        break;
    }
}
void IncreaseSnack(Snack* last, Snack prelast)       //当蛇吃到食物增长蛇身
{
    Snack* pt = (Snack*)malloc(sizeof(Snack));
    pt->x = prelast.x;
    pt->y = prelast.y;
    pt->next = NULL;
    pt->pre = last;
    last->next = pt;
}

int main()
{
    int score = 0;
    int t = 200;
    Snack* head = CreateSnack();
    char key = 'd';
    Food food = { 2,4,"D" };
    while (1)
    {
        PrintMap(head, &food);
        printf("\n");
        printf("score : %d", score);
        Snack* last = least(head);
        Snack prelast = { last->x,last->y,NULL,NULL };
        if (_kbhit())              //检验键盘是否写入
        {
            key = _getch();
        }
        MoveSnack(head, last, key);
        if (GameOver(head) == 1)
        {
            system("cls");
            printf("GameOver");
            break;
        }
        if (SnackEatFood(head, &food) == 1)
        {
            score += 10;
            if (t > 60)
                t -= 10;
            IncreaseSnack(last, prelast);
            CreateFood(&food, head);
        }
        Sleep(t);
    }
    return 0;
}
