#include "matrix.h"

void Matrix::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            cout<<get(i,j)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int Matrix::get(int i,int j){
    i=i%n;
    j=j%p;
    return tab[i+n*j];
}

void Matrix::set(int i, int j, int x){
    i=i%n;
    j=j%p;
    tab[i+n*j]=x;
}

void Matrix::set_vector(int j, vector<int> X){
    j=j%p;
    for(int i=0;i<n;i++)
        set(i,j,X[i]);
}

vector<int> Matrix::get_vector(int j){
    vector<int> X(n);
    j=j%p;
    for(int i=0;i<n;i++)
        X[i]=get(i,j);
    return X;
}


vector<int> Matrix::swap(int i){
    vector<int> X(n);
    for(int k=0;k<n;k++)
        X[k]=get_vector(i-1)[k]+get_vector(i+1)[k]-get_vector(i)[k];
    return X;
}

vector<int> Matrix::get_vector_max(){
    int i=0;
    int max=tab[0];
    for(int k=0;k<p;k++){
        if(max<tab[n*k]){
            max=tab[n*k];
            i=k;
        }
    }
    return get_vector(i);
}

