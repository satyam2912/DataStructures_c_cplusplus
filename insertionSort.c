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
void insertionSort(int *A, int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int key, j;
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
int main()
{
    int A[] = {3, 44, 12, 42, 14};
    int n = noOfElementsInArr(A);
    displayArr(A, n);
    insertionSort(A, n);
    displayArr(A, n);

    return 0;
}