#include <iostream>

using namespace std;

template <typename T>
class Node {
    private:
        T val;
        Node <T>* next;
    public:
        Node(){
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
        Lista(const Lista<T>& lista) {
            this->head = nullptr;
            this->length = 0;

            Node<T>* node = lista.getHead();
            if (!node) {
                return;
            }

            this->head = new Node<T>(node->getVal());
            this->length++;

            Node<T>* nodeCopy = this->head;
            node = node->getNext();

            while (node) {

                Node<T>* newNode = new Node<T>(node->getVal());
                nodeCopy->setNext(newNode);
                nodeCopy = newNode;

                node = node->getNext();
                this->length++;
            }
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
        void setLength(int length) {
            this->length=length;
        }
        void push (T val){
            Node <T>* newNode= new Node(val);
            newNode->setNext(head);
            head=newNode;
            this->length++;
        }

        T pop () {
            if(this->head==nullptr){
                throw runtime_error("Lista vuota!");
            }
            Node <T>* deleteNode= head;
            head=head->getNext();
            this->length--;
            T returnVal = deleteNode->getVal();
            delete deleteNode;
            return returnVal;
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
    cout<<"eliminooooo->"<<lista.pop()<<"\n";
    cout<<"eliminooooo->"<<lista.pop()<<"\n";
    cout<<"eliminooooo->"<<lista.pop()<<"\n";
    cout<<lista;
    lista.orderedInsert(4);
    lista.orderedInsert(1);
    lista.orderedInsert(2);
    lista.orderedInsert(3);
    cout<<lista;
    Lista copia= lista;
    cout<<"listacopia->\n"<<copia;

    return 0;
}
