#include <iostream>
#include <random>
#define STUDENTE 0
#define LAVORATORE 1
#define PENSIONATO 2

using namespace std;


class Persona{
    protected:
        string names[6]={"Luigi", "Salvo", "Ludovico", "Pippo", "Silvio", "Paolo"};
        string surNames[4]={"L", "S", "P", "M"};
        string nome;
        string cognome;
        int eta;
        int etaMin;
        int etaMax;

    public:
        Persona(){
            this->nome=names[rand()%6];
            this->cognome=surNames[rand()%4];
        }
        Persona(string nome,string cognome, int eta){
            this->nome=nome;
            this->cognome=cognome;
            this->eta=eta;
        }
        ~Persona(){}

        virtual void stampa(){
            cout<<endl;
            cout<<"Nome:"<<this->nome<<endl;
            cout<<"Cognome:"<<this->cognome<<endl;
            cout<<"Eta':"<<this->eta<<endl;
            cout<<endl;
        }
        string getNome(){
            return this->nome;
        }
        string getCognome(){
            return this->cognome;
        }
        int getEta(){
            return this->eta;
        }
        virtual int getTipo()=0;
};

class Studente: public Persona{
    private:

    public:
        Studente(): Persona(){
            this->etaMax=30;
            this->etaMin=5;
             this->eta=rand()%(etaMax-etaMin+1)+etaMin;
        }
        Studente(string nome,string cognome, int eta){
            this->nome=nome;
            this->cognome=cognome;
            if(etaMax>=eta && etaMin<=eta){
                this->eta=eta;
            }else{
                 this->eta=(rand()%etaMax)+etaMin;
            }

        }
        ~Studente(){}
        virtual void stampa(){
            cout<<"Studente"<<endl;
            cout<<"Nome:"<<this->nome<<endl;
            cout<<"Cognome:"<<this->cognome<<endl;
            cout<<"Eta':"<<this->eta<<endl;
            cout<<endl;
        }
        int getTipo(){
            return STUDENTE;
        }

};
class Lavoratore: public Persona{
    private:

    public:
        Lavoratore(): Persona(){
            this->etaMax=70;
            this->etaMin=20;
             this->eta=rand()%(etaMax-etaMin+1)+etaMin;
        }
        Lavoratore(string nome,string cognome, int eta){
            this->nome=nome;
            this->cognome=cognome;
            if(etaMax>=eta && etaMin<=eta){
                this->eta=eta;
            }else{
                 this->eta=(rand()%etaMax)+etaMin;
            }

        }
        ~Lavoratore(){}
        virtual void stampa(){
            cout<<"Lavoratore"<<endl;
            cout<<"Nome:"<<this->nome<<endl;
            cout<<"Cognome:"<<this->cognome<<endl;
            cout<<"Eta':"<<this->eta<<endl;
            cout<<endl;
        }

        int getTipo() {
            return LAVORATORE;
        }
};
class Pensionato: public Persona{
    private:

    public:
        Pensionato(): Persona(){
            this->etaMax=95;
            this->etaMin=65;
             this->eta=rand()%(etaMax-etaMin+1)+etaMin;
        }
        Pensionato(string nome,string cognome, int eta){
            this->nome=nome;
            this->cognome=cognome;
            if(etaMax>=eta && etaMin<=eta){
                this->eta=eta;
            }else{
                 this->eta=(rand()%etaMax)+etaMin;
            }

        }
        ~Pensionato(){}
        virtual void stampa(){
            cout<<"Pensionato"<<endl;
            cout<<"Nome:"<<this->nome<<endl;
            cout<<"Cognome:"<<this->cognome<<endl;
            cout<<"Eta':"<<this->eta<<endl;
            cout<<endl;
        }
        int getTipo(){
            return PENSIONATO;
        }

};
template<typename T>
struct Node{
    T val;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
};
template<typename T>
class Tree{
    private:
        Node<T>* root;
    public:
        Tree(){
            this->root=nullptr;
        }
        ~Tree(){
            deleteAllNodes(root);
        }
        void deleteAllNodes(Node<T>* parent){
            if(!parent){
                return;
            }
            deleteAllNodes(parent->left);
            deleteAllNodes(parent->right);
            delete parent;
        }
        void add(T val){
            Node<T>* newNode = new Node<T>();
            newNode->left=nullptr;
            newNode->parent=nullptr;
            newNode->right=nullptr;
            newNode->val=val;

            if(!root){
                this->root=newNode;
                return;
            }
            Node<T>* curr = this->root;
            Node<T>* prev = nullptr;
            while(curr){
                prev=curr;
                if(val->getEta()<=curr->val->getEta()){
                    curr=curr->left;
                }else{
                    curr=curr->right;
                }
            }
            if(val->getEta()<=prev->val->getEta()){
                    prev->left=newNode;
            }else{
                    prev->right=newNode;
            }
            newNode->parent=prev;

        }
        void stampa(Node <T>* parent, int lvl){
            if(!parent){
                return;
            }

            stampa(parent->right,lvl+1);
            for(int i=0; i<lvl; i++){
                cout<<"\t";
            }
            cout<<"||-"<<parent->val->getEta()<<endl;
            stampa(parent->left,lvl+1);

        }
        Node<T>* getRoot() const{
            return this->root;
        }

};
void stampaMedia(const Tree<Persona*>& tree );
template<typename T>
void calcolaMedia(const Node<T>* parent, int& countS, int& sommaS,int& countL, int& sommaL, int& countP,  int& sommaP );
int main()
{
    srand(time(0));
    Studente* s1= new Studente();
    Studente* s2=new Studente();

    Lavoratore* l1=new Lavoratore();
    Lavoratore* l2=new Lavoratore();

    Pensionato* p1=new Pensionato();
    Pensionato* p2=new Pensionato();

    s1->stampa();
    s2->stampa();
    l1->stampa();
    l2->stampa();
    p1->stampa();
    p2->stampa();
    Tree<Persona*> tree;

    tree.add(s1);
    tree.add(s2);

    tree.add(l1);
    tree.add(l2);

    tree.add(p1);
    tree.add(p2);
    tree.stampa(tree.getRoot(),0);
    stampaMedia(tree);
    return 0;
}
void stampaMedia(const Tree<Persona*>& tree ){


    if(!tree.getRoot()){
        return;
    }
    int countS=0;
    int sommaS=0;
    int countL=0;
    int sommaL=0;
    int countP=0;
    int sommaP=0;


 calcolaMedia(tree.getRoot(),countS, sommaS, countL, sommaL, countP,  sommaP);
    cout<<"Media Studenti:  "<<(double)sommaS/countS<<endl;
    cout<<"Media Lavoratori:    "<<(double)sommaL/countL<<endl;
    cout<<"Media Pensionati:    "<<(double)sommaP/countP<<endl;


}
template<typename T>
void calcolaMedia(const Node<T>* parent, int& countS, int& sommaS,int& countL, int& sommaL, int& countP,  int& sommaP ){
    if (!parent) {
        return;
    }
   calcolaMedia(parent->left,countS, sommaS, countL, sommaL, countP,  sommaP);
   int tipo= parent->val->getTipo();
   switch(tipo){
        case 0:
            countS++;
            sommaS+= parent->val->getEta();
            break;
        case 1:
            countL++;
            sommaL+= parent->val->getEta();
            break;
        case 2:
            countP++;
            sommaP+= parent->val->getEta();
            break;
   }
   calcolaMedia(parent->right,countS, sommaS, countL, sommaL, countP,  sommaP);
}
