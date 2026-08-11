#include <iostream>
using namespace std;

template <typename T>
class Rettangolo {
    private:
        T b;
        T h;
    public:
        Rettangolo (T b, T h){
            this->b=b;
            this->h=h;
        }
        T getB(){
            return this->b;
        }
        T getH(){
            return this->h;
        }

        void setB( T b){
            this->b=b;
        }
        void setH( T h){
            this->b=b;
        }
        bool operator == (const Rettangolo& rettangolo) const{
            return (this->getArea()==rettangolo.getArea());
        }
        bool operator < (const Rettangolo& rettangolo) const {
            return (this->getArea()<rettangolo.getArea());
        }
        friend
        ostream& operator <<(ostream& out, const Rettangolo& rettangolo){
            out<<"rettangolo:{b:"<<rettangolo.b<<", h: "<<rettangolo.h<<", area: "<<rettangolo.getArea()<<"}";
            return out;
        }
        T getArea() const{
            return this->b*this->h;
        }

};
template <typename T>
void swapped ( T& a , T& b){
    T temp= a;
    a=b;
    b=temp;
}
template <typename T>
void sortArray (T v[], int n){
    int posMin;
    for(int i=0; i<n-1; i++){
        posMin=i;
        for(int j=i+1; j<n; j++){
            if(v[j]<v[posMin]){
                posMin=j;
            }
        }
        swapped(v[i], v[posMin]);
    }
}


template <typename T>
void printArray(T v[], int n){
    for(int i=0; i<n; i++){
        cout<<"["<<i<<"]:"<<v[i]<<"\n";
    }
    cout<<"--------------------------------------\n";
}
int main()
{
    int n= 5;
    int  intArray[n]={4,6,2,2,1};
    char charArray[n]={'a','z','h','b','r'};
    Rettangolo <int> rettangoloArray[5]={{1,2}, {7,8},{6,3}, {100,101},{5,9}};

    sortArray(intArray,n);
    sortArray(charArray,n);
    sortArray(rettangoloArray, n);

    printArray(intArray,n);
    printArray(charArray,n);
    printArray(rettangoloArray,n);
    cout << "Hello world!" << endl;
    return 0;
}
