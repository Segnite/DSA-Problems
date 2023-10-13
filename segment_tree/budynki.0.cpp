#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e5;
int segment_tree[maxn * 10];
vector<int> height;
int power = 2;

int odpowiedz(int pp,int kp,int v,int a,int b){
    if(kp < a || b < pp)
        return 0;
    
    if(a <= pp && kp <= b){
        return segment_tree[v];
    }

    return odpowiedz(pp,(pp+kp)/2,v*2,a,b) + odpowiedz((pp+kp)/2+1,kp,v*2+1,a,b);
}

void aktualizacja(int v){
    v /= 2;
    while(v > 0){
        segment_tree[v] = segment_tree[v*2] + segment_tree[v*2+1];
        v /= 2;
    }
}

int main(){
    int n,k;
    cin >> n >> k;

    for(int i=0;i<n;++i){
        int x;
        cin >> x;

        height.push_back(x);
    }

    while(power < n)
        power *= 2;

    for(int i=0;i<n-2;++i){
        if(height[i+1] > height[i+2] && height[i+2] > height[i])
        {
            segment_tree[power+i] = 1;
            aktualizacja(power+i);
        }
    }

    for(int i=0;i<k;++i){
        int q;
        cin >> q;
        if(q == 2){
            int a,b;
            cin >> a >> b;
            a--;
            height[a] = b;
            if(0 <= a && a <= n - 3){
                if(height[a+1] > height[a+2] && height[a+2] > height[a]){
                    segment_tree[power+a] = 1;
                    aktualizacja(power+a);
                }
                else{
                    segment_tree[power+a] = 0;
                    aktualizacja(power+a);
                }
            }

            if(1 <= a && a <= n-2){
                if(height[a] > height[a+1] && height[a+1] > height[a-1]){
                    segment_tree[power+a-1] = 1;
                    aktualizacja(power+a-1);
                }
                else
                {
                    segment_tree[power+a-1] = 0;
                    aktualizacja(power+a-1);
                }
            }

            if(2 <= a && a <= n-1){
                if(height[a-1] > height[a] && height[a] > height[a-2]){
                    segment_tree[power+a-2] = 1;
                    aktualizacja(power+a-2);
                }
                else{
                   segment_tree[power+a-2] = 0;
                   aktualizacja(power+a-2);
               }
            }
        }
        else{
            int a,b;
            cin >> a >> b;
            --a;--b;
            if(b - a + 1 < 3)
                cout << "0" << '\n';
            else
                cout << odpowiedz(0,power-1,1,a,b-2) << '\n';
        }
    }
    return 0;
}