#include <iostream>
#include <utility>

using namespace std;

const int maxn = 1508;
char tab[maxn][maxn];
int dp_overall[maxn][maxn];
int dp_left[maxn][maxn];
int dp_up[maxn][maxn];

int dp_overall2[maxn][maxn];
int dp_right[maxn][maxn];
int dp_down[maxn][maxn];
int n,m;

bool the_same(int s,int times,int counter1=1,int counter2=1) {
    pair<int,int> pos1,pos2;
    bool isit=true;
    if(times == 1)
    {    
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dp_up[i][j] == s || dp_left[i][j] == s)
                    {
                        pos1 = {i,j};
                        isit = false;
                        break;
                    }
            }
            if(isit == false)
                break;
        }
        if(isit)
            return false;
        isit = true;
        
        for(int i=n;i>=1;--i){
            for(int j=n;j>=1;--j){
                if(dp_down[i][j] == s || dp_right[i][j] == s)
                    {
                        pos2 = {i,j};
                        isit = false;
                        break;
                    }
            }
            if(isit == false)
                break;
        }

        if(isit)
            return false;
    }
    else if(times == 2){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dp_up[i][j] == s || dp_left[i][j] == s)
                    {
                        pos1 = {i,j};
                        isit = false;
                        break;
                    }
            }
            if(isit == false)
                break;
        }
        if(isit)
            return false;
        isit = true;
        
        int starter1=1;
        int starter2=1;
        for(int i=n;i>=1;--i){
            for(int j=n;j>=1;--j){
                if(dp_down[i][j] == s || dp_right[i][j] == s)
                {
                    if(counter2 == starter2){
                        isit= false;
                        pos2 = {i,j};
                        break;
                    }
                    starter2++;
                }
            }
            if(isit == false)
                break;
        }

        if(isit)
            return false;
    }
    else if(times == 3){
        int starter1=1;
        int starter2=1;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dp_up[i][j] == s || dp_left[i][j] == s)
                    {
                        pos1 = {i,j};
                        if(starter1 == counter1){
                            isit = false;
                            break;
                        }
                        ++starter1;
                    }
            }
            if(isit == false)
                break;
        }
        if(isit)
            return false;
        isit = true;
        
        for(int i=n;i>=1;--i){
            for(int j=n;j>=1;--j){
                if(dp_down[i][j] == s || dp_right[i][j] == s)
                    {
                        pos2 = {i,j};
                        isit = false;
                        break;
                    }
            }
            if(isit == false)
                break;
        }

        if(isit)
            return false;
    }
    else if(times == 4){
        int starter1=1;
        int starter2=1;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dp_up[i][j] == s || dp_left[i][j] == s)
                    {
                        if(starter1 == counter1){
                            pos1 = {i,j};
                            isit = false;
                            break;
                        }
                        ++starter1;
                    }
            }
            if(isit == false)
                break;
        }
        if(isit)
            return false;
        isit = true;
        
        starter1=1;
        starter2=1;
        for(int i=n;i>=1;--i){
            for(int j=n;j>=1;--j){
                if(dp_down[i][j] == s || dp_right[i][j] == s)
                    {
                        if(counter2 == starter2){
                            pos2 = {i,j};
                            isit = false;
                            break;
                        }
                        ++starter2;
                    }
            }
            if(isit == false)
                break;
        }

        if(isit)
            return false;
    }

    //1 Case: pos1-> | pos2-> |
    if(dp_up[pos1.first][pos1.second] == s && dp_down[pos2.first][pos2.second] == s){
        
        int start1,start2,end1,end2;
        int start3,start4,end3,end4;

        start2 = pos1.first;
        start1 = pos1.second;
        end2 = pos1.first - s + 1;
        end1 = pos1.second;

        start4 = pos2.first;
        start3 = pos2.second;
        end4 = pos2.first + s - 1;
        end3 = pos2.second;

        if(start1 == end3 && start2 == end4 && start3 == end1 && start4 == end2){
            return false;
        }

        if(start1 < start3 || end3 < end1 || end4 < end2 || start2 < start4){
            return true;
        }
    }
    //2 Case: pos1-> | pos2-> -
    else if(dp_up[pos1.first][pos1.second] == s && dp_right[pos2.first][pos2.second] == s){
        int start1,start2,end1,end2;
        int start3,start4,end3,end4;

        start2 = pos1.first;
        start1 = pos1.second;
        end2 = pos1.first - s + 1;
        end1 = pos1.second;

        start4 = pos2.first;
        start3 = pos2.second;
        end4 = pos2.first;
        end3 = pos2.second + s - 1;

        if(start4 < end2 || end1 < start3 || start2 < start4 || end3 < end1){
            return true;
        }
    }
    //3 Case: pos1-> - pos2-> |
    else if(dp_left[pos1.first][pos1.second] == s && dp_down[pos2.first][pos2.second] == s){
        int start1,start2,end1,end2;
        int start3,start4,end3,end4;

        start2 = pos1.first;
        start1 = pos1.second;
        end2 = pos1.first;
        end1 = pos1.second - s + 1;

        start4 = pos2.first;
        start3 = pos2.second;
        end4 = pos2.first + s - 1;
        end3 = pos2.second;

        if(end4 < end2 || start1 < start3 || end2 < start4 || start3 < end1){
            return true;
        }
    }
    //4 Case: pos1-> - pos2-> -
    else if(dp_left[pos1.first][pos1.second] == s && dp_right[pos2.first][pos2.second] == s){
        int start1,start2,end1,end2;
        int start3,start4,end3,end4;

        start2 = pos1.first;//pos1 {i,j} , start1 -> j, start2 -> i ; end1 -> j, end2-> i;
        start1 = pos1.second;
        end2 = pos1.first;
        end1 = pos1.second - s + 1;

        start4 = pos2.first;
        start3 = pos2.second;
        end4 = pos2.first;
        end3 = pos2.second + s - 1;

        if(start1 == end3 && start2 == end4 && start3 == end1 && start4 == end2){
            return false;
        }
        
        if(start1 < start3 || end3 < end1 || start4 < start2 || start2 < start4){
            return true;
        }
    }

    
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin >> tab[i][j];
        }
    }
    
    //dp1
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(tab[i][j] == '.'){
                dp_left[i][j] = dp_left[i][j-1] + 1;
                dp_up[i][j] = dp_up[i-1][j] + 1;
                dp_overall[i][j] = max(dp_up[i][j],dp_left[i][j]);
            }
        }
    }
    if(m == 1){
        //m=1
        int maxi=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                maxi = max(maxi,dp_overall[i][j]);
            }
        }
        cout << maxi << '\n';}
    else if(m == 2){
        //dp for m=2
        for(int i=n;i>=1;--i){
            for(int j=n;j>=1;--j){
                if(tab[i][j] == '.'){
                    dp_right[i][j] = dp_right[i][j+1] + 1;
                    dp_down[i][j] = dp_down[i+1][j] + 1;
                    dp_overall2[i][j] = max(dp_right[i][j],dp_down[i][j]);
                }
            }
        }
        //binary search by answer
        int l=0,r=n+1;
        int mid;
        while(r-l>=1) {
            mid = (l + r + 1)/2;
            if(the_same(mid,1) || the_same(mid,2,1,2) || the_same(mid,3,2,1) || the_same(mid,4,2,2) || the_same(mid,4,3,2) || the_same(mid,4,4,3) || the_same(mid,4,3,4) || the_same(mid,4,4,4) || the_same(mid,4,5,4) || the_same(mid,4,4,5) || the_same(mid,4,5,5) || the_same(mid,4,6,5) || the_same(mid,4,5,6) || the_same(mid,4,6,6) || the_same(mid,4,6,7)  || the_same(mid,4,7,6) || the_same(mid,4,7,7) || the_same(mid,4,7,8) || the_same(mid,4,8,7) || the_same(mid,4,8,8))
                l = mid;
            else
                r = mid-1;
        }

        if(l == 0)
            cout << 0 << '\n';
        else
            cout << l << '\n';
    }
    else{
        cout << 0 << '\n';
    }
    return 0;
}