#include <stdio.h>

typedef struct {

    int numerateur ;
    int denominateur;

}NombreRationnel;

void saisie (NombreRationnel *N);
NombreRationnel addition (NombreRationnel *N1 , NombreRationnel *N2);
NombreRationnel multiplication (NombreRationnel *N1, NombreRationnel *N2);
void affichage (NombreRationnel N);


int main(void){

    NombreRationnel N1;
    NombreRationnel N2;

    printf ("Enter le premier Nomber : \n");
    saisie(&N1);

    printf ("\n");

    printf ("Enter le deuxieme Nomber : \n");
    saisie(&N2);
    
    printf("\nL'addition des deux nombers : \n");
    affichage(addition(&N1,&N2));

    printf("\nLa multiplication des deux nombers : \n");
    affichage(multiplication(&N1,&N2));
       

return 0;}

void saisie (NombreRationnel *N){
    printf ("Enter le numerateur : ");
    scanf ("%d",&N->numerateur);
    printf ("Enter le denominateur : ");
    scanf ("%d",&N->denominateur);
}


NombreRationnel addition (NombreRationnel *N1 , NombreRationnel *N2){
    NombreRationnel resultat ;
    resultat.numerateur = (N1->numerateur * N2->denominateur)+(N2->numerateur * N1->denominateur);
    resultat.denominateur = N1->denominateur * N2->denominateur;
    return resultat;
}


NombreRationnel multiplication (NombreRationnel *N1, NombreRationnel *N2){
    NombreRationnel resultat ;
    resultat.numerateur = N1->numerateur * N2->numerateur ;
    resultat.denominateur = N1->denominateur * N2->denominateur;
    return resultat;
}

void affichage (NombreRationnel N){
    printf ("%d\n",N.numerateur);
    printf("---\n");
    printf("%d",N.denominateur);

}