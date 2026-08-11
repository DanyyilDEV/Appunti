#include <iostream>

using namespace std;

enum Stato {OFF, ON, BROKEN};
class Lampadina{
    private:
        Stato stato=OFF;
        bool onCorrente=0;
        int countClick=0;
        int maxClick=100;
    public:
        Lampadina (int maxC){
            maxClick=maxC;
        }
        Lampadina (){
            maxClick=10;
        }
        void click(){

            countClick++;
            if(isBreak()){
                return;
            }

            if(stato==ON){
                stato=OFF;
            }else if (onCorrente){
                stato=ON;
            }
        }
        int getStato(){return stato;}
        int getMaxClick(){return maxClick;}
        void print(){
            cout<<"Lampadina={stato: "<<stato<<", countClick: "<<countClick<<", maxClick: "<<maxClick<<"} \n";
        }
        bool isBreak(){
            if(stato==2){
                return true;
            }
            if(countClick>maxClick){
                stato=BROKEN;
                return true;
            }
            int randomNum = rand() % 101;
            if(randomNum==0){
                stato=BROKEN;
                return true;
            }
            return false;
        }
        void aggiusta(){
            stato=OFF;
            countClick=0;
        }
        void setOnCorrente(bool on){
            onCorrente=on;
        }

};
class Interruttore{
    private:
        Lampadina ** lampadine;
        bool * onContatore=0;
        int nLampadine;


    public:
        Interruttore (int dim, Lampadina ** v, bool * on){
               nLampadine=dim;
               onContatore=on;
               lampadine = new Lampadina*[nLampadine];
               for(int i=0; i<nLampadine; i++){
                   lampadine[i]=v[i];
                }
        }
        void click(){
            for(int i=0; i<nLampadine; i++){
                   lampadine[i]->click();
            }
        }
        int getNLapadine(){return nLampadine;}
        void printLampadine(){
            cout<<"------------------------------\n";
             for(int i=0; i<nLampadine; i++){

                cout<<"Lampadina["<<i<<"]:";
                   lampadine[i]->print();

            }

            cout<<"------------------------------\n";
        }

        void updateCorrenteLampadine(){
            for(int i=0; i<nLampadine; i++){
                   lampadine[i]->setOnCorrente(*onContatore);
            }
        }
};
void iniziallizzaLampadine(int maxClick,  Lampadina ** lampadine, int nLampadine);
int menu();
void switchContatore(bool * onContatore, Interruttore * Interruttori[], int nInterruttori);
int main()
{

    cout<<"-------------Parte 1----------------------\n";
    Lampadina * lampadina = new Lampadina(5);
    lampadina->print();
    for(int i=0; i<10; i++){
        lampadina->click();
        lampadina->print();
    }
    srand(time(0));
    lampadina->aggiusta();
    lampadina->print();
    cout<<"-------------------------------------------\n";
    cout<<"-------------Parte 2\3----------------------\n";
    int nLampadine=2;

    Lampadina ** lampadine = new Lampadina*[nLampadine];
    iniziallizzaLampadine(5, lampadine, nLampadine);
    bool * onContatore= new bool(true);

    Interruttore * interruttore1= new Interruttore(nLampadine,lampadine, onContatore);

    Interruttore * interruttore2= new Interruttore(nLampadine,lampadine,  onContatore );
    Interruttore * interruttori []=  { interruttore1, interruttore2 };
    int nInterruttori=2;
    switchContatore(onContatore, interruttori, nInterruttori);
    int  scelta;
    do{
        scelta=menu();
        switch (scelta){
            case 1:
                interruttore1->click();
                interruttore1->printLampadine();
                break;
            case 2:
                interruttore2->click();
                interruttore2->printLampadine();
                break;
            case 3:
                switchContatore(onContatore, interruttori, nInterruttori);
                break;
        }
    }while(scelta!=4);
    cout<<"-------------------------------------------\n";
    return 0;
}

void iniziallizzaLampadine(int maxClick,  Lampadina ** lampadine , int nLampadine){
    for(int i=0; i<nLampadine; i++){
        lampadine[i]=new Lampadina(maxClick);
    }
}

int menu(){
    int scelta;
    do{
    cout<<"-------------Menu-------------------------\n";
    cout<<"1) clicca interruttore 1----------------------\n";
    cout<<"2) clicca interruttore 2----------------------\n";
    cout<<"3) Clicca contatatore----------------------\n";
    cout<<"4) esci----------------------\n";
    cin>>scelta;
    }while(scelta<1 || scelta>4);
    return scelta;
}
void switchContatore(bool * on, Interruttore * v[], int nInterruttori){
            if(*on){
                cout<<"\ncontatoreOFF\n";
                *on=false;
                for(int i=0; i<nInterruttori; i++){
                    v[i]->updateCorrenteLampadine();
                }

            }else{
                *on=true;
                cout<<"\ncontatoreON\n";
                for(int i=0; i<nInterruttori; i++){
                    v[i]->updateCorrenteLampadine();
                }
            }
}
