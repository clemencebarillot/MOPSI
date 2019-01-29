
#include "matrix.h"
#include "kuhn.h"

int main()
{
    map<int,int> value_function;
    for(int i=0;i<5;i++)
        value_function[i]=i+1;

    Matrix S(2,2);
    S.set(1,1,1);
    S.set(1,2,2);
    S.set(2,1,3);
    S.set(2,2,2);
    S.display();
    Matrix D=increase_dim(S);
    D.display();

//    Matrix F=decreaseDim(D);
//    F.display();
    int mod=1;
    while(mod != 3){
        cout<<"//==========="<<endl;
        cout<<"debut boucle"<<endl;
        next(D,mod);
        D.display();
        vector<int> labels=findLabel(D,value_function);
        mod=findNext(D,labels);
        cout<<mod<<endl;
        cout<<"fin"<<endl;
        cout<<"//==========="<<endl;
    }


    return 0;
    
}
