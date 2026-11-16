#include <stdio.h>

typedef struct {

    float longeur ;
    float largeur ;
    float epaisseur;
    int type ;

}Panneau;

void saisie(Panneau *p1);
void affichage (Panneau *p);
void volume (Panneau *p,float *volume);

int main(void){

    Panneau p1 ;
    float vol ;
    saisie(&p1);
    affichage(&p1);
    volume(&p1,&vol);

return 0;}


void saisie(Panneau *p1){

    printf ("Enter la longueur : ");
    scanf ("%f",&p1->longeur);
    printf ("Enter la largueur : ");
    scanf ("%f",&p1->largeur);
    printf ("Enter la epaisseur : ");
    scanf ("%f",&p1->epaisseur);
    printf ("Enter la type : ");
    scanf ("%d",&p1->type);

}

void affichage (Panneau *p){
    printf ("longueur : %.3f \n",p->longeur);
    printf ("largueur : %.3f\n",p->largeur);
    printf ("epaisseur : %.3f\n",p->epaisseur);
    printf ("type : %d\n",p->type);
}


void volume (Panneau *p,float *volume){
    *volume = p->longeur * p->largeur * p->epaisseur;
    printf ("le volume est :%.3f",*volume);

}