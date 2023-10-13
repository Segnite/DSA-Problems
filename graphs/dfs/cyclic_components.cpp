#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
bool visited[MAXN];
bool checker;

void DFS(int v) {
    visited[v] = true;
    if (graph[v].size() != 2)
        checker = false;
    for (int j = 0; j < graph[v].size(); ++j) {
        if(visited[graph[v][j]])
            continue;

        DFS(graph[v][j]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int counter = 0;
    for (int i = 1; i <= n; ++i) {
        if (visited[i])
            continue;
        checker = true;
        DFS(i);
        if(checker) {
            ++counter;
        }
    }
    cout << counter << '\n';
    return 0;
}