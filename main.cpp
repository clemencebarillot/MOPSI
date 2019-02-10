
#include "matrix.h"
#include "kuhn.h"
#include "path.h"
#include "data.h"

#include "time.h"

int main()
{
    map<int,int> value_function;
    int nb_player=20, nb_perl=200;
    string path="TestRandom";

    vector<vector<int>> Ef2;



    for(nb_perl=100;nb_perl<500;nb_perl+=100){

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
