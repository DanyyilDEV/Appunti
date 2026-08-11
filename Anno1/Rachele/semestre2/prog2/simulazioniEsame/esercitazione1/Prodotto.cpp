#include "Prodotto.h"
using namespace std;


Prodotto::Prodotto(int code, double price) {
    this->code = code;
    this->price = price;
}

Prodotto::Prodotto() {
    this->code = 0;
    this->price = 0.0;
}

int Prodotto::getCode() { return code; }
double Prodotto::getPrice() { return price; }
Prodotto::~Prodotto() {}
void Prodotto::setCode(int code) {
    this->code = code;
}

void Prodotto::setPrice(double price) {
    this->price = price;
}

void Prodotto::leggi() {
    cout << "input code: ";
    cin >> this->code;
    cout << "input price: ";
    cin >> this->price;
}
string Prodotto::toString() {
   string s="Prodotto {code: "+to_string(this->code)+", price: "+to_string(this->price)+"}\n";
   return s;
}

ostream& operator<<(ostream& out, Prodotto& prodotto) {
    out <<prodotto.toString();
    return out;
}
