#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 5e5  + 5;
vector<int> graph[MAXN];

int main(){
    int n,m;

    cin >> n >> m;

    for(int i=0;i<m;++i){
        int x,y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1;i<=n;++i){
        sort(graph[i].begin(),graph[i].end());
        for(auto current : graph[i]){
            cout << current << ' ';
        }

        if(graph[i].size() == 0){
            cout << "Wiewior sam!";
        }

        cout << '\n';
    }
    return 0;
}