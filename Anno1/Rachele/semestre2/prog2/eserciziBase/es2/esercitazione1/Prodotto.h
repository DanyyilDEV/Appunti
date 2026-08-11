#include <iostream>
#ifndef PRODOTTO_H
#define PRODOTTO_H
using namespace std;


class Prodotto{
    private:
        int code;
        double price;
    public:
        Automobile(int code, double price);
        Automobile();

        int getCode();
        double getPrice();

        void setCode(int code);
        void setPrice(double price);

        ostream& operator << (ostream& out, const Prodotto& prodotto);
        void leggi();
};

