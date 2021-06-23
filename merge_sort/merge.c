// merge_sort

#include<stdio.h>

void merge_sort(int [], int, int);
void merge(int [], int, int, int);

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

    merge_sort(arr, 0, n - 1);

    // printing the sorted array
    printf("\nThe sorted elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge_sort(int arr[], int beg, int end)
{
    int mid = (beg + end) / 2;

    if (beg < end)
    {
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }

}

// merging the two sorted arrays into one
void merge(int arr[], int beg, int mid, int end)
{
    int tmp[end - beg + 1];
    int i = beg, j = mid + 1, k = 0;

    // while right part is less than the middle and left is less than the end
    while ((i <= mid) && (j <= end))
    {
        // if left element is less than right element, then copy to tmp array
        if (arr[i] < arr[j])
        {
            tmp[k] = arr[i];
            i++;
        }
        // if right element is less than left element, then copy to tmp array
        else
        {
            tmp[k] = arr[j];
            j++;
        }
        k++;
    }

    // if merging the left is completed, but right part is remains to be merged
    if (i > mid)
    {
        while (j <= end)
        {
            tmp[k] = arr[j];
            j++;
            k++;
        }
    }
    // if merging the right is completed, but left part is remains to be merged
    else
    {
        while (i <= mid)
        {
            tmp[k] = arr[i];
            i++;
            k++;
        }
    }

    // copying my tmp array to arr array
    for (i = 0; i < k; i++)
    {
        arr[beg] = tmp[i];
        beg++;
    }
}