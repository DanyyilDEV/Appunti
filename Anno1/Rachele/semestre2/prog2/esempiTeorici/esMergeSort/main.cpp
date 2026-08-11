#include <iostream>

using namespace std;
void mergeV(int v[], int left,int mid, int right);
void devideV(int v[], int left, int right);
int main()
{
    int v[6]={1,-10, 28, 15, 9, 17};
    int dim= sizeof(v)/sizeof(int);
    devideV(v, 0, dim-1);
    for(int i=0; i<dim; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout << "Hello world!" << endl;
    return 0;
}

void devideV(int v[], int left, int right){
    if(left>=right){
        return;
    }
    int mid=left+(right-left)/2;

    devideV(v, left, mid);
    devideV(v, mid+1, right);

    mergeV(v, left, mid, right);

}

void mergeV(int v[], int left,int mid, int right){
    int dimLeft=mid-left+1;
    int dimRight=right-mid;

    int vLeft[dimLeft];
    int vRight[dimRight];
    for(int i=0; i<dimLeft; i++){
        vLeft[i]=v[left+i];
    }
    for(int i=0; i<dimRight; i++){
        vRight[i]=v[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=left;
    while(i<dimLeft && j<dimRight){
        if(vLeft[i]<=vRight[j]){
            v[k]=vLeft[i];
            i++;
        }else{
            v[k]=vRight[j];
            j++;
        }
        k++;
    }
    while(i<dimLeft){
        v[k]=vLeft[i];
        i++;
        k++;
    }
    while(j<dimRight){
        v[k]=vRight[j];
        j++;
        k++;
    }


}
