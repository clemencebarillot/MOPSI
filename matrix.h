#ifndef MATRIX_H
#define MATRIX_H


#include <iostream>
#include <string>
#include "assert.h"
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;


class Matrix{
protected:
    int n,p;
    vector<vector<int>> tab;
public:
    int last_modified;
    bool isFullyLabelled;
    vector<int> last_labels; //Ce vecteur garde en mémoire les vecteurs de la colonne qui était le last_modified avant d'augmenter de dimension
    Matrix(int n_,int p_){n=n_;p=p_;last_modified=p_-1;tab = vector<vector<int>>(n); for(int i=0;i<n;i++) tab[i].resize(p);}
//    Matrix(int n_,int p_,int* tab_){p=p_;n=n_;tab=new int[n_*p_];
//                                    for(int i=0;i<n_*p_;i++)
//                                        tab[i]=tab_[i];last_modified=p_-1;}
    Matrix(){}
    ~Matrix(){tab.clear();}
    void get_dim(int& a,int& b){a=n;b=p;}
    int get(int i, int j);
    vector<int> get_vector(int j);
    vector<int> get_vector_max();

    void set(int i, int j, int x);
    void set_vector(int j,vector<int> X);
    vector<int> swap(int i);    
    void operator =(Matrix B);
    void display();


};




#endif // MATRIX_H
