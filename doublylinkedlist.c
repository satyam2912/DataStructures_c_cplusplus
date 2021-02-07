#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("element is:%d\n", ptr->data);
        ptr = ptr->next;

    }
}

int main()
{
    struct Node *head, *N1, *N2, *N3;
    head = (struct Node *)malloc(sizeof(struct Node));
    N1 = (struct Node *)malloc(sizeof(struct Node));
    N2 = (struct Node *)malloc(sizeof(struct Node));
    N3 = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 30;
    head->next = N1;

    N1->prev = head;
    N1->data = 23;
    N1->next = N2;

    N2->prev = N1;
    N2->data = 43;
    N2->next = N3;

    N3->prev = N2;
    N3->data = 5;
    N3->next = NULL;
    traversal(head);
    return 0;
}