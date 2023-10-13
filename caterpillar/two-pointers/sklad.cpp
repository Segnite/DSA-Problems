#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

vector<int> arr;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n >> k;

    for(int i=0;i<n;++i){
        int x;
        cin >> x;

        arr.pb(x);
    }

    int l=0,r=0;
    int sum = 0;
    int s = 2e6+5;
    while(r < n){
        sum += arr[r];
        while(sum > k){
            sum -= arr[l];
            ++l;
        }

        if(sum == k)
            s = min(s,r - l + 1);
        ++r;
    }
    if(s == 2e6+5)
        cout << 'N' << '\n';
    else
        cout << s << '\n';
    return 0;
}