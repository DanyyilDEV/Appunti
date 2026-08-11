#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int nRows;
    do{
        cout<<"inserisci il numero di righe:";
        cin>>nRows;
    }while(nRows<=5);

    cout<<"triangolo di pascal"<<endl;

    int r=0, c=0;
    for(int i=0; i<nRows; i++){
        int val=1;
        for(int j=0; j<i+1; j++){
            //int risultato=tgamma(i+1)/(tgamma(j+1*tgamma(i-j)));
            cout<<val<<"\t";
            val=val*(i-j)/(j+i);
        }
    }
    /*
    int matrix [][nRow];
    int center=nRow/2;
    for(int i=1; i<=nRow; i++){
       if(i==1 && j==1){
            matrix[center]=i;
            break;
       }
       matrix[];
    }
    */
    return 0;
}
