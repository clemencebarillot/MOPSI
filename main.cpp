
#include "matrix.h"
#include "kuhn.h"
#include "path.h"

#include "time.h"

int main()
{
    map<int,int> value_function;
    for(int i=0;i<nb_perl;i++)
        value_function[i]=i+1;

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
    EF2(D,value_function);
    clock_t t2=clock();
    cout<<"temps d'exécution: "<<(t2-t1)/CLOCKS_PER_SEC<<" secondes."<<endl;

    cout<<"résultat final"<<endl;
    D.display();
    findLabel(D,value_function);

    return 0;
}
