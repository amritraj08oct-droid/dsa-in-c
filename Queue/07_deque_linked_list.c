#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void insertFront(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        front->prev = newNode;
        front = newNode;
    }
}

void insertRear(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void deleteFront() {
    if (front == NULL) {
        printf("Deque Underflow\n");
        return;
    }

    Node *temp = front;
    printf("Deleted from front: %d\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;
    else
        front->prev = NULL;

    free(temp);
}

void deleteRear() {
    if (rear == NULL) {
        printf("Deque Underflow\n");
        return;
    }

    Node *temp = rear;
    printf("Deleted from rear: %d\n", temp->data);
    rear = rear->prev;

    if (rear == NULL)
        front = NULL;
    else
        rear->next = NULL;

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    Node *temp = front;
    printf("Deque: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n");
        printf("4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
