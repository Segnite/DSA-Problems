#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;
int poczatek[maxn];
int koniec[maxn];
std::vector<int> bracia;
std::vector<int> preprocessing;
vector<int> dp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    bracia.push_back(0);

    for(int i=1;i<=n;++i){
        int x;
        std::cin >> x;

        bracia.push_back(x);
    }

    //poczatek dla bracia
    for(int i=1;i<=maxn;++i)
        poczatek[i] = -1;
    
    for(int i=1;i<=n;++i)
        if(poczatek[bracia[i]] == -1)
            poczatek[bracia[i]] = i;
    
    //koniec dla bracia
    for(int i=1;i<=maxn;++i)
        koniec[i] = -1;
    
    for(int i=n;i>=1;--i)
        if(koniec[bracia[i]] == -1)
            koniec[bracia[i]] = i;
    
    //preprocessing 3 2 4 2 5 - > 3 3 2 4 4 2 5 5
    preprocessing.push_back(0);
    for(int i=1;i<=n;++i){
        if(poczatek[bracia[i]] == koniec[bracia[i]])
        {
            preprocessing.push_back(bracia[i]);
            preprocessing.push_back(bracia[i]);
        }
        else if(poczatek[bracia[i]] == i || koniec[bracia[i]] == i)
            preprocessing.push_back(bracia[i]);
    }

    //poczatek dla preprocessing
    for(int i=1;i<=maxn;++i)
        poczatek[i] = -1;
    
    for(int i=1;i<=preprocessing.size()-1;++i)
        if(poczatek[preprocessing[i]] == -1)
            poczatek[preprocessing[i]] = i;
    
    //koniec dla preprocessing
    for(int i=1;i<=maxn;++i)
        koniec[i] = -1;
    
    for(int i=preprocessing.size()-1;i>=1;--i)
        if(koniec[preprocessing[i]] == -1)
            koniec[preprocessing[i]] = i;
    
    //dp
    dp.resize(preprocessing.size());//rezerwuję dopiero jak wiem ile ma preprocessing wielkości
    dp[0] = 0;
    for(int i=1;i<=preprocessing.size()-1;++i){
        if(i == koniec[preprocessing[i]])
            dp[i] = max(dp[poczatek[preprocessing[i]]] + 1,dp[i-1]);
        else
            dp[i] = dp[i-1];
    }

    cout << dp[preprocessing.size()-1] << '\n';
    return 0;
}
//7
//3 2 4 5 5 2 5
