#include <stdio.h>
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int indInsert(int arr[],int size,int element,int capacity,int index){
if (size>=capacity)
{
    return -1;
}else{
   for (int  i = size-1; i>= index; i--)
   {
       arr[i+1] = arr[i];
   }
   arr[index] = element;
   return 1;
}


}
int main()
{
    int arr[100] = {2, 4, 7, 9};
    int size = 4, element= 88;
    int index = 0;
    display(arr, size);
    indInsert(arr,size,element,100,index);
    size+=1;
    display(arr,size);
    return 0;
}