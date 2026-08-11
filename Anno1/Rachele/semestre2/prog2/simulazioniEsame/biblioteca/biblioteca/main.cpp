#include <iostream>

using namespace std;

class Item {
    private:
        string title;
        string publication;
        int id=0;

    public:
        Item(string title, string publication, int id){
            this->title=title;
            this->publication=publication;
            this->id=id;
        }
        Item(){
            this->title="xxxxx";
            this->publication="xxxxx";
            this->id=0;
        }
        string getTitle()const{
            return this->title;
        }
        string getPublication()const{
            return this->publication;
        }
        int getId()const{
            return this->id;
        }
        void setTitle( string title){
            this->title=title;
        }
        void setPublication(string publication){
            this->publication=publication;
        }
        void setId(int id){
            this->id=id;
        }
          friend ostream& operator<<(ostream& os, const Item& item){
            os<<"Item{ "<<item.title<<", "<<item.publication<<", "<<item.id<<"}";
            return os;
        }

};
class Book: public Item{
    private:
        string author;

    public:
        Book(){
             Item();
            this->author="xxxxx";
        }
        string getAuthor()const{
            return this->author;
        }

        void setAuthor(string author){
            this->author=author;
        }
        friend ostream& operator<<(ostream& os, const Book& book){
            os<<"Book{ "<<book.getTitle()<<", "<<book.getPublication()<<", "<<book.getId()<<","<<book.getAuthor()<<"}";
            return os;
        }

};
class DVD: public Item{
    private:
        string duration;

    public:
        DVD(){
            Item();
            this->duration="xxxxx";
        }
        string getDuration()const{
            return this->duration;
        }

        void setDuration(string duration){
            this->duration=duration;
        }
        friend ostream& operator<<(ostream& os, const DVD& dvd){
            os<<"Persona{ "<<dvd.getTitle()<<", "<<dvd.getPublication()<<", "<<dvd.getId()<<","<<dvd.getDuration()<<"}";
            return os;
        }

};

class Persona{
    private:
        string name;
        string surname;
        Item * items;
        int  nItem=0;
        int limit=0;
    public:
        Persona( string name, string surname, Item* items, int limit){
            this->items=new Item[limit];
            inizializzaItem();
            this->surname=surname;
            this->name=name;
            this->limit=limit;
        }

        Persona( ){

            this->items = nullptr;
            this->name = "";
            this->surname = "";

        }
        Persona( string name, string surname, Item* items){
            this->items=new Item[limit];
            inizializzaItem();
            this->surname=surname;
            this->name=name;
        }
         Persona( string name, string surname){
            this->items= new Item[limit];
            inizializzaItem();
            this->surname=surname;
            this->name=name;

        }
        void inizializzaItem(){
                for(int i=0; i<this->limit; i++){
                    this->items[i].setId(0);
                }
        }
        virtual string getName()const{
            return this->name;
        }
        virtual void setName(string name){
            this->name=name;
        }
        virtual string getSurname()const{
            return this->surname;
        }
        virtual void setSurname(string surname){
            this->surname=surname;
        }
        virtual Item * getItem()const{
            return this->items;
        }

        virtual void setItem(Item * items){
            this->items=items;
        }

        virtual int getLimit()const{
            return this->limit;
        }
        virtual void setLimit(int limit){
            this->limit=limit;
        }
        virtual int getNItem()const{
            return this->nItem;
        }
        virtual void setNItem(int nItem){
            this->nItem=nItem;
        }
        virtual void printItem()const{
            for(int i=0; i<this->nItem; i++){
                cout<<items[i];
            }
        }
        friend ostream& operator<<(ostream& os, const Persona& persona){
            os<<"Persona{ "<<persona.getName()<<", "<<persona.getSurname()<<", "<<persona.getLimit()<<", "<<persona.getItem()<< "}";
            return os;
        }
        virtual void addItem(Item item){
            if(this->nItem<=this->limit){

                this->nItem++;
                for(int i=0; i<this->limit; i++){
                     if(this->items[i].getId()==0){
                        this->items[this->nItem-1]=item;
                     }
                }

            }

        }
        virtual void deleteItem(int i){
            if(this->nItem>1){
                this->nItem--;
                this->items[i].setId(this->items[i].getId()*(-1));
            }

        }

};


class Studente: public  Persona {
    public:
        Studente(string name, string surname, Item* items){
            Persona(name, surname, items);
            setLimit(5);
        }
        Studente():Persona(){
            setLimit(5);
            setItem(new Item[5]);
        }
};
class Professore: public Persona {
    public:
        Professore(string name, string surname, Item* items){
            setLimit(10);
            Persona(name, surname, items);
        }
        Professore(){
            setLimit(10);
            Persona();
            setItem(new Item[10]);
        }
};

template  < typename T>
struct Nodo{
    T val;
    Nodo<T> * next;
};

template <typename T>
class Queue{
    private:
        Nodo<T>* head;
        Nodo<T>* tail;

    public:
        Queue(){
            head=nullptr;
            tail=nullptr;
        }


        Nodo<T>*  getHead()const{
            return this->head;
        }

        Nodo<T>*  getTail()const{
            return this->tail;
        }

        void setHead(Nodo<T>*  head){
            this->head=head;
        }
        void setTail(Nodo<T>*  tail){
            this->tail=tail;
        }

        void push(T  val){
            Nodo<T>* nodo= new Nodo<T>;
            nodo->val=val;

            if(!this->head){
                nodo->next=nullptr;
                this->head=nodo;
                this->tail=nodo;
                return;
            }
            nodo->next=tail;
            tail=nodo;
        }
        T pop(){
            if(!this.head){
                cout<<"Errore pop: Queue vuota!"<<endl;
                return;
            }
            Nodo<T>* deleteNodo;
            deleteNodo=this.head;
            this.head=this.head->next;
            T returnVal = deleteNodo.val;
            delete deleteNodo;
            return returnVal;
        }

        friend ostream& operator<<(ostream& os, const Queue& queueN){
            Nodo<T>* curr=queueN.getHead();
            os<<"Queue{ ";
            while(curr){
                os<<"-"<<curr->val<<"\n";
            }
            os<<"}\n ";
            return os;
        }


};
class Library{
    private:
        Queue<Studente>  queueS;
        Queue<Professore>  queueP;
        Item* items;
        int nItems;
    public:
        Library(Queue<Studente>  queueS, Queue<Professore>  queueP, Item*  items, int nItems){
            this->queueS=queueS;
            this->queueP=queueP;
            this->items=items;
            this->nItems=nItems;
        }
        Library(Item*  items, int nItems){
            this->queueS=Queue<Studente> ();
            this->queueP=Queue<Professore>();
            this->items=items;
            this->nItems=nItems;
        }
        Queue<Studente> getQueueS()const{
            return this->queueS;
        }
        Queue<Professore> getQueueP()const{
            return this->queueP;
        }
         Item* getItems()const{
            return this->items;
        }

        void setQueueS(Queue<Studente> queueS ){
            this->queueS=queueS;
        }
        void setQueueP(Queue<Professore> queueP ){
            this->queueP=queueP;
        }
         void setItems(Item* items ){
            this->items=items;
        }
        virtual int getNItems()const{
            return this->nItems;
        }
        virtual void setNItems(int nItems){
            this->nItems=nItems;
        }
        int getIndexItemById(int id){
            for(int i=0; i<this->nItems; i++){
                //cout<<"item["<<i<<"]="<<items[i].getId()<<endl;
                if(items[i].getId()==id){
                    //cout<<"presenteeeeeee"<<endl;
                    return i;
                }
            }
            return -1;
        }
        void borrowItem(int id, Persona& persona){
            //cout<<persona.getNItem()<<"vs"<<persona.getLimit();
            if(persona.getNItem()>=persona.getLimit()){
                cout<<"Limiti libri in prestito superato\n";
                return;
            }
            int i=getIndexItemById(id);
            if(i<0){
                cout<<"Item non presente \n";
                return;
            }
            cout<<"Item CEDUTO \n";
            persona.addItem(this->items[i]);
            this->items[i].setId(id*(-1));
        }
        void returnItem(int id, Persona& persona){
            int i=getIndexItemById(id*(-1));
            if(i<0){
                cout<<"Item non della libreria\n";
                return;
            }
             cout<<"Item RESTITUITO \n";

            this->items[i].setId(id*(-1));
            persona.deleteItem(i);
        }
        void stampIdItemND(){
            cout<<"Libri in prestito: \n";
            for(int i=0; i<this->nItems; i++){
                if(items[i].getId()<0){
                    cout<< items[i].getId()*(-1)<<", ";
                }
            }
            cout<<"}\n";
        }
};

int main (){
    Studente studente;


    Professore professore;
    int nItems=100;
    Item* items= new Item[nItems];

    Library lib(items, nItems);

    lib.getQueueP().push(professore);
    lib.getQueueS().push(studente);

    for(int i=0; i<15; i++){
        items[i]= Item("aaa","aaa",i+1);
    }

    lib.setItems(items);

    for(int i=0; i<15; i++){
        cout<<lib.getItems()[i]<<endl;
    }
    cout<<"-------------------------/n";

    lib.borrowItem(1,studente);
    lib.borrowItem(1,professore);

    lib.borrowItem(1,studente);

    lib.returnItem(1,studente);
    lib.returnItem(1,professore);

    for(int i=0; i<15; i++){
        lib.borrowItem(i,studente);
        lib.borrowItem(i,professore);
    }
    lib.stampIdItemND();
    cout<<"-------------------------\n";
    for(int i=0; i<15; i++){
        cout<<lib.getItems()[i]<<endl;
    }
    cout<<"-------------------------\n";
}
