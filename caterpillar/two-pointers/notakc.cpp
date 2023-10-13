#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 500005;

int n;
int ciag[MAX_N];
vector<int> oblicz_ile_nieprzedluzalne()
{
    vector<int> ile_nieprzedluzalne(n + 1, 0);
    int aktualna_dlugosc = 1;
    for (int i = 0; i < n; i++)
    { // na koncu porownamy sie z ciag[n+1], ktory jest zerem
        if (ciag[i] < ciag[i + 1])
            aktualna_dlugosc++;
        else
        {
            ile_nieprzedluzalne[aktualna_dlugosc]++;
            aktualna_dlugosc = 1;
        }
    }
    return ile_nieprzedluzalne;
}
vector<int> sumuj_wyniki(const vector<int> &ile_nieprzedluzalne)
{
    vector<int> wyniki(n + 2, 0);
    int suma = 0;
    for (int i = n; i >= 1; --i)
    { // na poczatku wyniki[n+1] jest 0
        suma += ile_nieprzedluzalne[i];
        wyniki[i] = wyniki[i + 1] + suma;
    }
    return wyniki;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ciag[i];

    vector<int> ile_nieprzedluzalne = oblicz_ile_nieprzedluzalne();
    vector<int> wyniki = sumuj_wyniki(ile_nieprzedluzalne);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        cout << wyniki[k] << "\n";
    }

    return 0;
}