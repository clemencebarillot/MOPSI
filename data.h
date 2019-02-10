#ifndef DATAS_H
#define DATAS_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;


void read_file(string path, map<int, int> &value_function,int& nb_player,int& nb_perl);
void write_data(string path, vector<vector<int> > Ef2);

void create_data(string path, int nb_player, int nb_perl, int max);
#endif // DATAS_H
