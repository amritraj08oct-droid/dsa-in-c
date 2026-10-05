#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOperation(int a, int b, char op) {
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    return a / b;
}

int main() {
    char expression[MAX];
    char operators[MAX];
    int operatorTop = -1;
    int values[MAX];
    int valueTop = -1;

    printf("Enter an infix expression: ");
    fgets(expression, MAX, stdin);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isspace(expression[i]))
            continue;

        if (isdigit(expression[i])) {
            int number = 0;

            while (isdigit(expression[i])) {
                number = number * 10 + (expression[i] - '0');
                i++;
            }

            values[++valueTop] = number;
            i--;
        }
        else if (expression[i] == '(') {
            operators[++operatorTop] = expression[i];
        }
        else if (expression[i] == ')') {
            while (operatorTop >= 0 && operators[operatorTop] != '(') {
                int b = values[valueTop--];
                int a = values[valueTop--];
                char op = operators[operatorTop--];

                values[++valueTop] = applyOperation(a, b, op);
            }
            operatorTop--;
        }
        else {
            while (operatorTop >= 0 &&
                   operators[operatorTop] != '(' &&
                   precedence(operators[operatorTop]) >= precedence(expression[i])) {
                int b = values[valueTop--];
                int a = values[valueTop--];
                char op = operators[operatorTop--];

                values[++valueTop] = applyOperation(a, b, op);
            }

            operators[++operatorTop] = expression[i];
        }
    }

    while (operatorTop >= 0) {
        int b = values[valueTop--];
        int a = values[valueTop--];
        char op = operators[operatorTop--];

        values[++valueTop] = applyOperation(a, b, op);
    }

    printf("Result = %d\n", values[valueTop]);

    return 0;
}
