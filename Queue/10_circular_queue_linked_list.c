#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *rear = NULL;

void enqueue(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;

    if (rear == NULL) {
        rear = newNode;
        rear->next = rear;
    } else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into circular queue.\n", value);
}

void dequeue() {
    if (rear == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    Node *front = rear->next;
    printf("%d deleted from circular queue.\n", front->data);

    if (front == rear) {
        rear = NULL;
    } else {
        rear->next = front->next;
    }

    free(front);
}

void display() {
    if (rear == NULL) {
        printf("Circular queue is empty.\n");
        return;
    }

    Node *temp = rear->next;
    printf("Circular Queue: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);

    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
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
