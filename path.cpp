#include "path.h"



int sameDim(Matrix& D,map<int,int> value_function,int& mod){ //mod c'est la colonne à modifier, elle prend en sortie la valeur de la dimension+1
    int n,p;
    D.get_dim(n,p);
    while(mod != p){
        cout<<"//==========="<<endl;
        cout<<"debut boucle"<<endl;
        D.display();
        vector<int> labels=findLabel(D,value_function);
        mod=findNext(D,labels);
        if(mod<p){
            cout<<"mod="<<mod<<endl;
            next(D,mod);
            D.display();}
        if(sideReached(D)) return 1;
        cout<<"fin boucle"<<endl;
        cout<<"//==========="<<endl;
    }
    return 0;
}
void EF2(Matrix& D,map<int,int> value_function){
    int mod=0;
    int test=0; //prend 0 Si fully labelled dans la dimension actuelle, 1 si on a atteind le bord et qu'il faut diminuer d'une dimension
    while(mod<=nb_player){
        test=sameDim(D,value_function,mod);

        D.display();
        cout<<"test="<<test<<" mod="<<mod<<endl;
        if(test){
            cout<<"Decrease Dim=================="<<endl;
            D=decreaseDim(D);}
        else{
            if(mod<nb_player){
                D.display();
                cout<<"Increase Dim=================="<<endl;
                D=increase_dim(D);}
            else
                mod++;
        }
    }
}
