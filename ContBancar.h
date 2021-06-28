//
// Created by Paul Chelaru on 06/05/2021.
//
#include "Persoana.h"
#include <iostream>
#include "Card.h"

using namespace std;
#ifndef OOP3_CONTBANCAR_H
#define OOP3_CONTBANCAR_H


class ContBancar {
    time_t t = time(0);
    struct tm *timeStruct = localtime(&t);
protected:
    string idContBancar;
    Persoana detinator;
    Card card;
    const string dataDeschidere = to_string(ZZDeAzi()) + "-" + to_string(LLDeAzi()) + "-" + to_string(YYYYDeAzi());
    const int ziDeschidere = ZZDeAzi();
    const int lunaDeschidere = LLDeAzi();
    const int anDeschidere = YYYYDeAzi();
    double sold;
    static int nrConturi;

public:
    ContBancar(Persoana, double, Card, int);

    ContBancar();

    ContBancar(const ContBancar &);

    Persoana getDetinator();

    virtual ~ContBancar();

    string getIdContBancar();

    void setDetinator(Persoana &detinator);

    double getSold();

    Card getCard();

    void setCard(Card card);

    void setSold(double sold);

    static int getNrConturi();

    static void setNrConturi(int nrConturi);

    string getDataDeschidere() const;

    virtual void afisare(ostream &) const;

    friend ostream &operator<<(ostream &, const ContBancar &);

    virtual void citire(istream &);

    friend istream &operator>>(istream &, ContBancar &);

    ContBancar &operator=(const ContBancar &);

    virtual void adaugaBani(double);

    int ZZDeAzi();

    int LLDeAzi();

    int YYYYDeAzi();

    const int getZiDeschidere() const;

    const int getLunaDeschidere() const;

    const int getAnDeschidere() const;

    string dataDeAziString();
};


#endif //OOP3_CONTBANCAR_H
