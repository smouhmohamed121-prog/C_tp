#include <stdio.h>

typedef struct {
    int jour;
    char mois[10];
    int annee;
}Date;
typedef struct {
    char nom[15], prenom[15];
    Date anniversire, date_embauche;
}Employe;
int main(void){
    int num ;
    int i ;
    printf ("Enter le Nomber d'employes : ");
    scanf ("%d",&num);
    Employe employe[num];
    for (i=0; i<num ; i++){
        printf ("\nEnter Employe %d:\n",i+1);
        printf ("Enter le Nom : ");
        scanf ("%s",&employe[i].nom);
        printf ("Entrer le Prenom : ");
        scanf ("%s",&employe[i].prenom);
        printf ("Enter la Date de naissance : ");
        scanf ("%d %s %d",&employe[i].anniversire.jour,&employe[i].anniversire.mois,&employe[i].anniversire.annee);
        printf ("Enter la Date d embauche : ");
        scanf ("%d %s %d",&employe[i].date_embauche.jour,&employe[i].date_embauche.mois,&employe[i].date_embauche.annee);
    }
    for (i=0; i<num ; i++){
        printf ("\nEmploye %d\n",i+1);
        printf ("Nom : %s\n"
                "Prenom : %s\n"
                "Date de naissance : %d %s %d \n"
                "Date d'embauche : %d %s %d\n"
                ,employe[i].nom,
                employe[i].prenom,
                employe[i].anniversire.jour,employe[i].anniversire.mois,employe[i].anniversire.annee,
                employe[i].date_embauche.jour,employe[i].date_embauche.mois,employe[i].date_embauche.annee
            );
    }
return 0;}