//
// Created by Paul Chelaru on 06/05/2021.
//

#include "ContBancar.h"
#include "Card.h"

int ContBancar::nrConturi = 0;

ContBancar::ContBancar(Persoana persoana, double sold, Card card, int nrTranzactiiGratuite) {
    try {
        if (sold < 0)
            throw 1;
    } catch (int i) {
        cout << "Eroare constructor, soldul unui card la creare nu poate fi negativ";
        exit(EXIT_FAILURE);
    }
    nrConturi++;
    idContBancar = "Banca-Cont-Nr:" + to_string(nrConturi);
    ContBancar::detinator = persoana;
    ContBancar::sold = sold;
    ContBancar::card = card;
}

ContBancar::ContBancar() {
    nrConturi++;
    idContBancar = "Banca-Cont-Nr:" + to_string(nrConturi);
}

ContBancar::ContBancar(const ContBancar &contBancar) {
    nrConturi++;
    idContBancar = "Banca-Cont-Nr:" + to_string(nrConturi);
    idContBancar = contBancar.idContBancar;
    detinator = contBancar.detinator;
    sold = contBancar.sold;
    card = contBancar.card;
}

ContBancar::~ContBancar() {}

Persoana ContBancar::getDetinator() {
    return detinator;
}

void ContBancar::setDetinator(Persoana &detinator) {
    ContBancar::detinator = detinator;
}

double ContBancar::getSold() {
    return sold;
}

void ContBancar::setSold(double sold) {
    ContBancar::sold = sold;
}

int ContBancar::getNrConturi() {
    return nrConturi;
}

void ContBancar::setNrConturi(int nrConturi) {
    ContBancar::nrConturi = nrConturi;
}

string ContBancar::getDataDeschidere() const {
    return dataDeschidere;
}

Card ContBancar::getCard() {
    return card;
}

void ContBancar::setCard(Card card) {
    ContBancar::card = card;
}

void ContBancar::afisare(ostream &out) const {
    out << "Id-ul contului bancar este: " << idContBancar << endl;
    out << "Detinatorul contului bancar si datele sale sunt: " << endl;
    out << detinator << endl;
    out << "Data deschiderii contului este: " << dataDeschidere << endl;
    out << "Soldul curent este: " << sold << endl << endl;
    out << "Datele cardului asociant contului sunt: " << card << endl;
}

ostream &operator<<(ostream &out, const ContBancar &contBancar) {
    contBancar.afisare(out);
    return out;
}

void ContBancar::citire(istream &in) {
    cout << "Introduceti datele detinatorului cardului bancar." << endl;
    in >> detinator;
    cout << "Introduceti sold-ul curent: ";
    in >> sold;
    try {
        if (sold < 0)
            throw 1;
    } catch (int i) {
        cout << "Eroare la citire, soldul unui card la creare nu poate fi negativ";
        exit(EXIT_FAILURE);
    }
    in >> card;
}

istream &operator>>(istream &in, ContBancar &contBancar) {
    contBancar.citire(in);
    return in;
}

string ContBancar::getIdContBancar() {
    return idContBancar;
}

ContBancar &ContBancar::operator=(const ContBancar &contBancar) {
    idContBancar = contBancar.idContBancar;
    detinator = contBancar.detinator;
    card = contBancar.card;
    sold = contBancar.sold;
    return *this;
}


void ContBancar::adaugaBani(double suma) {
    sold += suma;
    cout << "Suma a fost adaugata cu succes!" << endl;
    cout << "Soldul curent este: " << sold << endl;
}

int ContBancar::ZZDeAzi() {
    int data = timeStruct->tm_mday;
    return data;
}

int ContBancar::LLDeAzi() {
    int data = 1 + timeStruct->tm_mon;
    return data;
}

int ContBancar::YYYYDeAzi() {
    int data = 1900 + timeStruct->tm_year;
    return data;
}

const int ContBancar::getZiDeschidere() const {
    return ziDeschidere;
}

const int ContBancar::getLunaDeschidere() const {
    return lunaDeschidere;
}

const int ContBancar::getAnDeschidere() const {
    return anDeschidere;
}

string ContBancar::dataDeAziString() {
    return to_string(ZZDeAzi()) + "-" + to_string(LLDeAzi()) + "-" + to_string(YYYYDeAzi());
}
