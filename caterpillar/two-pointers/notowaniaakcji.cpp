#include <iostream>

using namespace std;

const int MAXN = 5e5 + 5;

int arr[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;

    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        
        if(k == 1)
        {
            cout << n << '\n';
            continue;
        }

        int l=0,r=0;
        int s=1;
        int pairs=0;
        while(r < n){
            if(s <= k)
            {
                ++r;
                ++s;
            }
            if(s > k)
            {
                ++l;
                --s;
            }
            if(arr[r] <= arr[r-1])
            {
                l = r;
                s = 1;
            }
            if(k == s)
                ++pairs;
        }
        cout << pairs << '\n';
    }
    return 0;
}