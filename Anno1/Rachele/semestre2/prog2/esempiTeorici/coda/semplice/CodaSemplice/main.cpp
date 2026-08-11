#include <iostream>

using namespace std;

template <typename T>
class Node {
    private:
        T val;
        Node<T>* next;
    public:
        Node(){
            this->next=nullptr;
        }
        Node(T val){
            this->val=val;
            this->next=nullptr;
        }

        T getVal()const{
            return this->val;
        }
        Node<T>* getNext()const{
            return this->next;
        }
        void setVal(T val){
            this->val=val;
        }
        void setNext(Node<T>* next){
            this->next=next;
        }
};
template <typename T>
class Coda{
    private:
        Node<T>* tail;
        Node<T>* head;
        int length=0;
    public:
        Coda(){
            this->tail=nullptr;
            this->head=nullptr;
        }
        void push(T val){
            Node<T>* newNode = new Node<T>(val);
            if(!tail){
                head=newNode;
                tail=newNode;
                return;
            }
            tail->setNext(newNode);
            tail=newNode;
        }
        T pop(){
            if(!head){
                throw runtime_error ("pop su coda vuota");

            }
            Node<T>* deleteNode = this->head;
            this->head=this->head->getNext();
            if(this->head==nullptr){
                tail=nullptr;
            }
            T returnVal = deleteNode->getVal();
            delete deleteNode;
            return returnVal;
        }
        ~Coda(){
            Node<T>* current= this->head;
            Node<T>* prev= nullptr;
            while(current){
                prev=current;
                current=current->getNext();
                delete prev;
            }
        }
        Node<T>* getHead()const{
            return this->head;
        }

        Node<T>* getTail()const{
            return this->tail;
        }
        void setHead( Node<T>* head){
            this->head=head;
        }

        void setTail( Node<T>* tail){
            this->tail= tail;
        }
        friend
        ostream& operator<<(ostream& os, const Coda<T>& coda){
            if(!coda.getHead()){
                return os;
            }
            Node<T>* node= coda.getHead();
            while(node){
                os<<node->getVal()<<" - ";
                node=node->getNext();
            }
            os<<"\n";
            return os;
        }
};
int main()
{
    cout << "Hello world!" << endl;
    Coda<int> coda;
    coda.push(2);


    coda.push(6);
    coda.push(-16);
    cout<<"insert---------------------\n";
    cout<<coda;
    try{
        cout<<"popcoda-> "<<coda.pop()<<endl;
        cout<<"popcoda-> "<<coda.pop()<<endl;
        cout<<"popcoda-> "<<coda.pop()<<endl;
        cout<<"popcoda-> "<<coda.pop()<<endl;
    }catch(const runtime_error& e){
        cout<<e.what()<<endl;
    }
    cout<<"pop---------------------\n";
    cout<<coda;

    return 0;
}


