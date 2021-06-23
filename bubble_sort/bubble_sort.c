//bubble_sort

#include <stdio.h>
#include "/home/ubuntu/my_header_file/array.h"

void swap(int *, int *);

int main(void)
{
    int n;

    printf("Enter the number of elements do you want to enter\n");
    scanf("%d", &n);

    int arr[n];

    get_array(arr, n);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    printf("The sorted elements are:\n");
    display_array(arr, 0, n - 1);
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}