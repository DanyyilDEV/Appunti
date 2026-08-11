/*
    Questa classe implementa un BST per tipi generici
*/
#include<iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <strings.h>
using namespace std;

template <typename T>
class Nodo{
    public:
    Nodo(){}
	T val;
	Nodo<T>* left;
	Nodo<T>* right;
	Nodo<T>* padre;
};


template <typename T>
class BST{
public:
	BST() : radice(nullptr) {};
	void inserisci(T valore);

	void inOrder()const;
	void preOrder()const;
	void postOrder()const;
	int altezza(Nodo<T>* p)const;
	int altezza()const { return altezza(radice);}
    Nodo<T>* ricercaRicorsiva(T valore);
    Nodo<T>* getRadice(){return radice;}
    Nodo<T>* getMinNode(Nodo<T> * subroot);
    Nodo<T>* getMaxNode(Nodo  <T>* subroot) ;
    Nodo<T>* getNext(Nodo <T>*  subroot);
    void  trapianta(Nodo <T>*  to, Nodo <T>* from );
    int distanceFrom(Nodo<T>* subroot, T valore);
    void deleteFromTree(T valore);
    Nodo<T>* LCA (Nodo<T>* subroot, T x,T y);

    friend
	ostream& operator<<(ostream& out, const BST<T>& t){
        int h = t.altezza(t.radice);
        cout << "Albero di oggetti Persona:" << endl;
        for (int i=0; i<h; i++) {
            stampaLivello(t.radice, i);
            cout << endl;
        }
        return out;
	}


private:
	Nodo<T>* radice;

	int num_elem = 0;
	void inOrder(Nodo<T>* p)const;
	void preOrder(Nodo<T>* p)const;
	void postOrder(Nodo<T>* p)const;
    Nodo<T>* ricercaRicorsiva(Nodo<T>* x, T valore);
};

/* stampa i nodi ad un dato livello */
template <typename T>
void stampaLivello(Nodo<T>* p, int level)
{

    // Il nodo non contiene una chiave
    if (p == nullptr){
        cout << "_\t";
        return;
        }

    if (level == 0)
        cout << p->val << "\t";
    else if (level > 0){
        stampaLivello(p->left, level-1);
        stampaLivello(p->right, level-1);
    }
}

template <typename T>
void BST<T>::inserisci(T valore) {
	Nodo<T>* nuovo= new Nodo<T>;
	Nodo<T>* x=radice, *y=nullptr;

	nuovo->val=valore;
	nuovo->left=nuovo->right=nullptr;

	// cerco una foglia disponibile dove inserirlo
	while(x!=nullptr) {
		y=x; // y tiene traccia del padre di x
		if (valore < x->val)
            x=x->left;
		else
            x=x->right;
    }
	nuovo->padre=y;
	if (y==nullptr)
        radice=nuovo;
	//In tal caso l'albero è vuoto
	else if (valore < y->val)
        y->left=nuovo;
	else
        y->right=nuovo;

    num_elem++;
}

template <typename T>
void BST<T>::inOrder(Nodo<T>* p)	const{
	if (p!=nullptr) {
		inOrder(p->left);
		cout << p->val << "\t";
		inOrder(p->right);
		}
}
// versione pubblica
template <typename T>
void BST<T>::inOrder()	const{inOrder(radice);}

template <typename T>
void BST<T>::preOrder(Nodo<T>* p)	const{
	if (p!=nullptr) {
		cout << p->val << "\t";
		preOrder(p->left);
		preOrder(p->right);
		}
}
template <typename T>
void BST<T>::preOrder()	const{preOrder(radice);}

template <typename T>
void BST<T>::postOrder(Nodo<T>* p)	const{
	if (p!=nullptr) {
		postOrder(p->left);
		postOrder(p->right);
		cout << p->val << "\t";
		}
}
template <typename T>
void BST<T>::postOrder() const{ postOrder(radice);}

template <typename T>
int BST<T>::altezza(Nodo<T>* p)const{
    if (p == nullptr)
        return 0;
    else
    {
        int lheight = altezza(p->left);
        int rheight = altezza(p->right);

        if (lheight > rheight)
            return(lheight + 1);
        else
          return(rheight + 1);
    }
}


template <typename T>
Nodo<T>* BST<T>::ricercaRicorsiva(T valore) {
    return ricercaRicorsiva(radice,valore);
}
template <typename T>
Nodo<T>* BST<T>::ricercaRicorsiva(Nodo<T>* x, T valore) {
    if(x==nullptr || x->val==valore)
        return x;

    cout << endl << "-->" << x->val;
    if(valore < x->val)
        return ricercaRicorsiva(x->left, valore);
    else
        return ricercaRicorsiva(x->right, valore);
}

template <typename T>
int BST<T>::distanceFrom(Nodo<T>* subroot, T valore) {
    int countDistance=0;
    while(subroot!=nullptr && subroot->val!=valore){
        countDistance++;
        if(valore < subroot->val)
            subroot=subroot->left;
        else
             subroot=subroot->right;

    }

    return (subroot == nullptr) ? -1:countDistance ;


}
template <typename T>
Nodo<T>* BST<T>::LCA (Nodo<T>* subroot, T x,T y) {
    while(subroot && subroot->val!=x && y!= subroot->val){
        if(x<subroot->val && y<subroot->val){
            subroot=subroot->left;
        }else if(x>subroot->val && y>subroot->val){
            subroot=subroot->right;
        }else{
            break;
        }
    }
    return subroot;
}

template <typename T>
Nodo<T>* BST<T>::getMinNode(Nodo<T> * subroot) {
    if(subroot==nullptr){
        return nullptr;
    }
    Nodo <T>* nodo = subroot;
    while(subroot->left){
        subroot=subroot->left;
    }
    return subroot;

}

template <typename T>
Nodo<T>* BST<T>::getMaxNode(Nodo <T> * subroot) {
    if(subroot==nullptr){
        return nullptr;
    }
    Nodo <T>* nodo = subroot;
    while(subroot->right){
        subroot=subroot->right;
    }
    return subroot;

}
template <typename T>
Nodo<T>* BST<T>::getNext(Nodo <T>*  subroot) {
    if(!subroot){
        return nullptr;
    }
    if(subroot->right){
        return  this->getMinNode(subroot->right);
    }
    Nodo <T>* child= subroot;
    Nodo <T>* parent=subroot->padre;
    while(parent && child==parent->right){
        child= parent;
        parent= parent->padre;
    }
    return parent;

}

template <typename T>
void  BST<T>::trapianta(Nodo<T> *  from, Nodo <T>*  to ) {
    if(from->padre== nullptr){
        this->radice=to;
    }else if(from->padre->left==from){
        from->padre->left=to;
    }else{
        from->padre->right=to;
    }
    if(to){
        to->padre=from->padre;
    }
}

template <typename T>
void BST<T>::deleteFromTree(T valore) {
    Nodo <T>* deleteNodo= ricercaRicorsiva( this->radice, valore);
    if(!deleteNodo){
        cout<<"nodo non trovato";
        return;
    }

    if(deleteNodo->right==nullptr){
        trapianta(deleteNodo, deleteNodo->left);
        delete deleteNodo;
        return;
    }
    if(deleteNodo->left==nullptr){
        trapianta(deleteNodo, deleteNodo->right);
        delete deleteNodo;
        return;
    }
    Nodo <T>* next = getNext(deleteNodo);
    if(next->padre != deleteNodo){
        trapianta(next, next->right);
        next->right= deleteNodo->right;
        deleteNodo->right->padre=next;
    }
    trapianta(deleteNodo, next);
    next->left=deleteNodo->left;
    deleteNodo->left->padre=next;

    delete deleteNodo;
    return;

}
void readFile(BST<char>&  bstChar, BST<int>& bstint);
void opInt(BST<int>& bst, int dim, ifstream& infile);
void opChar(BST<char>& bst, int dim, ifstream& infile);
int main (){
    BST <int> bstInt;
    BST <char> bstChar;
    readFile(bstChar, bstInt);

    cout<<bstInt;
    cout<<bstChar;

}
void readFile(BST<char>&  bstChar, BST<int>& bstInt){
    ifstream inFile("inputDistanze.txt");
    if(!inFile.is_open()){
        cout<<"errore apertura file";
    }
    string  tipo;
    int dim;

    while (inFile >> tipo)
    {
        inFile >> dim;
        if(tipo.compare("int")==0){
            opInt(bstInt,dim, inFile);
        }else{
            opChar(bstChar,dim, inFile);
        }
    }

    inFile.close();

}
void opInt(BST<int>& bst, int dim, ifstream& inFile){
    string valString;

    for(int i=0; i<dim; i++){

        if (inFile >> valString) {
            stringstream ss(valString);
            string op;

            getline(ss, op, ':');
            getline(ss, valString);

            try {
                int val = stoi(valString);
                if (op.compare("ins") == 0) {
                    bst.inserisci(val);
                } else {
                    bst.deleteFromTree(val);
                }
            } catch (const std::invalid_argument& e) {
                cout << "\n[ERRORE STOI] Tentato di convertire: '" << valString << "' che non e' un numero!" << endl;
                cout << "Operazione letta correntemente: " << op << endl;
                return; // Interrompiamo per evitare crash a catena
            }
        }
    }
    string  sk, sh;
    if(inFile>>sk && inFile>>sh){
        int k = stoi(sk);
        int h = stoi(sh);
         Nodo<int>* antenato=bst.LCA(bst.getRadice(),k,h);

        cout<<" Distance k="<<k<<"- h="<<h<<"-> "<<bst.distanceFrom(antenato,h)+bst.distanceFrom(antenato,k)<<endl;
    }
}
void opChar(BST<char> & bst, int dim, ifstream& inFile){

     string valString;

    for(int i=0; i<dim; i++){

        if (inFile >> valString) {
            stringstream ss(valString);
            string op;
            char carattere;
            getline(ss, op, ':');
            getline(ss, valString);
            carattere=valString[0];
            try {
                if (op.compare("ins") == 0) {

                    bst.inserisci(carattere);
                } else {
                    bst.deleteFromTree(carattere);
                }
            } catch (const exception e) {
                cout << "\n[ERRORE STOI] Tentato di convertire: '" << carattere << "' che non e' un carattere!" << endl;
                cout << "Operazione letta correntemente: " << op << endl;
                return; // Interrompiamo per evitare crash a catena
            }
        }
    }
    string  sk, sh;
    if(inFile>>sk && inFile>>sh){
        char k = sk[0];
        char h = sh[0];
        Nodo<char>* antenato=bst.LCA(bst.getRadice(),k,h);

        cout<<" Distance k="<<k<<"- h="<<h<<"-> "<<bst.distanceFrom(antenato,h)+bst.distanceFrom(antenato,k)<<endl;

    }
}
