#include "dfs.h"
#include <iostream>

void DFSRecursive(int graph[][100], int n, int start, bool visited[]) {
    visited[start] = true;
    std::cout << start << " ";

    for (int i = 0; i < n; i++) {
        if (graph[start][i] != 0 && !visited[i]) {
            DFSRecursive(graph, n, i, visited);
        }
    }
}

void DFSIterative(int graph[][100], int n, int start) {

    bool* visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }

    Stack stack;
    stack.push(start);

    while (!stack.isEmpty()) {
        int node = stack.pop();

        if (!visited[node]) {
            visited[node] = true;
            std::cout << node << " ";

            for (int i = n - 1; i >= 0; i--) {
                if (graph[node][i] != 0 && !visited[i]) {
                    stack.push(i);
                }
            }
        }
    }

    delete[] visited;
    visited = nullptr;
}


