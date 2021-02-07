#include <stdio.h>
int linear_search(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int binary_search(int arr[], int size, int element)
{
    int count = 0;
    int low, high, mid;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            count++;
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {

            high = mid - 1;
        }
    }
    printf("%d", count);
    return -1;
}
int main()
{
    // int arr[] = {2, 4, 5, 10, 12, 14, 15, 67, 135, 222};
    int arr[] = {1,2,3,4,5};
    // calculating  array size
    int size = sizeof(arr) / sizeof(int);
    int element = 4;
    int searchIndex = binary_search(arr, size, element);
    printf("the element %d was found at %d", element, searchIndex);
    return 0;
}