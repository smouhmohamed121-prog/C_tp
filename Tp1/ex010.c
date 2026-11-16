
#include <stdio.h>

typedef struct {
    int type ;
    int reference ;
    float prix ;
    int quantit ;

}Produit;

void saisie(Produit *p1);
void affichage (Produit *p);
Produit command (Produit *p);
void commapare (Produit *p1, Produit*p2);
int main(void){

    Produit p1 ;
    saisie(&p1);
    affichage(&p1);
    Produit p2;
    command (&p2);
    commapare (&p1,&p2);
return 0;}


void saisie(Produit *p1){

    printf ("Enter la reference : ");
    scanf ("%d",&p1->reference);
    printf ("Enter la prix : ");
    scanf ("%f",&p1->prix);
    printf ("Enter la quantit : ");
    scanf ("%d",&p1->quantit);
    printf ("Enter la produit : ");
    scanf ("%d",&p1->type);

}

void affichage (Produit *p){
    printf ("reference : %d \n",p->reference);
    printf ("prix : %.3f\n",p->prix);
    printf ("quantit : %d\n",p->quantit);
    printf ("produit : %d\n",p->type);
}


Produit command (Produit *p){
    printf ("Enter la command :\n");
    printf ("Enrer le produit : ");
    scanf ("%d",&p->type);
    printf ("Enter la quantite : ");
    scanf ("%d",&p->quantit);
}

void commapare (Produit *p1, Produit*p2){
    if (p1->type == p2->type){
    printf ("reference : %d \n",p1->reference);
    printf ("prix : %.3f\n",p1->prix*p2->quantit);
    printf ("quantit : %d\n",p1->quantit-p2->quantit);
    printf ("produit : %d\n",p1->type);
}
}