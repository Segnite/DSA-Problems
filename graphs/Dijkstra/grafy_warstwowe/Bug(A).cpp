#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 4e5 + 7;
vector<pair<int,int>> graph[MAXN];
int dist[MAXN];
int n,m;

void Dijkstra(int start){
    fill(dist,dist + 2*n + 1,1e9);
    priority_queue<pair<int,int>> Q;
    Q.push({0,start});
    while(Q.size()){
        auto [w,v] = Q.top();
        Q.pop();
        if(-w >= dist[v])
            continue;
        dist[v] = -w;
        
        for(auto [u,d] : graph[v]){
            if(dist[u] > dist[v] + d)
                Q.push({-(dist[v] + d),u});
        }
    }
}

void add_edge(int a,int b,int w){
    graph[a].push_back({b,w});
    graph[b].push_back({a,w});
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;

    for(int i=0;i<m;++i){
        int a,b,w;
        cin >> a >> b >> w;

        if(w & 1){
            add_edge(a,b + n,w);
            add_edge(a + n,b,w);
        }
        else{
            add_edge(a,b,w);
            add_edge(a+n,b+n,w);
        }
    }

    Dijkstra(1);
    if(dist[2 * n] == 1e9)
        cout << "0\n";
    else
        cout << dist[2 * n] << '\n';
    return 0;
}