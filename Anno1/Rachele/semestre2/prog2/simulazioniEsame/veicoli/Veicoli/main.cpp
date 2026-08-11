#include <iostream>

using namespace std;



class Veicolo {
    private:
        string targa;
        int cilindrata;
        string modello;
        string anno;
        string marca;
    public:
        Veicolo( string targa, int cilindrata, string modello,string anno, string marca){
            this->targa=targa;
            this->cilindrata=cilindrata;
            this->modello=modello;
            this->anno=anno;
            this->marca=marca;
        }
        string getTarga()const{
            return this->targa;
        }
        int getCilindrata()const{
            return this->cilindrata;
        }
        string getModello()const{
            return this->modello;
        }
        string getAnno()const{
            return this->anno;
        }
        string getMarca()const{
            return this->marca;
        }

        virtual void stampa()=0;
};
class Auto: public Veicolo{
    private:
        int nPorte;
    public:
        Auto(string targa, int cilindrata, string modello,string anno, string marca, int nPorte=4): Veicolo(targa, cilindrata,  modello, anno, marca){
            this->nPorte=nPorte;
        }
        void stampa(){
            cout<<"Auto: \n";
            cout<<"Targa: "<<getTarga()<<"\t";
            cout<<"Nome modello: "<<getModello()<<endl;
            cout<<"Marca: "<<getMarca()<<"\t";
            cout<<"Anno fabbricazione:"<<getAnno()<<endl;
            cout<<"Cilindrata: "<<getCilindrata()<<"\t";
            cout<<"Numero porte: "<<this->nPorte;
        };

};
class Moto: public Veicolo{
    private:
        string tipo;
    public:
        Moto(string targa, int cilindrata, string modello,string anno, string marca, string tipo): Veicolo(targa, cilindrata,  modello, anno, marca){
            this->tipo=tipo;
        };
        void stampa(){
            cout<<"Auto: \n";
            cout<<"Targa: "<<getTarga()<<"\t";
            cout<<"Nome modello: "<<getModello()<<endl;
            cout<<"Marca: "<<getMarca()<<"\t";
            cout<<"Anno fabbricazione:"<<getAnno()<<endl;
            cout<<"Cilindrata: "<<getCilindrata()<<"\t";
            cout<<"Tipo moto: "<<this->tipo;
        };
};
template <typename T>
struct Node{
    T val;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;

};
template <typename T>
class Tree{
    private:
        Node<T>* root;
        int dim=0;
    public:
        Tree(){
            this->root= nullptr;
        }
        ~Tree(){
            deleteAllNodes(this->root);
        }
        void deleteAllNodes(Node<T>*  root){
            if(!root){
                return;
            }
            deleteAllNodes(root->left);
            deleteAllNodes(root->right);
            delete root;
        }
        Node<T>* getRoot()const{
            return this->root;
        }
        int getDim()const{
            return this->dim;
        };
        void stampaLog (Node<T>*  root, int level){
            if(!root){
                return;
            }
            stampaLog(root->right, level+1);
            for(int i=0; i<level; i++){
                cout<<"\t";
            }
            cout<<"--||"<<root->val->getTarga()<<endl;
            stampaLog(root->left, level+1);

            cout<<"\n";


        }
        void stampaPreOrder (Node<T>*  root){
            if(!root){
                return;
            }
            root->val->stampa();
            cout<<"\n";
            stampaPreOrder(root->left);
            stampaPreOrder(root->right);

        }
        void stampaInOrder (Node<T>*  root){
             if(!root){
                return;
            }
            stampaInOrder(root->left);
            root->val->stampa();
            cout<<"\n";
            stampaInOrder(root->right);
        }
        Node<T>*  searchInTree (Node<T>*  root, T val){
            if(!root){
                return nullptr;
            }
            Node<T>*  curr=this->root;
            Node<T>*  prev=nullptr;
            while(curr){
                prev=curr;
                if(curr->val->getTarga()==val->getTarga()){
                    return curr;
                }else if(curr->val->getTarga() > val->getTarga()){
                    curr=curr->left;
                }else{
                    curr=curr->right;
                }
            }
             return nullptr;
        }
        void add (T val){
            Node<T>*  newNodo = new Node<T>();
            newNodo->left=nullptr;
            newNodo->right=nullptr;
            newNodo->parent=nullptr;
            newNodo->val=val;
            this->dim++;

            if(!this->root){
                this->root=newNodo;
                return;
            }


            Node<T>*  curr=this->root;
            Node<T>*  prev=nullptr;

            while(curr){
                prev=curr;
                if(curr->val->getTarga()>=val->getTarga()){
                    curr=curr->left;
                }else{
                    curr=curr->right;
                }
            }

            if(prev->val->getTarga()>=val->getTarga()){
                    prev->left=newNodo;
            }else{
                    prev->right=newNodo;
            }
            newNodo->parent= prev;
        }
        void trapianta (Node<T>*  destination, Node<T>*  source){

            if(!destination->parent){
                this->root=source;
                return;
            }

            if(destination->parent->left==destination){
                destination->parent->left=source;
            }else{
                destination->parent->right=source;
            }
            if(source){
                 source->parent=destination->parent;
            }


        }
        void deleteNode(Node<T>* deleteN){
            if(!deleteN->left ){
                 trapianta(deleteN, deleteN->right);
                delete deleteN;
                return;
            }

            if(!deleteN->right ){
                trapianta(deleteN, deleteN->left);
                delete deleteN;
                return;
            }

            Node<T>*  next= getMin(deleteN->right);

            if(next->parent!=deleteN){
                trapianta(next, next->right);
                next->right=deleteN->right;
                next->right->parent=next;

            }

            trapianta(deleteN, next);
            next->left=deleteN->left;
            next->left->parent=next;
            delete deleteN;


        }

        Node<T>* getMin (Node<T>*  parent){
            if(!parent){
                return nullptr;
            }
            while(parent->left){
                parent=parent->left;
            }
            return parent;
        }
        Node<T>* getMax (Node<T>*  parent){
            if(!parent){
                return nullptr;
            }
            while( parent->right){
                parent=parent->right;
            }
            return parent;
        }
};
int main(){

    Auto * auto1 = new Auto("1", 769,"Panda FIRE","1986","Fiat",3);
    Auto * auto3 = new Auto("3", 4943,"Ferrari Testarossa","1984","Ferrari",3);
    Auto * auto5 = new Auto("5", 1199,"Peugeot 208","2019","Peugeot",5);

    Moto * moto4 = new Moto("4", 249,"YZF-R3","2014","Yamaha","SporMva");
    Moto * moto6 = new Moto("6", 749,"Honda Africa Twin 650","1983","Honda","Enduro");

   Tree <Veicolo*> tree;

    tree.add(auto3);
    tree.add(auto1);
    tree.add(auto5);
    tree.add(moto4);
    tree.add(moto6);

    tree.stampaLog(tree.getRoot(),0);
    cout<<"--------------"<<endl;

    Node<Veicolo*>* deleteN3=tree.searchInTree(tree.getRoot(), auto3);
    Node<Veicolo*>* deleteN5=tree.searchInTree(tree.getRoot(), auto5);
    tree.deleteNode(deleteN3);
    cout<<"--------------"<<endl;

    tree.stampaLog(tree.getRoot(),0);
    tree.deleteNode(deleteN5);
    cout<<"--------------"<<endl;
    tree.stampaLog(tree.getRoot(),0);

    tree.stampaPreOrder(tree.getRoot());
    cout<<"--------------"<<endl;
    /*
    tree.stampaInOrder(tree.getRoot());
    */
    return 0;

}
