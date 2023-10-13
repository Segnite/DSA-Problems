#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> fib(n+1);
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2;i<=n;++i)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000000000000000;
    }
    cout << fib[n] << '\n';
    return 0;
}