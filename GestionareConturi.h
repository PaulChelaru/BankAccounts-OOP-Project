////
//// Created by Paul Chelaru on 08/05/2021.
////
//
#ifndef OOP3_GESTIONARECONTURI_H
#define OOP3_GESTIONARECONTURI_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include "ContEconomii.h"

using namespace std;

template<class T>
class GestionareConturi {
    int contId = 0;
    unordered_map<int, pair<T, vector<pair<string, int> > > > conturi;
public:
    GestionareConturi();

    ~GestionareConturi();

    void operator+=(const T &);

    void adaugaBani(int, int);

    void afisareConturi();

    double checkSold(int);

//    void afisareIstoric();
};

//template<class T> int  GestionareConturi<T>::contId = 0;

template<class T>
GestionareConturi<T>::GestionareConturi() {}

template<class T>
GestionareConturi<T>::~GestionareConturi() {}

template<class T>
void GestionareConturi<T>::operator+=(const T &cont) {
    conturi[contId].first = cont;
    conturi[contId].second.push_back({"Deschidere cont ", 0});
    contId++;
}


template<class T>
void GestionareConturi<T>::adaugaBani(int condId, int suma) {
    conturi[condId].first.adaugaBani(suma);
    conturi[condId].second.push_back({"Adaugata suma de ", suma});
}

template<class T>
double GestionareConturi<T>::checkSold(int contId) {
    return conturi[contId].first.getSold();
}

template<class T>
void GestionareConturi<T>::afisareConturi() {
    for (int i = 0; i <= contId; ++i)
        cout << conturi[i].first << "\n";
}

template<>
class GestionareConturi<ContEconomii> {
    int contId = 0;
    unordered_map<int, pair<ContEconomii, vector<pair<string, int> > > > conturi;
public:
    void afisareConturi12() {
        for (int i = 0; i <= contId; ++i)
            if (conturi[i].first.getDobanda() == 12)
                cout << conturi[i].first << "\n";
    }

    double checkSold(int contId) {
        return conturi[contId].first.getSold();
    }

    void operator+=(const ContEconomii &contEconomii) {
        conturi[contId].first = contEconomii;
        conturi[contId].second.push_back({"Deschidere cont ", 0});
        contId++;
    };
};

//int GestionareConturi<ContEconomii>::contId = 0;

#endif //OOP3_GESTIONARECONTURI_H
