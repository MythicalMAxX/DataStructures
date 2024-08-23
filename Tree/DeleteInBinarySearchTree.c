#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

struct node* delete(struct node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void display(struct node* root) {
    if (root == NULL) {
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

void main(){
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal of the binary search tree:\n");
    display(root);
    printf("\n");

    root = delete(root, 20);
    printf("In-order traversal of the binary search tree after deleting 20:\n");
    display(root);
    printf("\n");

    root = delete(root, 30);
    printf("In-order traversal of the binary search tree after deleting 30:\n");
    display(root);
    printf("\n");

    root = delete(root, 50);
    printf("In-order traversal of the binary search tree after deleting 50:\n");
    display(root);
    printf("\n");

    getch();
}