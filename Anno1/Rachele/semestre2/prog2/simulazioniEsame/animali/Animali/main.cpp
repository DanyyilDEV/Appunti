#include <iostream>
using namespace std;


class Animale {

    private:
        string nome;
        string razza;
        int eta;
    public:
        Animale(){
        }
        Animale(string nome, string razza, int eta){
            this->nome=nome;
            this->razza=razza;
            this->eta=eta;
        }
        virtual ~Animale()=0;
        virtual string getNome()const{
            return this->nome;
        }

        virtual string getRazza()const{
            return this->razza;
        }
        virtual int getEta()const{
            return this->eta;
        }
        virtual string stampa()=0;
        virtual string getVerso() const=0;
};

class Cane: public Animale {

    private:
        string verso;
    public:
        Cane(){
        }
        Cane(string nome, string razza, int eta):  Animale( nome,  razza,  eta){
            //Animale(string nome, string razza, int eta);
            this->verso="BAU";
        }
        ~Cane(){
        }
        string stampa(){
            string s;
            s=getNome()+" è un cane di razza "+getRazza()+" di "+to_string(getEta())+" anni.\n";
            return s;
        };
        string StampaVerso(){
            string s;
            s="Il verso di "+getNome()+" è "+getVerso()+"\n";
            return s;
        };
        string getVerso()const{
            return this->verso;
        }
};

class Gatto: public Animale {

    private:
        string verso;
    public:
        Gatto(){
        }
        ~Gatto(){
        }
        Gatto(string nome, string razza, int eta):  Animale( nome,  razza,  eta){
            this->verso="MIAU";
        }
        string stampa(){
            string s;
            s=getNome()+" è un gatto di razza "+getRazza()+" di "+to_string(getEta())+" anni.\n";
            return s;
        };
        string StampaVerso(){
            string s;
            s="Il verso di "+getNome()+" è "+this->verso+"\n";
            return s;
        };
        string getVerso()const{
            return this->verso;
        }
};
template<typename T>
struct Nodo{
    T animale;
    Nodo<T>* left;
    Nodo<T>* right;
    Nodo<T>* parent;
};
template<typename T>
class Tree{
    private:
        Nodo<T>* root;
        int dim=0;

    public:

        Tree(){
            this->root=nullptr;
        }

        void deleteTreeNodes(Nodo<T>* parent){
            if(parent==nullptr){
                return;
            }

            deleteTreeNodes(parent->left);
            deleteTreeNodes(parent->right);
            delete parent->animale;
            parent->animale=nullptr;
            delete parent;

        }
        ~Tree(){
            deleteTreeNodes(this->root);

        }
        Nodo<T>* getRoot() const{
            return this->root;
        }
        void add(T animale){


            Nodo<T>* newNodo= new Nodo<T>();

            newNodo->animale=animale;
            newNodo->left=nullptr;
            newNodo->right=nullptr;
            this->dim++;
            if(!this->root){

                newNodo->parent=nullptr;
                this->root=newNodo;
                return;
            }

            Nodo<T>* curr=this->root;
            Nodo<T>* prev=nullptr;
            while(curr){
                prev=curr;

                if(animale->getNome().compare(curr->animale->getNome())<=0){
                    curr=curr->left;
                }else{
                    curr=curr->right;
                }

            }
            newNodo->parent=prev;
            if(animale->getNome().compare(prev->animale->getNome())<=0){
                prev->left=newNodo;
            }else{
                prev->right=newNodo;
            }
        }
        T searchT(string nome){
            if(!this->root){
                return nullptr;
            }
            Nodo<T>* curr=this->root;
            Nodo<T>* prev;
            while(curr){
                prev=curr;
                if(nome.compare(curr->animale->getNome())==0){
                    return curr->animale;
                }
                if(nome.compare(curr->animale->getNome())<0){
                    curr=curr->left;
                }else{
                    curr=curr->right;
                }
            }
            cout<<"Animale non presente\n";
            return nullptr;
        }
        void stampa(Nodo<T>* parent, int level) const{

            if(parent==nullptr){
                return;
            }
            stampa(parent->left, level+1);

            for(int i=0; i<level; i++){
                cout<<"\t";
            }
            cout<<"|-"<<parent->animale->getNome()+"\n";
            stampa(parent->right, level+1);
        }
        void stampaInfo(Nodo<T>* parent) const{

            if(parent==nullptr){
                return;
            }
            stampaInfo(parent->left);
            cout<<parent->animale->stampa()+"\n";
            stampaInfo(parent->right);
        }
        friend
        ostream& operator<< ( ostream& os,const Tree<T>& tree){
                if(tree.getRoot()==nullptr){
                    return os;
                }
                tree.stampa(tree.getRoot(), 0);
                return os;
        }
};


int main()
{
    Tree<Animale*>* tree= new Tree<Animale*>();

    Cane* cane1= new Cane("Fido", "Labrador", 3);

    Cane* cane2= new Cane("Rex", "Pastore", 5);
    Cane* cane3= new Cane("Milo", "Beagle", 1);
    Gatto* gatto1= new Gatto("Luna","Siamese", 2);
    Gatto* gatto2= new Gatto("Leo","Persiano", 4);
    Gatto* gatto3= new Gatto("Nala","Maine Coon", 3);

    tree->add(cane1);
    tree->add(cane2);
    tree->add(cane3);

    tree->add(gatto1);
    tree->add(gatto2);
    tree->add(gatto3);

    cout<<*tree;
    tree->stampaInfo(tree->getRoot());
    cout<<"------------------------------------------"<<endl;

    string nome;
    cout<<"Inserisci il nome di un animale da cercare:";
    cin>>nome;
    cout<<endl;
    Animale* animale=tree->searchT(nome);
    if(animale){
        cout<<animale->stampa();
    }

    cout<<"------------------------------------------"<<endl;
    delete tree;
    tree=nullptr;
    /**/
}

