//
// Created by Paul Chelaru on 08/05/2021.
//
#ifndef OOP3_CONTECONOMII_H
#define OOP3_CONTECONOMII_H

#include "ContBancar.h"
#include <iostream>
#include <unordered_map>

class ContEconomii : public ContBancar {
    double dobanda;
    int tipDobanda;
    unordered_map<string, double> istoric;
public:
    ContEconomii(Persoana, double, Card, int, double, int);

    ContEconomii();

    ContEconomii(const ContEconomii&);

    virtual ~ContEconomii();

    double getDobanda();

    void setDobanda(double dobanda);

    void setTipDobanda(int);

    int getTipDobanda();

    unordered_map<string, double> getIstoric();

    void setIstoric(unordered_map<string, double> istoric);

    void adaugaBani(double suma);

    void afisareIstoric();

    void afisare(ostream &);

    ContEconomii &operator=(const ContEconomii&);

    void citire(istream &);

    void adaugaDobanda();
};

#endif //OOP3_CONTECONOMII_H
