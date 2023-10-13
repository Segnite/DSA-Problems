#include <iostream>

using namespace std;

int tab[300000+5];

int bsup(int x,int n){
    int l=-1,r=n;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(tab[mid] >= x)
            r = mid;
        else
            l = mid;
    }
    return r;
}
int bsdown(int x,int n){
    int l=-1,r=n;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(tab[mid] <= x)
            l = mid;    
        else
            r = mid;
    }
    
    return l;
}



int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;++i){
        cin >> tab[i];
    }
    for(int i=0;i<m;++i){
        int k;
        cin >> k;
        if(tab[0] > k)
            cout << tab[bsup(k,n)] - k << '\n';
        else if(tab[n-1] < k)
            cout << k - tab[bsdown(k,n)] << '\n';
        else
            cout << min(tab[bsup(k,n)] - k,k - tab[bsdown(k,n)]) << '\n';
    }
    return 0;
}