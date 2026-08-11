#include <iostream>
#include <vector>
#define N 5
using namespace std;


void marge(int v[], int left,int mid,int right){
    int dimLeft=mid-left+1;
    int dimRight=right-mid;

    vector <int> vLeft(dimLeft);
    vector<int> vRight(dimRight);

    for(int i=0; i<dimLeft; i++){
        vLeft[i]=v[left+i];
    }
    for(int i=0; i<dimRight; i++){
        vRight[i]=v[mid+1+i];
    }

    int indexL=0;
    int indexR=0;
    int index=left;
    while(indexL<dimLeft && indexR<dimRight){
        if(vLeft[indexL]<vRight[indexR]){
            v[index]=vLeft[indexL];
            indexL++;
        }else{
            v[index]=vRight[indexR];
            indexR++;
        }
        index++;
    }
    while(indexL<dimLeft){
         v[index]=vLeft[indexL];
        indexL++;
        index++;
    }
    while(indexR<dimRight){
        v[index]=vRight[indexR];
        indexR++;
        index++;
    }

}

void div(int v[], int left,int right){
    if(left>=right){
        return;
    }

    int mid=left+(right-left)/2;
    div(v, left, mid);
    div(v, mid+1, right);
    marge(v, left,mid, right);
}

void div(int v[], int left,int right);
void marge(int v[], int left,int mid,int right);
int main()
{
    int v[N]={1,15,3,8,2};
    int left=0;
    int right=N-1;

    div(v, left,right);
    for(int i=0; i<N; i++){
        cout<<"   "<<v[i];
    }
    return 0;
}
