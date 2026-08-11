#include <iostream>
#define PERIODICI 1
#define NUOVIMEDIA 2
#define LIBRI 3
using namespace std;

class Risorsa {
    private:
        string titolo;
        int codice_id;
        int dimensione_pagine;
        int minPag=0;
        int maxPag=0;
    public:
        Risorsa(string titolo, int codice_id, int dimensione_pagine){
            this->titolo=titolo;
            this->codice_id=codice_id;
            this->dimensione_pagine=dimensione_pagine;
        }
        Risorsa(string titolo, int codice_id){
            this->titolo=titolo;
            this->codice_id=codice_id;
            this->dimensione_pagine=dimensione_pagine;
        }
        int getDimensione_pagine(){
            return this->dimensione_pagine;
        }
        string geTitolo(){
            return this->titolo;
        }
        int getCodice_id(){
            return this->codice_id;
        }
        void setDimensione_pagine(int dimensione_pagine){
            this->dimensione_pagine=dimensione_pagine;
        }
        void stampa(){
            cout<<"Titolo: "<<titolo<<", id: "<<codice_id<<", dimensione_pagine: "<<dimensione_pagine<<endl;
        }
        virtual int getTipo()=0;
};
class Periodici: public Risorsa {
    private:
        int const minPag=20;
        int const maxPag=120;
    public:
        Periodici(string titolo, int codice_id, int dimensione_pagine):Risorsa(titolo, codice_id){
            if(dimensione_pagine>minPag&&dimensione_pagine<maxPag){
               setDimensione_pagine(dimensione_pagine);
            }
        }
        int getTipo(){
            return PERIODICI;
        }
};
class NewMedia: public Risorsa {
    private:
        int const minPag=100;
        int const maxPag=500;
    public:
        NewMedia(string titolo, int codice_id, int dimensione_pagine):Risorsa(titolo, codice_id){
            if(dimensione_pagine>minPag&&dimensione_pagine<maxPag){
                setDimensione_pagine(dimensione_pagine);
            }
        }
        int getTipo(){
            return NUOVIMEDIA;
        }
};
class Libri: public Risorsa {
    private:
        int const minPag=200;
        int const maxPag=1000;
    public:
        Libri(string titolo, int codice_id, int dimensione_pagine):Risorsa(titolo, codice_id){
            if(dimensione_pagine>minPag&&dimensione_pagine<maxPag){
                 setDimensione_pagine(dimensione_pagine);
            }
        }
        int getTipo(){
            return LIBRI;
        }
};
template <typename T>
struct Node{
    T val;
    Node<T>* parent;
    Node<T>* left;
    Node<T>* right;
};

template<typename T>
class Tree{
    private:
        Node<T>* root;
    public:
        Tree(){
            this->root=nullptr;
        }
        void add(T val){
            Node<T>* newNode= new Node<T>();
            newNode->left=nullptr;
            newNode->right=nullptr;
            newNode->val=val;

            if(!root){
                newNode->parent=nullptr;
                root=newNode;
                return;
            }
            Node<T>* curr= root;
            Node<T>* prev= nullptr;
            while(curr){
                prev=curr;
                if(val->getCodice_id()<curr->val->getCodice_id()){
                    curr=curr->left;
                }else{
                    curr=curr->right;
                }

            }
            if(val->getCodice_id()<prev->val->getCodice_id()){
                prev->left=newNode;
            }else{
                prev->right=newNode;
            }
            newNode->parent=prev;
        }
        void stampa(Node<T>* parent, int lvl=0){
            if(!parent){
                return;
            }
            stampa(parent->right, lvl+1);
            for(int i=0; i<lvl; i++){
                cout<<"\t";
            }
            cout<<"||-"<<parent->val->getCodice_id()<<endl;
            stampa(parent->left, lvl+1);

        }
        Node<T>* getRoot(){
            return this->root;
        }
        void inOrder(Node<T>* parent){
            if(!parent){
                return;
            }
            inOrder(parent->left);
            cout<<parent->val->stampa()<<endl;
            inOrder(parent->right);
        }
        Node<T>* getMin(Node<T>* parent){
            if(!parent){
                return nullptr;
            }
            Node<T>* curr= parent;
            while(curr->left){
                curr=curr->left;
            }
            return curr;
        }
        Node<T>* getMax(){
            if(!root){
                return nullptr;
            }
            Node<T>* curr= root;
            while(curr->right){
                curr=curr->right;
            }
            return curr;
        }
        void trapianta(Node<T>* destination, Node<T>* source){


            if(!destination->parent){
                this->root=source;
            }else if(destination->parent->left==destination){
               destination->parent->left=source;

            }else{
               destination->parent->right=source;
            }

            if(source!=nullptr){
                source->parent=destination->parent;
            }

        }
        Node<T>* searchNodeOf(T val){
            Node<T>* curr= root;
            while(curr){
                if(val->getCodice_id()==curr->val->getCodice_id()){
                   return curr;
                }
                if(val->getCodice_id()<curr->val->getCodice_id()){
                    curr=curr->left;
                }else{
                    curr=curr->right;
                }
            }
            return nullptr;

        }
        void deleteN(T val){
            if(!root){
                cout<<"lista vuota!"<<endl;
                return;
            }
            Node<T>* deleteNode= searchNodeOf(val);
            if(!deleteNode){
                cout<<"nodo non trovato!"<<endl;
                return;
            }
            if(!deleteNode->left){
                trapianta(deleteNode,deleteNode->right);
                delete deleteNode;
                return;
            }
            if(!deleteNode->right){
                trapianta(deleteNode,deleteNode->left);
                delete deleteNode;
                return;
            }
            Node<T>* next= getMin(deleteNode->right);
            if(next->parent!=deleteNode){
                trapianta(deleteNode->right, next);
                next->right=deleteNode->right;
            }
            trapianta(deleteNode, next);
            next->left=deleteNode->left;
            delete deleteNode;
        }
        void nMattoni(Node<T>* parent, int maxPag, int& countMattoniP=0, int& countMattoniNM=0, int& countMattoniL=0){
            if(!parent){
                return;
            }
            nMattoni(parent->right, maxPag,countMattoniP, countMattoniNM, countMattoniL );
            if(parent->val->getDimensione_pagine()<maxPag){
                return;
            }else{
                switch(parent->val->getTipo()){
                    case 1:
                        countMattoniP++;
                        break;
                    case 2:
                        countMattoniNM++;
                        break;
                    case 3:
                        countMattoniL++;
                        break;
                }
            }
            nMattoni(parent->left, maxPag, countMattoniP, countMattoniNM, countMattoniL);
        }
};
int main()
{
    Periodici * periodico1= new Periodici("1",11,100);
    Periodici * periodico2= new Periodici("a2",12,108);

    NewMedia* newMedia1= new NewMedia("c",21,350);
    NewMedia* newMedia2= new NewMedia("c2",22,300);

    Libri* libro1= new Libri ("e",31, 205);
    Libri* libro2= new Libri ("e",32, 300);

    Tree<Risorsa*> tree;
    tree.add(periodico1);
    tree.add(periodico2);
    tree.add(newMedia1);
    tree.add(newMedia2);
    tree.add(libro1);
    tree.add(libro2);

    tree.stampa(tree.getRoot());

    int nMattoniP=0;
    int nMattoniNM=0;
    int nMattoniL=0;
    tree.nMattoni(tree.getRoot(),250,nMattoniP,nMattoniNM,nMattoniL);
    cout << "Numero mattoni periodici: "<<nMattoniP << endl;
    cout << "Numero mattoni Nuovi Media: "<<nMattoniNM << endl;
    cout << "Numero mattoni Libri: "<<nMattoniL << endl;
    tree.deleteN(periodico1);
    tree.deleteN(periodico2);
    tree.deleteN(newMedia1);
    tree.deleteN(newMedia2);
    tree.deleteN(libro1);
    tree.deleteN(libro2);

    tree.stampa(tree.getRoot());
    return 0;
}
