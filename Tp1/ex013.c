#include <stdio.h>

struct etudiant {
    char nom[15], prenom[15];
    int CNE;
    float notes[4], moyenne;
};

int grandeMoyenne(struct etudiant *T, int num);
void affichage(struct etudiant *T, int indice);
void tri_tableau(struct etudiant *T, int taille);

int main(void) {
    int num;

    printf("Entrer le nombre des etudiants : ");
    scanf("%d", &num);

    struct etudiant T[num];

    // Saisie des informations
    for (int i = 0; i < num; i++) {
        printf("\nEtudiant %d :\n", i + 1);

        printf("Nom : ");
        scanf("%14s", T[i].nom);

        printf("Prenom : ");
        scanf("%14s", T[i].prenom);

        printf("CNE : ");
        scanf("%d", &T[i].CNE);

        printf("Notes :\n");
        for (int j = 0; j < 4; j++) {
            printf("N%d : ", j + 1);
            scanf("%f", &T[i].notes[j]);
        }

        printf("Moyenne : ");
        scanf("%f", &T[i].moyenne);
    }

    // Recherche de la plus grande moyenne
    int indice = grandeMoyenne(T, num);

    printf("\nL'etudiant ayant la plus grande moyenne :\n");
    affichage(T, indice);

    // Tri du tableau
    tri_tableau(T, num);

    // Affichage du tableau trie
    printf("\nLe tableau trie en ordre decroissant :\n");

    for (int i = 0; i < num; i++) {
        affichage(T, i);
    }

    return 0;
}

// Recherche de la plus grande moyenne
int grandeMoyenne(struct etudiant *T, int num) {
    float grand_moyenne = T[0].moyenne;
    int indice = 0;

    for (int i = 1; i < num; i++) {
        if (grand_moyenne < T[i].moyenne) {
            grand_moyenne = T[i].moyenne;
            indice = i;
        }
    }

    return indice;
}

// Affichage d'un etudiant
void affichage(struct etudiant *T, int indice) {
    printf("\nEtudiant %d :\n", indice + 1);

    printf("Nom : %s\n", T[indice].nom);
    printf("Prenom : %s\n", T[indice].prenom);
    printf("CNE : %d\n", T[indice].CNE);

    printf("Notes :\n");

    for (int j = 0; j < 4; j++) {
        printf("N%d = %.2f\n", j + 1,
               T[indice].notes[j]);
    }

    printf("Moyenne : %.2f\n", T[indice].moyenne);
}

// Tri en ordre decroissant selon la moyenne
void tri_tableau(struct etudiant *T, int taille) {
    int max;
    struct etudiant temp;

    for (int i = 0; i < taille - 1; i++) {
        max = i;

        for (int j = i + 1; j < taille; j++) {
            if (T[j].moyenne > T[max].moyenne) {
                max = j;
            }
        }

        if (max != i) {
            temp = T[i];
            T[i] = T[max];
            T[max] = temp;
        }
    }
}
