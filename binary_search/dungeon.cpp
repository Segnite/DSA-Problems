#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;++i){
        int a,b,c;
        cin >> a >> b >> c;

        long long sum = a + b + c;
        if(sum % 9 == 0 && min(a,min(b,c)) >= sum / 9)
            cout << "YES" << "\n";
        else
            cout << "NO" << '\n';

    }
    return 0;
}