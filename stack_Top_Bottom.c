#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//PUSH
void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow:\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
//POP
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow:\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
/// value at position
int peek(struct stack *ptr, int  i ){
    int arrayInd = ptr->top-i+1;
    if (arrayInd<0)
    {
        return -1;
    }else{
        return ptr->arr[arrayInd];
    } 
    
}
//stack top
int stackTop(struct stack *s){
    return s->arr[s->top];
}
//stack bottom

int stackBottom(struct stack *s){
    return s->arr[0];
}

int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("stack has been created :\n");


    push(s, 143);
    push(s, 64);
    push(s, 35);
    push(s, 11);
    push(s, 43);
    push(s, 112);
    push(s, 324);
    push(s, 34);
    push(s, 4);
    push(s, 14);
//check if stack is full after pushing elements

printf("The topmost element is %d:\n",stackTop(s));
printf("The bottommost element is %d:\n",stackBottom(s));
printf("The popped element is %d:\n",pop(s));

    return 0;
}
