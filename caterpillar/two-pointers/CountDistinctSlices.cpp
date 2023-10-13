#include <iostream>
#include <vector>
using namespace std;

int solution(int m,vector<int> &arr){
    long long sum = 0;
    vector<int> check(m+1,0);
    int l,r;
    l = 0;
    r = 0;

    while(r < arr.size()){

        while(check[arr[r]] == 1){
            check[arr[l]] = 0;
            ++l;
        }
        check[arr[r]] = 1;

        sum += (r - l) + 1;
        ++r;
    }
    if(sum > 1e9) sum = 1e9;
    return sum;
}

int main(){
    vector<int> wektor = {3,4,5,5,2};
    cout << solution(1e5,wektor);
    return 0;
}