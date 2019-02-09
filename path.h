#ifndef PATH_H
#define PATH_H

#include "matrix.h"
#include "kuhn.h"

int sameDim(Matrix& D, map<int,int> value_function, int &mod);

void EF2(Matrix& D, map<int,int> value_function, int nb_perl, int nb_player);

#endif // PATH_H
