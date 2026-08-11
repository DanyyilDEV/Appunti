#include <iostream>

using namespace std;

template <typename T>
struct Nodo{
    T val;
    Nodo<T>* next;

};

template <typename T>
class Queue {

    private:
        Nodo<T>* head;
    public:
        Queue(){
            this->head=nullptr;
        }
        ~Queue(){
            Nodo<T>* curr=this->head;
            Nodo<T>* prev=nullptr;
            while(curr){
                prev=curr;
                curr=curr->next;
                delete prev;
            }
        }
        void enqueue(T val){
            Nodo<T>* newNode= new  Nodo<T>;
            newNode->val=val;
            newNode->next=nullptr;

            if(!head){
                this->head=newNode;
                return;
            }
            Nodo<T>* curr=this->head;
            Nodo<T>* prev=nullptr;
            while(curr){
                prev=curr;
                curr=curr->next;
            }
            if(prev==head){
                head->next=newNode;
                return;
            }
            prev->next=newNode;
        }
        void dequeue(){
            if(!head){
                cout<<"errore";
                return;
            }
            Nodo<T>* deleteNode=this->head;
            this->head=this->head->next;
            delete deleteNode;
        }
        void print(){
            Nodo<T>* curr=this->head;
            while(curr){
                cout<<*(curr->val)<<endl;
                curr=curr->next;

            }
        }
};
int main()
{
    Queue<int*> q;
    int* a=new int;
    *a=1;
    int* b=new int;
    *b=2;
    int* c=new int;
    *c=3;
    q.enqueue(a);
    q.enqueue(b);
    q.enqueue(c);
    q.dequeue();
    q.print();
    cout << "Hello world!" << endl;
    return 0;
}
