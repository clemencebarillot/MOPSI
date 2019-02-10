#ifndef PATH_H
#define PATH_H

#include "matrix.h"
#include "kuhn.h"

int sameDim(Matrix& D, map<int, map<int, int> > Value_Functions, int &mod, vector<vector<int> > &Ef2);

vector<int> EF2(Matrix& D, map<int, map<int, int> > Value_Functions, int nb_perl, int nb_player, vector<vector<int>>& Ef2);

bool EF1(vector<vector<int>> Ef2, map<int,int> value_function, vector<vector<int> > Ef1);

#endif // PATH_H
