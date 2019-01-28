#ifndef KUHN_H
#define KUHN_H

#include "matrix.h"

void left(Matrix &M);
void right(Matrix& M);
void next(Matrix &M, int i);

Matrix increase_dim(Matrix M);
bool sideReached(Matrix simplex);
Matrix decreaseDim(Matrix simplex);
void next_step(Matrix& currentSimplex);


#endif // KUHN_H
