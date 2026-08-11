#include <iostream>
#include "Prodotto.h"
#ifndef VENDITORE_H
#define VENDITORE_H
using namespace std;


class Venditore{
    private:
        int code;
        Prodotto ** prodotti;
        int maxProdotti=0;
        int nProdotti=0;
    public:
        Venditore(int code,  Prodotto ** prodotti, int nProdotti, int maxProdotti);
        Venditore(int code);
        Venditore(Venditore&  venditore);
        Venditore();
        int getcCode();
        Prodotto ** getProdotti();
        void setProdotti(Prodotto ** prodotti);
        double calcolaPrezzoTotale();
        double calcolaValoreMagazzino();
        void aggiungiProdotto();
        friend ostream& operator << (ostream& out, Venditore& venditore);
        void leggi();
        int  menu();
};
#endif // VENDITORE_H


