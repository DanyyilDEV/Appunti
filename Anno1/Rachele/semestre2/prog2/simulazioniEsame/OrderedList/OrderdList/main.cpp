#include <iostream>

using namespace std;

class Studente{
    private:
        string nome;
        string matricola;
        int voto;
    public:
        Studente( ){

        }
        Studente( string nome,string matricola, int voto){
            this->nome=nome;
            this->matricola=matricola;
            this->voto=voto;
        }
        string getNome()const{
            return this->nome;
        }
        string getMatricola()const{
            return this->matricola;
        }
        int getVoto()const{
            return this->voto;
        }
        friend
        ostream& operator<<( ostream& os, const Studente& studente){
            os<<"Nome: "<<studente.getNome()<<", Matrico: "<<studente.getMatricola()<<", Voto: "<<studente.getVoto()<<endl;
            return os;
        }
        friend
        bool operator>(const Studente& studente1, const Studente& studente2 ){

           if(studente1.getVoto()>studente2.getVoto()){

                return true;
           }
           return false;
        }
        friend
        bool operator<(const Studente& studente1, const Studente& studente2 ){
           if(studente1.getVoto()<studente2.getVoto()){
                return true;
           }
            return false;
        }
        friend
        bool operator==(const Studente& studente1, const Studente& studente2 ){
           if(studente1.getVoto()==studente2.getVoto()){
                return true;
           }
            return false;
        }
};
template <typename T>
struct Nodo{
    T val;
    Nodo<T>* next;
};

template <typename T>
class OrderedList{
    private:
        Nodo<T>* head;
    public:
        OrderedList(){
            this->head=nullptr;
        }
        void push(T val){
            Nodo<T>* newNodo= new Nodo<T>;
            newNodo->val=val;

            Nodo<T>* curr= head;
            Nodo<T>* prev= nullptr;
            while(curr){
                if(curr->val>val){
                    break;
                }
                prev=curr;
                curr=curr->next;
            }
            if(curr==head){
                newNodo->next=head;
                head=newNodo;
                return;
            }
            if(!prev->next){
                prev->next=newNodo;
                newNodo->next=nullptr;
                return;
            }

            prev->next=newNodo;
            newNodo->next=curr;
        }
        void deleteNodeOf(T val){
            if(!head){
                cout<<"errore delete lista vuota";
                return;
            }

            Nodo<T>* curr= head;
            Nodo<T>* prev= nullptr;
            while(curr){
                if(curr->val==val){
                    break;
                }
                prev=curr;
                curr=curr->next;
            }
            if(!curr){
                cout<<"errore delete studente non presente";
                return;
            }
            if(curr==head){
                head=head->next;
                delete curr;
                return;
            }
            if(curr->next==nullptr){
                prev->next=nullptr;
                delete curr;
                return;
            }

            prev->next=curr->next;
            delete curr;
        }
        void deleteBetween(T minS, T maxS){
            Nodo<T>* curr= head;
            Nodo<T>* prev= nullptr;
            while(curr){
                if(curr->val>minS && curr->val<maxS ){
                    deleteNodeOf(curr->val);
                    curr=head;
                    prev= nullptr;
                    continue;

                }
                prev=curr;
                curr=curr->next;
            }
        }
        void stampa(){
            Nodo<T>* curr= head;
            while(curr){
                cout<<curr->val;
                curr=curr->next;
            }
        }
};

int main()
{
    /*
    Studente st1("A", "B",10);
    Studente st2("A", "B",12);
    Studente st3("A", "B",4);
    Studente st4("A", "B",7);

    oList.push(st1);
    oList.push(st2);
    oList.push(st3);
    oList.push(st4);
    oList.deleteBetween(st3,st2);
    oList.stampa();
    */
    OrderedList<Studente> oList;
    int n;
    string nome;
    string matricola;
    int voto;
    cout<<"Quanti studenti inserire?"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Studente["<<i<<"]"<<endl;
        cout<<"Nome:"<<endl;
        cin>>nome;
        cout<<"Matricola:"<<endl;
        cin>>matricola;
        cout<<"Voto:"<<endl;
        cin>>voto;
        oList.push(Studente(nome, matricola, voto));
    }
    cout << "_________________________" << endl;
    oList.stampa();
    cout << "_________________________" << endl;
    int minV;
    int maxV;
    cout<<"Voto minimo:"<<endl;
    cin>>minV;
    cout<<"Voto massimo:"<<endl;
    cin>>maxV;
    Studente minS(" ", " ", minV);
    Studente maxS(" ", " ", maxV);
    cout << "_________________________" << endl;
    oList.deleteBetween(minS, maxS);
    cout << "_________________________" << endl;
    cout<<"Studenti con voto compreso tra massimo e minimo eliminati"<<endl;
    cout << "_________________________" << endl;
    oList.stampa();
    return 0;
}
