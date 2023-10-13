#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 250 + 8;
int n,r;
int prefix_sum[maxn][maxn],W[maxn][maxn];
bool a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin >> prefix_sum[i][j];
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            prefix_sum[i][j] += prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
        }
    }
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=n;++j){
    //         cout << prefix_sum[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            a = b = false;
            if(i + r <= n && j + r <= n)
                W[i][j] = prefix_sum[i+r][j+r];
            else if(i + r <= n){
                W[i][j] = prefix_sum[i+r][n];
            }
            else if(j + r <= n){
                W[i][j] = prefix_sum[n][j+r];
            }
            else
                W[i][j] = prefix_sum[n][n];

            if(i-r > 1 && j+r <= n){
                W[i][j] -= prefix_sum[i-r-1][j+r];
                a = true;
            }
            else if(i-r > 1){
                W[i][j] -= prefix_sum[i-r-1][n];
                a = true;
            }
            
            if(j-r>1 && i + r <= n){
                W[i][j] -= prefix_sum[i+r][j-r-1];
                b = true;
            }
            else if(j-r>1){
                W[i][j] -= prefix_sum[n][j-r-1];
                b=true;
            }

            if(i-r>1 && j-r>1 && a == true && b == true){
                W[i][j] += prefix_sum[i-r-1][j-r-1];

            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout << W[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}