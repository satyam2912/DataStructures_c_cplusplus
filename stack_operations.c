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

int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("stack has been created :\n");

    // Check if stack is empty
    if (isEmpty(s))
    {
        printf("The stack is empty:\n");
    }
    else
    {
        printf("The stack is not empty:\n");
    }
    push(s, 34);
    push(s, 34);
    push(s, 34);
    push(s, 34);
    push(s, 34);
    push(s, 34);
    push(s, 34);
    push(s, 34);
    push(s, 4);

    printf(" popped %d\n",pop(s));
    return 0;
}
