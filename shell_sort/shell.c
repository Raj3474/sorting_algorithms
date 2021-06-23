// shell sort
// generalization of insertion sort


#include <stdio.h>
#include "/home/ubuntu/my_header_file/array.h"

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

    // initializing gap for shell to n/2
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // for each element in the array from gapth to nth
        for (int j = gap; j < n; j ++)
        {
            // creating the hole in the array
            int tmp = arr[j];
            int i = j - gap;

            // looking the elements from the gapth position to 0th position
            while ((i >= 0) && (tmp < arr[i]))
            {
                // shifting the elements from left to rigth
                arr[i + gap] = arr[i];
                i -= gap;
            }
            // substituting the last hole with selected element
            arr[i + gap] = tmp;
        }
    }

    // printing the sorted array
    printf("The sorted elements are:\n");
    display_array(arr, 0, n - 1);
}