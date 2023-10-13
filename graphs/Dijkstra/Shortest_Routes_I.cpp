#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 7;
//   v=5  idzie do 3, waga 5   
vector<pair<int,int>> G[MAXN];
long long dist[MAXN]; //Ostateczne odległości // wartości mogą sięgnąć miliard * ile można przejść

void Dijkstra(int start){
    fill(dist,dist+MAXN,1e18);
    priority_queue<pair<long long,int>> Q;
    Q.push({0,start});
    while(Q.size()){
        auto [d, v] = Q.top();
        Q.pop();
        if(dist[v] <= -d)
            continue;
        dist[v] = -d;
        for(auto [u, w] : G[v])
            if (dist[u] > dist[v] + w)
                Q.push({-(dist[v] + w), u});
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;++i){
        int a,b,c;
        cin >> a >> b >> c;

        G[a].push_back({b,c});
    }

    Dijkstra(1);
    for(int i=1;i<=n;++i){
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}