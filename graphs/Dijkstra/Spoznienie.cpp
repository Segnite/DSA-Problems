#include <iostream>
#include <vector>
#include <queue>
using namespace std;


const int MAXN = 1e5 + 7;
vector<pair<int, int>> G1[MAXN];
vector<pair<int, int>> G2[MAXN];

void Dijkstra(int start, vector<int>& dist, vector<pair<int, int>> G[]) {
    priority_queue<pair<int, int>> Q;
    Q.push({ 0,start });
    while (Q.size()) {
        int d = -(Q.top().first);
        int v = Q.top().second;
        Q.pop();
        if (dist[v] <= d)
            continue;
        dist[v] = d;

        for (auto e : G[v])
            if (dist[v] + e.second < dist[e.first])
                Q.push({ -(dist[v] + e.second),e.first });
    }
}

bool check(int n, int s, int t)
{
    vector<int> dist_s(n + 1, 2e9);
    Dijkstra(s, dist_s, G1);
    vector<int> dist_t(n + 1, 2e9);
    Dijkstra(t, dist_t, G2);

    int opt = dist_s[t];
    for (int v = 1; v <= n; ++v) {
        for (auto e : G1[v])
            if (dist_s[v] + e.second + dist_t[e.first] == opt + 1)
                return true;
    }
    return false;
}

int main() {
    int vertices, edges, home, work;
    cin >> vertices >> edges >> home >> work;

    for (int i = 0; i < edges; ++i) {
        int a, b, w;
        cin >> a >> b >> w;

        G1[a].push_back({ b,w });
        G2[b].push_back({ a,w });
    }
    if (check(vertices, home, work))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}