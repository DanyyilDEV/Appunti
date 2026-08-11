#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <iostream>
using namespace std;


class Prodotto{
    private:
        int code;
        double price;
    public:
        Prodotto(int code, double price);
        Prodotto();
        virtual ~Prodotto();
        int getCode();
        double getPrice();
        virtual string toString();
        void setCode(int code);
        void setPrice(double price);
        friend
        ostream& operator << (ostream& out, Prodotto& prodotto);
        virtual void leggi();
};

#endif
