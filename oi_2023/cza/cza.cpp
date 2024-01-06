//O(n + n)
//to do: R nie wystąpiło nigdzie indziej w słowie S′, to przyjmujemy c = a.
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <stdio.h>

using namespace std;
typedef long long ll;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash2 != hash1) {
            return hash1 ^ hash2;              
        }
         
          return hash1;
    }
};

const int maxn = 1e6+5;

char alfabet[26+4] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
unordered_map<pair<string,char>,long long,hash_pair> h_map;

int n,k;
long long a,b;
string text;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> a >> b;

    // for(int i=0;i<26;++i){
    //     cout << alfabet[i] << ' ';
    // }

    cin >> text;

    string prefix;
    
    for(int i=0;i<=n-k-1;++i){
        prefix = text.substr(i,k);
        // cout << prefix << '\n';
        h_map[{prefix,text[i+k]}] += 1;
    }

    
    string suffix;
    for(long long i=n-1;i<b-1;++i){
        suffix = text.substr(text.size()-1-k+1,k);

        //looking for a maximum
        pair<long long,char> maxi {0,'a'};
        for(int j=0;j<26;++j){
            if(h_map[{suffix,alfabet[j]}] > maxi.first){
                maxi.first = h_map[{suffix,alfabet[j]}];
                maxi.second = alfabet[j];
            }
            else if(h_map[{suffix,alfabet[j]}] == maxi.first)
            {
                if(maxi.second > alfabet[j])
                {
                    maxi.second = alfabet[j];
                }
            }
        }

        text += maxi.second;
        // cout << suffix << '\n';
        suffix = text.substr(text.size()-1-k,k);
        
        h_map[{suffix,maxi.second}] += 1;
    }

    int sizeofwanted = b - a + 1;
    // cout << text << '\n';
    cout << (text.substr(text.size()-sizeofwanted,sizeofwanted)) << '\n';
    getchar();
    return 0;
}