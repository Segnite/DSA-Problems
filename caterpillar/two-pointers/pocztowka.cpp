#include <iostream>

int tab[1000000+5];
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;++i)
        cin >> tab[i];
    
    int l=0,r=0;
    int counter = 0;
    while(r < n){
        while(tab[l] < m){
            ++l;
        }
        if(tab[r] >= m || r >= l){
            counter += r - l + 1;
        }
        ++r;
    }
    cout << counter << '\n';
    return 0;
}