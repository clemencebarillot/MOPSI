#include "matrix.h"
#include "data.h"

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

void write_data(string path,Matrix M){
    ofstream file(path, ios::trunc);
    if(file){
        int n,p;
        M.get_dim(n,p);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<p;j++){
                file << M.get(i,j) << " ";
            }
            file << endl;
        }
    }
}

void create_data(string path, int nb_player, int nb_perl, int max){
    ofstream file(path, ios::trunc);
    if(file){
        file<<nb_player<<endl;
        file<<nb_perl<<endl;
        for(int i=0;i<nb_perl;i++){

        }
    }
}
