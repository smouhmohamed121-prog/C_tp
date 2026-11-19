#include <stdio.h>
#include <math.h>
int somme(int nomber); // calculate 1+2+3 +..+ nomber
int puissance (int nomber); // calculate 1+2⁴ + 3⁴+ ...+ n⁴
// gcc -S -O0 -fno-omit-frame-pointer ex001.c -o main.s : to get the amamble
double cos_f(double x,int n); // calculate cos(x) using taylyor formula
double exp_f(double x,int n); // calculate exp(x) using taylor formula
double power(double x, int n); // calculate x^n using recursive function 
                                // It already defined in C pow but just for fun


int main(void){
    int n,num ;
    float x ;

    printf ("Enter le nomber n : ");
    scanf("%d",&n);
    int resultat = somme(n);
    printf("la somme est %d ",resultat);
    printf("\nla puissance : %d",puissance(n));


    printf("\n Calcule de cos (x,n) exp(x,n) & x^n \n");
    printf ("Enter le nomber n: ");
    scanf("%d",&num);
    printf("Enter le nomber x: ");
    scanf("%f",&x);

    printf ("Le cos : %5.3f",cos_f(x,num));
    printf("\nL'exp : %5.3f",exp_f(x,num));
    printf("\npower : %5.3f",power(x,num));

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
    //§ tgamma : double tgamma(double x); the gamma function 
    //* tgamma (n+1) = n!
}

double exp_f(double x,int n){
    if (n == 0) return 1;
    else return pow(x,n)/tgamma(n+1) + exp_f(x,n-1);
}

double power(double x,int n){
    if (n== 0) return 1;
    else return x*power(x,n-1);
}