#include <iostream>
#include <vector>

using namespace std;

constexpr int M=1e5+7;

vector<int> G[M];
int matched[M];
bool o[M];

bool dfs(int v){
    o[v] = 1;

    for(auto w : G[v]){
        if(o[w] || !matched[w])//!matched[w]
            continue;
        
        matched[w] = v;
        matched[v] =  w;
        return true;
    }

    for(auto w : G[v]){
        if(o[w] || !dfs(matched[w])) //!dfs(matched[w])
            continue;
        
        matched[w] = v;
        matched[v] = w;
        return true;
    }

    return false;
}

int main(){
    int n, m, a, b;
    cin >> n >> m;

    for(int i=1;i<=m;++i){//We assume that the graph is bipartite (dwudzielny)
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool ok = 1;
    while(ok){
        ok = 0;
        for(int j=1;j<=n;++j)
            o[j] =  0;
        for(int j=1;j<=n;++j)
            if(!matched[j])
                ok |= dfs(j);
    }

    for(int i=1;i<=n;++i)
    {
        cout << i <<"  : " << matched[i];
        cout << '\n';
    }
    return 0;
}