//
// Created by Paul Chelaru on 09/05/2021.
//

#ifndef OOP3_MENU_H
#define OOP3_MENU_H

#include <iostream>
#include "ContEconomii.h"
#include "ContCurent.h"
#include "ContBancar.h"
#include "GestionareConturi.h"
using namespace std;

class Menu {
    static Menu *menu;
    Menu(){};

    void menu_output() {
        cout << "\n Chelaru paul 134 - Proiect3 - Nume proiect: Tema12 \n";
        cout << "\n\t MENIU:";
        cout << "\n===========================================\n";
        cout << "\n";
        cout << "1. Depunere bani intr-un cont curent.";
        cout << "\n";
        cout << "2. Extragere bani de pe un cont curent.";
        cout << "\n";
        cout << "3. Gestiunea conturilor - Template.";
        cout << "\n";
        cout << "4. Gestiunea conturilor - Specializare ContEconomii";
        cout << "\n";
        cout << "5. Sold-ul conturilor din gestiunea conturilor - Template.";
        cout << "\n";
        cout << "6. Afiseaza istoric cont de economii.";
        cout << "\n";
        cout << "0. Iesire.";
        cout << "\n";
    }


    void afisareConturi(vector<ContBancar *> conturi, int n) {
        for (int i = 0; i < n; i++) {
            cout << "Contul  " << i + 1 << " este: " << endl;
            cout << *conturi[i] << endl;
        }
    }

public:
    static Menu* getInstance() {
        if (!menu)
            menu = new Menu;
        return menu;
    }

    void menuDisplay() {
        int option;
        option = 0;

        vector<ContBancar *> conturi;
        cout << "Introduceti numarul de conturi: ";
        int n;
        cin >> n;
        for (int i = 0; i < n;) {
            string tipCont;
            cout << "\n";
            cout << "Introduceti tipul contului " << i + 1 << " [economii / curent]: ";
            cin >> tipCont;
            try {
                if (tipCont == "economii") {
                    ContEconomii *contEconomii = new ContEconomii;
                    cin >> *contEconomii;
                    conturi.push_back(contEconomii);
                    i++;
                } else if (tipCont == "curent") {
                    ContCurent *contCurent = new ContCurent;
                    cin >> *contCurent;
                    conturi.push_back(contCurent);
                    i++;
                } else throw 10;
            } catch (int j) {
                cout << "Nu ati introdus un tip de cont valid.\n ";
            }
        }

        cout << endl;
        cout << "Conturile salvate sunt: " << endl;
        afisareConturi(conturi, n);
        do {
            menu_output();

            cout << "\nIntroduceti numarul actiunii: ";
            cin >> option;

            if (option == 1) {
                cout << "Introduceti numarul contului in care doriti sa depuneti bani. (nu mai mare decat " << n
                     << ").";
                int nrCont;
                cin >> nrCont;
                cout << "Introdu suma pe care doriti sa o depuneti.";
                int suma;
                cin >> suma;
                ContCurent *contCurent = dynamic_cast<ContCurent *>(conturi[nrCont - 1]);
                if (contCurent) contCurent->adaugaBani(suma);
                else cout << "Eroare la alegerea cardului. Ati ales un cont de economii." << endl;
            }
            if (option == 2) {
                cout << "Introduceti numarul contului din care doriti sa extrageti bani. (nu mai mare decat " << n
                     << ").";
                int nrCont;
                cin >> nrCont;
                cout << "Introdu suma pe care doriti sa o extrageti.";
                int suma;
                cin >> suma;
                ContCurent *contCurent = dynamic_cast<ContCurent *>(conturi[nrCont - 1]);
                if (contCurent) contCurent->extragereBani(suma);
                else cout << "Eroare la alegerea cardului. Ati ales un cont de economii." << endl;
            }
            if (option == 3) {
                GestionareConturi<ContCurent> gestionareConturi;
                cout
                        << "Introduceti numarul de carduri curente pe care doriti sa le inserati in sistemul de gestiune: ";
                int nrCarduri;
                cin >> nrCarduri;
                ContCurent contCurent;
                for (int i = 0; i < nrCarduri; i++) {
                    cin >> contCurent;
                    gestionareConturi += contCurent;
                }
                gestionareConturi.afisareConturi();
            }
            if (option == 4) {
                GestionareConturi<ContEconomii> gestionareConturi;
                cout
                        << "Introduceti numarul de carduri curente pe care doriti sa le inserati in sistemul de gestiune: ";
                int nrCarduri;
                cin >> nrCarduri;
                ContEconomii contEconomii;
                for (int i = 0; i < nrCarduri; i++) {
                    cin >> contEconomii;
                    gestionareConturi += contEconomii;
                }
                gestionareConturi.afisareConturi12();
            }
            if (option == 5) {
                GestionareConturi<ContCurent> gestionareConturi;
                cout
                        << "Introduceti numarul de carduri curente pe care doriti sa le inserati in sistemul de gestiune: ";
                int nrCarduri;
                cin >> nrCarduri;
                ContCurent contCurent;
                for (int i = 0; i < nrCarduri; i++) {
                    cin >> contCurent;
                    gestionareConturi += contCurent;
                }
                cout << "Introduceti numarul cardului caruia doriti sa ii verificati sold-ul: ";
                int nrCard;
                cin >> nrCard;
                gestionareConturi.checkSold(nrCard);
            }
            if (option == 6) {
                cout << "Introduceti numarul contului din care doriti sa extrageti bani. (nu mai mare decat " << n
                     << ").";
                int nrCont;
                cin >> nrCont;

                ContEconomii *contEconomii = dynamic_cast<ContEconomii *>(conturi[nrCont - 1]);
                if (contEconomii) {
                    cout << "Introduceti de cate ori doriti sa adaugati bani: ";
                    int nrBani;
                    cin >> nrBani;
                    for (int i = 0; i < nrBani; i++) {
                        cout << "Introdu suma pe care doriti sa o adaugati.";
                        int suma;
                        cin >> suma;
                        contEconomii->adaugaBani(suma);
                    }
                    contEconomii->afisareIstoric();
                } else cout << "Eroare la alegerea cardului. Ati ales un cont curent." << endl;
            }
            if (option == 0) {
                cout << "\nEXIT!\n";
            }
            if (option < 0 || option > 6) {
                cout << "\nSelectie invalida\n";
            }
            cout << "\n";
        } while (option != 0);
    }
};


#endif //OOP3_MENU_H
