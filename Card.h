//
// Created by Paul Chelaru on 06/05/2021.
//
#include <iostream>
using namespace std;

#ifndef OOP3_CARD_H
#define OOP3_CARD_H

class Card {
private:
    string nrCard;
    string numeDetinator;
    string prenumeDetinator;
    string dataExpirare;
    int CVV;
    double comision;
public:
    Card();

    Card(string, string, string, string, int, double);

    Card(const Card &card);

    virtual ~Card();

    string getNrCard();

    void setNrCard(string nrCard);

    string getNumeDetinator();

    double getComision();

    void setComision(double comision);

    string &getPrenumeDetinator();

    void setPrenumeDetinator(string prenumeDetinator);

    void setNumeDetinator(string numeDetinator);

    string getDataExpirare();

    void setDataExpirare(string dataExpirare);

    int getCvv();

    void setCvv(int CVV);

    virtual void citire(istream &in);

    virtual void afisare(ostream &out) const;

    friend istream &operator>>(istream &in, Card &card);

    friend ostream &operator<<(ostream &out, const Card &card);

    Card &operator=(const Card &card);
};
#endif //OOP3_CARD_H
