//100 pkt
#include <iostream>
#include <deque>
#include <utility>
#include <cstdio>

using namespace std;

deque<pair<int,int>> kolejka;
pair<int,int> tab[1000000+3];

inline void push_(int x,int idx){
    while(!kolejka.empty() && kolejka.back().first < x)
        kolejka.pop_back();
    
    kolejka.push_back(make_pair(x,idx));
}

inline void pop_(int idx){
    if(!kolejka.empty() && kolejka.front().second == idx)
        kolejka.pop_front();
}

inline int get_maximum_(){
    if(kolejka.empty())
        return -1e9-5;
    return kolejka.front().first;;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;

    for(int i=0;i<n;++i){
        cin >> tab[i].first;
        cin >> tab[i].second;
    }
    push_(tab[0].first,0);
    int l=0,r=1;
    int wynik=1;
    while(r < n){
        while(get_maximum_() > tab[r].second){
            pop_(l);
            ++l;
        }
        if(l > r){
            ++r;
        }
        if(get_maximum_() <= tab[r].second){
            wynik = max(wynik,r - l + 1);
            push_(tab[r].first,r);
        }
        
        ++r;
    }
    printf("%d",wynik);

    return 0;
}