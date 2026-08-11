#include "Lampadina.h"
enum Stato {ON, OFF, BROKEN};
Class Lampadina{
    protected:
        Stato stato;
        int countClick=0;
        int maxClick;
    public:
        Lampadina (int maxClick): maxClick(maxClick) {}
        void click(){
            if(isBreak()){
                return;
            }
            countClik++;
        }
        int getStato(){return stato;}
        void print(){
            cout<<"Lampadina={stato: "<<stato<<", countClick: "<<countClick<<", maxClick: "<<maxClick<<"} \n";
        }
        bool isBreak(){
            if(stato=2){
                return true;
            }
            if(countClick>maxClick){
                stato=2;
                return true;
            }
            return false;
        }
}
