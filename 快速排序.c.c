#include<stdio.h>
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {

        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x)           //从后面找小的数
                j--;
            if (i < j && s[j] < x)
                s[i++] = s[j];               //小的数移动到前面

            while (i < j && s[i] <= x)           //从前面找大的数
                i++;
            if (i < j && s[i]>x)
                s[j--] = s[i];             //大的数移动到后面
        }
        s[i] = x;
        quick_sort(s, l, i - 1);            //递归前一半未排列的数
        quick_sort(s, i + 1, r);            //递归后一半未排列的数
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







//qsort函数     基于快速排列
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