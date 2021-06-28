//
// Created by Paul Chelaru on 08/05/2021.
//

#ifndef OOP3_CONTCURENT_H
#define OOP3_CONTCURENT_H

#include "ContBancar.h"

class ContCurent : public ContBancar {
    int nrTranzactiiGratuite;
    double comisionRetragere;
public:
    ContCurent();

    virtual ~ContCurent();

    ContCurent(Persoana &persoana, double d, Card &card, int i, int nrTranzactiiGratuite,
               double comisionRetragere);

    ContCurent(const ContCurent &);

    void extragereBani(double);

    ContCurent& operator=(const ContCurent&);

    void afisare(ostream&);

    void citire(istream&);

    int getNrTranzactiiGratuite();

    void setNrTranzactiiGratuite(int nrTranzactiiGratuite);

    double getComisionRetragere();

    void setComisionRetragere(double comisionRetragere);
};


#endif //OOP3_CONTCURENT_H
