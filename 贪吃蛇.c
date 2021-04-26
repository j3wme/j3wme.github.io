//̰����
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define WIDTH 20   //�߽���
#define HIGH 20    //�߽�߶�
//������ͷ
typedef struct Snack
{
    int x;
    int y;
    struct Snack* next;
    struct Snack* pre;
}Snack;
//ʳ��
typedef struct Food
{
    int x;
    int y;
    char c;
}Food;
void PrintMap(Snack* head, Food* food) //���Ƶ�ͼ ������ͷ ʳ��
{
    system("cls");
    printf("������������������������\n");      //�����ϱ߽�
    for (int j = 0; j < HIGH; j++)
    {

        printf("��");                       //������߽�
        for (int i = 0; i < WIDTH; i += 2)
        {
            Snack* pt = head;
            int flag = 0;   //�ж��Ƿ�Ϊ������ͷ
            while (pt)
            {
                if (i == pt->x && j == pt->y)
                {
                    if (pt == head)
                        printf("��");   //������ͷ
                    else
                        printf("��");   //��������
                    flag = 1;
                    break;
                }
                pt = pt->next;
            }
            if (flag == 0)
            {

                if (i == food->x && j == food->y)      //����ʳ��
                {
                    printf("%c", food->c);
                    printf("%c", food->c);

                }
                else

                    printf("  ");         //ʲô�����Ǵ�ӡ�հ�
            }

        }
        printf("��\n");                //�����ұ߽�
    }
    printf("������������������������");        //�����±߽�
}
Snack* CreateSnack()      //��ʼ����ͷ����
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
int GameOver(Snack* head)    //�ж���Ϸ����   ��ͷײ��������Ϸ����   ��ͷײ�߽�����Ϸ����
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
int SnackEatFood(Snack* head, Food* food)   //�ж����Ƿ�Ե�ʳ��
{
    if (head->x == food->x && head->y == food->y)
        return 1;
    else
        return 0;
}
void CreateFood(Food* food, Snack* head)   //���ˢ��ʳ��
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

            if (food->x == pt->x && food->y == pt->y)       //�ж�ʳ���Ƿ���������ͷ�غ�
            {
                flag = 0;
                break;
            }
            pt = pt->next;

        }
    } while (flag == 0);
}
Snack* least(Snack* head)    //�ҵ���β
{
    while (head->next)
        head = head->next;
    return head;
}

void MoveSnack(Snack* head, Snack* last, char key)  //���ƶ�
{

    switch (key)
    {
    case 'W':        //�����ƶ�
    case 'w':
        while (last->pre)
        {
            last->x = last->pre->x;    //�������������һ����������
            last->y = last->pre->y;
            last = last->pre;
        }
        head->y -= 1;
        break;
    case 'S':         //�����ƶ�
    case 's':

        while (last->pre)         //�������������һ����������
        {
            last->x = last->pre->x;
            last->y = last->pre->y;
            last = last->pre;
        }
        head->y += 1;
        break;
    case 'A':        //�����ƶ�
    case 'a':

        while (last->pre)             //�������������һ����������
        {
            last->x = last->pre->x;
            last->y = last->pre->y;
            last = last->pre;
        }
        head->x -= 2;
        break;
    case 'D':          //�����ƶ�
    case 'd':

        while (last->pre)              //�������������һ����������
        {
            last->x = last->pre->x;
            last->y = last->pre->y;
            last = last->pre;
        }
        head->x += 2;
        break;
    }
}
void IncreaseSnack(Snack* last, Snack prelast)       //���߳Ե�ʳ����������
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
        if (_kbhit())              //��������Ƿ�д��
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
