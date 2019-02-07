#ifndef KUHN_H
#define KUHN_H

#include <map>
#include "matrix.h"

const int nb_perl=100;
const int nb_player=7;

void left(Matrix &M);
void right(Matrix& M);
void next(Matrix &M, int i);

Matrix increase_dim(Matrix M);
bool sideReached(Matrix &simplex);
Matrix decreaseDim(Matrix simplex);
void next_step(Matrix& currentSimplex);
void next(Matrix& M,int i);

vector<int> findLabel(Matrix &Label, map<int,int> value_function);

int findNext(Matrix &M, vector<int> labels);


#endif // KUHN_H
