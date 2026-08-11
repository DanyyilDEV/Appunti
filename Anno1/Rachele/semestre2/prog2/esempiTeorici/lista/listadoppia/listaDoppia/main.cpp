#include <iostream>

using namespace std;

template <typename T>
class Node {
    private:
        T val;
        Node <T>* next;
        Node <T>* prev;
    public:
        Node(){
            this->next= nullptr;
            this->prev= nullptr;
        }
        Node(T val){
            this->val=val;
            this->next= nullptr;
            this->prev= nullptr;
        }
        T getVal() const{
            return this->val;
        }

        Node <T>* getNext() const{
            return this->next;
        }
        Node <T>* getPrev() const{
            return this->prev;
        }
        void setVal(T val) {
             this->val=val;
        }

        void setNext(Node <T>* next) {
             this->next=next;
        }
        void setPrev(Node <T>* prev) {
             this->prev=prev;
        }
};
template <typename T>
class Lista {
    private:
        Node<T> * head;
        int length=0;
    public:
        Lista(){
            this->head=nullptr;
        }
        Lista(const Lista<T>& lista){
            Node<T>*  nodo= lista.getHead();
            if(!nodo){
                return;
            }
            this->head= new Node <T>(nodo->getVal());
            this->length++;

            Node<T>*  currentToCopy= this->head;
            nodo=nodo->getNext();
            while(nodo){
                Node<T>*  newToCopy= new Node <T>(nodo->getVal()) ;
                currentToCopy->setNext(newToCopy);
                newToCopy->setPrev(currentToCopy);
                currentToCopy=newToCopy;
                nodo=nodo->getNext();
                this->length++;
            }
        }
        ~Lista(){
            Node <T> * current=this->head;
            Node <T> * prev=nullptr;
            while(current!=nullptr){
                prev=current;
                current=current->getNext();
                delete prev;
            }
        }

        Node<T>* getHead() const{
            return this->head;
        }
        int getLength() const{
            return this->length;
        }
        void push (T val){
            Node <T>* newNode= new Node(val);
            newNode->setNext(head);
            newNode->setPrev(nullptr);
            if(head){
                head->setPrev(newNode);
            }
            head=newNode;
            this->length++;
        }

        T pop () {
            if(this->head==nullptr){
                throw runtime_error ("lista vuota");
            }
            Node <T>* deleteNode= head;
            head=head->getNext();
            if(head){
                head->setPrev(nullptr);
            }
            this->length--;
            T returnVal= deleteNode->getVal();
            delete deleteNode;
            return returnVal;
        }
        void orderedInsert (T val){
            Node <T>* newNode= new Node(val);
            if(this->head==nullptr){
               newNode->setNext(nullptr);
               newNode->setPrev(nullptr);
               head=newNode;
               this->length++;
               return;
            }
            Node <T>* prev= nullptr;
            Node <T>* current= head;
            while(current!=nullptr){
                if(current->getVal()  >  newNode->getVal()){
                    break;
                }
                prev=current;
                current=current->getNext();

            }
            if(prev==nullptr){
                newNode->setNext(head);
                newNode->setPrev(nullptr);
                head=newNode;
                this->length++;
                return;
            }

            newNode->setNext(current);
            newNode->setPrev(prev);
            prev->setNext(newNode);
            if(current){
                current->setPrev(newNode);
            }
            this->length++;
        }
        friend
        ostream& operator<<(ostream& os,  const Lista<T>& lista){
            const Node <T> * current=lista.getHead();
            os<<"\n-----List-----\n";
            while(current!=nullptr){
                os<<current->getVal()<<" -  ";
                current=current->getNext();
            }
             os<<"\n----------\n";
            return os;
        }
};
int main()
{
    Lista<int> lista;
    lista.push(4);
    lista.push(1);
    lista.push(2);
    cout<<lista;
    cout<<"eliminooooo->"<<lista.pop()<<"\n";
    cout<<"eliminooooo->"<<lista.pop()<<"\n";
    cout<<"eliminooooo->"<<lista.pop()<<"\n";
    cout<<lista;

    lista.orderedInsert(4);
    lista.orderedInsert(1);
    lista.orderedInsert(2);
    lista.orderedInsert(3);
    cout<<lista;
    Lista<int> copia=lista;
    cout<<copia;
    return 0;
}
