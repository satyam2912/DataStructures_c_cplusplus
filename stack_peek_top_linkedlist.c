#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

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
int pop(struct Node *tp)
{
    if (isEmpty(tp))
    {
        printf("Stack is Empty:\n");
    }
    else
    {
        struct Node *n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos)
{
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int stackTop()
{
    return top->data;
}

int main()
{
    top = push(top, 78);
    top = push(top, 12);
    top = push(top, 45);
    traverseList(top);
    int ele = peek(2);
    if (ele == -1)
    {
        printf("ele does not exists:\n");
    }
    else
    {
        printf("peeked ele is %d\n", ele);
    }
    printf("top element is %d", stackTop());
    return 0;
}