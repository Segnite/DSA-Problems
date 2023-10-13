#include <iostream>
#include <algorithm>

using namespace std;

int tab[500000+5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;++i)
        cin >> tab[i];
    
    sort(tab,tab+n);
    int answer = 0;
    for(int i=0;i<n-2;++i)
    {
        if(tab[i+2] - tab[i] <= 1)
        {
            ++answer;
            i += 2;
        }
    }
    cout << answer << '\n';
    return 0;
}