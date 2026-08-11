#include <iostream>
#define N 5
using namespace std;
int partitionV(int v[], int low, int high);
void quickSort(int v[], int low, int high);
void swapped(int& a, int& b);
int main()
{
    int v[5]={7,4,2,1,5};
    quickSort(v,0,N-1);
    cout << "Hello world!" << endl;
    return 0;
}
void quickSort(int v[], int low, int high){
    if(low>=high){
        return;
    }
    int pivotI=partitionV(v,low,high);

    quickSort(v, low, pivotI-1);
    quickSort(v, pivotI+1, high);


}
int partitionV(int v[], int low, int high){
    int pivot=v[high];
    int i=low-1;
    for(int j=low; j<high; j++){
        if(v[j]<pivot){
            i++;
            swapped(v[i], v[j]);
        }
    }
    swapped(v[i+1], v[high]);
    return i+1;

}
void swapped(int& a, int& b){
    int temp=a;
    a=b;
    b=temp;
}
