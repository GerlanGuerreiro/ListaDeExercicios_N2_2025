#include <stdio.h>
#include <stdlib.h>

// Função que cria dinamicamente um vetor de n elementos
int* criarVetor(int n) {
    int *vetor = (int*) malloc(n * sizeof(int)); // aloca espaço para n inteiros
    return vetor;
}

// Função que imprime os elementos de um vetor
void imprimirVetor(int *vetor, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função que libera a memória alocada
void liberarVetor(int *vetor) {
    free(vetor);
}

int main() {
    int n, i;
    int *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // Criação do vetor
    vetor = criarVetor(n);

    // Leitura dos elementos
    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // Impressão dos elementos
    printf("Elementos do vetor: ");
    imprimirVetor(vetor, n);

    // Liberação da memória
    liberarVetor(vetor);

    return 0;
}
