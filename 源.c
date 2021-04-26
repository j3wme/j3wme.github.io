#include<stdio.h>
#include<stdlib.h>
typedef struct Node       //结构体定义
{
    int data;
    struct Node* next;
}node;
node* creatlink()               //创建链表  
{
    node* head = (node*)malloc(sizeof(node));          //开辟空间
    head->next = NULL;                            //创建头结点 
    return head;
}
void inserlink(node* head, int num)              //插入链表       尾插法
{
    if (num >= 2)
    {
        for (int i = 1; i <= num; i++)
        {
            node* ct = head;
            while (ct->next)                //指针指向链表尾部
                ct = ct->next;
            node* pt = (node*)malloc(sizeof(node));
            pt->data = i;
            pt->next = NULL;               //新结构体指向NULL
            ct->next = pt;                    //原链表尾部指向新结构体
        }
    }
    node* ct = head;
    while (ct->next)
        ct = ct->next;
    ct->next = head->next;            //尾部指向头部
}
void foo(node* head)
{
    head = head->next;
    while (head->next)              //当循环链表只剩一个节点时结束循环
    {
        int num;
        printf("please input a num\n");
        scanf("%d", &num);       //输入第几人死亡
        for (int i = 0; i < num - 1; i++)
        {
            head = head->next;
        }
        printf("%d号死亡\n", head->data);
        node* pt = head->next;
        if (head == pt->next)
        {
            head->data = pt->data;       //若只有两个节点 下一节点指向NULL
            head->next = NULL;
            free(pt);
        }
        else
        {
            head->data = pt->data;         //该一节点数据等于下一节点数据   该节点指向下下一节点
            head->next = pt->next;
            free(pt);
        }
    }
    printf("%d号死亡\n", head->data);
}

int main()
{
    node* head = creatlink();
    inserlink(head, 10);
    foo(head);
}