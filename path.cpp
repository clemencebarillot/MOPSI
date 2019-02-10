#include "path.h"



int sameDim(Matrix& D,map<int,int> value_function,int& mod,vector<vector<int>>& Ef2){ //mod c'est la colonne à modifier, elle prend en sortie la valeur de la dimension+1
    int n,p;
    D.get_dim(n,p);
    while(mod != p){
//        cout<<"//==========="<<endl;
//        cout<<"debut boucle"<<endl;
//        D.display();
        vector<int> labels=findLabel(D,value_function,Ef2);
        mod=findNext(D,labels);
        if(mod<p){
//            cout<<"mod="<<mod<<endl;
            next(D,mod);
//            D.display();
        }
        if(sideReached(D)) return 1;
//        cout<<"fin boucle"<<endl;
//        cout<<"//==========="<<endl;
    }
    return 0;
}
vector<int> EF2(Matrix& D,map<int,int> value_function,int nb_perl,int nb_player,vector<vector<int>>& Ef2){


    cout<<"Initialisation..."<<endl;
    int mod=0;
    D.set(0,0,2*nb_perl); //surement multiplier par 2  pour prendre en compte les demis....

    vector<int> labels=findLabel(D,value_function,Ef2);  //Petite initialisation à la main pour éviter les bug.
    mod=findNext(D,labels);
    cout<<"Increasing to dimension  2"<<endl;
    increase_dim(D);

    int test=0; //prend 0 Si fully labelled dans la dimension actuelle, 1 si on a atteind le bord et qu'il faut diminuer d'une dimension
    while(mod<=nb_player){
        test=sameDim(D,value_function,mod,Ef2);
        if(test){
            cout<<"Decreasing to dimension "<<mod-1<<endl;
            decreaseDim(D);}
        else{
            if(mod<nb_player){
                cout<<"Increasing to dimension "<<mod+1<<endl;
                increase_dim(D);}
            else
                mod++;
        }
    }
    labels=findLabel(D,value_function,Ef2,true);
//    for(int i=0;i<Ef2.size();i++){
//    cout<<"The perl for the player "<<i<<" are ";
//    for(int j=0;j<Ef2[i].size();j++)
//        cout<<Ef2[i][j]<<" ";
//    cout<<endl;
//    }
    cout<<"Ef2 is found, please have a look in the Result File."<<endl;
    return labels;
}


