
#include "PRODOTTO_H"
using namespace std;
struct Data{
    int day;
    int month;
    int year;
};
typedef struct Data Data;

class ProdottoAlimentare: public Prodotto{
    private:
         Data scadenza;
    public:
        ProdottoAlimentare(int code, double price, Data scadenza): Prodotto (code, price){
            this->scadenza=scadenza;
        }
        Prodotto();

        int getScadenza(){
            return this->scadenza;
        }
        void setScadenza(int day, int month, int year){
            this->day=da;
        }
        void setPrice(double price){
            return this->price;
        }

        ostream& operator << (ostream& out, const Prodotto& prodotto){
            out<<"Prodotto {code: "<<prodotto.code<<", price "<<prodotto.price<<"}";
            return out;
        }
        void leggi(){
            int code;
            double price;
            cout<<"input code:\n";
            cin>>code;
            cout<<"input price: \n";
            cin>>price;

            this->code=code;
            this->price=price;
        }
};



