#include <stdio.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void indDelete(int arr[],int size,int index){

   for (int  i = index; i< size-1; i++)
   {
       arr[i] = arr[i+1];
   }


}
int main()
{
    int arr[100] = {2, 4, 7, 9};
    int size = 4,index = 0;
    display(arr, size);
    indDelete(arr,size,index);
    size-=1;
    display(arr,size);
    return 0;
}