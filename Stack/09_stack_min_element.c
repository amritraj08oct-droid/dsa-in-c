#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow.\n");
        return;
    }

    stack[++top] = value;
}

int findMin(void) {
    int min = stack[0];
    int i;

    for (i = 1; i <= top; i++) {
        if (stack[i] < min)
            min = stack[i];
    }

    return min;
}

void display(void) {
    int i;

    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
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

    display();
    printf("Minimum element = %d\n", findMin());

    return 0;
}
