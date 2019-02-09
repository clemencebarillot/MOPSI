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
    if(j<0)
        j+=p;
    if(i<0)
        i+=n;
    return tab[i][j];
}

void Matrix::set(int i, int j, int x){
    i=i%n;
    j=j%p;
    if(j<0)
        j+=p;
    if(i<0)
        i+=n;
    tab[i][j]=x;
}

void Matrix::set_vector(int j, vector<int> X){
    for(int i=0;i<n;i++)
        set(i,j,X[i]);
}

vector<int> Matrix::get_vector(int j){
    vector<int> X(n);
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

void Matrix::operator =(Matrix B){
    B.get_dim(n,p);

    tab.clear();
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<p;j++){
            temp.push_back(B.tab[i][j]);
        }
        tab.push_back(temp);
    }
    last_modified=B.last_modified;
    isFullyLabelled=B.isFullyLabelled;
    last_labels.clear();
    for(int i=0;i<B.last_labels.size();i++)
        last_labels.push_back(B.last_labels[i]);
//    cout<<&this->tab<<" et "<<&B.tab<<endl;
}
