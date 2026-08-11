
#include "Prodotto.h"
#include "ProdottoAlimentare.h"
#include <sstream>
#include <ctime>
using namespace std;

ProdottoAlimentare:: ProdottoAlimentare(int code, double price, Data scadenza): Prodotto (code, price){
    this->scadenza=scadenza;
}
ProdottoAlimentare:: ProdottoAlimentare(){}

Data ProdottoAlimentare:: getScadenza(){
    return this->scadenza;
}
void ProdottoAlimentare:: setScadenza(int day, int month, int year){
    this->scadenza.day=day;
    this->scadenza.month=month;
    this->scadenza.year=year;
}
void ProdottoAlimentare:: setScadenza(Data scadenza){
    this->scadenza.day=scadenza.day;
    this->scadenza.month=scadenza.month;
    this->scadenza.year=scadenza.year;
}
string ProdottoAlimentare:: stringScadenza(){
    stringstream ss;
    ss<<this->scadenza.day<<"/"<<this->scadenza.month<<"/"<<this->scadenza.year;
    return ss.str();
}
string ProdottoAlimentare::toString() {
   string s="Prodotto {code: "+to_string(getCode())+", price "+to_string(getPrice())+", scadenza: "+stringScadenza()+"} \n";
    return s;
}
/*
ostream& operator << (ostream& out,ProdottoAlimentare& prodottoAlimentare){
    out<<"Prodotto {code: "<<prodottoAlimentare.getCode()<<", price "<<prodottoAlimentare.getPrice()<<"scadenza: "<<prodottoAlimentare.stringScadenza()<<"} \n";
    return out;
}
*/
void ProdottoAlimentare:: leggi(){
    int code;
    double price;
    Data scadenza;
    cout<<"input code:\n";
    cin>>code;
    cout<<"input price: \n";
    cin>>price;
    cout<<"input scadenza day: \n";
    cin>>scadenza.day;
    cout<<"input scadenza month: \n";
    cin>>scadenza.month;
    cout<<"input scadenza year: \n";
    cin>>scadenza.year;

    setCode(code);
    setPrice(price);
    setScadenza(scadenza);
}

bool ProdottoAlimentare:: isScaduto(){
    time_t t = time(0);
    struct tm* adesso = localtime(&t);

    // Costruiamo il numero AAAAMMGG
    int todayYear = adesso->tm_year + 1900;
    int todayMonth = adesso->tm_mon + 1;
    int todayDay = adesso->tm_mday;
    int today = (todayYear * 10000) + (todayMonth * 100) + todayDay;
    int dataScadenza = (scadenza.year * 10000) + (scadenza.month * 100) + scadenza.day;
    if (dataScadenza < today) {
        return true;
    }
    return false;

}
