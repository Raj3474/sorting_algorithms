// bucket_sorting....

#include<stdio.h>
#include<string.h>

#include "/home/ubuntu/my_header_file/array.h"

void bucket_sort(int [], int);
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

    bucket_sort(arr, n);

    // printing the sorted array
    printf("\nThe sorted elements are:\n");
    display_array(arr, 0, n - 1);
}

void bucket_sort(int arr[], int length)
{
    int max = maximum(arr, length);
    for (int pos = 1; max / pos > 0; pos *= 10)
    {
        int count[10], bucket[10][length];

        // memset() for initializing the array with 0, #include<string.h>
        memset(count, 0, (10) * sizeof(int));

        for (int i = 0; i < length; i++)
        {
            int remainder = (arr[i] / pos) % 10;
            bucket[remainder][count[remainder]] = arr[i];
            count[remainder] += 1;
        }

        int k = 0;
        // collect the numbers after every pass
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < count[i]; j++ )
            {
                arr[k] = bucket[i][j];
                k++;
            }
        }
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