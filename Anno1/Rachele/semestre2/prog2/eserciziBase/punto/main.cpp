#include <iostream>
using namespace std;

template <typename T>
class Point {
    private:
        T x;
        T y;
    public:
        Point (T x, T y){
            this->x=x;
            this->y=y;
        }
        T getX(){
            return this->x;
        }
        T getY(){
            return this->y;
        }

        void setX( T x){
            this->x=x;
        }
        void setY( T y){
            this->x=x;
        }
        bool operator == (const Point& punto) const{
            return (this->x==punto.x && this->y==punto.y );
        }
        /*
        bool operator < (const Rettangolo& rettangolo) const {
            return (this->getArea()<rettangolo.getArea());
        }
        */
        friend
        ostream& operator <<(ostream& out, const Point& point){
            out<<"punto:{x:"<<point.x<<", y: "<<point.y<<"}\n";
            return out;
        }

};

template <typename T>
int searchT (T t, T v[], int n){
    for(int i=0; i<n; i++){
       if(t==v[i]){
        return i;
       }

    }
    return -1;
}


template <typename T>
void printArray(T v[], int n){
    for(int i=0; i<n; i++){
        cout<<"["<<i<<"]:"<<v[i]<<"\n";
    }
    cout<<"--------------------------------------\n";
}

template <typename T>
void popolaArray(T v[], int n){
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
}
int main()
{

    int n= 5;
    int  intArray[n]={4,6,2,2,1};
    char charArray[n]={'a','z','h','b','r'};
    Point <int> pointArray[5]={{1,2}, {7,8},{6,3}, {100,101},{5,9}};
    printArray(intArray,n);
    printArray(charArray,n);
    printArray(pointArray,n);
    cout<<"-----------------------------"<<endl;
    int integer;
    int x;
    int y;
    char character;
    cout<<"Inserisci l'intero da cercare:\n";
    cin>>integer;
    cout<<"Inserisci il carattere da cercare:\n";
    cin>>character;
    cout<<"Inserisci cordinata x del punto da cercare:\n";
    cin>>x;
    cout<<"Inserisci cordinata y del punto da cercare:\n";
    cin>>y;
    Point point={x,y};
    cout<<searchT(integer, intArray, n)<<endl;
    cout<<searchT(character, charArray, n)<<endl;
    cout<<searchT(point, pointArray, n)<<endl;


    return 0;
}
