#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int search(struct Node *root, int value)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == value)
    {
        return 1;
    }

    if (search(root->left, value) || search(root->right, value))
    {
        return 1;
    }

    return 0;
}

int main()
{
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    int value = 5;

    if (search(root, value))
    {
        printf("Tìm thấy giá trị %d trong cây nhị phân.\n", value);
    }
    else
    {
        printf("Không tìm thấy giá trị %d trong cây nhị phân.\n", value);
    }

    return 0;
}
