//Żaba skacze o 1 lub 2 w prawo. Zlicz możliwe ścieżki
#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> dp(n+1,0);
    dp[1] = 1;
    for(int i=2;i<=n;++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    std::cout << dp[n] << '\n';
    return 0;
}