#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

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

void CountLeaf(struct Node* node, int* LeafCount) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        (*LeafCount)++;
    }
    CountLeaf(node->left, LeafCount);
    CountLeaf(node->right, LeafCount);
}

void main() {
    struct Node* root = createNode(1);
    int LeafCount = 0;
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    CountLeaf(root, &LeafCount);
    printf("\nTotal Leaf Nodes are: %d", LeafCount);
    getch();
}