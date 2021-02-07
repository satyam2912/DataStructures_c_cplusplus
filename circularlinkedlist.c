#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

//traversing list

void traverseList(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    // printf("Element is %d\n",ptr->data);
    // ptr = ptr->next;
    //     while (ptr != head)
    //     {
    //         printf("element is:%d\n", ptr->data);
    //         ptr = ptr->next;
    //     }
}

//insertion at beginning

struct Node *insertElementAtfirst(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next!=head)
    {
       p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 6;
    third->next = fourth;
    fourth->data = 1;
    fourth->next = head;
printf("Linked list beforeinstertion:\n");
    traverseList(head);
    head = insertElementAtfirst(head, 80);
    head = insertElementAtfirst(head, 22);
printf("Linked list after instertion:\n");

    traverseList(head);
    free(head);
    free(second);
    free(third);
    free(fourth);
    return 0;
}