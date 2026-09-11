#include <stdio.h>

#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void enqueue(int value) {
    if (top1 == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    stack1[++top1] = value;
    printf("%d inserted into queue.\n", value);
}

void transfer() {
    while (top1 != -1) {
        stack2[++top2] = stack1[top1--];
    }
}

void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue Underflow\n");
        return;
    }

    if (top2 == -1)
        transfer();

    printf("%d deleted from queue.\n", stack2[top2--]);
}

void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");

    for (int i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);

    for (int i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);

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
