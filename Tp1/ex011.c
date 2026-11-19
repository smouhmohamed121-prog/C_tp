#include <stdio.h>
#include <stdlib.h>

typedef struct{
int nb_elem;
int *tab;
}TypeTableau;

TypeTableau CreationTableau(int n); 
void DestructionTableau(TypeTableau T);
void SimpleLectureTableau(TypeTableau T); 
void Affichage(TypeTableau T);
TypeTableau DoubleTableau(TypeTableau T);
int main(void){

    int n;
    printf("Enter le nomber des elements : ");
    scanf ("%d",&n);
    TypeTableau T = CreationTableau(n);
    printf ("Enter les elements du tableau : \n");
    SimpleLectureTableau(T);
    printf ("Les elements du tableau sont : \n");
    Affichage(T);
    TypeTableau T1 = DoubleTableau(T); 
    printf ("Les elements du tableau double sont : \n");
    Affichage(T1);
    DestructionTableau(T);
    DestructionTableau(T1);
return 0;}

//todo:  qui crée un tableau de n éléments.

TypeTableau CreationTableau(int n){
    
    TypeTableau tableau;
    tableau.tab = malloc (n * sizeof(int));
    if (tableau.tab ==NULL){
        exit(0);
    }
    tableau.nb_elem = n;
    return tableau;
}

//todo: qui libère la mémoire occupée par un tableau.
void DestructionTableau(TypeTableau T){
    free(T.tab);
}
//todo :qui lit les éléments d’un tableau au clavier. 
    //todo: On supposera dans cette fonction que le tableau a déjà été alloué précédemment.
void SimpleLectureTableau(TypeTableau T){
    for (int i = 0; i<T.nb_elem;i++){
        printf("T[%d] = ",i+1);
        scanf("%d",&T.tab[i]);
    }
}


//todo: qui affiche le contenu d’un tableau.
void Affichage(TypeTableau T){
    for (int i=0 ; i < T.nb_elem ;i++){
        printf ("T[%d] = %d\n",i+1,T.tab[i]);
    }
}

//todo: qui crée un nouveau tableau de même taille que T mais
TypeTableau DoubleTableau(TypeTableau T){
    TypeTableau T1;
    T1.tab = malloc(T.nb_elem * sizeof (int));
    T1.nb_elem = T.nb_elem;
    for (int i = 0 ; i<T.nb_elem;i++){
        T1.tab[i] = 2 * (T.tab[i]);
    }
    return T1;

}

