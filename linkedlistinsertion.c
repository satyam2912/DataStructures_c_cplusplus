#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
//linked list traversal
void traverseList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("element is:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
//linked list insert at beginning
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;

}
//linked list instertion at given index
struct Node *insertAtIndex(struct Node *head, int data,int index)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i!=index-1)
    {
        p= p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;

}
//linked list insertion at end
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
//insert after a node
struct Node *insertAfterNode(struct Node *head,struct Node *prevNode, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next  = prevNode->next;
    prevNode->next = ptr;  
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;
    second->data = 122;
    second->next = third;
    third->data = 34;
    third->next = NULL;
    printf("Linked list before insertion:\n");
    traverseList(head);
    // head =insertAtFirst(head,56);
    // head =insertAtIndex(head,56,1);
    // head =insertAtEnd(head,56);
    // head =insertAfterNode(head,head,56);
    printf("\n");
    printf("Linked list after insertion:\n");
    traverseList(head);

    free(head);
    free(second);
    free(third);
    return 0;
}