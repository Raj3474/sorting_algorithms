// merging two arrays into a single one. This method is
// use in merge sort


#include<stdio.h>


int main(void)
{
    int arr1[] = {1, 3, 5, 8, 10}, arr2[] = {2, 4, 6, 7, 9};
    int tmp[10];

    int i = 0, j = 0, k = 0;
    while ((i < 5) && (j < 5))
    {
        if (arr1[i] < arr2[j])
        {
            tmp[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            tmp[k] = arr2[j];
            j++;
            k++;
        }
    }

    if (i > 5)
    {
        while (j < 5)
        {
            tmp[k] = arr2[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i < 5)
        {
            tmp[k] = arr1[i];
            k++;
            i++;
        }
    }



    for (i = 0; i < 10; i++)
    {
        printf("%d ", tmp[i]);
    }
    printf("\n");

}