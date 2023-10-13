//to change!
#include <bits/stdc++.h>

using namespace std;

int tab[1000*100];

int main(){
    int n,t;
    cin >> n >> t;

    for(int i=0;i<n;++i)
        cin >> tab[i];

    int l=0,r=-1;
    int max_size = 0;
    int sum = 0;

    
    while(r < n){
        if(sum <= t){
            max_size = max(max_size,r-l+1);
            ++r;
            sum += tab[r];
        }
        while(sum > t){
            sum -= tab[l];
            ++l;
        }
    }

    cout << max_size << '\n';
    return 0;
}