#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>
using namespace std;

const int maxn = 1e6 + 5;
int segment_tree[maxn * 3];
int power = 2;
int idx[maxn];
unordered_map<char,deque<int>> hashmap;

void actualization(int v){
    v /= 2;
    while(v > 0){
        segment_tree[v] = segment_tree[v*2] + segment_tree[v*2+1];
        v /= 2;
    }
}

int ans(int pp,int kp,int v,int a,int b){
    if(kp < a || b < pp)
        return 0;
    
    if(a <= pp && kp <= b)
        return segment_tree[v];
    
    return ans(pp,(pp+kp)/2,v*2,a,b) + ans((pp+kp)/2+1,kp,v*2+1,a,b);
}

int main(){
    int n;
    cin >> n;

    string a,b;
    cin >> a >> b;

    while(power < n)
        power *= 2;

    long long inversions = 0;
    int x;
    for(int i=0;i<n;++i){
        hashmap[a[i]].push_back(i);
    }
    for(int i=0;i<n;++i){
        int akt = hashmap[b[i]].front();
        hashmap[b[i]].pop_front();

        idx[i] = akt;
    }
    for(int i=n-1;i>=0;--i){
        inversions += (long long)ans(0,power-1,1,0,idx[i]-1);
        segment_tree[power+idx[i]] = 1;
        actualization(power+idx[i]);
        
    }
    cout << inversions << '\n';
    return 0;
}