#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Estrutura para representar a pilha
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Inicializa a pilha
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Verifica se a pilha está vazia
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Verifica se a pilha está cheia
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Empilha um item na pilha
void push(struct Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Pilha cheia!\n");
        exit(1);
    }
    stack->top++;
    stack->items[stack->top] = item;
}

// Desempilha um item da pilha
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    char item = stack->items[stack->top];
    stack->top--;
    return item;
}

// Retorna o topo da pilha sem desempilhar
char peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    return stack->items[stack->top];
}

// Verifica se o caractere é um operador
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Verifica a precedência do operador
int precedence(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return 0;
    }
}

// Converte uma expressão infixa para posfixa
char *infixToPostfix(char *infix) {
    struct Stack stack;
    initializeStack(&stack);

    int i, j = 0;
    char *postfix = (char *)malloc(sizeof(char) * MAX_SIZE);

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) != '(') {
                printf("Expressão inválida!\n");
                free(postfix);
                return NULL;
            } else {
                pop(&stack); // Remove '(' da pilha
            }
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(infix[i]) <= precedence(peek(&stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        } else {
            printf("Caractere inválido: %c\n", infix[i]);
            free(postfix);
            return NULL;
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Adiciona o caractere nulo no final da string
    return postfix;
}

int main() {
    char infix[MAX_SIZE];
    printf("Digite a expressão infixa: ");
    scanf("%s", infix);

    char *postfix = infixToPostfix(infix);

    if (postfix != NULL) {
        printf("Expressão posfixa: %s\n", postfix);
        free(postfix);
    }

    return 0;
}