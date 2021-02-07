#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node *searchItr(struct node *root, int key)
{
    while (root != NULL)
    {

        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}
int main()
{
    struct node *root;
    struct node *p1;
    struct node *p2;
    struct node *p3;
    struct node *p4;

    root = createNode(5);
    p1 = createNode(3);
    p2 = createNode(6);
    p3 = createNode(1);
    p4 = createNode(4);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    struct node *n = searchItr(root, 4);
    if (n != NULL)
    {
        printf(" found %d ", n->data);
    }
    else
    {
        printf("Element not found:");
    }

    return 0;
}