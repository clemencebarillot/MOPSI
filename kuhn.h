#ifndef KUHN_H
#define KUHN_H

#include "matrix.h"

Matrix increase_dim(Matrix M);
bool sideReached(Matrix simplex);
Matrix decreaseDim(Matrix simplex);
void next_step(Matrix& currentSimplex);
void next(Matrix& M,int i);


#endif // KUHN_H
