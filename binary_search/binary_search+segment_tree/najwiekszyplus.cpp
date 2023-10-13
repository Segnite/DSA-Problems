#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 4e5+5;
const int INF = 1e9 + 5;
int segtree[MAXN * 3];
int potega=1;

vector<int> T;

int odpowiedz(int pp,int kp,int v,int a,int b){
    if(kp < a || b < pp)//nie ma wspólnych
        return INF;
    
    if(a <= pp && kp <= b)
        return segtree[v];
    
    return min(odpowiedz(pp,(pp+kp)/2,v*2,a,b),odpowiedz((pp+kp)/2+1,kp,v*2+1,a,b));
}

void aktualizacja(int v){
    v /= 2;
    while(v >= 1){
        segtree[v] = min(segtree[v*2],segtree[v*2+1]);
        v /= 2;
    }
}

bool sprawdz(int k,int n){
    bool istrue = false;
    for(int i=1;i<=n;++i){
        if(T[i-1] >= 2*k+1 && i-k >= 1 && i+k <= n){
            if(min(odpowiedz(1,potega,1,i-k,i-1),odpowiedz(1,potega,1,i+1,i+k)) >= k+1)
                return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;

    for(int i=0;i<n;++i){
        int x;
        cin >> x;

        T.push_back(x);
    }

    while(potega < n)
        potega *= 2;
    
    for(int i=1;i<=n;++i){
        segtree[potega+i-1] = T[i-1];
        aktualizacja(potega+i-1);
        
    }

    int l = 0, r = n/2;
    int mid = (r + l)/2;
    while(l <= r){
        mid = (r + l)/2;
        if(sprawdz(mid,n))
            l = mid+1;
        else
            r = mid-1;
    }

    cout << l-1 << '\n';
    return 0;
    }