// modified Counting_Sort for sorting negative numbers as well,
// previous counting sort is for sorting positive numbers only

#include<stdio.h>
#include<string.h> // for using memset()

// for using user defined functions like get_array(), display_array()
#include "/home/ubuntu/my_header_file/array.h"

void modified_counting_sort(int [], int, int);
int maximum(int [], int, int);
int minimum(int [], int, int);

int main(void)
{
    int n;

    printf("Enter the number of elements do you want to enter\n");
    scanf("%d", &n);

    int arr[n];

    // getting elements of a array from the user, get_array(array, length)
    get_array(arr, n);

    // printing my unsorted array.....
    printf("The elements before sorting are:\n");
    display_array(arr, 0, n - 1); // display_array(array, start_index, end_index)

    modified_counting_sort(arr, 0, n - 1);

    // printing the sorted array
    printf("\nThe sorted elements are:\n");
    display_array(arr, 0, n - 1); // display_array(array, start_index, end_index);
}


void modified_counting_sort(int arr[], int beg, int end)
{
    int max = maximum(arr, beg, end);
    int min = minimum(arr, beg, end);

    int range = max - min + 1;

    int count[range], output[end + 1];

    // memset() for initializing the array with 0, #include<string.h>
    memset(count, 0, (range) * sizeof(int));

    for (int i = 0; i <= end; i++)
    {
        // store the count of the minimum element at 0 index
        count[arr[i] - min]= count[arr[i] - min] + 1;
    }

    for (int i = 1; i < range; i++)
    {
        count[i] = count[i - 1] + count[i];
    }

    for (int i = end; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min] = count[arr[i] - min] - 1;
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

int minimum(int arr[], int beg, int end)
{
    int min = arr[beg];

    for (int i = 0; i <= end; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}