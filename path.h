#ifndef PATH_H
#define PATH_H

#include "matrix.h"
#include "kuhn.h"

int sameDim(Matrix& D, map<int,int> value_function, int &mod, vector<vector<int> > &Ef2);

vector<int> EF2(Matrix& D,map<int,int> value_function,int nb_perl,int nb_player,vector<vector<int>>& Ef2);
int value_part(map<int,int> value_function, vector<int> part); //pour des value fonction identiques, renvoie la valeur de la part
int max_vect(vector<int> vect);
bool EF1(vector<vector<int>> Ef2, map<int,int> value_function, vector<vector<int>> Ef1);

#endif // PATH_H
