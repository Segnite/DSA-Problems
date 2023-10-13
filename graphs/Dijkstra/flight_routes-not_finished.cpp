#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


const int MAXN = 1e5 + 7;
vector<pair<int, int>> G1[MAXN];
vector<pair<int, int>> G2[MAXN];
int best;
vector<int> a;

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

void check(int k, int s, int t)
{
    vector<int> dist_s(t + 1, 2e9);
    Dijkstra(s, dist_s, G1);
    vector<int> dist_t(t + 1, 2e9);
    Dijkstra(t, dist_t, G2);

    int opt = dist_s[t];
    a.push_back(opt);
    pair<int,int> b = {1e9,1e9};
    for(int i=1;i<k;++i){
        best = 1e9;
        for (int v = 1; v <= t; ++v) {
            for (auto e : G1[v])
                if (dist_s[v] + e.second + dist_t[e.first] >= opt && (v != b.first && e.first != b.second)){
                    best = min(best,dist_s[v] + e.second + dist_t[e.first]);
                    b = {v,e.first};
                }
                    
        }
        a.push_back(best);
        opt = best;
    }
}

int main() {
    int vertices, edges, k;
    cin >> vertices >> edges >> k;

    for (int i = 0; i < edges; ++i) {
        int a, b, w;
        cin >> a >> b >> w;

        G1[a].push_back({ b,w });
        G2[b].push_back({ a,w });
    }

    check(k,1,vertices);
    sort(a.begin(),a.end());
    for(auto abc : a){
        cout << abc << ' ';
    }
    return 0;
}