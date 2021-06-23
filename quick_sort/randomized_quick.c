// randomized quick_sort for better implementation
// randomized quick_sort is modified version of the previous quick_sort
// in randomized quick_sort partition index is selected randomly

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quick_sort(int [], int, int);
int partition(int [], int, int);
int partition_rand(int [], int, int);

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

    quick_sort(arr, 0, n - 1);

    // printing the sorted array
    printf("\nThe sorted elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void quick_sort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        // calling partition function for partition index
        int pIndex = partition_rand(arr, beg, end);

        // quick sort for elements before partition index
        quick_sort(arr, beg, pIndex - 1);

        // quick sort for elements after the partition index
        quick_sort(arr, pIndex + 1, end);
    }
}

// partition function for finding the partition index in such a way that,
// all elements before partition index are less than the element at partition index and
// all elements after partition index are more than the element at partition index.
int partition(int arr[], int beg, int end)
{
    // fixing the pivot point at the last element
    int pivot = arr[end];
    int pIndex = beg;

    for (int i = beg; i < end; i++)
    {
        // if elements in array is less than pivot then swaps with the element at the partition index
        if (arr[i] <= pivot)
        {
            // swapping...
            int tmp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = tmp;

            pIndex++;
        }
    }
    int tmp = arr[end];
    arr[end] = arr[pIndex];
    arr[pIndex] = tmp;

    return pIndex;
}

int partition_rand(int arr[], int beg, int end)
{
    srand(time(NULL));
    // choosing random index for the partitioning
    int random = (rand() % (end - beg + 1) + beg);

    // swapping the element at the random index to the element at the last index
    int tmp = arr[random];
    arr[random] = arr[end];
    arr[end] = tmp;

    return partition(arr, beg, end);
}