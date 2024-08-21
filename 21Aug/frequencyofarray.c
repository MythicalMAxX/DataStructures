#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// use linkedlist to store frequency of elements

struct Node {
    int data;
    int freq;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int data) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            temp->freq++;
            return;
        }
        temp = temp->next;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->freq = 1;
    newNode->next = head;
    head = newNode;
}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d: %d\n", temp->data, temp->freq);
        temp = temp->next;
    }
}

void main() {
    int arr[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }
    display();
    getch();
}