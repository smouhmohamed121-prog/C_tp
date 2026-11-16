/* todo 
Ecrire un programme qui :
-
 Déclare un tableau d’étudiants T.
-
 Lit les informations de 5 étudiants.
-
 Cherche l'étudiant ayant la plus grande moyenne, puis affiche ses informations.
-
 Trie le tableau de structures T en ordre décroissant selon la moyenne.
*/
#include <stdio.h>

struct etudiant{
    char nom[15] ,prenom[15];
    int CNE;
    float notes[4] , moyenne;
};

int grandeMoyenne (struct etudiant *T,int *num);
void affichage (struct etudiant *T,int indice);
void tri_tableau (struct etudiant *T,int *taille);
int main(void){
    int num = 0;
    printf ("Enter le nomber des Etudiants : ");
    scanf ("%d",&num);
    struct etudiant T[num];
    int sum = 0;
    int i ;
    for ( i = 0; i<num ; i++){
        printf ("Etudiant %d :\n",i+1);
        printf("Nom : ");
        scanf ("%s",T[i].nom);
        printf("Prenom : ");
        scanf ("%s",T[i].prenom);
        printf("CNE : ");
        scanf("%d",&T[i].CNE);
        printf ("Notes : \n");
        for (int j=0 ; j<4 ; j++){
            printf("N%d : ",j+1);
            scanf ("%f",&T[i].notes[j]);
    
        }
        printf ("Moyenne : ");
        scanf ("%f",&T[i].moyenne);
    }
    int indice = grandeMoyenne(&T,&num);
    printf ("L'eleve qui a le plus grand Moyenne :\n");
    void affichage (&T[indice] ,indice);
    printf ("\nLe tableau trie :\n");
    void tri_tableau (struct etudiant *T,int *taille);
    for ( i = 0; i<num ; i++){
        printf ("Etudiant %d :\n",i+1);
        printf("Nom : ");
        scanf ("%s",T[i].nom);
        printf("Prenom : ");
        scanf ("%s",T[i].prenom);
        printf("CNE : ");
        scanf("%d",&T[i].CNE);
        printf ("Notes : \n");
        for (int j=0 ; j<4 ; j++){
            printf("N%d : ",j+1);
            scanf ("%f",&T[i].notes[j]);
    
        }
        printf ("Moyenne : ");
        scanf ("%f",&T[i].moyenne);
    }
return 0;}

//* le plus grand moyenne :
int grandeMoyenne (struct *T,int *num){
    float grand_moyenne = T[0]->moyenne;
    int indice = 0;
    for (int i = 0; i<num;i++){
        if (grand_moyenne < T[i]->moyenne){
            indice = i;
        }
    }
    return indice;
}
//* Affichage d'etudiant avac le puls gand moyenne :
void affichage (struct *etudiant,int indice){
    printf ("Etudiant %d :\n",indice);
    printf("Nom : %s",T[indice]->nom);
    printf("Prenom : %s",T[indice]->prenom);
    printf("CNE : %d",T[indice]->CNE);
    printf ("Notes : \n");
    for (int j=0 ; j<4 ; j++){
    printf("N%d = %f\n",j+1,T[indice]->notes[j]);
    }
    printf ("Moyenne : %f",T[indice]->moyenne);
}
//* tri le tableau en order decroissant :
void tri_tableau (struct etudiant *T,int *taille){
    int max ,i ,j,temp;
    for (i = 0; i< *taille - 1 ; i++){
        max = T[i]->moyenne;
        for (j = i+1 ; j< *taille ; j++){
            if (T[i]->moyenne <= T[j]-> moyenne){
                max = T[j]->moyenne;
            }

        }
        if (max == T[i]->moyenne) continue;
        else {
            temp = T[i]->moyenne;
            T[i]->moyenne = T[j]->moyenne;
            T[j]->moyenne = temp;
        }
    }
}