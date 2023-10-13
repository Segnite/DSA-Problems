#include <iostream>

using namespace std;

const int BASE = 128 * 1024;
const int MAXN = 1e5 + 5;

int numbers[MAXN];
int segtree[2 * BASE + 7];

void init(int n){
    for(int i=1;i <=n;++i){
        segtree[BASE + i] = numbers[i];
    }

    for(int i=BASE-1;i >= 1;--i){
        segtree[i] = min(segtree[2*i],segtree[2*i+1]);
    }
}

int get_min(int a,int b,int v,int l,int r){
    if(r < a || b < l)
        return 2147483647-100;
    else if(a <= l && r <= b)
        return segtree[v];
    
    int mid = (l + r) / 2;
    int ls = get_min(a,b,2*v,l,mid);
    int rs = get_min(a,b,2*v+1,mid+1,r);
    return min(ls,rs);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    
    for(int i = 1;i <= n; ++i)
        cin >> numbers[i];
    
    for(int i=1;i<=2*BASE+3;++i)
        segtree[i] = 2147483647-100;
    init(n);
    int k;
    cin >> k;

    for(int i=0;i<k;++i){
        int left,right;
        cin >> left >> right;

        if(left > right)
        {
            int tmp = left;
            left = right;
            right = tmp;
        }

        cout << get_min(left+1,right+1,1,0,BASE-1) << '\n';
    }
    return 0;
}