
#include "Prodotto.h"
#include "ProdottoBambini.h"
using namespace std;

ProdottoBambini::ProdottoBambini(int code, double price, Ranges range): Prodotto (code, price){
    this->range=range;
}
ProdottoBambini::ProdottoBambini(){};

Ranges ProdottoBambini::getRange(){
    return this->range;
}
void ProdottoBambini::setRange(int range){
    this->range=(Ranges)range;
}
string ProdottoBambini::toString() {
   string s="Prodotto {code: "+to_string(getCode())+", price "+to_string(getPrice())+"range: "+to_string((Ranges) getRange())+"} \n";
   return s;
}
/*
ostream& operator << (ostream& out,  ProdottoBambini& prodottoBambini){
    out<<"Prodotto {code: "<<prodottoBambini.getCode()<<", price "<<prodottoBambini.getPrice()<<"scadenza: "<<prodottoBambini.getRange()<<"} \n";
    return out;
}
*/
void ProdottoBambini::leggi(){
    int code;
    int price;
    int range;
    cout<<"input code:\n";
    cin>>code;
    cout<<"input price: \n";
    cin>>price;
    cout<<"input range con Ranges \n";
    cout<<"0=0-3\n";
    cout<<"1=3-6\n";
    cout<<"2=6-9\n";
    cout<<"3=9-12\n";
    cin>>range;

    setCode(code);
    setPrice(price);
    this->range=(Ranges)range;
}



