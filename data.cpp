#include "matrix.h"
#include "data.h"
#include "random"

void read_file(string path, map<int, int> &value_function,int& nb_player,int& nb_perl){
    ifstream file(path, ios::in);
    if(file){
        string values;
        file >> nb_player >> nb_perl;
        getline(file,values);
        getline(file,values);
//        cout<< nb_player << "_" << nb_perl << "_end" << endl;
//        cout<<values<<"_end"<<endl;
        int perl=0;
        values=values+" "; //Pour comparer avec le digit i+1
        for(int i=0;i<values.size()-1;i++){ //On enlève 1 car on a rajouté un charactère
            string digit=string(1,values[i]);
            string next_digit=string(1,values[i+1]);
            while(next_digit.compare(" ") != 0 && next_digit.compare("  ") != 0 ){
                digit+=next_digit;
                i++;
                next_digit=string(1,values[i+1]);
            }
            value_function[perl]=stoi(digit);
            perl++;
        }
        file.close();}
    else
        cerr << "File cannot be opened" << endl;
}

void write_data(string path,vector<vector<int>> Ef2){
    ofstream file(path, ios::trunc);
    if(file){
        for(int i=0;i<Ef2.size();i++){
        file<<"The perl for the player "<<i<<" are ";
        for(int j=0;j<Ef2[i].size();j++)
            file<<Ef2[i][j]<<" ";
        file<<endl;
        }
        file.close();
    }
    else cerr<<"Cannot create result file"<<endl;
}

void create_data(string path, int nb_player, int nb_perl, int max){
    ofstream file(path, ios::trunc);
    if(file){
        file<<nb_player<<endl;
        file<<nb_perl<<endl;
        for(int i=0;i<nb_perl;i++){
            file<< rand()%max;
            if(i<nb_perl-1)
                file<<" ";
        }
        file.close();
    }
    else cerr<<"Cannot create data file"<<endl;
}
