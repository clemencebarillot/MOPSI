#ifndef PATH_H
#define PATH_H

#include "matrix.h"
#include "kuhn.h"

int sameDim(Matrix& D, map<int, map<int, int> > Value_Functions, int &mod, vector<vector<int> > &Ef2);

<<<<<<< HEAD
vector<int> EF2(Matrix& D,map<int,int> value_function,int nb_perl,int nb_player,vector<vector<int>>& Ef2);
int value_part(map<int,int> value_function, vector<int> part); //pour des value fonction identiques, renvoie la valeur de la part
int max_vect(vector<int> vect);
bool EF1(vector<vector<int>> Ef2, map<int,int> value_function, vector<vector<int>> Ef1);
=======
vector<int> EF2(Matrix& D, map<int, map<int, int> > Value_Functions, int nb_perl, int nb_player, vector<vector<int>>& Ef2);

bool EF1(vector<vector<int>> Ef2, map<int,int> value_function, vector<vector<int> > Ef1);
>>>>>>> d0f6ed0983ed0156054851a79857f3f971d73698

#endif // PATH_H
