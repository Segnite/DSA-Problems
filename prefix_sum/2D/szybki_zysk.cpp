#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 7;
int arr_z[MAXN][MAXN];
int arr_n[MAXN][MAXN];
int zeros[MAXN][MAXN];
int negs[MAXN][MAXN];
void compute_sums(int S[][MAXN], int A[][MAXN], int n, int m) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i][j];
        }
    }
}
int get_sum(int S[][MAXN], int r1, int c1, int r2, int  c2) {
    return S[r2][c2] - S[r1 - 1][c2] - S[r2][c1 - 1] + S[r1 - 1][c1 - 1];
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int a;
            cin >> a;
            arr_z[i][j] = (a == 0);
            arr_n[i][j] = (a < 0);
        }
    }
    compute_sums(zeros, arr_z, n, m);
    compute_sums(negs, arr_n, n, m);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (get_sum(zeros, r1, c1, r2, c2))
            cout << "0\n";
        else if (get_sum(negs, r1, c1, r2, c2) % 2 == 1)
            cout << "-1\n";
        else
            cout << "1\n";
    }
    return 0;
}