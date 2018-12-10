#include "kuhn.h"


Matrix increase_dim(Matrix M){
    vector<int> max=M.get_vector_max();
    int n,p;
    M.get_dim(n,p);
    Matrix Mp(n+1,p+1);
    max[0]--; max[n]++;
    for(int i=0;i<n+1;i++)
        for(int j=0;j<p+1;j++){
            if(j==p)
                Mp.set(i,j,max[i]);
            else if(j!=p && i==n)
                Mp.set(i,j,0);
            else
                Mp.set(i,j,M.get(i,j));
        }
    Mp.last_modified=p;
    return(Mp);
}

//int findLabel(Matrix Label;map)


//bool isFullyLabelled;

//int findLabel(Matrix, fonction labbel, tableau des labels (memoisation))

//Matrix increaseDim(Matrix currentSimplex, ???); //deja fait

//bool sideReached(??); //renvoie true si on a atteint le bord du simplexe et qu'on doit descendre d'une dim
//Vérifier si dans la nouvelle colonne s'il n'y a pas de -1.
bool sideReached(Matrix simplex){
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

//Matrix decreaseDim(Matrix& currentSimplex, ???);
//Si on a un nombre négatif on supprime cette colonne
//La ligne a sup est celle ou il n'y a que des 0 (après avoir sup la colonne)

Matrix decreaseDim(Matrix& simplex){
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

    for(int i=0; i<n; i++){
        for(int j=0; j<p; j++){
            if(j==j0)
                delta_p = 1;
            if( i == i0)
                delta_n = 1;
            Mp.set(i,j,simplex.get(i+i0, j+j0));

        }
    }
    Mp.last_modified = ??; // ON MET QUELLE VALEUR DU COUP ICI?
    return(Mp);
}

//void next_step(Matrix& currentSimplex, ???); // modifie la matrice en argument
//choisir la colonne à modifier : la première (et d'ailleurs l'unique) colonne avec le label égal au label de la nouvelle colonne formée. S'il n'y en a pas, on est en fullyLabelled()

//Matrix EF2() qui renvoie la matrice ef2, on verra après quel partage on prend.


//??? EF2(int nPlayers,??? ); la fonction finale qui renvoie le partage EF2
////il faut créer une methode display pour les matrices; une methode label(colonne)
////a voir si on ne doit pas prendre en argument les labels aussi, et voir comment on garde en memoire le dernier pont ajouté
