#include <iostream>
#include <string>

using namespace std;

string jas;
string malgosia;

int suma=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    cin >> jas;
    cin >> malgosia;

    for(int i=0;i<n;++i){
        char szukany = jas[i];

        int idx = 0;
        while(malgosia[idx] != szukany){
            ++idx;
        }
        suma += idx;
        malgosia.erase(malgosia.begin() + idx);
    }

    cout << suma << '\n';
    return 0;
}