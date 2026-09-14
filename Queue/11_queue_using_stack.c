#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void enqueue(int value) {
    if (top == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    stack[++top] = value;
    printf("%d enqueued successfully.\n", value);
}

void dequeue() {
    if (top == -1) {
        printf("Queue Underflow\n");
        return;
    }

    int i;
    int deleted = stack[0];

    for (i = 0; i < top; i++) {
        stack[i] = stack[i + 1];
    }

    top--;
    printf("%d dequeued successfully.\n", deleted);
}

void display() {
    int i;

    if (top == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
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
