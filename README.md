# 📚 Lista de Exercícios N2 – 2025  

✍️ Disciplina: Estrutura de Dados II – 2025
📍 Universidade: Centro Universitário Fametro
👨‍🏫 Professor: Tiago Santos Figueira

👥 Equipe
Gabriel Fernando Souza da Silva 2408416
Gerlan Guerreiro Damasceno	2410324
Lucas Del-Aguila Maia 2405848


Este repositório contém a lista de exercícios da N2 da disciplina **Estrutura de Dados II**.  
O trabalho deve ser realizado **em equipe de até três integrantes** e contém **duas partes**: teórica e prática.  
Todos os integrantes devem contribuir com commits para receber a nota.

---

## 🧠 Parte 1 – Teoria

Responda às seguintes questões conceituais:

1. O que significa alocação estática de memória para um conjunto de elementos?  
2. Qual a diferença entre alocação estática e alocação dinâmica?  
3. O que é um ponteiro?  
4. O que é uma estrutura de dados homogêneos?  
5. O que é uma estrutura de dados heterogêneos?  
6. Qual a vantagem das listas sobre os vetores em termos de consumo de memória? Exemplifique.  
7. O que é uma lista simplesmente encadeada? Apresente um diagrama ilustrativo.  
8. O que é uma lista duplamente encadeada? Apresente um diagrama ilustrativo.  
9. O que é uma lista circular? Apresente um diagrama ilustrativo.  
10. Explique o funcionamento dos algoritmos de **busca binária** e **busca sequencial**.  
11. Explique o funcionamento dos algoritmos de ordenação:  
    - Insertion Sort  
    - Selection Sort  
    - Merge Sort  
    - Count Sort  
    - Quick Sort  

---

## 💻 Parte 2 – Prática

### 📝 Questão 01 – Agenda Telefônica com Lista Encadeada

Implemente, em C, um programa para gerenciar uma agenda telefônica utilizando **listas simplesmente encadeadas**.  
Cada contato deve conter os seguintes dados:

- Nome (até 40 caracteres)  
- Telefone (até 15 caracteres)  
- Celular (até 15 caracteres)  
- Email (até 40 caracteres)  
- Data de Aniversário (dia e mês)

#### Estrutura Base:

```c
struct elemento {   
    Contato info;  
    struct elemento* prox;  
};   
typedef struct elemento Elemento;

Funções obrigatórias:

    cria_agenda()

    insere_contato()

    lista_contatos()

    busca_contato()

    remove_contato()

    atualiza_contato()

Menu de operações:

    Inserir Contato

    Listar Contatos

    Buscar Contato

    Editar Contato

    Remover Contato

    Sair

O programa deve permanecer em execução até o usuário escolher a opção 6 (Sair).
🧮 Questão 02 – Vetor Dinâmico

Implemente um programa em C com as seguintes funções:

    Criar dinamicamente um vetor de n elementos.

    Imprimir os elementos do vetor.

    Liberar a memória alocada.

A função principal deve:

    Ler o valor de n.

    Alocar dinamicamente o vetor.

    Ler os n elementos.

    Imprimir os elementos.

    Liberar a memória.

⚙️ Questão 03 – Avaliador de Expressões em Notação Pós-Fixa (RPN)

Implemente, em C, um programa que avalia expressões matemáticas em RPN (Notação Polonesa Reversa).
Requisitos:

    Usar uma pilha dinâmica baseada em lista ligada.

    Operações da pilha:

        createStack

        push

        pop

        isEmpty

        freeStack

    Função principal: double evaluateRPN(char* expression)

Exemplo:

Comando: ./avaliador "10 5 +"
Saída:   Resultado: 15.00

Deve tratar:

    Erros de expressão malformada

    Divisão por zero

    Ordem correta dos operandos

🧪 Entrega

    Todo o conteúdo (teoria + prática) deve estar neste repositório.

    Cada integrante deve ter commits no histórico.

    O link do repositório deve ser enviado no portal digital da instituição.

📌 Dicas

    Utilize strtok() para separar tokens da expressão.

    Utilize atof() para conversão de strings em double.

    Gerencie bem a memória dinâmica, liberando todos os nós alocados.
