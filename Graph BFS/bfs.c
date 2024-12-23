#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100

void bfs(int adj[MAX][MAX], int V, int s){
    int q[MAX], front = 0, rear = 0; //Creating a Queue and intializing it

    bool visited[MAX] = {false}; //Marking the visited array intializing as false

    visited[s] = true;  // Mark the source node as visited and enqueue it
    q[rear++]= s;

    while(front<rear){  //Iterate over the queue
        int curr = q[front++];
        printf("%d",curr);

        for(int i =0;i<V;i++){ //visiting the adjacent neighbouring sides for which is not visited..
            if(adj[curr][i]==1&& !visited[i]){
                visited[i] = true;
                q[rear++] = i; 
            }
        }
    }
}
void addEdge(int adj[MAX][MAX],int u, int v){  //Adding the Edge To the graph..
        adj[u][v] = 1;
        adj[v][u] = 1;
}
int main(){
    int V = 5;
    
    // Adjacency matrix representation of the graph
    int adj[MAX][MAX] = {0};
    
    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    
    // Perform BFS traversal starting from vertex 0
    printf("BFS starting from 0:\n");
    bfs(adj, V, 0);
    
    return 0;
}
