#include <iostream>

using namespace std;

bool oblicz(long long mid, long long m,long long n){
    long long ob = 1;
    for(int i=0;i<m;++i)
    {    
        if(ob * mid > n)
            return true;
        ob *= mid;
    }
    if(ob > n)
        return true;
    else
        return false;
}

long long bs(long long n,long long m){
    long long l=-1,r=n;
    long long mid;
    while(r - l > 1){
        mid = (l + r) / 2;
        if(oblicz(mid,m,n))
            r = mid;
        else
            l = mid;
    }
    return l;
}

int main(){
    int T;
    cin >> T;

    for(int i=0;i<T;++i){
        long long n,m;
        cin >> n >> m;
        if(m == 1)
            cout << n << '\n';
        else if(n == 1)
            cout << 1 << '\n';
        else{
            long long a = bs(n,m);
            cout << a << '\n';
        }
    }
    return 0;
}