#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define noOfElementsInArr(x) (sizeof(x) / sizeof((x)[0]))
void displayArr(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int maximumElement(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}
void countSort(int *A, int n)
{
    int i, j;
    int max = maximumElement(A, n);
    printf("%d\n", max);
    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }
    i = 0;
    j = 0;
    while (i < max + 1)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int A[] = {3, 44, 12, 42, 14};
    int n = noOfElementsInArr(A);
    displayArr(A, n);
    countSort(A, n);
    displayArr(A, n);
    return 0;
}