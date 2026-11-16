#include <stdio.h>

void calcule (int *tableau, int *taille , int *somme , int *produit);
int main(void){
    int taille = 0;
    do {
        printf ("Enter la taille du tableau : ");
        scanf ("%i",&taille);
    }while (taille <= 0);

    int tableau [taille];
    int i = 0;
    for (i; i<taille ; i++){
        printf ("tableau [%d] = ",i+1);
        scanf ("%d",&tableau[i]);
    }
    int somme , produit;
    somme = 0;
    produit = 1;
    calcule(tableau,&taille,&somme,&produit);
    printf ("la somme : %d Produit : %d",somme,produit);

return 0;}



void calcule (int *tableau, int *taille , int *somme , int *produit){
    for (int i = 0; i< (*taille) ; i++){
        *somme += *(tableau+i);
        *produit *= *(tableau+i);
    }
}