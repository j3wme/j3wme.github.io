#include<stdio.h>
#include<stdlib.h>
typedef struct Node       //�ṹ�嶨��
{
    int data;
    struct Node* next;
}node;
node* creatlink()               //��������  
{
    node* head = (node*)malloc(sizeof(node));          //���ٿռ�
    head->next = NULL;                            //����ͷ��� 
    return head;
}
void inserlink(node* head, int num)              //��������       β�巨
{
    if (num >= 2)
    {
        for (int i = 1; i <= num; i++)
        {
            node* ct = head;
            while (ct->next)                //ָ��ָ������β��
                ct = ct->next;
            node* pt = (node*)malloc(sizeof(node));
            pt->data = i;
            pt->next = NULL;               //�½ṹ��ָ��NULL
            ct->next = pt;                    //ԭ����β��ָ���½ṹ��
        }
    }
    node* ct = head;
    while (ct->next)
        ct = ct->next;
    ct->next = head->next;            //β��ָ��ͷ��
}
void foo(node* head)
{
    head = head->next;
    while (head->next)              //��ѭ������ֻʣһ���ڵ�ʱ����ѭ��
    {
        int num;
        printf("please input a num\n");
        scanf("%d", &num);       //����ڼ�������
        for (int i = 0; i < num - 1; i++)
        {
            head = head->next;
        }
        printf("%d������\n", head->data);
        node* pt = head->next;
        if (head == pt->next)
        {
            head->data = pt->data;       //��ֻ�������ڵ� ��һ�ڵ�ָ��NULL
            head->next = NULL;
            free(pt);
        }
        else
        {
            head->data = pt->data;         //��һ�ڵ����ݵ�����һ�ڵ�����   �ýڵ�ָ������һ�ڵ�
            head->next = pt->next;
            free(pt);
        }
    }
    printf("%d������\n", head->data);
}

int main()
{
    node* head = creatlink();
    inserlink(head, 10);
    foo(head);
}