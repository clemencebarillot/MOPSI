#ifndef DATAS_H
#define DATAS_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;


void read_file(string path, map<int, map<int, int> > &Value_Functions, int& nb_player, int& nb_perl, bool &sameValueFunction);
void write_data(string path, vector<vector<int> > Ef2);

void initiate_data_perl();
void write_time(int nb_perl, int time);

void create_data(string path, int nb_player, int nb_perl, int max, bool sameValueFunction);
#endif // DATAS_H
