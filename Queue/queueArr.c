#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXSIZE 5

int front = -1, rear = -1;
int queue[MAXSIZE];

void insert(int item) {
    if (rear == MAXSIZE - 1) {
        printf("\nQueue Overflow\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = rear + 1;
    }
    queue[rear] = item;
    printf("\nValue inserted: %d\n", item);
}

void delete() {
    int item;
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow\n");
        return;
    } else {
        item = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = front + 1;
        }
        printf("\nValue deleted: %d\n", item);
    }
}

void display() {
    int i;
    if (rear == -1) {
        printf("\nEmpty queue\n");
    } else {
        printf("\nPrinting values\n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    insert(5);
    insert(10);
    insert(15);
    insert(20);
    insert(25);
    display();
    delete();
    display();
    insert(30);
    display(); 
    getch();
}
