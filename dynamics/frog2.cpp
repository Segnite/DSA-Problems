#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> h(n+1),dp(n+1);
    for(int i=0;i<n;++i)
        cin >> h[i];
    
    fill(dp.begin(),dp.end(),1e9+5);
    dp[0] = 0;
    for(int i=0;i<n;++i)
        for(int j=i+1;j<=i+k;++j)
        {
            if(j <= n)
                dp[j] = min(dp[j],abs(h[i] - h[j]) + dp[i]);
        }

    cout << dp[n-1] << '\n';
    return 0;
}