#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 5;
int arr[MAXN];
int distances[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int size_,queries;
    cin >> size_ >> queries;
    for(int i=0;i<size_;++i){
        cin >> arr[i];
    }
    //Na wypadek jakby n = 1 to wtedy maksymalny dystans 1 jest równy 1. Natomiast ostatni element zawsze ma długośc 1
    distances[0] = distances[size_ -1] = 1; 
    int l=0,r=1;
    int sum = arr[1] - arr[0];
    while(r < size_){
        while(arr[r+1] - arr[r] != sum){
            distances[l] = r - l + 1;
            ++l;
            sum = arr[l + 1] - arr[l];
        }
        ++r;
    }
    // for(int i=0;i<size_;++i)
    //     cout << distances[i] << ' ';
    for(int i=0;i<queries;++i){
        int left,right;
        cin >> left >> right;

        int border = left - 1 + distances[left-1];
        if(right <= border)
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }
    return 0;
}