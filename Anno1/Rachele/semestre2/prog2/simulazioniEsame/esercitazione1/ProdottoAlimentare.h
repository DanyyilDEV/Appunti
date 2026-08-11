#include <iostream>
#include "Prodotto.h"
#ifndef PRODOTTOALIMENTARE_H
#define PRODOTTOALIMENTARE_H
using namespace std;
struct Data{
    int day;
    int month;
    int year;
};
typedef struct Data Data;

class ProdottoAlimentare: public Prodotto{
    private:
         Data scadenza;
    public:
        ProdottoAlimentare(int code, double price, Data scadenza);
        ProdottoAlimentare();
        Data getScadenza();
        void setScadenza(int day, int month, int year);
        void setScadenza(Data scadenza);
        string stringScadenza();
        string toString();
        //friend ostream& operator << (ostream& out, ProdottoAlimentare& prodottoAlimentare);
        void leggi();
        bool isScaduto();
};


#endif // PRODOTTOALIMENTARE_H


