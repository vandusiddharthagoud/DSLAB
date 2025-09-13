#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int st[MAX];
int top = -1;

void push(int st[], int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        st[++top] = val;
    }
}

int pop(int st[]) {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return st[top--];
    }
}

int evaluatepostfixExp(char exp[]) {
    int i = 0;
    int op1, op2, value;
    char ch;

    while ((ch = exp[i]) != '\0' && ch != '\n') {
        if (isdigit(ch)) {
            push(st, ch - '0');  // convert char to int
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            op2 = pop(st);
            op1 = pop(st);
            switch (ch) {
                case '+': value = op1 + op2; break;
                case '-': value = op1 - op2; break;
                case '*': value = op1 * op2; break;
                case '/': 
                    if (op2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    value = op1 / op2; break;
            }
            push(st, value);
        }
        i++;
    }

    return pop(st);
}

int main() {
    int val;
    char exp[100];

    printf("ENTER any postfix expression (single-digit numbers, e.g., 53+82-*): ");
    fgets(exp, sizeof(exp), stdin);

    val = evaluatepostfixExp(exp);
    printf("VALUE of the postfix expression = %d\n", val);
    
    return 0;
}



























