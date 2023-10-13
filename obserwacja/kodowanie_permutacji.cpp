#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
vector<int> permutation;
vector<int> answer;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for(int i=0;i<n;++i){
        int x;cin >> x;
        a.push_back(x);
    }
    bool isit = true;
    for(int i=n-1;i>=0;--i){
        if(i - a[i] < 0)
            isit = false;
    }
    if(isit == false){
        cout << "NIE\n";
        return 0;
    }

    for(int i=1;i<=n;++i){
        permutation.push_back(i);
    }
    for(int i=n-1;i>=0;--i){
        int akt = a[i];
        answer.push_back(permutation[permutation.size()-1-akt]);
        permutation.erase(permutation.begin() + permutation.size()-1-akt);
    }
    for(int i=answer.size()-1;i>=0;i--)
        cout << answer[i] << '\n';
    return 0;
}