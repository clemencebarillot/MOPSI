
#include "matrix.h"
#include "kuhn.h"
#include "path.h"
#include "data.h"

#include "time.h"

int main()
{

    map<int,int> value_function;
    map<int,map<int,int>> Value_Functions;

    bool sameValueFunction=false;

    int nb_player=3, nb_perl=5;
    string path="TestRandom";

    vector<vector<int>> Ef2;
    vector<vector<int>> Ef1;

    initiate_data_perl();
/*
    for(nb_perl=100;nb_perl<900;nb_perl+=10){
        if(nb_perl>=300)
            nb_perl+=10;
        if(nb_perl>=600)
            nb_perl+=30;
        Matrix S(1,1);

        create_data(path+".txt",nb_player,nb_perl,100,sameValueFunction);
        read_file(path+".txt",Value_Functions,nb_player,nb_perl,sameValueFunction);


        clock_t t1=clock();
        EF2(S,Value_Functions,nb_perl,nb_player,Ef2);
        clock_t t2=clock();
        cout<<"Execution time: "<<(t2-t1)/CLOCKS_PER_SEC<<" seconds."<<endl;


        write_data(path+"Results"+".txt",Ef2);

        write_time(nb_perl,(t2-t1)/CLOCKS_PER_SEC);
    }*/
    Matrix S(1,1);

    create_data(path+".txt",nb_player,nb_perl,100);
    read_file(path+".txt",value_function,nb_player,nb_perl);


    clock_t t1=clock();
    EF2(S,value_function,nb_perl,nb_player,Ef2);
    clock_t t2=clock();
    cout<<"Execution time: "<<(t2-t1)/CLOCKS_PER_SEC<<" seconds."<<endl;


    write_data(path+"Results"+".txt",Ef2);

    write_time(nb_perl,(t2-t1)/CLOCKS_PER_SEC);

//    for(int i=0;i<Ef2.size();i++){
//        cout<<"The perl for the player "<<i<<" are ";
//        for(int j=0;j<Ef2[i].size();j++)
//            cout<<Ef2[i][j]<<" ";
//        cout<<endl;
//        }

    cout<<"calcul EF1 ";

    bool res = EF1(Ef2,value_function,Ef1);

    cout<<res<<endl;
    return 0;
}
