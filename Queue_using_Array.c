#include <stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
//check if queue is full
int isFull(struct queue *a){
    if (a->r == a->size-1)
    {
     return 1;
    }else
    {
        return 0 ;
    }
}
//check if queue is expty
int isEmpty(struct queue *a){
    if (a->r == a->f)
    {
     return 1;
    }else
    {
        return 0 ;
    }
}
//inserting elements into queue
void enqueue(struct queue *a,int val){
    if (isFull(a)){
        printf("Queue is full:\n");
    }else
    {
       a->r++;
       a->arr[a->r] = val;      
    }    
}
//deleting elements into queue
int  dequeue(struct queue *a){
    int b = -1;
    if (isEmpty(a)){
        printf("Queue is Empty:\n");
    }else
    {
       a->f++;
       b = a->arr[a->f];   
    }   
    return b; 
}
int main(){
struct queue q1;
q1.size = 100;
q1.f = q1.r = -1;
q1.arr = (int*)malloc(q1.size*sizeof(int));

///Enqueue few elements

enqueue(&q1,12);
enqueue(&q1,15);
printf("Dequeying element %d\n", dequeue(&q1));
printf("Dequeying element %d\n", dequeue(&q1));
if (isEmpty(&q1)){
printf("Queue is Empty\n");
}
    return 0;
}