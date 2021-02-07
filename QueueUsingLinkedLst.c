#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *f = NULL;
struct Node *r = NULL;
void traverseList(struct Node *ptr)
{
    printf("Printing the element of linked list:\n");
    while (ptr != NULL)
    {
        printf("element is:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
//enqueue
void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}
//enqueue
int dequeue()
{
    int val = -1;
    struct Node *ptr;
    ptr = f;
    if (f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
int main()
{

    traverseList(f);
    printf("Dequeying element %d:\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(12);
    printf("Dequeying element %d:\n", dequeue());
    printf("Dequeying element %d:\n", dequeue());
    printf("Dequeying element %d:\n", dequeue());
    traverseList(f);
    return 0;
}