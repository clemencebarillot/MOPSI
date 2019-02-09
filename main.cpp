
#include "matrix.h"
#include "kuhn.h"
#include "path.h"



int main()
{
    map<int,int> value_function;
    for(int i=0;i<nb_perl;i++)
        value_function[i]=nb_perl-i+1;

    int mod=0;


    Matrix S(1,1);
    S.set(0,0,nb_perl);
    S.display();
    vector<int> labels=findLabel(S,value_function);
    mod=findNext(S,labels);
    cout<<mod<<endl;
    cout<<"début"<<endl;
    Matrix D;   
    increase_dim(S);
    D=S;

    D.display();
    sameDim(D,value_function,mod);
    decreaseDim(D);
    D.display();

    EF2(D,value_function);

    cout<<"résultat final"<<endl;
//    D.display();
//    findLabel(D,value_function);

    return 0;
}
