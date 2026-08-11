#include <iostream>

using namespace std;


class Persona{
    private:
        string nome;
        int nTicket;
    public:
        Persona(){
            this->nome="---";
            this->nTicket=-1;
        }
        Persona(string nome, int nTicket){
            this->nome=nome;
            this->nTicket=nTicket;
        }
        string getNome()const{
            return this->nome;
        }
        int getNTicket()const{
            return this->nTicket;
        }
        friend ostream& operator<<(ostream& os, const Persona& persona) {
            os<<persona.toString();
            return os;
        }
        string toString() const {
            string s;
            // Supponendo che getNTicket() restituisca un intero o una stringa
            s = "Nome: " + this->nome + ", nTicket: " + to_string(this->nTicket) + "\n";
            return s;
        }
        void stampa(){
            cout<<toString();
        }
};

class Nodo{
    private:
        Persona persona;
        Nodo* next;
    public:
        Nodo(Persona persona, Nodo* next){
            this->persona=persona;
            this->next=next;
        }
        Nodo(Persona persona){
            this->persona=persona;
            this->next=nullptr;
        }
        Nodo(){
            this->next=nullptr;
        }
        Persona getPersona()const{
            return this->persona;
        }
        Nodo* getNext(){
            return this->next;
        }
        void setPersona(Persona persona){
            this->persona=persona;
        }
        void setNext(Nodo * next){
            this->next=next;
        }
};


class Queue{
    private:
        Nodo* head;
        Nodo* tail;
        int nNodi=0;
    public:
        Queue( Nodo* head, Nodo* tail){
            this->head=head;
            this->tail=tail;
        }
        Queue(){
            this->head=nullptr;
            this->tail=nullptr;
        }
        void enqueue(string name, int nTicket){
            Persona persona(name, nTicket);
            this->nNodi++;
            Nodo * nodo=new Nodo;
            nodo->setPersona(persona);
            nodo->setNext(nullptr);
            if(!head){
                this->head=nodo;
                this->tail=nodo;
                return;
            }
            tail->setNext(nodo);
            tail=nodo;
        }
        Persona * dequeue(){
            if(!head){
               cout<<"error dequeue: queue empty";
               return nullptr;
            }
            this->nNodi--;
            Nodo * deletenodo=head;
            Persona persona= deletenodo->getPersona();
            head=head->getNext();
            return &persona;
        }
        bool isEmpty(){
             if(!head){
               return true;
            }
            return false;
        }

        Nodo* frontHead(){
            return this->head;
        }
        friend ostream& operator<<(ostream& os, const Queue& queueN){
            os<<queueN.toString();
        }
        string toString()const{
            string s;
            Nodo * curr= head;
            while(curr){
                s=s+""+curr->getPersona().toString()+"\n";
                curr=curr->getNext();
            }
            return s;
        }
        void stampa(){
            cout<<toString();
        }
};

int main (){
    Queue queueN;
    queueN.enqueue("Mario", 1);
    queueN.enqueue("Luigi", 2);
    queueN.enqueue("Anna", 3);
    queueN.stampa();
    queueN.dequeue();
    queueN.stampa();
    cout<<"frontHead"<<queueN.frontHead()->getPersona().toString();


}
