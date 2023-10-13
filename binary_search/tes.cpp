#include <iostream>
#include <unordered_map>
#include <vector>
 
using namespace std;
 
unordered_map<int,vector<int>> map;
int tab[1000*1000+5];
 
int bs(int index, int current){
    int poczatek = -1, koniec = map[index].size(), srodek = 0;
    while(koniec - poczatek > 1)
    {
        srodek = poczatek + (koniec - poczatek) / 2;
        if (map[index][srodek] > current)
            koniec = srodek;
        else
            poczatek = srodek;
    }
    if (koniec == map[index].size())
        return -1;
    return koniec;
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
 
    //map[1]->indeksy_gdzie_jest
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        map[x].push_back(i);
    }
 
    //test_cases
    int t;
    cin >> t;
    for(int j=0;j<t;++j)
    {
        int k;
        cin >> k;
 
        bool notok = false;
        int index = -1;
        //wrzucam całą listę zapytania do tablicy
        for(int l=0;l<k;++l){
            cin >> tab[l];
        }
        for(int i=0;i<k;++i)
        {
            //biorę aktualną liczbę z zapytania
            int current = tab[i];
            int answer;
            //sprawdzam czy nie ma tam elementu
            if(map.find(current) == map.end())
            {    notok = true;break;}
            //sprawdzam czy element występuje raz
 
            answer = bs(current,index);
 
            //jeśli nie ma
            if(answer == -1)
            {
                notok = true;
                break;
            }
            index = map[current][answer];
        }
        if(notok == false)
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }
    return 0;
}