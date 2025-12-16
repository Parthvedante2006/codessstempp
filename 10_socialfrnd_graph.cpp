#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter number of users: ";
    cin >> n;

    vector<vector<int>> graph(n + 1);

    cout << "Friend connections (edges):\n";
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Suggest friends for user: ";
    cin >> start;

    vector<bool> visited(n + 1, false);
    vector<int> level(n + 1, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;
    level[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int friendNode : graph[curr]) {
            if (!visited[friendNode]) {
                visited[friendNode] = true;
                level[friendNode] = level[curr] + 1;
                q.push(friendNode);
            }
        }
    }

    cout << "Friend suggestions for user " << start << ": ";
    for (int i = 1; i <= n; i++) {
        if (level[i] == 2)
            cout << i << " ";
    }

    return 0;
}
