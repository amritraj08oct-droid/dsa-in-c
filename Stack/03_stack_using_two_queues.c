#include <stdio.h>
#define MAX 100

int queue1[MAX], queue2[MAX];
int front1 = 0, rear1 = -1;
int front2 = 0, rear2 = -1;

void push(int value) {
    while (front1 <= rear1)
        queue2[++rear2] = queue1[front1++];

    queue1[++rear1] = value;

    while (front2 <= rear2)
        queue1[++rear1] = queue2[front2++];

    front1 = 0;
    rear1 = rear1;
    front2 = 0;
    rear2 = -1;
}

int pop() {
    if (front1 > rear1)
        return -1;

    return queue1[front1++];
}

void display() {
    if (front1 > rear1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    for (int i = front1; i <= rear1; i++)
        printf("%d ", queue1[i]);
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rear1 == MAX - 1) {
                    printf("Stack Overflow.\n");
                    break;
                }
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value == -1)
                    printf("Stack Underflow.\n");
                else
                    printf("Popped: %d\n", value);
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
