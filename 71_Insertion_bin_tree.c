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

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf(" %d Insertion is not possible already in bst \n",key);
            return ;
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
    struct node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
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
    insert(root, 16);
    return 0;
}