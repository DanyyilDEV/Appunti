#include <iostream>
#include "Prodotto.h"
#include "ProdottoAlimentare.h"
#include "ProdottoBambini.h"
#include "Venditore.h"
#define nVenditori
#define nVenditori 3
using namespace std;

int menu(){
    int scelta;
    do {
        cout<<"---------------Menu-------------------\n";
        cout<<"1)+ prodotto venditore 1\n";
        cout<<"2)+ prodotto venditore 2\n";
        cout<<"3)+ prodotto venditore 3\n";
        cout<<"4)esci\n";
        cin>>scelta;
    }while(scelta<1||scelta>4);
    return scelta;
}
int main()
{
    Venditore * venditori= new Venditore[nVenditori];

    for(int i=0; i<nVenditori; i++){
        venditori[i].leggi();
    }
    for(int i=0; i<nVenditori; i++){
        cout<<venditori[i];
    }
    int scelta;
    do{
        scelta= menu();
        Prodotto * prodotto = new Prodotto;
        prodotto->leggi();
        switch(scelta){
            case 1:{
                     venditori[0].aggiungiProdotto();
                     break;
                 }
            case 2:{

                     venditori[1].aggiungiProdotto();
                     break;
                 }
            case 3:{
                     venditori[2].aggiungiProdotto();
                     break;
                 }

        }
        for(int i=0; i<nVenditori; i++){
            cout<<venditori[i];
        }
    }while(scelta!=4);
    return 0;
}
