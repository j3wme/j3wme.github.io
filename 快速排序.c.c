#include<stdio.h>
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {

        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x)           //�Ӻ�����С����
                j--;
            if (i < j && s[j] < x)
                s[i++] = s[j];               //С�����ƶ���ǰ��

            while (i < j && s[i] <= x)           //��ǰ���Ҵ����
                i++;
            if (i < j && s[i]>x)
                s[j--] = s[i];             //������ƶ�������
        }
        s[i] = x;
        quick_sort(s, l, i - 1);            //�ݹ�ǰһ��δ���е���
        quick_sort(s, i + 1, r);            //�ݹ��һ��δ���е���
    }
}
int main()
{
    int arr[10] = { 4,7,6,2,5,1,3,9,8,10 };
    quick_sort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
}







//qsort����     ���ڿ�������
#include<stdio.h>
#include<stdlib.h>
int CallBackCompare(const void* a, const void* b)
{
    return  *(int*)a > * (int*)b ? 1 : -1;
}
int main()
{
    int arr[10] = { 5,4,1,3,6,9,7,2,8,10 };
    qsort(arr, 10, sizeof(int), CallBackCompare);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
}