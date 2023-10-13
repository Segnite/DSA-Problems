#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
vector<pair<int,int>> a;
int power = 2;
int segment_tree[maxn * 3];
int maxi;

bool cmp(pair<int,int> x,pair<int,int> y){//punkt widzenia dla lewej
    if(x.first == y.first)
        return x.second > y.second;
    
    return x.first < y.first;
}

int answer(int pp,int kp,int v,int a,int b){
    if(kp < a || b < pp)
        return 0;
    
    if(a <= pp && kp <= b)
        return segment_tree[v];
    
    return max(answer(pp,(pp+kp)/2,v*2,a,b),answer((pp+kp)/2+1,kp,v*2+1,a,b));
}

void actualization(int v){
    v /= 2;
    while(v > 0){
        segment_tree[v] = max(segment_tree[v*2],segment_tree[v*2+1]);
        v /= 2;
    }
}

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;++i){
        int x;
        cin >> x;

        a.push_back({x,i});
    }

    sort(a.begin(),a.end(),cmp);

    //for(auto b : a)
    //    cout << b.first << ' ' << b.second << '\n';

    while(power < n)
        power *= 2;
    //cout << potega;
    
    for(int i=0;i<a.size();++i){
        maxi = answer(0,power-1,1,0,a[i].second);
        maxi += a[i].first;
        //cout << maxi << '\n';

        segment_tree[power + a[i].second] = maxi;
        actualization(power + a[i].second);
    }
    cout << segment_tree[1] << '\n';
    return 0;
}