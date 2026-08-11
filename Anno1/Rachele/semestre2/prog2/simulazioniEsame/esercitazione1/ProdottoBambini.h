#include <iostream>
#include "Prodotto.h"
#ifndef PRODOTTOBAMBINI_H
#define PRODOTTOBAMBINI_H
using namespace std;
enum Ranges { ZERO_TRE, TRE_SEI, SEI_NOVE, NOVE_DODICI };

class ProdottoBambini: public Prodotto{
    private:
         Ranges range ;
    public:
        ProdottoBambini(int code, double price, Ranges range);
        ProdottoBambini();
        Ranges getRange();
        string toString() ;
        void setRange(int range);
        //friend ostream& operator << (ostream& out,  ProdottoBambini& prodottoBambini);
        void leggi();
};

#endif // PRODOTTOBAMBINI_H



