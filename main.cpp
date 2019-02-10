
#include "matrix.h"
#include "kuhn.h"
#include "path.h"
#include "data.h"

#include "time.h"

int main()
{
    map<int,int> value_function;
    int nb_player, nb_perl;
    read_file("FirstValueFunction.txt",value_function,nb_player,nb_perl);

    Matrix S(1,1);

    vector<vector<int>> Ef2;

    clock_t t1=clock();
    EF2(S,value_function,nb_perl,nb_player,Ef2);
    clock_t t2=clock();
    cout<<"Execution time: "<<(t2-t1)/CLOCKS_PER_SEC<<" seconds."<<endl;



    write_data("FirstValueFunctionResults.txt",S);


    return 0;
}
