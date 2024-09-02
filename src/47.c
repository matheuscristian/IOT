#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma aresta
typedef struct {
    int src, dest, weight;
} Aresta;

// Estrutura para representar um grafo
typedef struct {
    int V, E;
    Aresta* arestas;
} Grafo;

// Função para criar um grafo
Grafo* criarGrafo(int V, int E) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->V = V;
    grafo->E = E;
    grafo->arestas = (Aresta*)malloc(E * sizeof(Aresta));
    return grafo;
}

// Função para encontrar o conjunto de um elemento (usando o algoritmo de união por caminho)
int encontrar(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return encontrar(parent, parent[i]);
}

// Função para unir dois conjuntos
void unir(int parent[], int rank[], int x, int y) {
    int raizX = encontrar(parent, x);
    int raizY = encontrar(parent, y);

    if (raizX != raizY) {
        if (rank[raizX] < rank[raizY])
            parent[raizX] = raizY;
        else if (rank[raizX] > rank[raizY])
            parent[raizY] = raizX;
        else {
            parent[raizY] = raizX;
            rank[raizX]++;
        }
    }
}

// Função de comparação para ordenar as arestas por peso
int compararArestas(const void* a, const void* b) {
    return ((Aresta*)a)->weight - ((Aresta*)b)->weight;
}

// Função para implementar o algoritmo de Kruskal
void kruskal(Grafo* grafo) {
    int V = grafo->V;
    Aresta resultado[V];
    int e = 0; // Índice para resultado[]
    int i = 0; // Índice para arestas ordenadas

    // Passo 1: Ordenar todas as arestas em ordem não decrescente de peso
    qsort(grafo->arestas, grafo->E, sizeof(Aresta), compararArestas);

    // Criar conjuntos disjuntos para cada vértice
    int parent[V];
    int rank[V];
    for (int v = 0; v < V; ++v) {
        parent[v] = v;
        rank[v] = 0;
    }

    // Passo 2: Adicionar arestas ao MST
    while (e < V - 1 && i < grafo->E) {
        Aresta proximaAresta = grafo->arestas[i++];

        int x = encontrar(parent, proximaAresta.src);
        int y = encontrar(parent, proximaAresta.dest);

        // Se a aresta não formar um ciclo
        if (x != y) {
            resultado[e++] = proximaAresta;
            unir(parent, rank, x, y);
        }
    }

    // Imprimir o MST
    printf("Arestas no MST:\n");
    int custoTotal = 0;
    for (i = 0; i < e; ++i) {
        printf("%d - %d: %d\n", resultado[i].src, resultado[i].dest, resultado[i].weight);
        custoTotal += resultado[i].weight;
    }
    printf("Custo total do MST: %d\n", custoTotal);
}

// Função principal
int main() {
    int V = 4; // Número de vértices
    int E = 5; // Número de arestas

    // Criar um grafo com V vértices e E arestas
    Grafo* grafo = criarGrafo(V, E);

    // Adicionar arestas ao grafo
    grafo->arestas[0] = (Aresta){0, 1, 10};
    grafo->arestas[1] = (Aresta){0, 2, 6};
    grafo->arestas[2] = (Aresta){0, 3, 5};
    grafo->arestas[3] = (Aresta){1, 3, 15};
    grafo->arestas[4] = (Aresta){2, 3, 4};

    // Encontrar o MST usando o algoritmo de Kruskal
    kruskal(grafo);

    // Liberar memória
    free(grafo->arestas);
    free(grafo);

    return 0;
}
