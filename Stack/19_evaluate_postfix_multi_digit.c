#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

int applyOperator(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

int main(void) {
    char expression[MAX];
    int i = 0, a, b, number;

    printf("Enter postfix expression (use spaces between numbers): ");
    fgets(expression, MAX, stdin);

    while (expression[i] != '\0') {
        if (expression[i] == ' ' || expression[i] == '\n') {
            i++;
            continue;
        }

        if (isdigit((unsigned char)expression[i])) {
            number = 0;

            while (isdigit((unsigned char)expression[i])) {
                number = number * 10 + (expression[i] - '0');
                i++;
            }

            push(number);
        } else if (expression[i] == '+' || expression[i] == '-' ||
                   expression[i] == '*' || expression[i] == '/') {
            if (top < 1) {
                printf("Invalid postfix expression.\n");
                return 1;
            }

            b = pop();
            a = pop();
            push(applyOperator(expression[i], a, b));
            i++;
        } else {
            printf("Invalid character in expression.\n");
            return 1;
        }
    }

    if (top == 0)
        printf("Result = %d\n", pop());
    else
        printf("Invalid postfix expression.\n");

    return 0;
}
