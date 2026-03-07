#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return top == -1 ? '\0' : stack[top--]; }
char peek() { return top == -1 ? '\0' : stack[top]; }

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char exp[MAX], c;
    scanf("%s", exp);
    for (int i = 0; exp[i]; i++) {
        c = exp[i];
        if (isalnum(c)) printf("%c", c);
        else if (c == '(') push(c);
        else if (c == ')') {
            while (peek() != '(') printf("%c", pop());
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(c)) printf("%c", pop());
            push(c);
        }
    }
    while (top != -1) printf("%c", pop());
    printf("\n");
    return 0;
}