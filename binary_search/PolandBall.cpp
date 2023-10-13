#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string,bool> unmap;

int main(){
    int a,b;
    cin >> a >> b;

    int duplicated = 0;

    string text {};
    for(int i=0;i<a;++i){
        cin >> text;
        unmap[text] = 1;
    }
    for(int i=0;i<b;++i){
        cin >> text;
        if(unmap[text] == 1)
            duplicated++;
    }
    a -= duplicated;
    b -= duplicated;

    if(duplicated % 2 != 0){
        if(a == b)
            cout << "YES" << '\n';
        else if(a > b)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    else{
        if(a == b)
            cout << "NO" << '\n';
        else if(a > b)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}