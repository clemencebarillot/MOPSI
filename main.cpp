
#include "matrix.h"
#include "kuhn.h"
#include "path.h"

int main()
{
    map<int,int> value_function;
    for(int i=0;i<5;i++)
        value_function[i]=i+1;

    int mod=0;
    Matrix S(1,1);
    S.set(0,0,5);
    S.display();
    vector<int> labels=findLabel(S,value_function);
    mod=findNext(S,labels);
    cout<<mod<<endl;
    Matrix D=increase_dim(S);
    D.display();
    sameDim(D,value_function,mod);
//    Matrix F=decreaseDim(D);
//    F.display();

    //EF2(S,value_function); //Ca marche po



    return 0;
    
}
