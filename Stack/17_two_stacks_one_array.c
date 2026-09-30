#include <stdio.h>

#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int value) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow.\n");
        return;
    }

    arr[++top1] = value;
}

void push2(int value) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow.\n");
        return;
    }

    arr[--top2] = value;
}

void pop1(void) {
    if (top1 == -1) {
        printf("Stack 1 is empty.\n");
        return;
    }

    printf("Popped from Stack 1 = %d\n", arr[top1--]);
}

void pop2(void) {
    if (top2 == MAX) {
        printf("Stack 2 is empty.\n");
        return;
    }

    printf("Popped from Stack 2 = %d\n", arr[top2++]);
}

void display(void) {
    int i;

    printf("Stack 1: ");
    for (i = top1; i >= 0; i--)
        printf("%d ", arr[i]);

    printf("\nStack 2: ");
    for (i = top2; i < MAX; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main(void) {
    int choice, value;

    do {
        printf("\n--- Two Stacks in One Array ---\n");
        printf("1. Push Stack 1\n");
        printf("2. Push Stack 2\n");
        printf("3. Pop Stack 1\n");
        printf("4. Pop Stack 2\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push1(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push2(value);
                break;

            case 3:
                pop1();
                break;

            case 4:
                pop2();
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
