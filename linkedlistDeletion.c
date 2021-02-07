#include <stdio.h>
#include <stdlib.h>
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
// deletion at first node
struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// deleting at index
struct Node *deleteNodeAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
//deleting last node
struct Node *deletelastNode(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
// deleting node with  given value
struct Node *deleteNodeAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
  while (q->data!=value && q->next!=NULL)
  {
      p = p->next;
        q = q->next;
  }
  
 if (q->data==value)
 {
    p->next = q->next;
    free(q);
 }
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
    printf("Linked list before deletion\n");
    traverseList(head);
    // head = deleteFirstNode(head);
    // head = deleteNodeAtIndex(head,2);
    // head = deletelastNode(head);
    // head = deleteNodeAtValue(head,122);
    printf("Linked list after deletion\n");
    traverseList(head);
    // free(head);
    // free(second);
    // free(third);
    return 0;
}