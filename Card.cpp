//
// Created by Paul Chelaru on 06/05/2021.
//
#include <iostream>
#include <utility>
#include "Card.h"

using namespace std;

Card::Card() {
    nrCard = "";
    numeDetinator = "";
    prenumeDetinator = "";
    dataExpirare = "";
    CVV = 0;
    comision = 0;
}

Card::Card(string nrCard, string numeDetinator, string prenumeDetinator,
           string dataExpirare, int CVV, double comision) {
    this->nrCard = nrCard;
    this->numeDetinator = numeDetinator;
    this->prenumeDetinator = prenumeDetinator;
    this->dataExpirare = dataExpirare;
    try {
        this->CVV = CVV;
        if (CVV < 100 or CVV > 1000) {
            throw 1;
        }
        this->comision = comision;
        if (comision < 0)
            throw 2;
    } catch (int i) {
        if (i == 1) {
            cout << "Eroare la citire, CVV-ul unui card trebuie sa fie de 3 cifre";
            exit(EXIT_FAILURE);
        }
        if (i == 2) {
            cout << "Eroare la citire, comisionul unui card trebuie sa fie >= 0";
            exit(EXIT_FAILURE);
        }
    }
}

Card::Card(const Card &card) {
    this->nrCard = card.nrCard;
    this->numeDetinator = card.numeDetinator;
    this->prenumeDetinator = card.prenumeDetinator;
    this->dataExpirare = card.dataExpirare;
    this->CVV = card.CVV;
    this->comision = card.comision;
}

Card::~Card() {
    nrCard = "";
    numeDetinator = "";
    prenumeDetinator = "";
    dataExpirare = "";
    CVV = 0;
    comision = 0;
}

string Card::getNrCard() {
    return nrCard;
}

string &Card::getPrenumeDetinator() {
    return prenumeDetinator;
}

void Card::setPrenumeDetinator(string prenumeDetinator) {
    Card::prenumeDetinator = prenumeDetinator;
}

void Card::setNrCard(string nrCard) {
    this->nrCard = nrCard;
}

string Card::getNumeDetinator() {
    return numeDetinator;
}

void Card::setNumeDetinator(string numeDetinator) {
    this->numeDetinator = numeDetinator;
}

string Card::getDataExpirare() {
    return dataExpirare;
}

void Card::setDataExpirare(string dataExpirare) {
    this->dataExpirare = dataExpirare;
}

int Card::getCvv() {
    return CVV;
}

void Card::setCvv(int CVV) {
    this->CVV = CVV;
}

void Card::citire(istream &in) {
    cout << "Introduceti datele cardului: " << endl;
    cout << "Introduceti numarul cardului: ";
    in >> nrCard;
    cout << "Introduceti nume detinator: ";
    in >> numeDetinator;
    cout << "Introduceti prenumee detinator: ";
    in >> prenumeDetinator;
    cout << "Introduceti data expirarii: ";
    in >> dataExpirare;
    try {
        cout << "Introduceti CVV-ul: ";
        in >> CVV;
        if (CVV < 100 or CVV > 1000)
            throw 1;
        cout << "Introduceti comisionul: ";
        in >> comision;
        if (comision < 0)
            throw 2;
    } catch (int i) {
        if (i == 1) {
            cout << "Eroare la citire, CVV-ul unui card trebuie sa fie de 3 cifre";
            exit(EXIT_FAILURE);
        }
        if (i == 2) {
            cout << "Eroare la citire, comisionul unui card trebuie sa fie >= 0";
            exit(EXIT_FAILURE);
        }
    }
}

istream &operator>>(istream &in, Card &card) {
    card.citire(in);
    return in;
}

void Card::afisare(ostream &out) const {
    out << "Numarul cardului este: " << nrCard << endl;
    out << "Card nume detinator: " << numeDetinator << endl;
    out << "Card prenume detinator: " << prenumeDetinator << endl;
    out << "Data cardului de expirare: " << dataExpirare << endl;
    out << "CVV-ul: " << CVV << endl;
    out << "Comisionul este: " << comision << endl;
}

ostream &operator<<(ostream &out, const Card &card) {
    card.afisare(out);
    return out;
}

Card &Card::operator=(const Card &card) {
    nrCard = card.nrCard;
    numeDetinator = card.numeDetinator;
    prenumeDetinator = card.prenumeDetinator;
    dataExpirare = card.dataExpirare;
    CVV = card.CVV;
    comision = card.comision;
    return *this;
}

double Card::getComision() {
    return comision;
}

void Card::setComision(double comision) {
    Card::comision = comision;
}
