#include <iostream>

using namespace std;

template <typename T>
class Node {
    private:
        T val;
        Node <T>* next;
    public:
        Node(){
            this->val=nullptr;
            this->next= nullptr;
        }
        Node(T val){
            this->val=val;
            this->next= nullptr;
        }
        T getVal() const{
            return this->val;
        }

        Node <T>* getNext() const{
            return this->next;
        }
        void setVal(T val) {
             this->val=val;
        }

        void setNext(Node <T>* next) {
             this->next=next;
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
        ~Lista(){
            Node <T> * current=this->head;
            Node <T> * prev=this->head;
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
            head=newNode;
            this->length++;
        }

        Node<T>* pop () {
            if(this->head==nullptr){
                return nullptr;
            }
            Node <T>* deleteNode= head;
            head=head->getNext();
            this->length--;
            return deleteNode;
        }
        void orderedInsert (T val){
            Node <T>* newNode= new Node(val);
            if(this->head==nullptr){
               newNode->setNext(nullptr);
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
                head=newNode;
                this->length++;
                return;
            }

            newNode->setNext(current);
            prev->setNext(newNode);
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
    cout<<"eliminooooo->"<<lista.pop()->getVal()<<"\n";
    cout<<"eliminooooo->"<<lista.pop()->getVal()<<"\n";
    cout<<"eliminooooo->"<<lista.pop()->getVal()<<"\n";
    cout<<lista;
    lista.orderedInsert(4);
    lista.orderedInsert(1);
    lista.orderedInsert(2);
    lista.orderedInsert(3);
    cout<<lista;
    return 0;
}
