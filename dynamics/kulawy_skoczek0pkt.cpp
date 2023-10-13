#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e3+5;
int tab[maxn][maxn];
int answer[maxn][maxn];
// vector<vector<int>> tab;
// vector<vector<int>> answer;

int main(){
    int n;
    cin >> n;
    
    // tab.resize(n+5,vector<int>(n+5));
    // answer.resize(n+5,vector<int>(n+5));

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin >> tab[i][j];
            answer[i][j] = tab[i][j];
        }
    }
    int y=0;int x=0;
    // for(int i=0;i<n;++i){
    //     x = i;
    //     y=0;
    //     while(y < n && x >= 0){
    //         if(x + 2 < n && y + 1 < n)
    //             answer[y+1][x+2] = max(answer[y+1][x+2],tab[y+1][x+2] + answer[y][x]);
    //         if(x + 2 < n && y - 1 >= 0)
    //             answer[y-1][x+2] = max(answer[y-1][x+2],tab[y-1][x+2] + answer[y][x]);
            
    //         if(y + 2 < n && x + 1 < n)
    //             answer[y+2][x+1] = max(answer[y+2][x+1],tab[y+2][x+1] + answer[y][x]);
    //         if(y + 2 < n && x - 1 >= 0)
    //             answer[y+2][x-1] = max(answer[y+2][x-1],tab[y+2][x-1] + answer[y][x]);
            
    //         ++y;--x;
    //     }
    // }
    // for(int i=0;i<n;--i){
    //     y = i;
    //     x = n-1;
    //     while(x >=0 && y < n){
    //         if(x + 2 < n && y + 1 < n)
    //             answer[y+1][x+2] = max(answer[y+1][x+2],tab[y+1][x+2] + answer[y][x]);
    //         if(x + 2 < n && y - 1 >= 0)
    //             answer[y-1][x+2] = max(answer[y-1][x+2],tab[y-1][x+2] + answer[y][x]);
            
    //         if(y + 2 < n && x + 1 < n)
    //             answer[y+2][x+1] = max(answer[y+2][x+1],tab[y+2][x+1] + answer[y][x]);
    //         if(y + 2 < n && x - 1 >= 0)
    //             answer[y+2][x-1] = max(answer[y+2][x-1],tab[y+2][x-1] + answer[y][x]);
            
    //         ++y;--x;
    //     }
    // }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}