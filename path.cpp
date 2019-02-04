#include "path.h"

int sameDim(Matrix& D,map<int,int> value_function,int& mod){
    int iter=0;
    int n,p;
    D.get_dim(n,p);
    while(mod != p && iter<50){
        iter++;
        cout<<"//==========="<<endl;
        cout<<"debut boucle"<<endl;
        D.display();
        vector<int> labels=findLabel(D,value_function);
        mod=findNext(D,labels);
        cout<<mod<<endl;
        next(D,mod);
        D.display();
        if(sideReached(D)) return 1;
        cout<<"fin"<<endl;
        cout<<"//==========="<<endl;
        return 0;
    }
}
void EF2(Matrix& D,map<int,int> value_function){
    int mod=1;
    int test=0;
    while(mod<2){
        test=sameDim(D,value_function,mod);
        cout<<test<<" "<<mod<<endl;
        if(test){
            Matrix S=decreaseDim(D);
            delete &D;
            Matrix D=S;}
        else{
            Matrix S=increase_dim(D);
            delete &D;
            Matrix D=S;}
    }
}
