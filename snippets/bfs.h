#ifndef BFS_H
#define BFS_H

void BFSIterative(int graph[][100], int n, int start);
void BFSRecursive(int graph[][100], int n, int queue[], int front, int rear, bool visited[]);

#endif
