#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXN = 600 + 7;
const int MAXK = 50 + 7;
const int INF = 2e9 + 7;
int stacje[MAXN][MAXN];
int pref[MAXN][MAXN];
int dp[MAXN][MAXK];
int poprz[MAXN][MAXK];
int n, k;

int sumaNaProstokacie(int i1,int j1,int i2,int j2){
    int wyn = pref[i2][j2] - pref[i1-1][j2] - pref[i2][j1-1] + pref[i1-1][j1-1];
    return wyn;
}

//ile pasazerow wsiadlo pomiedzy stacjami a oraz b wlacznie
//a wysiadlo po stacji b
int pasazerowie(int a,int b){
    int wyn = sumaNaProstokacie(a,b+1,b,n);
    return wyn;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j){
            int x;
            cin >> x;
            stacje[i][j] = x;
        }
    
    //sumy prefiksowe 2d
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + stacje[i][j];
        }
    
    //idk
    for(int i=1;i<=k;++i)
        dp[0][i] = -INF;
    dp[0][0] = 0;

    for(int i=1;i<n;++i){
        for(int kontr=1;kontr<=k;++kontr){
            for(int j=i-1;j>=0;--j){
                int wyn = dp[j][kontr-1] + pasazerowie(j+1,i);

                if(wyn > dp[i][kontr])
                {
                    dp[i][kontr] = wyn;
                    poprz[i][kontr] = j;
                }
            }
        }
    }

    int maxi = 0;
    for(int i=1;i<=n;++i)
        if(dp[i][k] > dp[maxi][k])
            maxi = i;
    
    vector<int> kontrole;
    int ind = maxi;
    for(int ileKontroli = k;ileKontroli > 0;ileKontroli--){
        kontrole.push_back(ind);
        ind = poprz[ind][ileKontroli];
    }

    for(int i=kontrole.size()-1;i>=0;i--)
        cout << kontrole[i] << ' ';
    cout << '\n';
    return 0;
}