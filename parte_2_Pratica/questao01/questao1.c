#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

typedef struct {
    int dia;
    int mes;
} Data;

typedef struct {
    char nome[40];
    char telefone[15];
    char celular[15];
    char email[40];
    Data aniversario;
} Contato;

// Lista encadeada
struct elemento {
    Contato info;
    struct elemento* prox;
};

typedef struct elemento Elemento;

// Tipo ponteiro para o início da lista
typedef Elemento* Lista;

// Função que cria uma agenda (lista) vazia
Lista cria_agenda() {
    return NULL;
}
// Função que insere um contato no final da lista
Lista insere_contato(Lista lista) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    if (novo == NULL) {
        printf("Erro de memória!\n");
        return lista;
    }

    // Coleta os dados do contato
    printf("=== Inserir novo contato ===\n");
    printf("Nome: ");
    scanf(" %[^\n]", novo->info.nome);
    printf("Telefone: ");
    scanf(" %[^\n]", novo->info.telefone);
    printf("Celular: ");
    scanf(" %[^\n]", novo->info.celular);
    printf("Email: ");
    scanf(" %[^\n]", novo->info.email);
    printf("Data de aniversario (dia mes): ");
    scanf("%d %d", &novo->info.aniversario.dia, &novo->info.aniversario.mes);

    novo->prox = NULL;
    if (lista == NULL)
        return novo;

    Elemento* aux = lista;
    while (aux->prox != NULL)
        aux = aux->prox;
    aux->prox = novo;

    return lista;
}

// Função que lista todos os contatos
void lista_contatos(Lista lista) {
    if (lista == NULL) {
        printf("Agenda vazia!\n");
        return;
    }

    printf("\n=== Lista de Contatos ===\n");
    Elemento* aux = lista;
    while (aux != NULL) {
        printf("Nome: %s\n", aux->info.nome);
        printf("Telefone: %s\n", aux->info.telefone);
        printf("Celular: %s\n", aux->info.celular);
        printf("Email: %s\n", aux->info.email);
        printf("Aniversario: %02d/%02d\n", aux->info.aniversario.dia, aux->info.aniversario.mes);
        printf("-------------------------\n");
        aux = aux->prox;
    }
}

// Função que busca um contato pelo nome
Elemento* busca_contato(Lista lista, char nome[]) {
    Elemento* aux = lista;
    while (aux != NULL) {
        if (strcmp(aux->info.nome, nome) == 0)
            return aux; 
        aux = aux->prox;
    }
    return NULL; 
}

// Função que remove um contato da lista
Lista remove_contato(Lista lista) {
    char nome[40];
    printf("Digite o nome do contato a remover: ");
    scanf(" %[^\n]", nome);

    Elemento* ant = NULL;
    Elemento* atual = lista;

    while (atual != NULL && strcmp(atual->info.nome, nome) != 0) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Contato nao encontrado!\n");
        return lista;
    }

    if (ant == NULL)
        lista = atual->prox;
    else
        ant->prox = atual->prox;

    free(atual);
    printf("Contato removido com sucesso!\n");

    return lista;
}

// Função que atualiza (edita) um contato existente
void atualiza_contato(Lista lista) {
    char nome[40];
    printf("Digite o nome do contato a editar: ");
    scanf(" %[^\n]", nome);

    Elemento* contato = busca_contato(lista, nome);
    if (contato == NULL) {
        printf("Contato nao encontrado!\n");
        return;
    }

    printf("=== Editar Contato ===\n");
    printf("Novo nome: ");
    scanf(" %[^\n]", contato->info.nome);
    printf("Novo telefone: ");
    scanf(" %[^\n]", contato->info.telefone);
    printf("Novo celular: ");
    scanf(" %[^\n]", contato->info.celular);
    printf("Novo email: ");
    scanf(" %[^\n]", contato->info.email);
    printf("Nova data de aniversario (dia mes): ");
    scanf("%d %d", &contato->info.aniversario.dia, &contato->info.aniversario.mes);

    printf("Contato atualizado com sucesso!\n");
}


int main() {
    Lista agenda = cria_agenda();  // Cria lista vazia
    int opcao;

    limpar_tela();

    do {
        printf("\n===== AGENDA TELEFONICA =====\n");
        printf("1. Inserir Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato\n");
        printf("4. Editar Contato\n");
        printf("5. Remover Contato\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        limpar_tela();

        switch (opcao) {
            case 1:
                agenda = insere_contato(agenda);
                break;
            case 2:
                lista_contatos(agenda);
                break;
            case 3: {
                char nome[40];
                printf("Digite o nome para buscar: ");
                scanf(" %[^\n]", nome);
                Elemento* encontrado = busca_contato(agenda, nome);
                if (encontrado != NULL) {
                    printf("Contato encontrado:\n");
                    printf("Nome: %s\n", encontrado->info.nome);
                    printf("Telefone: %s\n", encontrado->info.telefone);
                    printf("Celular: %s\n", encontrado->info.celular);
                    printf("Email: %s\n", encontrado->info.email);
                    printf("Aniversario: %02d/%02d\n", encontrado->info.aniversario.dia, encontrado->info.aniversario.mes);
                } else {
                    printf("Contato nao encontrado.\n");
                }
                break;
            }
            case 4:
                atualiza_contato(agenda);
                break;
            case 5:
                agenda = remove_contato(agenda);
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

        printf("\nPressione ENTER para continuar...");
        getchar(); getchar();
        limpar_tela();

    } while (opcao != 6);

    return 0;
}
