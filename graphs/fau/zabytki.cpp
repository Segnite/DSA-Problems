#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

const int maxn = 2e6 + 5;
int rep[maxn];
vector<pair<int,int>> a;

int FIND(int a){
    if(rep[a] == a)
        return rep[a];
    rep[a] = FIND(rep[a]);
    return rep[a];
}

void UNION(int a,int b){
    rep[FIND(rep[a])] = rep[FIND(rep[b])];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;

    for(int i=1;i<=m;++i){
        int x,y;
        cin >> x >> y;
        a.push_back({x,y});
    }

    for(int i=1;i<=n;++i)
        rep[i] = i;

    int week = 0;
    bool isit = false;
    for(int i=1;i<=m;++i){
        int x,y;
        x = a[i-1].first;
        y = a[i-1].second;

        if(FIND(rep[x]) == FIND(rep[y])){
            week = i;
            isit = true;
            break;
        }
        UNION(FIND(rep[x]),FIND(rep[y]));
    }
    if(isit)
        cout << week << '\n';
    else
        cout << "NIE" << '\n';
    return 0;
}