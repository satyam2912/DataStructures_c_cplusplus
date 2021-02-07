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

struct node *search(struct node *root, int key)
{
    if (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key > root->data)
        {
            return search(root->right, key);
        }
        else
        {
            return search(root->left, key);
        }
    }
    else
    {
        return NULL;
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
    struct node *n = search(root, 1);
    if (n != NULL)
    {
        printf(" found %d ", n->data);
    }else
    {
        printf("Element not found:");
    }
    

    return 0;
}