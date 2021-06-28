//
// Created by Paul Chelaru on 06/05/2021.
//

#include "Persoana.h"

Persoana::Persoana(string nume, string prenume, string nrTelefon, string cnp, string adresa)
        : nume(nume), prenume(prenume), nrTelefon(nrTelefon), CNP(cnp), adresa(adresa) {
    try {
        for (unsigned int i = 0; i < cnp.length(); i++)
            if (cnp[i] < '0' || cnp[i] > '9')
                throw 1;
    } catch (int i) {
        cout << "Eroare constructor, CNP-ul persoanei poate contine doar cifre.\n";
        exit(EXIT_FAILURE);
    }
}

Persoana::Persoana() : nume(""), prenume(""), nrTelefon(""), CNP(""), adresa("") {}

Persoana::Persoana(const Persoana &persoana) {
    nume = persoana.nume;
    prenume = persoana.prenume;
    nrTelefon = persoana.nrTelefon;
    CNP = persoana.CNP;
    adresa = persoana.adresa;
}

Persoana::~Persoana() {}

string Persoana::getNume() {
    return nume;
}

void Persoana::setNume(string nume) {
    Persoana::nume = nume;
}

string Persoana::getPrenume() {
    return prenume;
}

void Persoana::setPrenume(string prenume) {
    Persoana::prenume = prenume;
}

string Persoana::getNrTelefon() {
    return nrTelefon;
}

void Persoana::setNrTelefon(string nrTelefon) {
    Persoana::nrTelefon = nrTelefon;
}

string Persoana::getCnp() {
    return CNP;
}

void Persoana::setCnp(string cnp) {
    try {
        for (unsigned int i = 0; i < cnp.length(); i++)
            if (cnp[i] < '0' || cnp[i] > '9')
                throw 1;
    } catch (int i) {
        cout << "Eroare setter CNP, CNP-ul persoanei poate contine doar cifre.\n";
        exit(EXIT_FAILURE);
    }
    CNP = cnp;
}

string Persoana::getAdresa() {
    return adresa;
}

void Persoana::setAdresa(string adresa) {
    Persoana::adresa = adresa;
}

void Persoana::afisare(ostream &out) const {
    out << "Numele este: " << nume << endl;
    out << "Prenumele este: " << prenume << endl;
    out << "Numarul de telefon este: " << nrTelefon << endl;
    out << "CNP-ul este: " << CNP << endl;
    out << "Adresa este: " << adresa << endl;
}

ostream &operator<<(ostream &out, const Persoana &persoana) {
    persoana.afisare(out);
    return out;
}

void Persoana::citire(istream &in) {
    cout << "Numele este: ";
    in >> nume;
    cout << "Prenumele este: ";
    in >> prenume;
    cout << "CNP-ul este: ";
    try {
        in >> CNP;
        for (unsigned int i = 0; i < CNP.length(); i++)
            if (CNP[i] < '0' || CNP[i] > '9')
                throw 1;
    } catch (int i) {
        cout << "Eroare la citire, CNP-ul persoanei poate contine doar cifre.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Numarul de telefon este: ";
    in >> nrTelefon;
    cout << "Adresa este: ";
    in >> adresa;
}

istream &operator>>(istream &in, Persoana &persoana) {
    persoana.citire(in);
    return in;
}

Persoana &Persoana::operator=(const Persoana &persoana) {
    if(this != &persoana){
        nume = persoana.nume;
        prenume = persoana.prenume;
        nrTelefon = persoana.nrTelefon;
        CNP = persoana.CNP;
        adresa = persoana.adresa;
    }
    return *this;
}
