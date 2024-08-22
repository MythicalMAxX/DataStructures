#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int maxHeight(struct Node* node, int count,int maxCount) {
    if (node == NULL)
    {
        return maxCount;
    }
    
    if (node->left == NULL && node->right == NULL) {
        if (count > maxCount) {
            maxCount = count;
        }
    }
    maxCount = maxHeight(node->left, count + 1, maxCount);
    maxCount = maxHeight(node->right, count + 1, maxCount);
    return maxCount;
}

void main(){
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->left->left = createNode(6);
    root->left->left->right = createNode(7);
    
    int maxCount = 0;
    maxCount = maxHeight(root, 0, maxCount);
    printf("\nMax Height of Tree is: %d", maxCount);
    getch();
}