
#include <iostream>

using namespace std;

string scelta();
int  vincitoreMance (string scelta1, string scelta2);
void gioco0 (int n);
void gioco1 (int n);
int lancioDadi();

int main()
{
    bool sceltaOk=false;
    int giocoTipo;
    do{
        cout<<"Inserire numero del gioco scelto"<<endl;
        cout<<"0) sasso carta forbice"<<endl;
        cout<<"1) dadi"<<endl;
        cin>>giocoTipo;
        if(cin.fail()){
            cout<<"errore inserimento"<<endl;
            cin.clear();
            //cin.ignore(numeric_limits<streamsize>:max(), )
            continue;
        }
        if(giocoTipo!=0 && giocoTipo!=1  ){
            cout<<"errore valori ammissibili [0 o 1]"<<endl;
            continue;
        }
        sceltaOk=true;

    }while(!sceltaOk);

    cout<<"giocoTipo="<<giocoTipo<<endl;
    cout<<"---------------------------------"<<endl;
    srand(time(NULL));
    int n;
    cout << "Inserisci N" << endl;
    cin>>n;
    switch (giocoTipo){
        case 0:
            gioco0(n);
            break;
        case 1:
            gioco1(n);
            break;
    }

}

string scelta(){
     string casi[]={"sasso", "carta", "forbice"};
     string caso=casi[rand()%3];
     return caso;
}
int  vincitoreMance (string scelta1, string scelta2){
    if(scelta1== scelta2){
        return 0;
    }
    if((scelta1== "sasso" &&  scelta2== "forbice" )||(scelta1== "carta" &&  scelta2== "sasso" )|| (scelta1== "forbice" &&  scelta2== "carta" )){
        return 1;
    }
    return -1;
}
void gioco0 (int n){
    int contWin1=0;
    int contWin2=0;
    for(int i=0; i<n; i++){
        cout<<"Mance N: "<<i<<endl;
        string scelta1=scelta();
        string scelta2=scelta();
        cout<<"giocatore1: "<<scelta1<<endl;
        cout<<"giocatore2: "<<scelta2<<endl;
        int vincitore=vincitoreMance(scelta1, scelta2);
        switch(vincitore){
            case 0:
                cout<<"pareggio\n ";
                break;
            case 1:
                cout<<"Mance vinta giocatore1\n ";
                contWin1++;
                break;
            case -1:
                cout<<"Mance vinta giocatore2\n ";
                contWin2++;
                break;
        }

    }
    if(contWin1==contWin2){
        cout<<"Pareggio \n";
        return;
    }
    if(contWin1>contWin2){
        cout<<"Giocatore1 Hai vinto \n";
        return;
    }
    cout<<"Giocatore2 Hai vinto \n";
}

void gioco1 (int n){
    int somma=0;
    for(int i=0; i<n; i++){
        cout<<"Mance N: "<<i<<endl;
        int valD1=lancioDadi();
        int valD2=lancioDadi();
        cout<<"D1: "<<valD1<<endl;
        cout<<"D2: "<<valD2<<endl;
        somma+=valD1+valD2;
        cout<<"update somma: "<<somma<<endl;
        cout<<"__________________________________"<<endl;
    }
}
int lancioDadi(){
    int esito= (((rand()%6)+1)+(rand()%6)+1);
    return esito;
}
