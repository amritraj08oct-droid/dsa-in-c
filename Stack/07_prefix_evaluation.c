#include <stdio.h>
#include <string.h>
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

int power(int base, int exponent) {
    int result = 1;

    while (exponent > 0) {
        result *= base;
        exponent--;
    }

    return result;
}

int applyOperator(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return power(a, b);
        default: return 0;
    }
}

int main(void) {
    char prefix[MAX];
    int i, a, b, result;

    printf("Enter a prefix expression: ");
    scanf("%99s", prefix);

    for (i = (int)strlen(prefix) - 1; i >= 0; i--) {
        if (isdigit((unsigned char)prefix[i])) {
            push(prefix[i] - '0');
        } else if (prefix[i] == '+' || prefix[i] == '-' ||
                   prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '^') {
            if (top < 1) {
                printf("Invalid prefix expression.\n");
                return 1;
            }

            a = pop();
            b = pop();
            result = applyOperator(prefix[i], a, b);
            push(result);
        } else {
            printf("Invalid character in expression.\n");
            return 1;
        }
    }

    if (top == 0)
        printf("Result = %d\n", pop());
    else
        printf("Invalid prefix expression.\n");

    return 0;
}
