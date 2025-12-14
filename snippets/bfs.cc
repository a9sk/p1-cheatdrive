#include "bfs.h"
#include <iostream>

void BFSIterative(int graph[][100], int n, int start) {

    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    Queue queue;
    queue.enqueue(start);
    visited[start] = true;

    while (!queue.isEmpty()) {
        int node = queue.dequeue();
        std::cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (graph[node][i] != 0 && !visited[i]) {
                queue.enqueue(i);
                visited[i] = true;
            }
        }
    }

    delete[] visited;
}

void BFSRecursive(int graph[][100], int n, int queue[], int front, int rear, bool visited[]) {
    if (front > rear) return; 

    int node = queue[front];
    std::cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (graph[node][i] != 0 && !visited[i]) {
            queue[++rear] = i;
            visited[i] = true;
        }
    }

    BFSRecursive(graph, n, queue, front + 1, rear, visited);
}
