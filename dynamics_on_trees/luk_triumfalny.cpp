#include <bits/stdc++.h>

using namespace std;
#define nd second
#define st first
#define pb push_back
typedef long long ll;
typedef long double ld;
const int N = 300 * 1000 + 7;
vector<int> ed[N];
int dp[N]; bool o[N];

void DFS(int v, int x)
{
    dp[v] = 0; o[v] = true;
    for(int i=0;i < (int)ed[v].size();++i)
    {
        if(o[ed[v][i]])
            continue;
        
        DFS(ed[v][i],x);
        dp[v] += dp[ed[v][i]] + 1;
    }
    dp[v] = max(dp[v] - x, 0); o[v] = false;
}

int BS(int n){
    int l=-1,mid,r = n;
    while(r - l > 1){
        mid = (l + r) / 2;
        DFS(1,mid);
        cout << mid << " : " << dp[1] << '\n'; 
        
        if(dp[1] == 0)
            r = mid;
        else
            l = mid;
    }
    return r;
}

void Solve(){
    int n,a,b;
    cin >> n;
    for(int i=1;i<=n-1;++i){
        cin >> a >> b;
        ed[a].pb(b);
        ed[b].pb(a);
    }
    cout << BS(n) << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();
    return 0;
}