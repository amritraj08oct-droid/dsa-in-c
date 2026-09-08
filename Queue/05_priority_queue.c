#include <stdio.h>
#define MAX 5

typedef struct {
    int data;
    int priority;
} Element;

Element queue[MAX];
int size = 0;

void enqueue(int data, int priority) {
    if (size == MAX) {
        printf("Priority Queue Overflow\n");
        return;
    }

    queue[size].data = data;
    queue[size].priority = priority;
    size++;
    printf("Element inserted successfully.\n");
}

void dequeue() {
    if (size == 0) {
        printf("Priority Queue Underflow\n");
        return;
    }

    int highest = 0;

    for (int i = 1; i < size; i++) {
        if (queue[i].priority < queue[highest].priority) {
            highest = i;
        }
    }

    printf("Deleted element: %d (Priority: %d)\n",
           queue[highest].data, queue[highest].priority);

    for (int i = highest; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }

    size--;
}

void display() {
    if (size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("\nPriority Queue:\n");
    printf("Data\tPriority\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%d\n", queue[i].data, queue[i].priority);
    }
}

int main() {
    int choice, data, priority;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority (smaller number = higher priority): ");
                scanf("%d", &priority);
                enqueue(data, priority);
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
