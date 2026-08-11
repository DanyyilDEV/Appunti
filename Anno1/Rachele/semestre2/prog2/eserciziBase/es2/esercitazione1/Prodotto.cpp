
#include "PRODOTTO_H"
using namespace std;


class Prodotto{

    public:
        Automobile(int code, double price){
            this->code=code;
            this->price=price;
        }
        Automobile();

        int getCode(){
            return this->code;
        }
        double getPrice(){
            return this->price;
        }

        void setCode(int code){
            return this->code;
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


