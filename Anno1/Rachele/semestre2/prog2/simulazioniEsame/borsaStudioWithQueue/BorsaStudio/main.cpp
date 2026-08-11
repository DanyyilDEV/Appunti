#include <iostream>
#define BORSISTA 1

using namespace std;


class Studente {
    private:
        string nome;
        string cognome;
        int matricola;
        double media;
    public:
        Studente( int matricola,string nome,string cognome, double media){
            this->matricola=matricola;
            this->nome=nome;
            this->cognome=cognome;
            this->media=media;
        }
        Studente( ){

        }
        string getNome()const{
            return nome;
        }
        string getCognome()const{
            return cognome;
        }
        int getMatricola()const{
            return matricola;
        }
        double getMedia()const{
            return media;
        }
        virtual void stampa()const{
            cout<<"matricola "<<matricola<<", nome "<<nome<<", cognome "<<cognome<<", media "<<media<<endl;
        }
        virtual int getTipo()const{
            return 0;
        }

};
class BorsaDiStudio{
    private:
        int importo;
        int durata;
    public:
        BorsaDiStudio(int importo, int durata=1){
            this->importo=importo;
            this->durata=durata;
        }
        int GetImportoBorsa()const{
            return importo;
        }

};
class StudenteBorsista: public Studente{
    private:
        BorsaDiStudio* borsa;
    public:
        StudenteBorsista(){

            this->borsa=nullptr;
        }

        StudenteBorsista( int matricola,string nome,string cognome, double media,  BorsaDiStudio* borsa): Studente( matricola, nome, cognome, media) {
            this->borsa=borsa;
        }
        void stampa()const{
            if(borsa==nullptr){
                cout<<"matricola "<<getMatricola()<<", nome "<<getNome()<<", cognome "<<getCognome()<<", media "<<getMedia()<<endl;
                return;
            }
            cout<<"matricola "<<getMatricola()<<", nome "<<getNome()<<", cognome "<<getCognome()<<", media "<<getMedia()<<"[borsa di "<<borsa->GetImportoBorsa()<<" euro]"<<endl;
        }
         virtual int getTipo()const{
            return BORSISTA;
        }
        BorsaDiStudio* getBorsa() const{
            return borsa;
        }


};
template<typename T>
struct Nodo{
    T val;
    Nodo<T>* next;
};

template<typename T>
class Queue{
    private:
        Nodo<T>* head;
        Nodo<T>* tail;
        int dim=0;
    public:
        Queue(){
            this->head=nullptr;
            this->tail=nullptr;
        }
        void enqueue(T val){
            Nodo<T>* newNode= new Nodo<T>;
            newNode->val=val;
            newNode->next=nullptr;
            dim++;
            if(!head){
                head=newNode;
                tail=newNode;
                return;
            }
            tail->next=newNode;
            tail=newNode;
        }

        void dequeue(){
            if(!head){
                cout<<"empty queue";
                return;
            }
            dim--;
            Nodo<T>* deleteNodo= head;
            head=head->next;
            if(!head){
                tail=nullptr;
            }
            delete deleteNodo;
        }
        void pushInHead(T val){
            Nodo<T>* newNode= new Nodo<T>;
            newNode->val=val;
            dim++;
            if(!head){
                head=newNode;
                tail=newNode;
                return;
            }
            newNode->next=head;
            head=newNode;
        }

        void dequeueStudente(T val){
            if(!head){
                cout<<"empty queue";
                return;
            }
            dim--;
            Nodo<T>* curr=head;
            Nodo<T>* prev=nullptr;
            while(curr){
                if(curr->val->getMatricola()==val->getMatricola()){
                    break;
                }
                prev=curr;
                curr=curr->next;

            }

            if(!curr){
                cout<<val->getMatricola()<<"no in queue";
                return;
            }
            if(curr==head){
                 cout<<"aaa";
               dequeue();
               return;
            }
            if(curr==tail){

                prev->next=nullptr;
                tail=prev;
                delete curr;
                return;
            }
            prev->next=curr->next;
            delete curr;
        }
        void dequeueStudentsByMedia(double media){
            Nodo<T>* curr=head;
            Nodo<T>* prev=nullptr;
            while(curr){
                if(curr->val->getMedia()<media){
                    cout<<"Studente rimosso:  ";
                    curr->val->stampa();
                    dequeueStudente(curr->val);
                    curr=prev;
                }
                prev=curr;
                curr=curr->next;
            }
        }
        void stampa(){
             Nodo<T>* curr=head;
             while(curr){
                curr->val->stampa();
                curr=curr->next;
             }
        }
        void stampaTotImporto(){
             Nodo<T>* curr=head;
             int importoTot=0;
             while(curr){
                if(curr->val->getTipo()==BORSISTA){
                    StudenteBorsista* sb=(StudenteBorsista*) curr->val;
                    importoTot+=sb->getBorsa()->GetImportoBorsa();
                }
                curr=curr->next;
             }
             cout<<"Importo: "<<importoTot<<endl;
        }


};
int main()
{
    Studente* s1=new Studente(1001, "Mario",  "Rossi",  25.5);
    Studente* s2=new Studente(1003, "Luca",  "Bianchi",  26.0);
    Studente* s3=new Studente(1004, "Sara",  "Neri",  27.5);


    BorsaDiStudio* b1= new BorsaDiStudio(880);
    StudenteBorsista* sb1=new StudenteBorsista(1002, "Anna",  "Verdi",  28.5, b1);

    BorsaDiStudio* b2= new BorsaDiStudio(500);
    StudenteBorsista* sb2=new StudenteBorsista(1005, "Marco",  "Gialli",  24.0, b2);

    BorsaDiStudio* b3= new BorsaDiStudio(600);
    StudenteBorsista* sb3=new StudenteBorsista(1006, "Laura",  "Marroni",  29, b3);

    Queue<Studente*> queueN;
    queueN.enqueue(s1);
    queueN.enqueue(sb1);
    queueN.enqueue(s2);
    queueN.enqueue(s3);
    queueN.enqueue(sb2);
    queueN.enqueue(sb3);
    queueN.stampa();
    cout<<"-----------------"<<endl;
    queueN.dequeue();
    queueN.dequeue();
    queueN.stampa();
    cout<<"-----------------"<<endl;
    queueN.enqueue(s1);
    queueN.enqueue(sb1);
   // queueN.pushInHead(sb1); funzioni commentate->inutili ho capito male la consegna XD
    //queueN.pushInHead(s1);
    queueN.stampa();
    cout<<"-----------------"<<endl;
    queueN.dequeueStudentsByMedia(25);
    queueN.stampa();
    cout<<"-----------------"<<endl;
    queueN.stampaTotImporto();
   // queueN.dequeue(1001,sb1);

    return 0;
}
