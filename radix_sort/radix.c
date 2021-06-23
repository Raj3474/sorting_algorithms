// radix sorting....

#include<stdio.h>
#include<string.h>

#include "/home/ubuntu/my_header_file/array.h"

void radix_sort(int [], int);
void counting_sort(int [], int, int pos);
int maximum(int [], int);

int main(void)
{
    int n;

    printf("Enter the number of elements do you want to enter\n");
    scanf("%d", &n);

    int arr[n];

    // getting elements from the user
    get_array(arr, n);

    // printing my unsorted array.....
    printf("The elements before sorting are:\n");
    display_array(arr, 0, n - 1);

    radix_sort(arr, n);

    // printing the sorted array
    printf("\nThe sorted elements are:\n");
    display_array(arr, 0, n - 1);
}

void radix_sort(int arr[], int length)
{
    int max = maximum(arr, length);
    for (int pos = 1; max / pos > 0; pos *= 10)
    {
        counting_sort(arr, length, pos);
    }
}

void counting_sort(int arr[], int length, int pos)
{

    int count[10], output[length];

    // memset() for initializing the array with 0, #include<string.h>
    memset(count, 0, (10) * sizeof(int));

    for (int i = 0; i < length; i++)
    {
        ++count[(arr[i] / pos) % 10];
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i - 1] + count[i];
    }

    for (int i = length - 1; i >= 0; i--)
    {
        output[count[(arr[i] / pos) % 10] - 1] = arr[i];
        --count[(arr[i] / pos) % 10];
    }

    for (int i = 0; i < length; i++)
    {
        arr[i] = output[i];
    }
}

int maximum(int arr[], int length)
{
    int max = arr[0];

    for (int i = 0; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}