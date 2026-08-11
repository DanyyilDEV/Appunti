#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
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
            deleteAllNodes(this->root);
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
            Node<T>* newNode= new Node<T>();
            newNode->left=nullptr;
            newNode->right=nullptr;
            newNode->parent=nullptr;
            newNode->val=val;

            if(!root){
                root=newNode;
                return;
            }
            Node<T>* curr= root;
            Node<T>* prev= nullptr;
            while(curr){
                prev=curr;
                if(val<=curr->val){
                    curr=curr->left;
                }else{
                    curr=curr->right;

                }
            }
            newNode->parent=prev;
            if(val<=prev->val){
                 prev->left=newNode;
            }else{
                prev->right=newNode;
            }

        }
        void trapianta(Node<T>* destination, Node<T>* source){

            if(!destination->parent){
                this->root=source;
                if(source){
                    source->parent=nullptr;
                }
                return;
            }

            if(source){
                source->parent=destination->parent;
            }
            if(destination->parent->left==destination){
                destination->parent->left=source;
                return;
            }
            destination->parent->right=source;


        }
        Node<T>* getMin(Node<T>* parent){
            if(!parent){
                return nullptr;
            }


            while(parent->left){
                parent=parent->left;
            }
            return parent;
        }
        void deleteNode(Node<T>* deleteNode){
            if(!deleteNode) return;
            if(!deleteNode->left){
                trapianta(deleteNode, deleteNode->right);
                delete deleteNode;
                return;
            }
            if(!deleteNode->right){
                trapianta(deleteNode, deleteNode->left);
                delete deleteNode;
                return;
            }

            Node<T>* next = getMin(deleteNode->right);

            if( next->parent!=deleteNode){
                trapianta(next, next->right);
                next->right=deleteNode->right;
                next->right->parent=next;
            }

            trapianta(deleteNode, next);
            next->left=deleteNode->left;
            next->left->parent=next;
            delete deleteNode;

        }
        Node<T>* searchNodeOf(T val){
            Node<T>* curr= root;
            Node<T>* prev= nullptr;
            while(curr){
                prev=curr;
                if(val==curr->val){
                    return curr;
                }
                if(val<=curr->val){
                    curr=curr->left;
                }else{
                    curr=curr->right;

                }
            }
            return nullptr;
        }
        void log(Node<T>* parent, int lvl=0){
            if(!parent){
                return;
            }
            log(parent->right, lvl+1);
            for(int i=0; i<lvl; i++){
                cout<<"\t";
            }
            cout<<"||--"<<parent->val<<endl;
            log(parent->left, lvl+1);
        }
        Node<T>* getRoot() const{
            return this->root;
        }

};

template<typename T>
void popolateFromFile(Tree<T>& tree, ifstream& inFile, int n){
    T dato;
    string operation;
    string word;


    for(int i=0; i<n; i++){
        inFile>>word;
        stringstream wordStream(word);
        getline(wordStream, operation,':');
        wordStream>>dato;
        if(operation.compare("ins")==0){

            tree.add(dato);
        }else{
            Node<T>* deleteNode= tree.searchNodeOf(dato);
            if(deleteNode){
                tree.deleteNode(deleteNode);
            }

        }
    }
}
template<typename T>
void popolateFromFile(Tree<T>& tree, ifstream& inFile, int n);
int main()
{

    ifstream inFile("inputDistanze.txt");
    int  n, hI, kI;
    char  hC, kC;
    string tipo;
    for(int i=0; i<7; i++){
        inFile>>tipo;
        inFile>>n;
        if(tipo.compare("int")==0){
            Tree<int> treeInt;
            popolateFromFile(treeInt, inFile, n);
            inFile>>hI;
            inFile>>kI;
            treeInt.log(treeInt.getRoot());
            cout<<"------------------"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
        }else{
            Tree<char> treeChar;
            popolateFromFile(treeChar, inFile, n);
            inFile>>hC;
            inFile>>kC;
            treeChar.log(treeChar.getRoot());
            cout<<"------------------"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
        }

    }


    return 0;
}
