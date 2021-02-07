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

int partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {

        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void quickSort(int *A, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}
int main()
{
    int A[] = {3, 44, 12, 42, 22, 3, 14};
    int n = noOfElementsInArr(A);
    displayArr(A, n);
    quickSort(A, 0, n - 1);
    displayArr(A, n);
    return 0;
}