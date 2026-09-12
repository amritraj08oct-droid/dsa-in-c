#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node *next;
} Node;

Node *front = NULL;

void enqueue(int value, int priority) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;

    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        Node *temp = front;
        while (temp->next != NULL && temp->next->priority <= priority)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("%d inserted with priority %d.\n", value, priority);
}

void dequeue() {
    if (front == NULL) {
        printf("Priority Queue Underflow\n");
        return;
    }

    Node *temp = front;
    printf("Deleted: %d (priority %d)\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }

    Node *temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("[%d, P%d] ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value, priority;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter priority (smaller number = higher priority): ");
                scanf("%d", &priority);
                enqueue(value, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
