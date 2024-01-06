//O(n + n)
//to do: R nie wystąpiło nigdzie indziej w słowie S′, to przyjmujemy c = a.
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;
typedef long long ll;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
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
string text2;
long long diff=0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> a >> b;

    // for(int i=0;i<26;++i){
    //     cout << alfabet[i] << ' ';
    // }

    cin >> text;
    text2 = text;

    string prefix;
    
    for(int i=0;i<=n-k-1;++i){
        if(i+k-1 > n-1){
            prefix = text.substr(i,text.size()-i);
        }
        else
            prefix = text.substr(i,k);
        // cout << prefix << '\n';
        h_map[{prefix,text[i+k]}] += 1;
    }

    string suffix_wanted = text.substr(n-k,k);
    string suffix;

    
    bool isittrue1 = false;
    for(int i=0;i<26;++i){
        // cout << h_map[{suffix_wanted,alfabet[i]}] << '\n';
        if(h_map[{suffix_wanted,alfabet[i]}] > 0){
            isittrue1 = true;
        }
    }
    string text3;
    bool isittrue = false;
    if(isittrue1 == false){
        isittrue = false;
        for(int i=0;i<k+1;++i){
            string suffixx;
            text3 = text;
            text3 += "a";

            suffixx = text3.substr(text3.size()-k,k);
            for(int j=0;j<26;++j){
                if(h_map[{suffixx,alfabet[j]}] > 0){
                    isittrue = true;
                }
            }
            if(isittrue == true){
                break;
            }
        }
        if(isittrue == false){
            for(long long i=a-n;i<=b-n;++i){
                std::cout << 'a';
            }
            std::cout << '\n';
            return 0;
        }
    }

    if(isittrue == true)
        text = text3;
    //case: we can find the suffix in the text
    suffix_wanted = text.substr(text.size()-k,k);
    do {
        suffix = text.substr(text.size()-k,k);

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
    } while(text.substr(text.size()-k,k) != suffix_wanted);
    // cout << difference << '\n';
    // cout << text << '\n';
    // cout << text2 <<  '\n';
    diff = (text.size() - text2.size());
    string temp = "";
    int ans = (1000000 / diff) + 1;
    // cout << ans << '\n';
    for(int i=1;i<=ans;++i){
        temp += text.substr(text.size()-diff,diff);
    }
    // for(int i=0;i<5;++i){
    //     cout << temp[i] << " ";
    // }
    // cout << endl;
    long long x,y;
    if(diff != 0)
        x = ((ll)a) % (ll)diff;
    else
        x = 0;
    
    y = (ll)b - (ll)a + (ll)1;
    // cout << k << ' ' << y << '\n';
    // cout << x << '\n';
    // cout << temp[x] << '\n';
    if(x == 0)
        x += 1;
    
    // for(int i=0;i<5;++i){
    //     cout << temp[i] << " ";
    // }
    // cout << endl;
    std::cout << (temp.substr((ll)x-(ll)1,(ll)y)) << '\n';    
    
    return 0;
}