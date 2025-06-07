// BOJ 1260 - DFS와 BFS
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
bool visited[1001];
int N, M, V;

void dfs(int v) {
    visited[v] = true;
    cout << v << ' ';
    for (int next : graph[v]) {
        if (!visited[next]) dfs(next);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = false;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for (int next : graph[cur]) {
            if (visited[next]) {
                visited[next] = false;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());

    dfs(V);
    cout << '\n';
    bfs(V);
}
