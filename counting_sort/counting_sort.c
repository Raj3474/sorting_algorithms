// Counting_Sort

#include <stdio.h>
#include <string.h>

#include "/home/ubuntu/my_header_file/array.h"

void counting_sort(int [], int, int);
int maximum(int [], int, int);

int main(void)
{
    int n;

    printf("Enter the number of elements do you want in a array\n");
    scanf("%d", &n);

    int arr[n];

    // getting elements of a array from the user, get_array(array, length)
    get_array(arr, n);

    // printing my unsorted array.....
    printf("The elements before sorting are:\n");
    display_array(arr, 0, n - 1); // display_array(array, start_index, end_index)

    counting_sort(arr, 0, n - 1);

    // printing the sorted array
    printf("\nThe sorted elements are:\n");
    display_array(arr, 0, n - 1); // display_array(array, start_index, end_index);
}


void counting_sort(int arr[], int beg, int end)
{
    int max = maximum(arr, beg, end);

    int count[max + 1], output[end + 1];

    // memset() for initializing the array with 0, #include<string.h>
    memset(count, 0, (max + 1) * sizeof(int));

    for (int i = 0; i <= end; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] = count[i - 1] + count[i];
    }

    for (int i = end; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]] = count[arr[i]] - 1;
    }

    for (int i = 0; i <= end; i++)
    {
        arr[i] = output[i];
    }
}

int maximum(int arr[], int beg, int end)
{
    int max = arr[beg];

    for (int i = beg; i <= end; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}