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
    struct Node* last = *head;
    new_node->data = data;
    new_node->next = *head;

    if (*head == NULL) {
        new_node->prev = new_node;
        new_node->next = new_node;
        *head = new_node;
    } else {
        while (last->next != *head) {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
        (*head)->prev = new_node;
        new_node->next = *head;
    }
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    new_node->data = data;

    if (*head == NULL) {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
    } else {
        while (last->next != *head) {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
        new_node->next = *head;
        (*head)->prev = new_node;
    }
}

void insertAtMiddle(struct Node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    prev_node->next->prev = new_node;
    prev_node->next = new_node;
}

void search(struct Node* head, int key) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            if (temp->data == key) {
                printf("Element %d is present in the linked list\n", key);
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
    printf("Element %d is not present in the linked list\n", key);
}

void delete(struct Node** head, int key) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp->data != key) {
        if (temp->next == *head) {
            printf("Element %d not found in the list\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == *head && prev == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    if (temp == *head) {
        prev = (*head)->prev;
        *head = (*head)->next;
        prev->next = *head;
        (*head)->prev = prev;
        free(temp);
    } else if (temp->next == *head) {
        prev->next = *head;
        (*head)->prev = prev;
        free(temp);
    } else {
        struct Node* next = temp->next;
        prev->next = next;
        next->prev = prev;
        free(temp);
    }
}

void edit(struct Node* head, int old_data, int new_data) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            if (temp->data == old_data) {
                temp->data = new_data;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

void backwardsPrint(struct Node* head) {
    struct Node* last = head;
    if (head != NULL) {
        do {
            last = last->next;
        } while (last->next != head);
        do {
            printf("%d ", last->data);
            last = last->prev;
        } while (last != head->prev);
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
    puts("Created Circular Linked List: ");
    printList(head);
    delete(&head, 1);
    puts("Circular Linked List after deletion of 1: ");
    printList(head);
    edit(head, 3, 5);
    puts("Circular Linked List after editing 3 to 5: ");
    printList(head);
    search(head, 5);
    search(head, 1);
    insertAtMiddle(head->next, 9);
    puts("Circular Linked List after inserting 9 after 7: ");
    printList(head);
    insertAtEnd(&head, 10);
    puts("Circular Linked List after inserting 10 at the end: ");
    printList(head);
    printf("Circular Linked List in reverse: ");
    backwardsPrint(head);
    getch();
    return 0;
}
