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

void insertAtBottom(int value) {
    int temp;

    if (top == -1) {
        push(value);
        return;
    }

    temp = pop();
    insertAtBottom(value);
    push(temp);
}

void reverseStack(void) {
    int temp;

    if (top == -1)
        return;

    temp = pop();
    reverseStack();
    insertAtBottom(temp);
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

    printf("\nBefore reversal:\n");
    display();

    reverseStack();

    printf("After reversal:\n");
    display();

    return 0;
}
