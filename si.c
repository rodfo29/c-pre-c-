#include <stdio.h>
#include <limits.h>
#define V 5 // Número de vértices en el grafo

// Función para encontrar el vértice con la distancia mínima que aún no ha sido procesado
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

// Función para imprimir las distancias más cortas desde el origen
void printSolution(int dist[]) {
    printf("Vértice \t Distancia desde el origen\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Implementación del algoritmo de Dijkstra
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // dist[i] guardará la distancia más corta desde src a i
    int visited[V];  // visited[i] será 1 si el vértice i ya fue procesado

    // Inicializar todas las distancias como infinitas y visited[] como falso
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    // La distancia desde el origen hasta sí mismo siempre es 0
    dist[src] = 0;

    // Encuentra la ruta más corta para todos los vértices
    for (int count = 0; count < V - 1; count++) {
        // Escoge el vértice con la distancia mínima del conjunto de vértices no procesados
        int u = minDistance(dist, visited);

        // Marca el vértice como procesado
        visited[u] = 1;

        // Actualiza el valor de distancia de los vértices adyacentes del vértice escogido
        for (int v = 0; v < V; v++)
            // Actualiza dist[v] solo si no está en visited, hay un borde de u a v,
            // y el peso total de la ruta desde src hasta v a través de u es menor que el valor actual de dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
    }
   // Imprime la distancia más corta desde el origen
    printSolution(dist);
}

int main() {


    // Ejemplo de grafo representado como matriz de adyacencia
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };

    // Llamada a la función dijkstra con el vértice 0 como origen
    dijkstra(graph, 2);

    return 0;
}
