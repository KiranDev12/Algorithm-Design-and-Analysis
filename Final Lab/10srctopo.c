#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n;
int AdjMat[MAX][MAX];
int queue[MAX], front = -1, rear = -1;
void Enqueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}
int isEmpty_queue() {
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}
int Dequeue() {
    int del_item;
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        exit(1);
    } else {
        del_item = queue[front];
        front = front + 1;
        return del_item;
    }
}
int indegree(int v) {
    int i, in_deg = 0;
    for (i = 0; i < n; i++)
        if (AdjMat[i][v] == 1)
            in_deg++;
    return in_deg;
}
void create_graph() {
    printf("Enter no of vertices\n");
    scanf("%d", & n);
    printf("Enter Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", & AdjMat[i][j]);
        }
    }
}
int main() {
    int i, v, count, stack[MAX], indeg[MAX];
    create_graph();
    for (i = 0; i < n; i++) {
        indeg[i] = indegree(i);
        if (indeg[i] == 0)
            Enqueue(i);
    }
    count = 0;
    while (!isEmpty_queue() && count < n) {
        v = Dequeue();
        stack[++count] = v;
        for (i = 0; i < n; i++) {
            if (AdjMat[v][i] == 1) {
                AdjMat[v][i] = 0;
                indeg[i] = indeg[i] - 1;
                if (indeg[i] == 0)
                    Enqueue(i);
            }
        }
    }
    if (count < n) {
        printf("Topological Sorting is not possible, graph contains cycle");
        exit(1);
    }
    printf("Vertices in Topological order are:\n");
    for (i = 1; i <= count; i++)
        printf("%d-->", stack[i]);
    printf("\n");
    return 0;
}
