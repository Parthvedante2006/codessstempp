#include <iostream>
#include <vector>
using namespace std;

#define N 5

// Names of locations
string place[N] = {
    "Restaurant", "AreaA", "AreaB", "AreaC", "AreaD"
};

// Adjacency list
vector<int> graph[N];
bool visited[N];

// BFS function
void bfs(int start) {
    int queue[N];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        cout << place[node] << " -> ";

        // simple for loop
        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            if (!visited[next]) {
                visited[next] = true;
                queue[rear++] = next;
            }
        }
    }
}

int main() {
    // Creating graph connections
    graph[0].push_back(1); // Restaurant -> AreaA
    graph[0].push_back(2); // Restaurant -> AreaB
    graph[1].push_back(3); // AreaA -> AreaC
    graph[2].push_back(4); // AreaB -> AreaD

    cout << "Food Delivery Routes (BFS - Shortest Path Estimation):\n";
    bfs(0);   // Start from Restaurant

    return 0;
}
