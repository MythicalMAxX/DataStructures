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

void display(struct Node* root) {
    if (root == NULL) {
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

void insertinbinarysearchtree(struct Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    if (data < (*root)->data) {
        insertinbinarysearchtree(&((*root)->left), data);
    } else {
        insertinbinarysearchtree(&((*root)->right), data);
    }
}

void main() {
    struct Node* root = NULL;
    insertinbinarysearchtree(&root, 50);
    insertinbinarysearchtree(&root, 30);
    insertinbinarysearchtree(&root, 20);
    insertinbinarysearchtree(&root, 40);
    insertinbinarysearchtree(&root, 70);
    insertinbinarysearchtree(&root, 60);
    insertinbinarysearchtree(&root, 80);

    printf("In-order traversal of the binary search tree:\n");
    display(root);
    printf("\n");

    getch();
}