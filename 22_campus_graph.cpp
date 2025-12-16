#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 5

// Building names
string building[N] = {
    "Library", "Canteen", "Lab", "Admin", "Hostel"
};

// Adjacency list
vector<int> graph[N];

// BFS function to find shortest path
void bfs(int start, int end) {
    bool visited[N] = {false};
    int parent[N];

    queue<int> q;
    visited[start] = true;
    parent[start] = -1;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : graph[node]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = node;
                q.push(next);
            }
        }
    }

    // Print shortest path
    int path[N], count = 0;
    for (int v = end; v != -1; v = parent[v]) {
        path[count++] = v;
    }

    cout << "Shortest Path: ";
    for (int i = count - 1; i >= 0; i--) {
        cout << building[path[i]];
        if (i != 0) cout << " -> ";
    }
    cout << endl;
}

int main() {
    // Create connections
    graph[0].push_back(2); // Library -> Lab
    graph[2].push_back(0);

    graph[2].push_back(4); // Lab -> Hostel
    graph[4].push_back(2);

    graph[1].push_back(0); // Canteen -> Library
    graph[0].push_back(1);

    graph[3].push_back(4); // Admin -> Hostel
    graph[4].push_back(3);

    // Find path from Canteen (1) to Hostel (4)
    bfs(1, 4);

    return 0;
}
