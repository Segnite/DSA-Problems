#include <iostream>
#include <algorithm>
using namespace std;

int tab[100000+5];

int bsdown(int x,int n){
    int l = -1,r = n+1;
    int mid;
    while(r - l > 1){
        mid = (l + r) / 2;
        if(tab[mid] <= x)
            l = mid;
        else
            r = mid;
    }
    return l;
}

int bsup(int x,int n){
    int l = -1,r = n;
    int mid;
    while(r - l > 1){
        mid = (l + r) / 2;
        if(tab[mid] >= x)
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    for(int i=0;i<n;++i){
        cin >> tab[i];
    }
    int k;
    cin >> k;

    sort(tab,tab+n);

    for(int i=0;i<k;++i){
        int lp,rp;
        cin >> lp >> rp;

        cout << bsup(rp+1,n) - 1 - bsup(lp,n)  << '\n';
    }
    return 0;
}