
#include "Prodotto.h"
#include "Venditore.h"
#include "ProdottoAlimentare.h"
#include "ProdottoBambini.h"
using namespace std;


void Venditore::setProdotti(Prodotto ** prodotti){
    for(int i=0; i<this->nProdotti; i++){
        this->prodotti[i]= prodotti[i];
    }
}
Venditore::Venditore(int code,  Prodotto ** prodotti, int nProdotti, int maxProdotti){
    this->code=code;
    this->nProdotti=nProdotti;
    this->maxProdotti=maxProdotti;
    setProdotti(prodotti);
}
Venditore::Venditore(int code){
    this->code=code;
}
Venditore::Venditore(Venditore&   venditore){
    this->code=venditore.code;
    this->maxProdotti=venditore.maxProdotti;
    this->nProdotti=nProdotti;
    setProdotti(venditore.prodotti);
}
Venditore::Venditore(){

}


int Venditore::getcCode(){
    return this->code;
}
Prodotto ** Venditore::getProdotti(){
    return this->prodotti;
};

double Venditore::calcolaPrezzoTotale(){
    double somma=0;
     for(int i=0; i<this->nProdotti; i++){
        somma+=this->prodotti[i]->getPrice();
    }
    return somma;
}
double Venditore::calcolaValoreMagazzino(){
    double somma=0;
     for(int i=0; i<this->nProdotti; i++){
        ProdottoAlimentare* prodottoAlimentare = dynamic_cast<ProdottoAlimentare*>(this->prodotti[i]);

        if(prodottoAlimentare->isScaduto()){
            somma+=this->prodotti[i]->getPrice();
        }

    }
    return somma;
}
void Venditore::aggiungiProdotto(){
    if(nProdotti==maxProdotti){
        cout<<"Magazzino pieno\n";
        return;
    }
    int scelta=menu();
    Prodotto * prodotto = NULL;
    switch(scelta){
            case 1:
                prodotto=new Prodotto;
                break;
            case 2:
                prodotto=new ProdottoAlimentare;
                break;
            case 3:
                prodotto=new ProdottoBambini();
                break;
            case 4:
                return;
    }

    prodotto->leggi();
    this->prodotti[nProdotti]=prodotto;
    nProdotti++;
}

ostream& operator << (ostream& out, Venditore& venditore){
    out<<"Venditore {code: "<<venditore.code<<", maxProdotti "<<venditore.maxProdotti<<", nProdotti: "<<venditore.nProdotti<<": } \n";
    for(int i=0; i<venditore.nProdotti; i++){
         out<<*(venditore.prodotti[i])<<"\n";
         //cout<<*(this->prodotti[i])<<"\n";
    }
    return out;
}
void Venditore::leggi(){


    cout<<"input venditore code:\n";
    cin>>this->code;
    cout<<"input max prodotti: \n";
    cin>>this->maxProdotti;

    do{
        cout<<"input n prodotti ( con nProdotti<maxProdotti !): \n";
        cin>>this->nProdotti;
    }while(this->nProdotti>this->maxProdotti);
    this->prodotti=  new Prodotto* [maxProdotti];

    for(int i=0; i<this->nProdotti; i++){
        cout<<"input ["<<i<<"] prodotto: \n";
        int scelta = menu();
        switch(scelta){
            case 1:
                 this->prodotti[i]=new Prodotto;
                 break;
            case 2:
                 this->prodotti[i]=new ProdottoAlimentare;
                 break;
            case 3:
                 this->prodotti[i]=new ProdottoBambini();
                 break;
            case 4:
                 return;
        }

        this->prodotti[i]->leggi();
    }

}
int  Venditore::menu(){
    int scelta;
    do {
        cout<<"---------------Menu-------------------\n";
        cout<<"1)+prodotto base\n";
        cout<<"2)+prodotto alimentare\n";
        cout<<"3)+prodotto per bambini\n";
        cin>>scelta;
    }while(scelta<1||scelta>3);
    return scelta;
}




