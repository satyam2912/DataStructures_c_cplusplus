#include <stdio.h>
#include<stdlib.h>
 struct node{
        int data;
        struct node *left;
        struct node *right;
    };
    struct node * createNode(int data){
        struct node *n;
        n = (struct node *) malloc(sizeof(struct node));
        n->data = data;
        n->left = NULL;
        n->right  = NULL;
        return n;
    }
int main(){
   struct node *root;
   struct node *p1;
   struct node *p2;
   root = createNode(2);
   p1 = createNode(1);
   p2 = createNode(4);
   root->left = p1;
   root->right = p2;
    return 0;
}