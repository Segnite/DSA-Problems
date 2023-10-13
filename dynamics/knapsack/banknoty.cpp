#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 2e4+5;
vector<int> b;
vector<int> u;
int use[maxn];
int zlicz[maxn];

int used_before[maxn];
int number_of_banknotes[maxn];
int use_of_current[maxn];

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;++i){
        int x;
        cin >> x;

        b.push_back(x);
    }
    for(int i=0;i<n;++i){
        int act = b[i];

        u.push_back(act);
    }
    for(int i=0;i<n;++i){
        int act;
        cin >> act;

        use[b[i]] = act;
    }
    int k;
    cin >> k;
    sort(b.begin(),b.end());
    fill(number_of_banknotes+1,number_of_banknotes+maxn,1e9);
    for(int i=b.size()-1;i>=0;--i){
        for(int j=0;j<k;++j){
            if((j + b[i] <= k) && (use_of_current[j] < use[b[i]]) && (number_of_banknotes[j+b[i]] > number_of_banknotes[j]+1)){
                int akt = j + b[i];
                used_before[akt] = b[i];
                number_of_banknotes[akt] = number_of_banknotes[j] + 1;
                use_of_current[akt] = use_of_current[j] + 1;

            }
            use_of_current[j] = 0;
        }
    }
    int akt = k;
    while(akt > 0){
        zlicz[used_before[akt]]++;
        akt -= used_before[akt];
    }
    cout << number_of_banknotes[k] << '\n';
    for(auto i : u){
        cout << zlicz[i] << ' ';
    }
    return 0;
}