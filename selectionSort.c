#include <stdio.h>
#define noOfElementsInArr(x) (sizeof(x) / sizeof((x)[0]))
void displayArr(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex, temp;
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[minIndex])
            {
                minIndex = j;
           
            }
            temp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = temp;
        }
    }
}
int main()
{
    int A[] = {3, 44, 12, 42, 14};
    int n = noOfElementsInArr(A);
    displayArr(A, n);
    selectionSort(A, n);
    displayArr(A, n);
    return 0;
}