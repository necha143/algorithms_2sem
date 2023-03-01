/*
#include <iostream>
#include <vector>
using namespace std;
string MashaCode, SashaCode;
vector<pair<int, char>> MashaMas; //pair позволяет обрабатывать два объекта как один
vector<pair<int, char>> SashaMas; // данная штука будет хранить в int-количество повторений буквы, а в char-данную букву


class decoder{
public:
    void masha (int n){
        for (int i=0; i<n; i++) {
            if (MashaCode[i]>47 && MashaCode[i]<58){
                MashaMas[MashaMas.size()-1].first = MashaMas[MashaMas.size()-1].first * 10 + (MashaCode[i]-'0');
            } else {
                MashaMas.push_back(make_pair(0, MashaCode[i])); // Функция шаблона, которую можно использовать для построения объектов типа pair
            }
        }
    }

    void sasha (int m){
        for (int i=0; i<m; i++) {
            if (SashaCode[i]>47 && SashaCode[i]<58){
                SashaMas[SashaMas.size()-1].first = SashaMas[SashaMas.size()-1].first * 10 + (SashaCode[i]-'0');
            } else {
                SashaMas.push_back(make_pair(0, SashaCode[i]));
            }
        }
    }
} Decoder;


void Display (int c, int k){
    c>k? cout << "No" : cout <<"Yes";
}


void check (int n, int m, int k){
    Decoder.masha(n);
    Decoder.sasha(m);
    //cout << MashaMas.size() << " " << SashaMas.size();

    */
/*int sum_of_ch;
    for (int i=0; i<MashaMas.size(); i++){
        sum_of_ch+=MashaMas[i].first;
    }
    if (sum_of_ch<k){
        cout << "Yes";
        return;
    }*//*


    int i=0, j=0, c=0;
    while (i+j < MashaMas.size() + SashaMas.size()){

        if (MashaMas[i].first < SashaMas[j].first){ // сравнение повторений количества некой буквы
            SashaMas[j].first -= MashaMas[i].first; // в удачном случае, уменьшим количество для будущей проверки
            if (MashaMas[i].second != SashaMas[j].second){ // ищем отличия
                c+=MashaMas[i].first;
            }
            i++;

        } else if (MashaMas[i].first > SashaMas[j].first){
            MashaMas[i].first -= SashaMas[j].first;
            if (MashaMas[i].second != SashaMas[j].second){
                c+=SashaMas[j].first;
            }
            j++;

        } else {
            if (MashaMas[i].second != SashaMas[j].second){
                c+=SashaMas[j].first;
            }
            i++; j++;
        }

    }

    Display(c,k);
    return;
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    cin >> MashaCode;
    cin >> SashaCode;
    check(n,m,k);

    return 0;
}
*/
