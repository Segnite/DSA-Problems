#include "stdio.h"

using namespace std;

int sum(int num){
    int whole = 0;
    while(num){
        whole += num % 10;
        num /= 10;
    }
    return whole;
}

int main(){
    int k;
    scanf("%d",&k);

    int counter = 10;
    while(k){
        counter += 9;
        if(sum(counter) == 10)
            --k;
    }
    
    printf("%d",counter);
    return 0;
}