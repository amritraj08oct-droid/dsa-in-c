#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1)
        stack[++top] = value;
}

int pop(void) {
    return stack[top--];
}

void sortStack(void) {
    int temp[MAX];
    int tempTop = -1;
    int value;

    while (top != -1) {
        value = pop();

        while (tempTop != -1 && temp[tempTop] > value) {
            push(temp[tempTop--]);
        }

        temp[++tempTop] = value;
    }

    while (tempTop != -1)
        push(temp[tempTop--]);
}

void display(void) {
    int i;

    printf("Stack (top to bottom): ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main(void) {
    int n, value, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(value);
    }

    printf("\nBefore sorting:\n");
    display();

    sortStack();

    printf("After sorting (smallest on top):\n");
    display();

    return 0;
}
