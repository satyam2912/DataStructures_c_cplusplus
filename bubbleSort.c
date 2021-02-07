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

void bubbleSort(int A[], int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // no of passes
    {
        printf("pass no is %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // comparison in each pass
        {
            if (A[j] >A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}
int main()
{
    int A[] = {3, 44, 12, 42, 14};
    // int A[] = {1,2,3,4,5,6};
    int n = noOfElementsInArr(A);
    displayArr(A, n);
    bubbleSort(A, n);
    displayArr(A, n);
    return 0;
}