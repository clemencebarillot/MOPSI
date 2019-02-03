
#include "matrix.h"
#include "kuhn.h"
#include "path.h"

int main()
{
    map<int,int> value_function;
    for(int i=0;i<5;i++)
        value_function[i]=i+1;

    int mod=1;
    Matrix S(2,2);
    S.set(0,0,3);
    S.set(1,0,0);
    S.set(0,1,2);
    S.set(1,1,1);
    S.display();
    next(S,0);

    S.display();
    vector<int> labels=findLabel(S,value_function);
    mod=findNext(S,labels);
    cout<<mod<<endl;
    Matrix D=increase_dim(S);
    D.display();

//    Matrix F=decreaseDim(D);
//    F.display();
    int iter=0;
    while(mod != 3 && iter<50){
        iter++;
        cout<<"//==========="<<endl;
        cout<<"debut boucle"<<endl;
        D.display();
        vector<int> labels=findLabel(D,value_function);
        mod=findNext(D,labels);
        cout<<mod<<endl;
        next(D,mod);
        D.display();
        cout<<"fin"<<endl;
        cout<<"//==========="<<endl;
    }


    return 0;
    
}
