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

// -----------------------------------------------------------
// -----------------------------------------------------------
// -----------------------------------------------------------

void bfs(int sx, int sy) {
    int qx[MAX * MAX];
    int qy[MAX * MAX];

    int front = 0;
    int rear = 0;

    vis[sx][sy] = true;
    qx[rear] = sx;
    qy[rear] = sy;
    rear++;

    while (front < rear) {
        int x = qx[front];
        int y = qy[front];
        front++;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!vis[nx][ny] && grid[nx][ny] == 1) {
                    vis[nx][ny] = true;
                    qx[rear] = nx;
                    qy[rear] = ny;
                    rear++;
                }
            }
        }
    }
}
