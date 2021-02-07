#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void traverseList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("element is:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
//
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//
int isEmpty(struct Node *top)
{

    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//push
struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow:\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
    }
}
//pop
int pop(struct Node**top)
{
    if (isEmpty(*top))
    {
        printf("Stack is Empty:\n");
    }
    else
    {
        struct Node *n =* top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}
int main()
{
    struct Node *top = NULL;
    top =push(top, 1);
    top =push(top, 6);
    top =push(top, 4);
    top =push(top, 2);
    top =push(top, 4);
 
    // int element  = pop(&top);
    // printf("Popped Elemet is: %d\n",element);
    traverseList(top);
    return 0;
}