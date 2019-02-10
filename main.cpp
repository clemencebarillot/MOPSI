
#include "matrix.h"
#include "kuhn.h"
#include "path.h"
#include "data.h"

#include "time.h"

int main()
{
    map<int,int> value_function;
<<<<<<< HEAD
    int nb_player=10, nb_perl=100;
=======
<<<<<<< HEAD
    map<int,map<int,int>> Value_Functions;

    bool sameValueFunction=false;

    int nb_player=3, nb_perl=5;
=======
    int nb_player=20, nb_perl=200;
>>>>>>> parent of 2dc9af6... Graphe perles
>>>>>>> 6d5aa98a2300076abacd661ee7a664b6f2b3121a
    string path="TestRandom";

    vector<vector<int>> Ef2;

<<<<<<< HEAD
    initiate_data_perl();

    for(nb_perl=100;nb_perl<900;nb_perl+=10){
        if(nb_perl>=300)
            nb_perl+=10;
        if(nb_perl>=600)
            nb_perl+=30;
=======


    for(nb_perl=100;nb_perl<500;nb_perl+=100){

>>>>>>> parent of 2dc9af6... Graphe perles
        Matrix S(1,1);

        create_data(path+".txt",nb_player,nb_perl,100);
        read_file(path+".txt",value_function,nb_player,nb_perl);


        clock_t t1=clock();
        EF2(S,value_function,nb_perl,nb_player,Ef2);
        clock_t t2=clock();
        cout<<"Execution time: "<<(t2-t1)/CLOCKS_PER_SEC<<" seconds."<<endl;


        write_data(path+"Results"+".txt",Ef2);

        write_time(nb_perl,(t2-t1)/CLOCKS_PER_SEC);
    }

    return 0;
}
