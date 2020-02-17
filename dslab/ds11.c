/* Tree Traversal */
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;
int count=1;
node *insert(node *tree,int digit)
{
    if(tree == NULL)
    {
        tree = (node *)malloc(sizeof(node));
        tree->left = tree->right=NULL;
        tree->data = digit;
        count++;
    }
    else if(count%2 == 0)
        tree->left = insert(tree->left, digit);
    else
        tree->right = insert(tree->right, digit);
        return tree;
}
void preorder(node *t)
{
    if(t != NULL)
    {
        printf(" %d", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void postorder(node *t)
{
    if(t != NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf(" %d", t->data);
    }
}
void inorder(node *t)
{
    if(t != NULL)
    {
        inorder(t->left);
        printf(" %d", t->data);
        inorder(t->right);
    }
}
void main()
{
    node *root = NULL;
    int digit;
    puts("Enter integer:To quit enter 0");
    scanf("%d", &digit);
    while(digit != 0)
    {
        root=insert(root,digit);
        scanf("%d",&digit);
    }
    printf("\nThe preorder traversal of tree is:\n");
    preorder(root);
    printf("\nThe inorder traversal of tree is:\n");
    inorder(root);
    printf("\nThe postorder traversal of tree is:\n");
    postorder(root);
}
