#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
Stack *createStack();
void push(Stack *stack, double value);
double pop(Stack *stack);
int isEmpty(Stack *stack);
void freeStack(Stack *stack);
double evaluateRPN(char *expression);

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack *stack)
{
    if (stack->top == NULL)
    {
        return 1;
    }
    return 0;
}

void push(Stack *stack, double value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

double pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
    double value = stack->top->value;
    Node *temp = stack->top; // temp guarda o endereço do nó
    stack->top = stack->top->next;

    free(temp); // libera o valor
    return value;
}

void freeStack(Stack *stack)
{
    while (isEmpty(stack) != 1)
    {
        pop(stack);
    }

    free(stack);
}

double evaluateRPN(char *expression)
{
    Stack *stack = createStack();

    // Separar tokens
    char *token = strtok(expression, " ");

    while (token != NULL)
    {
        // Verificar se é número ou operador
        if ((token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') && token[1] == '\0'){
            if (isEmpty(stack)) {
            printf("Erro: Expressao malformada (operandos insuficientes para o operador '%c').\n", token[0]);
            freeStack(stack);
            exit(1);
            }
            double val2 = pop(stack);

        if (isEmpty(stack)) {
        printf("Erro: Expressao malformada (operandos insuficientes para o operador '%c').\n", token[0]);
        freeStack(stack);
        exit(1);
        }           
        double val1 = pop(stack);
        
            double resultado;

            if (token[0] == '+'){
                resultado = val1 + val2;
            }
            else if (token[0] == '-'){
                resultado = val1 - val2;
            }
            else if (token[0] == '*'){
                resultado = val1 * val2;
            }
            else if (token[0] == '/'){
                if (val2 == 0)
                {
                    printf("Erro: Tentativa de divisão por zero.\n");
                    freeStack(stack);
                    exit(1);
                }
                resultado = val1 / val2;
            }
            push(stack, resultado);
        }
        else{
            push(stack, atof(token)); // converte token para double & empilha o número
        }

        // processar token
        token = strtok(NULL, " "); // pega próximo
    }

    // Pegar o resultado
    double result = pop(stack); // No final, deve sobrar 1 valor na pilha: o resultado!
    freeStack(stack);
    return result;
}

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Uso: %s \"expressao\"\n", argv[0]);
        return 1;
    }

    // Avalia e imprime o resultado
    double result = evaluateRPN(argv[1]);
    printf("Resultado: %.2f\n", result);

    return 0;
}
