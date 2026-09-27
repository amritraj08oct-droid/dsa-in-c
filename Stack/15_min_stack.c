#include <stdio.h>

#define MAX 100

int stack[MAX];
int minStack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow.\n");
        return;
    }

    top++;
    stack[top] = value;

    if (top == 0 || value < minStack[top - 1])
        minStack[top] = value;
    else
        minStack[top] = minStack[top - 1];
}

void pop(void) {
    if (top == -1) {
        printf("Stack Underflow.\n");
        return;
    }

    printf("Popped element = %d\n", stack[top]);
    top--;
}

void getMin(void) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Minimum element = %d\n", minStack[top]);
}

void display(void) {
    int i;

    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top to bottom): ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main(void) {
    int choice, value;

    do {
        printf("\n--- Min Stack ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Get Minimum\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                getMin();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
