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

    int test=0; //prend 0 Si fully labelled dans la dimension actuelle, 1 si on a atteint le bord et qu'il faut diminuer d'une dimension
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

int value_part(map<int,int> value_function, vector<int> part){ //pour des value fonction identiques, renvoie la valeur de la part
    int res = 0;
    if (part.size() ==0)
        return res;
    for (int i=0; i<part.size(); i++){
        res+= value_function[part[i]];
        //cout<<"valeur de la perle  "<<part[i]<< ": "<< value_function[part[i]] <<endl;
    }
    return res;
}

int max_vect(vector<int> vect){ // attention le vecteur doit etre non nul
    int res = vect[0];
    for(int i=0; i<vect.size(); i++){
        if (res<vect[i])
            res = vect[i];
    }
    return res;
}

void affiche_matrice(vector<vector<int>> mat){
    int n=mat.size(); //nb ligne
    int m = mat[0].size(); //nb col
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
void affiche_vecteur(vector<int> vect){
    if(vect.size()==0)
        cout<<" vect vide";
    for(int j=0; j<vect.size(); j++){
        cout<<vect[j]<<" ";}
    cout<<endl;
}

bool EF1(vector<vector<int>> Ef2, map<int,int> value_function, vector<vector<int>> Ef1){
    vector<vector<vector<int>>> parts; // la premiere ligne est le Ef2, la deuxieme la premiere perle de chaque ef2, la toiriseme la derniere (si differente de la premiere); la derniere l'ef2 privé de premiere et derniere
    parts.push_back(Ef2);
    int n = Ef2.size();


    vector<vector<int>> line1;
    vector<vector<int>> line2;
    vector<vector<int>> line3;


    for (int i=0; i<n; i++){
        vector<int> xf;
        vector<int> x0;

        if(Ef2[i].size()>0){
            xf.push_back( Ef2[i][Ef2[i].size() -1]);

            x0.push_back(Ef2[i][0]);

            if(xf==x0){
                xf.pop_back();
            }
        }

        vector<int> xj;
        if(Ef2[i].size()>2){
            for (int k=1; k<Ef2[i].size()-1; k++){
                xj.push_back(Ef2[i][k]);
            }
        }


        line1.push_back(x0);
        line2.push_back(xf);
        line3.push_back(xj);

    }

    parts.push_back(line1);
    parts.push_back(line2);
    parts.push_back(line3);

     vector<vector<int>> mat_value_parts; // la prmeiere ligne donne la val de chaque part du EF2, la dueximee de la part privee de la premier eperle, et la torisieme de lapart privee de la troisieme

      vector<int> value_inner_parts; // vect contenant la valeur des parts sans compter les extremités
      for(int i=0; i<n ; i++){ // on balaie les differentes parts
          value_inner_parts.push_back( value_part(value_function, parts[3][i]) );
      }

    vector<int> line_value1;
    vector<int> line_value2;
    vector<int> line_value3;


    for(int i=0; i<n; i++){// ligne des ef2
        int value = value_inner_parts[i] + value_part(value_function,parts[1][i]) + value_part(value_function,parts[2][i]);
        line_value1.push_back(value);
    }

    mat_value_parts.push_back(line_value1);

    for(int i=0; i<n; i++){// ligne des ef2-permiere perle

        int value = value_inner_parts[i];
        value+= value_part(value_function,parts[2][i]);
        line_value2.push_back(value);
    }

    mat_value_parts.push_back(line_value2);

    for(int i=0; i<n; i++){// ligne des ef2-derniere perle

        int value = value_inner_parts[i];
        value+= value_part(value_function,parts[1][i]);
        line_value3.push_back(value);
    }

    mat_value_parts.push_back(line_value3);

    // on a dorénavant une matrice qui contient la valeur du partage, du partage -premiere perle, et du partage moins derniere perle

    bool ef1 = true;
    int i=0;
    while(i<n && ef1){
        int val_part_i = mat_value_parts[0][i];

        if(val_part_i >= max_vect(mat_value_parts[0]))
           i++;
        else if(val_part_i >= max_vect(mat_value_parts[1]))
          i++;
        else if (val_part_i >= max_vect(mat_value_parts[2]))
          i++;
        else
          ef1=false;

    }
    return ef1;


}
