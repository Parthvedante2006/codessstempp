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

// DFS function
void dfs(int node) {
    visited[node] = true;
    cout << place[node] << " -> ";

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    // Creating graph connections
    graph[0].push_back(1); // Restaurant -> AreaA
    graph[0].push_back(2); // Restaurant -> AreaB
    graph[1].push_back(3); // AreaA -> AreaC
    graph[2].push_back(4); // AreaB -> AreaD

    cout << "Food Delivery Routes (DFS):\n";
    dfs(0);   // Start from Restaurant

    return 0;
}
