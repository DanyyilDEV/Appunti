#include <iostream>

using namespace std;

typedef struct Dato Dato;
struct  Dato {
    int n;
};

template <typename T>
class Nodo {
    private:
        T val;
        Nodo<T> * right;
        Nodo<T> * left;
        Nodo<T> * parent;
    public:
        Nodo<T> (){
            this->right=nullptr;
            this->left=nullptr;
            this->parent=nullptr;
        }
        Nodo<T> * getRight(){
            return this->right;
        }
        Nodo<T> * getLeft(){
            return this->left;
        }
        Nodo<T> * getParent(){
            return this->parent;
        }
        T getValue(){
            return this->val;
        }

        void setRight(Nodo <T>* nodo){
            this->right=nodo;
        }
        void setLeft(Nodo <T>* nodo){
            this->left=nodo;
        }
        void setParent(Nodo <T>* nodo){
            this->parent=nodo;
        }
        void setValue(T val){
            this->val=val;
        }

};

template <typename T>
class Tree {
    private:
        Nodo<T>* root;
        int numElements;
    public:
        Tree(){
            this->root=nullptr;
            this->numElements=0;
        }
        ~Tree() {
            distruggiRicorsivo(root);
        }
        void distruggiRicorsivo(Nodo<T>* n) {
            if (n == nullptr) return;
            distruggiRicorsivo(n->getLeft());  // Prima i figli
            distruggiRicorsivo(n->getRight());
            delete n;                         // Poi distruggo il nodo corrente
        }
        Nodo<T>* getRoot() const{
            return this->root;
        }
        int getNumElements() const{
            return this->numElements;
        }
        void static preOrder (Nodo <T>* root){
            if(root== nullptr){
                return;
            }
            cout<<root->getValue()<<" ";
            preOrder(root->getLeft());
            preOrder(root->getRight());
        }
        void static inOrder (Nodo <T>* root){
            if(root== nullptr){
                return;
            }
            inOrder(root->getLeft());
            cout<<root->getValue()<<" ";
            inOrder(root->getRight());
        }
        void static postOrder (Nodo <T>* root){
             if(root== nullptr){
                return;
            }
            postOrder(root->getLeft());
            postOrder(root->getRight());
            cout<<root->getValue()<<" ";

        }
        Nodo<T> * searchValue (T t){
            if(this->root==nullptr){
                return nullptr;
            }
            Nodo<T> * nodo= this->root;
            while(nodo!=nullptr && nodo->getValue()!=t){
                   if(t<nodo->getValue()){
                        nodo=nodo->getLeft();
                        continue;
                   }
                   nodo=nodo->getRight();
                   continue;
            }
            if(nodo==nullptr){
                cout<<"non trovato\n";
            }else{
                cout<<"trovato\n";
            }
            return nodo;


        }
        Nodo<T> * getMin (Nodo<T> * subRoot){
            if(subRoot==nullptr){
                return nullptr;
            }

            while(subRoot->getLeft()!=nullptr){
                   subRoot= subRoot->getLeft();
            }
            return subRoot;
        }
        Nodo<T> * getMax (Nodo<T> * subRoot){
            if(subRoot==nullptr){
                return nullptr;
            }
            while(subRoot->getRight() != nullptr){
                   subRoot= subRoot->getRight();
            }
            return subRoot;
        }
        Nodo<T> * getNextOf (Nodo<T> * child){
            if(this->root==nullptr){
                return nullptr;
            }
            if(child->getRight()){
                    return getMin(child->getRight());
            }
            Nodo<T> * parent= child->getParent();
            while(parent!= nullptr && child==parent->getRight()){
                   child=parent;
                   parent=parent->getParent();
            }
            return parent;
        }
        void insertNode(T val){
            Nodo<T>* nuovo = new Nodo <T>;
            Nodo<T>* x = root;
            Nodo<T>* y = nullptr;

            nuovo->setValue(val);
            nuovo->setLeft(nullptr);
            nuovo->setRight(nullptr);

            while(x!=nullptr){
                y=x;
                if(val<x->getValue()){
                    x=x->getLeft();
                }else{
                    x=x->getRight();
                }

            }
            nuovo->setParent(y);
            this->numElements++;
            if(y==nullptr){
                root=nuovo;
                return;
            }
            if(val<y->getValue()){
                y->setLeft(nuovo);
                return;
            }
            y->setRight(nuovo);
        }


        void stampaLivello (Nodo<T> *parent, int level=0) const{
            if (parent == nullptr) return;

            // 1. Stampa prima il sottoalbero destro (apparirà in alto)
            stampaLivello(parent->getRight(), level + 1);

            // 2. Stampa il nodo corrente preceduto da tabulazioni
            for (int i = 0; i < level; i++) {
                cout << "\t";
            }
            cout << "|-- " << parent->getValue() << endl;

            // 3. Stampa il sottoalbero sinistro (apparirà in basso)
            stampaLivello(parent->getLeft(), level + 1);

        }
        int getAltezza (Nodo <T>* parent)const {
            if(parent==nullptr){
                return 0;
            }

            int leftH=getAltezza(parent->getLeft());
            int rightH=getAltezza(parent->getRight());

            return (leftH > rightH ? leftH : rightH) + 1;
        }
        friend
        ostream& operator << ( ostream& out, const Tree <T> & tree ){

            tree.getAltezza(tree.root);
            cout << "Albero di oggetti...: " << endl;
            tree.stampaLivello(tree.getRoot());
            return out;
        }

        void trapianta (Nodo <T>* deleteNode, Nodo <T>* newNode ){
            if(deleteNode->getParent()==nullptr){
                this->root=newNode;
                return;
            }
            if(deleteNode->getParent()->getLeft()==deleteNode){
                deleteNode->getParent()->setLeft(newNode);
            }else{
                deleteNode->getParent()->setRight(newNode);
            }
            if(newNode!=nullptr){
                newNode->setParent(deleteNode->getParent());
            }
        }

        void  deleteNodeFromTree (Nodo <T>* deleteNode){
            if(deleteNode->getRight()==nullptr){
                trapianta(deleteNode, deleteNode->getLeft());
                delete deleteNode;
                return;
            }
            if(deleteNode->getLeft()==nullptr){
                trapianta(deleteNode, deleteNode->getRight());
                delete deleteNode;
                return;
            }

            Nodo <T>*  nextNode= getMin(deleteNode->getRight());
            if(nextNode->getParent()!=deleteNode){
                trapianta(nextNode, nextNode->getRight());
                nextNode->setRight(deleteNode->getRight());
                nextNode->getRight()->setParent(nextNode);
            }
            trapianta(deleteNode, nextNode);
            nextNode->setLeft(deleteNode->getLeft());
            nextNode->getLeft()->setParent(nextNode);
            delete deleteNode;
        }

};



int main()
{
    cout << "Hello world!" << endl;
    Tree<int> tree;
    Dato dato;
    dato.n=23;

    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(12);
    tree.insertNode(11);
    tree.insertNode(7);
    cout<<tree<<endl;
    cout<<"___________________________"<<endl;

    Tree <int>:: preOrder(tree.getRoot());
    cout<<endl;
    Tree <int>:: inOrder(tree.getRoot());
    cout<<endl;
    Tree <int>::postOrder(tree.getRoot());
    cout<<endl;
    cout<<"___________________________"<<endl;
    cout<<endl;
    cout<<tree.searchValue(5)<<endl;
    cout<<tree.searchValue(1111);
    cout<<endl;
    cout<<"___________________________"<<endl;

    cout<<"Max: "<<tree.getMax(tree.getRoot())->getValue()<<endl;
    cout<<"Min: "<<tree.getMin(tree.getRoot())->getValue()<<endl;

    cout<<"Nextof MIN: "<<tree.getNextOf(tree.getMin(tree.getRoot()))->getValue()<<endl;
    cout<<"___________________________"<<endl;
    cout<<"Delete 10: ";
    cout<<endl;
    Nodo <int>* deleteNode=tree.searchValue(10);
    tree.deleteNodeFromTree(deleteNode);
    cout<<tree<<endl;
    cout<<"___________________________"<<endl;
    return 0;
}
