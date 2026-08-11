#include <iostream>

using namespace std;

template <typename T>
class Nodo{
    public :
        Nodo () {}
        T val;
        Nodo <T>* left;
        Nodo <T>* right;
        Nodo <T>* parent;
};

template <typename T>
class BST{
    public:
        BST(): root (nullptr ) {}
        void inserisci(T);
        void inOrder()const;
        void preOrder()const;
        void postOrder()const;

        int altezza (Nodo <T>* p) const ;
        int altezza () const {return altezza (root);}

        Nodo <T>* ricerca (T val);
        Nodo <T>* getRadice () {return root;};



        friend ostream& operator << (ostream& out, const BST<T>& t){

            int h = t.altezza (t.root);
            cout<<"Albero di oggetti... "<<endl;
            for(int i=0; i<h; i++){
                stampaLivello(t.root, i);
                cout<<endl;
            }

            return out;

        }

    private :
        Nodo <T>* root;
        int numElem=0;
        void inOrder(Nodo<T>*p) const;
        Nodo <T>* ricerca (Nodo <T> * x, T val);

};

template <typename T>
void stampaLivello (Nodo <T>* p, int level){

    if(p== nullptr){
        cout<<"_\t";
        return;
    }
    if(level==0)cout <<p->val<<"\t";
    else if(level >0){
        stampaLivello(p->left, level-1);
        stampaLivello(p->right, level-1);
    }

}

template <typename T>
void BST<T>:: inserisci (T _val){
    Nodo <T>* nuovo = new Nodo <T>;
    Nodo <T>* x= root, *y=nullptr;

    nuovo->val= _val;
    nuovo->left=nuovo->right= nullptr;

    while(x!=nullptr){
        y=x;
        if(_val<x->val){
            x= x->left;
        }else{
            x=x->right;
        }
    }
    nuovo->parent= y;
    if(y==nullptr){
        root= nuovo;
    }else if(_val< y->val){
        y->left=nuovo;
    }else{
            y->right= nuovo;

    }
    numElem++;
}
template <typename T>
int BST<T>:: altezza (Nodo <T>* p) const{
    if(p=nullptr){
        return 0;
    }
    int lh=altezza(p->left);
    int rh= altezza(p->right);


    if(lh>rh){
        return (lh+1);
    }else{
        return (rh+1);
    }
}
int main()
{
    BST<int> tree;
    tree.inserisci(10);
    tree.inserisci(2);
    tree.inserisci(1);
    tree.inserisci(15);
    tree.inserisci(100);
    tree.inserisci(7);

    cout<<tree<<endl;
    return 0;
}
