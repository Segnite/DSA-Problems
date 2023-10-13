//to do!
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;++i){
        int n;char a;
        cin >> n >> a;

        string text;
        cin >> text;

        vector<int> array;
        for(int i=0;i<text.size();++i){
            if(text[i] == 'g')
                array.push_back(i);
        }
        int maxi = 0;
        for(int i=0;i<text.size();++i){
            if(text[i] != a)
                continue;
            
            int l = -1,r = array.size();
            while(r - l > 1){
                int mid = (l + r) / 2;
                if(array[mid] < i)
                    l = mid;
                else if(array[mid] >= i)
                    r = mid;
            }
            if(r == array.size()){
                int abc = text.size()-1 - i + array[0] + 1;
                maxi = max(maxi,abc);
            }
            else
                maxi = max(maxi,array[r] - i);
        }
        cout << maxi << '\n';
    }
    return 0;
}