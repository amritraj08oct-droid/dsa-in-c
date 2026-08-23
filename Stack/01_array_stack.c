#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int value) { if (top < MAX - 1) stack[++top] = value; }
int pop(void) { return top >= 0 ? stack[top--] : -1; }

int main(void) {
    push(10); push(20); push(30);
    printf("Popped: %d\n", pop());
    printf("Top: %d\n", stack[top]);
    return 0;
}
