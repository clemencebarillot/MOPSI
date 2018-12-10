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
    int* tab;
public:
    int last_modified;
    bool isFullyLabelled;
    Matrix(int n_,int p_){n=n_;p=p_;tab=new int[n*p];last_modified=p_-1;}
    Matrix(int n_,int p_,int* tab_){p=p_;n=n_;tab=new int[n_*p_];
                                    for(int i=0;i<n_*p_;i++)
                                        tab[i]=tab_[i];last_modified=p_-1;}
    Matrix(){}
    ~Matrix(){delete [] tab;}
    void get_dim(int& a,int& b){a=n;b=p;}
    int get(int i, int j);
    void set(int i, int j, int x);
    void set_vector(int j,vector<int> X);
    vector<int> get_vector(int j);
    void display();
    vector<int> swap(int i);
    vector<int> get_vector_max();
};




#endif // MATRIX_H
