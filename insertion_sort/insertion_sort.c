//insertion_sort

#include<stdio.h>

int main(void)
{
    int n;

    printf("Enter the number of elements do you want to enter\n");
    scanf("%d", &n);

    int arr[n];

    // getting elements from the user
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // printing my unsorted array.....
    printf("The elements before sorting are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // for each element in the array from 1th to nth
    for (int i = 1; i < n; i++)
    {
        // creating the hole in the array
        int tmp = arr[i];
        int j = i - 1;

        // looking the elements from the ith position to 0th position
        while ((j >= 0) && (tmp < arr[j]))
        {
            // shifting the elements from left to rigth
            arr[j + 1] = arr[j];
            j--;
        }
        // substituting the last hole with selected element
        arr[j + 1] = tmp;
    }

    // printing the sorted array
    printf("The sorted elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}