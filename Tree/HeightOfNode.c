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

int heightOfNode(struct Node* node, int data, int count) {
    if (node == NULL) {
        return -1;
    }
    if (node->data == data) {
        return count;
    }
    int left = heightOfNode(node->left, data, count + 1);
    int right = heightOfNode(node->right, data, count + 1);
    if (left == -1 && right == -1) {
        return -1;
    }
    if (left == -1) {
        return right;
    }
    return left;
}

void main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->left->left = createNode(6);
    root->left->left->right = createNode(7);
    int height = heightOfNode(root, 7, 0);
    if (height == -1) {
        printf("\nNode not found");
    }
    else {
        printf("\nHeight of Node is: %d", height);
    }
    getch();
}