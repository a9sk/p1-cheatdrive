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


// ------------------------------------------------------------------
// ------------------------------------------------------------------
// ------------------------------------------------------------------

const int MAX = 100;

int n, m;
int grid[MAX][MAX];
bool vis[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y) {
    vis[x][y] = true;

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (!vis[nx][ny] && grid[nx][ny] == 1) {
                dfs(nx, ny);
            }
        }
    }
}

void dfs_iterative(int sx, int sy) {
    int stack_x[MAX * MAX];
    int stack_y[MAX * MAX];
    int top = -1;

    top++;
    stack_x[top] = sx;
    stack_y[top] = sy;
    vis[sx][sy] = true;

    while (top >= 0) {
        int x = stack_x[top];
        int y = stack_y[top];
        top--;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!vis[nx][ny] && grid[nx][ny] == 1) {
                    vis[nx][ny] = true;
                    top++;
                    stack_x[top] = nx;
                    stack_y[top] = ny;
                }
            }
        }
    }
}
