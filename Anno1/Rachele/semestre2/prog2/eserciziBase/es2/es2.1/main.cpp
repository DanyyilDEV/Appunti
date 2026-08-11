#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream iFile("input.txt");
    ofstream oFile("output.txt");
    int a;
    int b;
    if (!iFile) {
        cerr << "Errore: il file input.txt non esiste!" << endl;
        return 1;
    }
    iFile>>a>>b;
    cout << "a " <<a<<"b "<<b<< endl;
    oFile<<a<<b;

    //getLine da fare
    return 0;
}
