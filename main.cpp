
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
    for(int i=0;i<value_function.size();i++)
        cout<<"i="<<i<<" et sa valeur vaut "<<value_function[i]<<"_end"<<endl;

    int mod=0;


    Matrix S(1,1);
    S.set(0,0,nb_perl);
    S.display();
    vector<int> labels=findLabel(S,value_function);
    mod=findNext(S,labels);
//    cout<<mod<<endl;
//    cout<<"début"<<endl;
    Matrix D(5,5);
    increase_dim(S);
    D=S;

    D.display();
    sameDim(D,value_function,mod);
    decreaseDim(D);
    D.display();

    clock_t t1=clock();

    EF2(D,value_function,nb_perl,nb_player);
    clock_t t2=clock();
    cout<<"temps d'exécution: "<<(t2-t1)/CLOCKS_PER_SEC<<" secondes."<<endl;

    cout<<"résultat final"<<endl;
    D.display();
    findLabel(D,value_function,true);


    return 0;
}
