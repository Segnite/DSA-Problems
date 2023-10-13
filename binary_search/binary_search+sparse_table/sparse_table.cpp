/*

https://swisscows.com/en/video?query=sparse+table

*/
#include <iostream>

using namespace std;

int main(){
    cout << (1<<2);//1 to power 2;
    //compute->
    //for(int j=1;j..log-1)
        // for(int i=0;i + (1 << j)-1 < n;++i){
        //     m[i][j] = min(m[i][j],m[i+(1<<(j-1))][j-1]);
        // }
    return 0;
}