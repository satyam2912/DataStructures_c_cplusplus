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

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    struct node *root;
    struct node *p1;
    struct node *p2;
    struct node *p3;
    struct node *p4;

    root = createNode(4);
    p1 = createNode(1);
    p2 = createNode(6);
    p3 = createNode(5);
    p4 = createNode(2);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    preOrder(root);
    return 0;
}