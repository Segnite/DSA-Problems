#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> kamyczki;

int main(){
    int n;
    cin >> n;
    kamyczki.push_back(0);
    for(int i=0;i<n;++i){
        int x;
        cin >> x;

        kamyczki.push_back(x);
    }

    sort(kamyczki.begin(),kamyczki.end());
    int maxi=1e9+5;
    int sizee = kamyczki.size();
    for(int i=0;i<=n;++i){
        maxi = min(maxi,kamyczki[i] + (sizee-i-1));
    }
    cout << maxi << '\n';
    return 0;
}