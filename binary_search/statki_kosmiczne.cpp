//0 pkt
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
vector<int> b;
vector<int> c;
double k = 0;
int x,y,z;
// bool even = true;

void INPUT(){
    int n1;
    cin >> n1;
    int maxi = 0;
    for(int i=0;i<n1;++i){
        int test;
        cin >> test;
        
        maxi = max(maxi,test);
        a.push_back(test);
    }
    k += maxi * x;

    int n2;
    cin >> n2;
    maxi = 0;

    for(int i=0;i<n2;++i){
        int test;
        cin >> test;

        maxi = max(maxi,test);
        b.push_back(test);
    }
    k += maxi * y;

    int n3;
    cin >> n3;

    maxi = 0;
    for(int i=0;i<n3;++i){
        int test;
        cin >> test;

        maxi = max(maxi,test);
        c.push_back(test);
    }
    k += maxi * z;
    // if(k % 2 != 0)
    //     even = false;
    k /= 2;
}

int main(){

    cin >> x >> y >> z;

    INPUT();

    int answer = 0;
    int product = 1;

    sort(c.begin(),c.end());
    
    for(int i=0;i<a.size();++i){
        for(int j=0;j<b.size();++j){
            product = a[i] * b[j];

            int l=-1,r=c.size()-1;
            int mid;
            while(l < r){
                mid = (r + l) / 2;
                if(c[mid] * product <= k){
                    l = mid;
                }
                else{
                    r = mid - 1;
                }
            }
            if(l != -1){
                answer += l + 1;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}