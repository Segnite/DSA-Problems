#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 4e5+5;
const int INF = 1e9 + 5;

vector<int> T;
int H[MAXN];


bool sprawdz(int k,int n){
    for(int i=1;i<=n;++i){
        H[i] = H[i-1];
        if(T[i-1] < k+1){
            H[i] += 1;
        }
    }

    // for(int i=1;i<=n;++i){
    //     cout << H[i] << ' ';
    // }
    // cout << '\n' << '\n' << '\n';

    for(int i=1;i<=n;++i){
        if(T[i-1] >= 2*k+1 && i-k >= 1 && i+k <= n){
            if(H[i+k]-H[i-k-1] <= 0)
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