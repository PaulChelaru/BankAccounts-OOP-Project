//
// Created by Paul Chelaru on 08/05/2021.
//

#include "ContCurent.h"

ContCurent::ContCurent(Persoana &persoana, double d, Card &card, int i, int nrTranzactiiGratuite,
                       double comisionRetragere) : ContBancar(persoana, d, card, i),
                                                   nrTranzactiiGratuite(nrTranzactiiGratuite),
                                                   comisionRetragere(comisionRetragere) {}

ContCurent::ContCurent() {}

ContCurent::~ContCurent() {}

ContCurent::ContCurent(const ContCurent &contCurent) : ContBancar(contCurent) {
    nrTranzactiiGratuite = contCurent.nrTranzactiiGratuite;
    comisionRetragere = contCurent.comisionRetragere;
}

void ContCurent::extragereBani(double sumaExtrasa) {
    if (sumaExtrasa > sold)
        cout << "Nu aveti suficient credit pentru a extrage suma dorita." << endl;
    else {
        if (nrTranzactiiGratuite == 0) {
            cout << "Pentru ca suma de extragere este mai mare decat limita de extragere"
                    " veti suporta un comision de " << comisionRetragere << "%." << endl;
            cout << "Continuati? [Y / N]: ";
            char raspuns;
            cin >> raspuns;

            if (raspuns == 'Y') {
                cout << "Ati extras suma de: " << sumaExtrasa << endl;
                sold -= sumaExtrasa;
                sold -= comisionRetragere / 100 * sumaExtrasa;
                cout << "Creditul dumneavoastra curent este: " << sold << endl;
            } else {
                cout << "Tranzactia a fost refuzata!";
            }
        } else {
            cout << "Ati extras suma de: " << sumaExtrasa << endl;
            sold -= sumaExtrasa;
            nrTranzactiiGratuite--;
            cout << "Creditul dumneavoastra curent este: " << sold << endl;
        }
    }
}

ContCurent &ContCurent::operator=(const ContCurent &contCurent) {
    ContBancar::operator=(contCurent);
    nrTranzactiiGratuite = contCurent.nrTranzactiiGratuite;
    comisionRetragere = contCurent.comisionRetragere;
    return *this;
}

void ContCurent::afisare(ostream &out) {
    ContBancar::afisare(out);
    cout << "Numarul de tranzactii gratuite este: " << nrTranzactiiGratuite << endl;
    cout << "Comisionul aplicat pentru tranzactiile negratuite este: " << comisionRetragere << endl;
}

void ContCurent::citire(istream &in) {
    ContBancar::citire(in);
    cout << "Introdu numarul de tranzatii gratuite: ";
    in >> nrTranzactiiGratuite;
    cout << "Introdu comisionul pentru tranzactiile negratuite: ";
    in >> comisionRetragere;
}

int ContCurent::getNrTranzactiiGratuite() {
    return nrTranzactiiGratuite;
}

void ContCurent::setNrTranzactiiGratuite(int nrTranzactiiGratuite) {
    ContCurent::nrTranzactiiGratuite = nrTranzactiiGratuite;
}

double ContCurent::getComisionRetragere() {
    return comisionRetragere;
}

void ContCurent::setComisionRetragere(double comisionRetragere) {
    ContCurent::comisionRetragere = comisionRetragere;
}
