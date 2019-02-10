#ifndef KUHN_H
#define KUHN_H

#include <map>
#include "matrix.h"


void left(Matrix &M);
void right(Matrix& M);
void next(Matrix &M, int i);

void increase_dim(Matrix &M);
bool sideReached(Matrix &simplex);
void decreaseDim(Matrix& simplex);
void next_step(Matrix& currentSimplex);
void next(Matrix& M,int i);

vector<vector<vector<int>>> vector_to_parts(Matrix& M);
vector<int> findLabel(Matrix &Label, map<int,map<int,int>> Value_Functions, vector<vector<int>> &Ef2, bool EF2=false);

int findNext(Matrix &M, vector<int> labels);


#endif // KUHN_H
