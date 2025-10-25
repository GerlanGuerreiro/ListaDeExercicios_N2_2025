#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

// Estrutura de um nó da pilha
typedef struct Node
{
    double value;
    struct Node *next;
} Node;

// Estrutura da pilha
typedef struct Stack
{
    Node *top;
} Stack;

// Declaração das funções
Stack* createStack();
void push(Stack* stack, double value);
double pop(Stack* stack);
int isEmpty(Stack* stack);
void freeStack(Stack* stack);
double evaluateRPN(char* expression);

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Uso: %s \"expressao\"\n", argv[0]);
        return 1;
    }

    // Avalia e imprime o resultado
    double result = evaluateRPN(argv[1]);
    printf("Resultado: %.2f\n", result);

    return 0;
}
