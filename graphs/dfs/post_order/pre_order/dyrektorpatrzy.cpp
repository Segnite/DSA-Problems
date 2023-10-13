#include <iostream>
#include <vector>

using namespace std;

const int maxn = 5e5 + 5;
vector<int> graph[maxn];
int visited[maxn];
int pre[maxn],post[maxn];
int c=1;

void DFS(int v){
    visited[v] = true;
    pre[v] = c;
    ++c;

    for(int i=0;i<graph[v].size();++i){
        if(visited[graph[v][i]])
            continue;
        
        DFS(graph[v][i]);
    }
    post[v] = c;
    ++c;
}

int main(){
    int n,m;
    cin >> n >> m;

    for(int i=2;i<=n;++i){
        int x;
        cin >> x;

        graph[i].push_back(x);
        graph[x].push_back(i);
    }

    DFS(1);
    for(int i=1;i<=8;++i){
        cout << i << ": "<< pre[i] << ' ';
    }
    return 0;
}