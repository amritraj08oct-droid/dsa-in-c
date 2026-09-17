#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void reverse(char str[]) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char infix[]) {
    char postfix[MAX], prefix[MAX];
    int i, j = 0;

    reverse(infix);

    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            if (top != -1)
                pop();
        } else {
            while (top != -1 && peek() != '(' &&
                   precedence(peek()) > precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    strcpy(prefix, postfix);
    reverse(prefix);

    printf("Prefix expression: %s\n", prefix);
}

int main() {
    char infix[MAX];

    printf("Enter an infix expression: ");
    scanf("%99s", infix);

    infixToPrefix(infix);

    return 0;
}
