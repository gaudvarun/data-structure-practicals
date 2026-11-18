#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX];
    int top = -1;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ' ') continue;

        if (isdigit((unsigned char)infix[i])) {
            while (isdigit((unsigned char)infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        } else if (infix[i] == '(') {
            stack[++top] = '(';
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            if (top != -1 && stack[top] == '(') top--;
        } else {
            while (top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            stack[++top] = infix[i];
        }
    }
    while (top != -1) {
        postfix[j++] = stack[top--];
        postfix[j++] = ' ';
    }
    if (j > 0 && postfix[j-1] == ' ') j--;
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; postfix[i] != '\0';) {
        if (postfix[i] == ' ') {
            i++;
            continue;
        }
        if (isdigit((unsigned char)postfix[i])) {
            int num = 0;
            while (isdigit((unsigned char)postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            stack[++top] = num;
        } else {
            char op = postfix[i];
            int b = stack[top--];
            int a = stack[top--];
            int result = 0;
            switch (op) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            stack[++top] = result;
            i++;
        }
    }
    return stack[top];
}

int main() {
    char infix[MAX] = "18+27*(15-11)";
    char postfix[MAX];

    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Final Result = %d\n", result);

    return 0;
}
