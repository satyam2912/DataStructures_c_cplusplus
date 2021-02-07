#include <stdio.h>
#include<stdlib.h>
struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
};
//check if queue is full
int isFull(struct circularQueue *a){
    if((a->r+1)%a->size==a->f)
    {
     return 1;
    }else
    {
        return 0 ;
    }
}
//check if queue is expty
int isEmpty(struct circularQueue *a){
    if (a->r == a->f)
    {
     return 1;
    }else
    {
        return 0 ;
    }
}
//inserting elements into queue
void enqueue(struct circularQueue *a,int val){
    if (isFull(a)){
        printf("Queue is full:\n");
    }else
    {
       a->r = (a->r+1)%a->size;
       a->arr[a->r] = val;     
       printf("Enqueued element : %d\n",val); 
    }    
}
//deleting elements into queue
int  dequeue(struct circularQueue *a){
    int b = -1;
    if (isEmpty(a)){
        printf("Queue is Empty:\n");
    }else
    {
       a->f=(a->f+1)%a->size;
       b = a->arr[a->f];   
    }   
    return b; 
}
int main(){
struct circularQueue q1;
q1.size = 5;
q1.f = q1.r = 0;
q1.arr = (int*)malloc(q1.size*sizeof(int));

///Enqueue few elements

enqueue(&q1,12);
enqueue(&q1,15);
enqueue(&q1,25);
enqueue(&q1,15);
printf("Dequeying element %d\n", dequeue(&q1));
printf("Dequeying element %d\n", dequeue(&q1));
printf("Dequeying element %d\n", dequeue(&q1));
printf("Dequeying element %d\n", dequeue(&q1));
enqueue(&q1,115);
enqueue(&q1,115);
enqueue(&q1,115);
enqueue(&q1,115);


if (isEmpty(&q1)){
printf("Queue is Empty\n");
}
if (isFull(&q1)){
printf("Queue is Full\n");
}
    return 0;
}