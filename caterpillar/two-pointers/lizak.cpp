#include <bits/stdc++.h>
// #define ll long long
using namespace std;
vector<int> a;
map<int,int> zlicz;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    int maxi = 0;
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        a.push_back(x);
        maxi = max(maxi,x);
    }
    int l=0,r=0;
    int s=5e5+5;
    while(r < n){
        zlicz[a[r]] += 1;
        while(zlicz[a[r]] == 3){
            s = min(s,r - l + 1);
            zlicz[a[l]] -= 1;
            ++l;
        }
        ++r;
    }
    if(s == 5e5+5)
        cout << "NIE" << '\n';
    else
        cout << s << '\n';
    return 0;
}