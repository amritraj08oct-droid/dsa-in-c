#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX];
    int i, a, b, result;

    printf("Enter a postfix expression: ");
    scanf("%99s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            b = pop();
            a = pop();

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return 1;
            }

            push(result);
        }
    }

    if (top == 0)
        printf("Result: %d\n", pop());
    else
        printf("Invalid postfix expression.\n");

    return 0;
}
