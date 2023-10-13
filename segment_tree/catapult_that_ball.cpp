#include <bits/stdc++.h>
using namespace std;

const int BASE = 64*1024;
const int MAXN = 5e4  + 7 ;

int heights[MAXN];
int segTree[2 * BASE + 7];

int get_max(int a,int b,int v,int l,int r){
    if(b < l || r < a)
        return 0;
    
    if(a <= l && r <= b)
        return segTree[v];
    
    int mid = (l + r) / 2;
    int res_l = get_max(a,b,2*v,l,mid);
    int res_r = get_max(a,b,2*v+1,mid+1,r);
    
    return max(res_l,res_r);
}

void init(int n){
    for(int i = 1;i <= n; ++i)
        segTree[BASE + i] = heights[i];

    for(int i = BASE -1;i >= 1; --i){
        segTree[i] = max(segTree[2 * i],segTree[2 * i + 1]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;++i){
        cin >> heights[i];
    }
    init(n);
    // for(int i=1;i<=n;++i)
    //     cout << i+BASE << ' ';
    // cout << endl;
    // for(int i=BASE-1;i>= 1;--i)
    //     cout << i << ": " << segTree[i] << ' ';
    int answer = 0;
    for(int i=0;i<m;++i){
        int a,b;
        cin >> a >> b;
        
        int query_l,query_r;
        if(a <= b){
            query_l = a;
            query_r = b - 1;
        }
        else{
            query_l = b + 1;
            query_r = a + 1;
        }

        int max_h = get_max(query_l,query_r,1,0,BASE-1);
        if(max_h <= heights[a])
            ++answer;
    }
    cout << answer << '\n';
    return 0;
}