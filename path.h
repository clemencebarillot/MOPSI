#ifndef PATH_H
#define PATH_H

#include "matrix.h"
#include "kuhn.h"

int sameDim(Matrix& D, map<int,int> value_function, int &mod, vector<vector<int> > &Ef2);

vector<int> EF2(Matrix& D,map<int,int> value_function,int nb_perl,int nb_player,vector<vector<int>>& Ef2);

#endif // PATH_H
