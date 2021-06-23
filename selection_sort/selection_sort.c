//selection_sort

#include<stdio.h>

int main(void)
{
    int n, minidx;

    printf("Enter the number of elements do you want to enter\n");
    scanf("%d", &n);

    int arr[n];

    // taking elements from the user
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // printing my unsorted array
    printf("The elements before sorting are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // for each elements in array from 0 to n - 1
    for (int i = 0; i < n - 1; i++)
    {
        minidx = i;
        // finding the smallest element in the unsorted part of the array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minidx])
            {
               minidx = j;
            }
        }

        // swapping smallest element from the unsorted array with the first element
        {
            int tmp = arr[i];
            arr[i] = arr[minidx];
            arr[minidx] = tmp;
        }
    }

    // printing my array after sorting...
    printf("The sorted elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}