#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
} tree;
tree *createnode(int x)
{
    tree *root = (tree *)malloc(sizeof(tree));
    if (root == NULL)
    {
        printf("memory allocate error\n");
        exit(1);
    }
    else
    {
        root->data = x;
        root->left = NULL;
        root->right = NULL;
    }
}

void printinorder(tree *r)
{
    if (r == NULL)
    {
        return;
    }
    else
    {
        printinorder(r->left);
        printf("%d ", r->data);
        printinorder(r->right);
    }
}
void preorderprint(tree *r)
{
    if (r == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", r->data);
        preorderprint(r->left);
        preorderprint(r->right);
    }
}
void postorderprint(tree *r)
{
    if (r == NULL)
    {
        return;
    }
    else
    {
        postorderprint(r->left);
        postorderprint(r->right);
        printf("%d ", r->data);
    }
}

int height(tree *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int lefth = height(root->left);
    int righth = height(root->right);
    return (lefth > righth ? lefth : righth) + 1;
}
int countnode(tree *root)
{
    // first solution using static int
    //  static int count = 0;
    //  if (root == NULL)
    //  {
    //      return count;
    //  }else{
    //      countnode(root->left);
    //      countnode(root->right);
    //      count++;
    //  }
    // second solution
    if (root == NULL)
    {
        return 0;
    }
    return 1 + (countnode(root->left) + countnode(root->right));
}

int countleaf(tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countleaf(root->right) + countleaf(root->left);
}
void printleaf(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        printf("%d ", root->data);
    }
    printleaf(root->left);
    printleaf(root->right);
}
int findMax(tree *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    int leftmax = findMax(root->left);
    int rightmax = findMax(root->right);
    if (root->data > leftmax && root->data > rightmax)
    {
        return root->data;
    }
    else
    {
        return (leftmax > rightmax ? leftmax : rightmax);
    }
}

int sumofallnodes(tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (root->data + sumofallnodes(root->right) + sumofallnodes(root->left));
}

void printLongestPath(tree *root){
    if (root == NULL)
    {
        return;
    }
    printf("%d ",root->data);
    int lhpath = height(root->left);
    int rhpath = height(root->right);
    if (lhpath > rhpath)
    {
        printLongestPath(root->left);
    }else{
        printLongestPath(root->right);
    }
    
}

int main()
{
    tree *root = createnode(1);
    root->left = createnode(2);
    root->left->left = createnode(3);
    root->left->left->right = createnode(10);
    root->left->right = createnode(4);
    root->right = createnode(5);
    printf("print inorder tree\n");
    printinorder(root);
    printf("\nprint preorder tree\n");
    preorderprint(root);
    printf("\nprint postorder tree\n");
    postorderprint(root);
    printf("\n");
    printf("the height is: %d\n", height(root));
    printf("the number of node is: %d\n", countnode(root));
    printf("the number of leaf is: %d\n", countleaf(root));
    printf("the max is: %d\n", findMax(root));
    printf("the sum of all nodes is: %d\n", sumofallnodes(root));
    printf("printing all leaves: ");
    printleaf(root);
    printf("\n");
    printf("Print the longest path: ");
    printLongestPath(root);
}