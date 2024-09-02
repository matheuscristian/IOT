#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int item) {
    if (!isFull(s)) {
        s->items[++(s->top)] = item;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return 0; // return 0 in case of empty stack
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return 0; // return 0 in case of empty stack
}

int evaluatePostfix(const char *postfix) {
    Stack s;
    init(&s);
    int i = 0;

    while (postfix[i]) {
        if (isdigit(postfix[i])) {
            push(&s, postfix[i] - '0');
        } else {
            int right = pop(&s);
            int left = pop(&s);
            switch (postfix[i]) {
                case '+': push(&s, left + right); break;
                case '-': push(&s, left - right); break;
                case '*': push(&s, left * right); break;
                case '/': push(&s, left / right); break;
                default: printf("Operador invalido %c\n", postfix[i]); exit(1);
            }
        }
        i++;
    }
    return pop(&s);
}

int main() {
    char postfix[MAX];
    printf("Digite a expressao pos-fixa: ");
    fgets(postfix, MAX, stdin);
    postfix[strcspn(postfix, "\n")] = '\0';
    int result = evaluatePostfix(postfix);
    printf("Resultado: %d\n", result);
    return 0;
}
