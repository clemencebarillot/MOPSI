#include "kuhn.h"



void left(Matrix& M){
    //Ici on veut modifier la matrice pour supprimer la première colonne, tout décaller et remettre la nouvelle tout à droite.
    int n,p;
    M.get_dim(n,p);
    vector<int> X=M.get_vector(0);
    for(int i=1;i<n;i++)
        M.set_vector(i-1,M.get_vector(i));
    M.set_vector(n-1,X);
}

void right(Matrix& M){
    //Ici on veut modifier la matrice pour supprimer la dernière colonne, tout décaller et remettre la nouvelle tout à gauche.
    int n,p;
    M.get_dim(n,p);
    vector<int> X=M.get_vector(n-1);
    for(int i=n-1;i>0;i--)
        M.set_vector(i,M.get_vector(i-1));
    M.set_vector(0,X);
}

void next(Matrix& M,int i){ //C'est avancer, on modifie la bonne colonne, et on fait les inversions nécessaires vues avec Fred
    int n,p;
    M.get_dim(n,p);
    vector<int> X(n);
    for(int k=0;k<n;k++)
        X[k]=M.get_vector(i-1)[k]+M.get_vector(i+1)[k]-M.get_vector(i)[k];
    M.set_vector(i,X);
    M.last_modified=i;
    if(i==0){
        left(M);
        M.last_modified=p-1;
    }
    else if(i==p-1){ //Faire attention quand on commencera dans la dimension 1 (avec le else)
        right(M);
        M.last_modified=0;
    }
}


void increase_dim(Matrix& M){ //Renvoie la matrice augmentée, et c'est suremenent un pb, faudrait olutot modifier M
    int n,p;
    M.get_dim(n,p);
    vector<int> new_column(n);
    new_column=M.get_vector(0);
    Matrix Mp(n+1,p+1);
    new_column[0]--; new_column.push_back(1);
    for(int i=0;i<n+1;i++)
        for(int j=0;j<p+1;j++){
            if(j==p)
                Mp.set(i,j,new_column[i]);
            else if(j!=p && i==n)
                Mp.set(i,j,0);
            else
                Mp.set(i,j,M.get(i,j));
        }
    Mp.last_modified=p;
    Mp.last_labels=vector<int>(M.last_labels);
    Mp.last_labels.push_back(p);
    M=Mp;
//    cout<<"fin increase dim"<<endl;
}


//bool sideReached(Matrix simplex) //renvoie true si on a atteint le bord du simplexe et qu'on doit descendre d'une dim
//Vérifier si dans la nouvelle colonne s'il n'y a pas de -1.
bool sideReached(Matrix& simplex){
    bool test = false;
    int currentCol = simplex.last_modified;
    int n, p;
    simplex.get_dim(n,p);
    for(int i = 0; i< n; i++){
        if (simplex.get(i,currentCol) <0)
            test = true;
    }
    return test;
}

vector<vector<vector<int>>> vector_to_parts(Matrix& M){
    /*
     Alors on va calculer les labels avec les demis :
     **Avoir le graphe sous les yeux peut etre utile**
     on compte la perle qui est supérieur au demi
     donc si c'est un entier, c'est que le couteau est sur la perle donc on ne l'a pas.
     donc avec un vecteur [3/2,2,3/2] ca veut dire qu'on a 5 perles
     donc on a [3,4,3]
     On fait x*2 par rapport au dessin p18 de la thèse !!!
     Donc on commence à 1, si la première est paire on prend ce qu'il y a entre. Le fait que l'on commence à 1 n'est pas important car on ne considère que les longueurs nous.
     Pas comme la thèse qui considère les coups de couteau.
     la première part prend là première perle, la deuxième prend la 3 ème et la dernière prend la dernière. La 2 et 4  ne sont pas comptées.
     */

    //On veut renvoyer un tableau du type [ [ [1,2,3],[5,6],[8] ], [ [1,2,3],[4,5],[7,8] ], [ [1,2],[3,4],[6,7,8] ]
    //c'est un part=vector<vector<vector<int>>>
    //Il veut dire part[i] : c'est la ième colonne que l'on va décomposer en parts donc M.get_vector(i).
    //Part[i][j] : correspond à la part de longueur M.get_vector(i)[j]
    //part[i][j] est composé des perles qui sont effectivement dans la part
    //Ainsi ensuite pour la fonction label il va suffire d'additionner la value function des perles qui sont dans chaque part et hop.

    int n,p;
    M.get_dim(n,p);
    vector<vector<vector<int>>> results;
    results.resize(p);
    for(int i=0;i<n;i++)
        results[i].resize(n);

    for(int i=0;i<p;i++){
        vector<int> column=M.get_vector(i);
        int start=1; //Il va servir à définir le coup de couteau qui sert de départ. S'il est impair, on ne compte pas la perle.
        int end=1; //Il va servir à définir le coup de couteau qui sert de fin. S'il est impair, on ne compte pas la perle.
        int length; //Représente la longueur de chaque part.
        for(int j=0;j<n;j++){
            if(n!=column.size())
                cerr<<"column size != n"<<endl;
            length=column[j];
            while(end-start<length){
                end++;
                if(end%2==1 && end>start+1){
                    results[i][j].push_back((end-1)/2-1); //Le -1 pour commencer à la perle 0.
                    //cout<<"colonne "<<i<<" ligne "<< j << " on push la perle " << end/2 -1 <<endl;
                }
            }
            start=end;
        }
    }
    return results;
}




vector<int> findLabel(Matrix& M, map<int,int> value_function, vector<vector<int>>& Ef2,bool EF2){
    /*
     Actuellement tous les joueurs ont la même fonction de labeling, donc au lieu d'avoir un vecteur de taille n, on a un vecteur de taille 1
     associé au label du découpage
     Le nombre correspond à la part préférée dans ce découpage
     (on peut faire le lien avec le fait que l'on veut des découpages où la part préférée est différente sur chaque angle du mini simplexe)
    */

//    cout<<"//=======Label"<<endl;

    vector<vector<vector<int>>> results=vector_to_parts(M);

    int n,p;
    M.get_dim(n,p);
    Matrix memory(n,p); //matrice qui donne a chaque partage son label
    for(int part=0;part<n;part++){ // part correspond à un partage du simplexe
        vector<vector<int>> column=results[part];

        vector<int> values;
        for(int j=0;j<column.size();j++){
            int value=0;
            for(int k=0;k<column[j].size();k++)
                value+=value_function[column[j][k]];
            values.push_back(value);
        }
        memory.set_vector(part,values);
    }

    vector<int> Label;
    for(int i=0;i<p;i++){
        int k=0;
        int max=memory.get(0,i);
        for(int j=0;j<n;j++)
            if(memory.get(j,i)>max){
                k=j;
                max=memory.get(j,i);
            }

        Label.push_back(k);
    }


    if(EF2){
        for(int i=0;i<p;i++){
            Ef2.push_back(results[i][Label[i]]);
        }
    }
//    cout<<"//=======End Label"<<endl;
    return Label;
}

int findNext(Matrix& M,vector<int> labels){
    int label=labels[M.last_modified];
    int n,p;
    M.get_dim(n,p);
    for(int i=0;i<p;i++)
        if(i!=M.last_modified && label==labels[i])
            return i;
//    cout<<"In this dimensions labels are ";
//    for(int i=0;i<p;i++)
//        cout<<labels[i]<<" ";
//    cout<<endl;
    return p; //On est en fully labelled
}

//Matrix decreaseDim(Matrix currentSimplex)
//Si on a un nombre négatif on supprime cette colonne
//La ligne a sup est celle ou il n'y a que des 0 (après avoir sup la colonne)

void decreaseDim(Matrix &simplex){
    int n, p, j0;
    j0 = simplex.last_modified;
    simplex.get_dim(n,p);
    // on va supprimer la derniere ajoutée fatalement non?
    Matrix Mp(n-1,p-1);
    for(int i=0; i<n; i++){ // on balaie la colonne a supprimer qu'on remplace par des 0 --> suppression vitruelle de la colonne
        simplex.set(i,j0,0);
    }

    //recherche ligne à supprimer
    int i0 = 0;
    int count = 0;
    while(i0<n && count<p){
        count = 0;
        for(int j=0; j<n; j++){
            if(simplex.get(i0,j) == 0)
                count ++;
        }
        i0++;
    }
    i0--; // donne la ligne à supprimer

    //creation de la nouvelle matrice
    int delta_n = 0, delta_p = 0; // pour quand on aura sauté la colonne last_modified

    for(int i=0; i<n-1; i++){
        for(int j=0; j<p-1; j++){
            if(j >= j0)
                delta_p = 1;
            else delta_p = 0;
            if( i >= i0)
                delta_n = 1;
            else delta_n = 0;
            Mp.set(i,j,simplex.get(i+delta_n, j+delta_p));
        }
    }
    Mp.last_modified = simplex.last_labels[simplex.last_labels.size()-1];
    simplex.last_labels.pop_back();
    Mp.last_labels = vector<int>(simplex.last_labels);
    simplex=Mp;
}

//void next_step(Matrix& currentSimplex); // modifie la matrice en argument
//choisir la colonne à modifier : la première (et d'ailleurs l'unique) colonne avec le label égal au label de la nouvelle colonne formée. S'il n'y en a pas, on est en fullyLabelled()

//Matrix EF2(????) qui renvoie la matrice ef2, on verra après quel partage on prend.
//Matrix EF2(){   }


//??? EF2(int nPlayers,??? ); la fonction finale qui renvoie le partage EF2
////il faut créer une methode display pour les matrices; une methode label(colonne)
////a voir si on ne doit pas prendre en argument les labels aussi, et voir comment on garde en memoire le dernier pont ajouté


/*Point du 28/01
pour appliquer le next : trouver la colonne last modified et touver la nouvelle colonne qui va etre la last modified : c'est la première et la seule qui a le meme label que l'ancienne
*/
