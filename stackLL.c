#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int isEmpty() {
    return top == NULL;
}

void handleHeapOverflow() {
    printf("Heap memory overflow\n");
}

void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        handleHeapOverflow();
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = top;
    int popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Top element is %d\n", peek());
    pop();
    display();
    printf("Top element is %d\n", peek());
    getch();
}