#include <iostream>

using namespace std;

const int MAXN = 2e5 + 5;
int tab[MAXN];

int main(){
    int k;
    cin >> k;

    for(int i=0;i<k;++i){
        int n;
        cin >> n;

        for(int i=0;i<n;++i)
            cin >> tab[i];
        int l=0,r=0;
        int s = 1;
        long long ans = 0;
        while(r < n){
            while(tab[r] < s){
                --s;
                ++l;
            }
            if(tab[r] >= s){
                ans += (r - l + 1);
            }
            ++r;
            ++s;
        }
        cout << ans << '\n';
    }
    return 0;
}