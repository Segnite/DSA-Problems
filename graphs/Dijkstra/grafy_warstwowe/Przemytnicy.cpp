#include <iostream>
#include <vector>
// #include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
using namespace std;

const int MAXN = 5e3 + 7;

vector<pair<int,int>> G[MAXN];
int cost[MAXN];
int dist[MAXN][2];

int n,m;

void Dijkstra(){
    for(int i=1;i<=n;++i)
        dist[i][0] = dist[i][1] = 2e9;
                        //odl v  czy przekroczylem granicę?
    priority_queue<tuple<int,int,bool>> Q;
    Q.push({0,1,0});
    while(Q.size()){
        auto [d,v,layer] = Q.top();
        Q.pop();

        if(dist[v][layer] <= -d)
            continue;
        dist[v][layer] = -d;

        if(layer == 0)
            Q.push({-(dist[v][0] + cost[v]/2),v,1});
        
        for(auto [u,w] : G[v])
            if(dist[u][layer] > dist[v][layer] + w)
                Q.push({-(dist[v][layer] + w),u,layer});
    }
}

int main(){;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;++i)
        cin >> cost[i];
    cin >> m;
    for(int i=0;i<m;++i){
        int a,b,w;
        cin >> a >> b >> w;

        G[a].push_back({b,w});
    }

    Dijkstra();
    cout << dist[1][1];
    return 0;
}