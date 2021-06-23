//bubble_sort

#include <stdio.h>
#include "/home/ubuntu/my_header_file/array.h"

void swap(int *, int *);

int main(void)
{
    int arr[20], n, counter = -1, k;

    printf("Enter the number of elements do you want to enter\n");
    scanf("%d", &n);

    get_array(arr, n);


    k = n;
    while (counter != 0)
    {
        counter = 0;
        for (int i = 0; i < k - 1; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                swap(&arr[i + 1], &arr[i]);
                counter++;
            }
        }
        k = k - 1;
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












k = n;
    while (counter != 0)
    {
        counter = 0;
        for (int i = 0; i < k - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                counter = counter + 1;
            }
        }
        k = k - 1;
    }