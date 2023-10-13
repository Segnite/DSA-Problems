#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;

    long long suma = 0;

    for(long long i=1;i<=a;++i){
        for(long long j=1;j<=b;++j){
            suma += i * j *(a-i+1) * (b-j+1);
        }
    }
    cout << suma << '\n';
    return 0;
}