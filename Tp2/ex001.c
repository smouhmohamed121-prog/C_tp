#include <stdio.h>
#include <math.h>
int somme(int nomber);
int puissance (int nomber);
// gcc -S -O0 -fno-omit-frame-pointer ex001.c -o main.s
double cos_f(double x,int n);


int main(void){
    int n ;
    printf ("Enter le nomber n : ");
    scanf("%d",&n);
    int resultat = somme(n);
    printf("la somme est %d ",resultat);
    printf("\nla puissance : %d",puissance(n));
    printf ("\nle cos : %f",cos_f(3.5,7));
return 0;}

int somme (int nomber){
    if (nomber == 0) return 0;
    else return nomber + somme(nomber-1);
}


int puissance (int nomber){
    if (nomber == 0) return 0;
    else return pow(nomber,4) + puissance(nomber-1);
}

double cos_f(double x,int n){
    if (n==0) return 1.0;
    else return pow((-1),n)*(pow(x,2*n)/tgamma((2*n)+1)) + cos_f(x,n-1);
}