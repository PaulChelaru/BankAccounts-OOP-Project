//
// Created by Paul Chelaru on 06/05/2021.
//
#include "iostream"

using namespace std;
#ifndef OOP3_PERSOANA_H
#define OOP3_PERSOANA_H


class Persoana {
private:
    string nume;
    string prenume;
    string nrTelefon;
    string CNP;
    string adresa;

public:
    Persoana(string nume, string prenume, string nrTelefon, string cnp, string adresa);

    Persoana();

    Persoana(const Persoana &);

    virtual ~Persoana();

    string getNume();

    void setNume(string nume);

    string getPrenume();

    void setPrenume(string prenume);

    string getNrTelefon();

    void setNrTelefon(string nrTelefon);

    string getAdresa();

    void setAdresa(string adresa);

    string getCnp();

    void setCnp(string cnp);

    void virtual afisare(ostream &) const;

    friend ostream &operator<<(ostream &, const Persoana &);

    void virtual citire(istream &);

    friend istream &operator>>(istream &, Persoana &);

    Persoana &operator=(const Persoana &);
};

#endif //OOP3_PERSOANA_H
