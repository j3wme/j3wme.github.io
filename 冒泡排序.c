#include<stdio.h>
void bubblesort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)       //ѭ������
    {
        for (int j = 0; j < n - 1 - i; j++)        //�Ƚ����ĸ���
        {
            if (*(arr + j) > * (arr + j + 1))
            {                                 //�����������ƶ�
                int t = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = t;
            }
        }
    }
}

int main()
{
    int arr[10] = { 2,4,7,9,6,3,1,5,8,10 };
    bubblesort(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
}