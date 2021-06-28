//
// Created by Paul Chelaru on 08/05/2021.
//

#include "ContEconomii.h"
#include "Persoana.h"

ContEconomii::ContEconomii(Persoana persoana, double d, Card card, int i, double dobanda, int tipDobanda) :
        ContBancar(persoana, d, card, i), dobanda(dobanda), tipDobanda(tipDobanda) {
    istoric[dataDeschidere] = sold;
}

ContEconomii::ContEconomii() {
    istoric[dataDeschidere] = sold;
}

ContEconomii::ContEconomii(const ContEconomii &contEconomii) :
        ContBancar(contEconomii) {
    dobanda = contEconomii.dobanda;
    tipDobanda = contEconomii.tipDobanda;
    istoric = contEconomii.istoric;
}

ContEconomii::~ContEconomii() {}

double ContEconomii::getDobanda() {
    return dobanda;
}

void ContEconomii::setDobanda(double dobanda) {
    ContEconomii::dobanda = dobanda;
}

unordered_map<string, double> ContEconomii::getIstoric() {
    return istoric;
}

void ContEconomii::setIstoric(unordered_map<string, double> istoric) {
    ContEconomii::istoric = istoric;
}

void ContEconomii::adaugaBani(double suma) {
    ContBancar::adaugaBani(suma);
    istoric[dataDeAziString()] = sold;
}

void ContEconomii::afisareIstoric() {
    for (auto i : istoric)
        cout << "In data de " << i.first << " a fost adaugata suma de " << i.second << endl;
}

void ContEconomii::afisare(ostream &out) {
    ContBancar::afisare(out);
    cout << "Tipul dobanzii este pe " << tipDobanda << " luni." << endl;
    cout << "Valorea dobanzii este de " << dobanda << " %." << endl;
    afisareIstoric();
}

void ContEconomii::citire(istream &in) {
    ContBancar::citire(in);
    istoric[dataDeAziString()] = sold;
    cout << "Introduceti tipul dobanzii. Numarul de luni poate fi [3 / 6 / 12]." << "Luni: ";
    int raspuns;
    try {
        in >> raspuns;
        if (raspuns != 3 and raspuns != 6 and raspuns != 12)
            throw 1;
    } catch (int i) {
        cout << "Eroare la introducerea tipului dobanzii, dobanda poate fi doar [3 / 6 / 12]";
    }
    cout << "Introduceti cat % dobanda va avea contul: ";
    cin >> dobanda;
}

void ContEconomii::setTipDobanda(int nrLuni) {
    tipDobanda = nrLuni;
}

int ContEconomii::getTipDobanda() {
    return tipDobanda;
}

void ContEconomii::adaugaDobanda() {
    if (tipDobanda == 3) {
        if (ZZDeAzi() - 3 == ziDeschidere) {
            sold += dobanda * sold;
            istoric[dataDeAziString()] = sold;
        } else if (ZZDeAzi() - 6 == ziDeschidere) {
            sold += dobanda * sold;
            istoric[dataDeAziString()] = sold;
        } else if (ZZDeAzi() - 9 == ziDeschidere) {
            sold += dobanda * sold;
            istoric[dataDeAziString()] = sold;
        } else if (ZZDeAzi() - 12 == ziDeschidere) {
            sold += dobanda * sold;
            istoric[dataDeAziString()] = sold;
        }
    } else if (tipDobanda == 6) {
        if (ZZDeAzi() - 6 == ziDeschidere) {
            sold += dobanda * sold;
            istoric[dataDeAziString()] = sold;
        } else if (ZZDeAzi() - 12 == ziDeschidere) {
            sold += dobanda * sold;
            istoric[dataDeAziString()] = sold;
        }
    } else if (tipDobanda == 12)
        if (ZZDeAzi() - 12 == ziDeschidere) {
            sold += dobanda * sold;
            istoric[dataDeAziString()] = sold;
        }
}

ContEconomii &ContEconomii::operator=(const ContEconomii &contEconomii) {
    ContBancar::operator=(contEconomii);
    dobanda = contEconomii.dobanda;
    tipDobanda = contEconomii.tipDobanda;
    istoric.clear();
    istoric = contEconomii.istoric;
    return *this;
}




