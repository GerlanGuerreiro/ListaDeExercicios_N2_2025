# 📚 Lista de Exercícios N2 – 2025  
## 💻 Estrutura de Dados II

Este trabalho deve ser feito em **equipe de até três integrantes** e está dividido em duas seções: **teórica** e **prática**.  
Ambas devem ser adicionadas ao repositório da equipe no GitHub. Todos os integrantes devem ter **commits** registrados, pois isso será considerado para a atribuição da nota.  

A lista tem como objetivo **reforçar os conceitos estudados**, promover a **pesquisa** e estimular o **desenvolvimento lógico e de programação**.  
É permitido pesquisar na internet, mas recomenda-se **evitar o uso de IA para resolver as questões** inicialmente.

Todos os integrantes devem **submeter o link do repositório** da equipe no portal digital.

---

## 📝 Parte 1 – Teoria

Responda às seguintes questões de forma clara e objetiva:

1. O que significa alocação estática de memória para um conjunto de elementos?  
2. Qual a diferença entre alocação estática e alocação dinâmica?  
3. O que é um ponteiro?  
4. O que é uma estrutura de dados homogêneos?  
5. O que é uma estrutura de dados heterogêneos?  
6. Qual a vantagem das listas sobre os vetores em termos de consumo de memória? Exemplifique.  
7. O que é uma lista simplesmente encadeada? Apresente um diagrama para ilustrar essa estrutura de dados.  
8. O que é uma lista duplamente encadeada? Apresente um diagrama para ilustrar essa estrutura de dados.  
9. O que é uma lista duplamente encadeada? Apresente um diagrama para ilustrar essa estrutura de dados.  
10. Explique o funcionamento dos algoritmos de **busca binária** e **sequencial**.  
11. Explique o funcionamento dos seguintes algoritmos de ordenação:  
   - Insertion Sort  
   - Selection Sort  
   - Merge Sort  
   - Count Sort  
   - Quicksort  

---

## 🧠 Parte 2 – Prática

### 📌 Questão 01 – Agenda Telefônica com Lista Encadeada

Desenvolva um programa em C que implemente uma **agenda telefônica** utilizando **listas encadeadas simples**.  
Cada contato possui as seguintes informações:

- **Nome** – até 40 caracteres  
- **Telefone** – até 15 caracteres  
- **Celular** – até 15 caracteres  
- **Email** – até 40 caracteres  
- **DataAniversario** – dia e mês

As informações podem ser representadas em dois tipos estruturados: `Data` e `Contato`.

A lista encadeada de contatos será representada pela estrutura:

```c
struct elemento {
    Contato info;
    struct elemento* prox;
};
typedef struct elemento Elemento;
