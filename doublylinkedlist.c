#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insert(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void insertatend(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

void insertatmiddle(struct Node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    if (prev_node->next != NULL) {
        prev_node->next->prev = new_node;
    }
    prev_node->next = new_node;
}

void search(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d is present in the linked list\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d is not present in the linked list\n", key);
}

void delete(struct Node** head, int key) {
    struct Node* temp = *head;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

void edit(struct Node* head, int old_data, int new_data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != old_data) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    temp->data = new_data;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void backwardsprint(struct Node* node) {
    struct Node* last = NULL;
    while (node != NULL) {
        last = node;
        node = node->next;
    }
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insert(&head, 7);
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 8);
    puts("Created Linked List: ");
    printList(head);
    delete(&head, 1);
    puts("Linked List after deletion of 1: ");
    printList(head);
    edit(head, 3, 5);
    puts("Linked List after editing 3 to 5: ");
    printList(head);
    search(head, 5);
    search(head, 1);
    insertatmiddle(head->next, 9);
    puts("Linked List after inserting 9 after 5: ");
    printList(head);
    insertatend(&head, 10);
    puts("Linked List after inserting 10 at the end: ");
    printList(head);
    printf("Linked List in reverse: ");
    backwardsprint(head);
    getch();
}
