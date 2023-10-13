#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> texts;
unordered_map<string,int> prefix;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i=0;i<n;++i){
        string x;
        cin >> x;

        texts.push_back(x);
    }

    for(int i=0;i<n;++i){
        prefix[texts[i]]++;
    }
    int answer = 0;
    for(int i=0;i<n;++i){
        string act = texts[i];
        int act_answer = 0;
        for(int j=0;j<=act.size();++j){
            string ss = act.substr(0,j);
            //cout << ss << ' ';
            if(prefix.find(ss) != prefix.end()){
                act_answer += prefix[ss];
            }
        }
        answer = max(answer,act_answer);
        //cout << '\n';
    }
    cout << answer << '\n';
    return 0;
}