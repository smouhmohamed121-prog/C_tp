
#include <stdio.h>
#include <math.h>
typedef struct {
    double re;
    double im;
}Complex;
double real(Complex *z);
double imag(Complex *z);
double abs_complex(Complex *z);
Complex mul(Complex *z1, Complex *z2);

int main(void){

    Complex com = {3 , 2};
    Complex con = {2 , 3};
    printf("imag : %f\n",imag(&com));
    printf ("real : %f\n",real(&com));
    printf ("module : %f\n",abs_complex(&com));
    Complex result = mul(&com,&con);
    printf ("multip : %f + %fi \n",result.re,result.im);
return 0;}

double imag(Complex *z){
    return z->im;
}
double real (Complex *z){
    return z->re;
}
Complex mul(Complex *z1, Complex *z2){
    Complex result ;
    result.re = z1->re * z2->re -(z1->im * z2->im);
    result.im = ((z1->re * z2->im) + (z1->im * z2->re));
    return result;
}
double abs_complex(Complex *z){
    return sqrt(pow(z->re,2)+pow(z->im,2));
}