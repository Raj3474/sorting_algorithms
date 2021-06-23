#include<stdio.h>


void get_array(int arr[], int length)
{
    printf("\nEnter the elements\n");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display_array(int arr[], int beg, int end)
{
    for (int i = beg; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}