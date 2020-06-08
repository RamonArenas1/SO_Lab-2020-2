#include "fix-point.h"
#include <stdio.h>

int main(){
    int a1 = 0;
    int a2 = 0;
    int r = 0;
    printf("Pruebas con TRUNCATED\n");
    
    //prueba 1, suma FP-Int
    a1 =FRAC_TO_FIXPOINT(24,10);
    a2 =FIXPOINT_TO_INT_TRUNCATED(ADD_FP_INT(a1,6));
    printf("PRUEBA Suma FP-INT: 2.4 + 6 es: %i\n",a2);
    
    //prueba 2, suma FP
    a1 = FRAC_TO_FIXPOINT(48,10);
    a2 = FRAC_TO_FIXPOINT(31,10);
    r = FIXPOINT_TO_INT_TRUNCATED(ADD_FP(a1,a2));
    printf("PRUEBA Suma FP: 4.8 + 3.1 es: %i\n",r);

    //prueba 3, resta FP-Int
    a1 = FRAC_TO_FIXPOINT(224,10);
    //a2 = FRAC_TO_FIXPOINT(31,10);
    r = FIXPOINT_TO_INT_TRUNCATED(SUB_FP_INT(a1,20));
    printf("PRUEBA Resta FP-INT: 22.4 - 20 es: %i\n",r);

    //prueba 4, resta FP
    a1 = FRAC_TO_FIXPOINT(554,100);
    a2 = FRAC_TO_FIXPOINT(202,100);
    r = FIXPOINT_TO_INT_TRUNCATED(SUB_FP(a1,a2));
    printf("PRUEBA Resta FP: 5.54 - 2.02 es: %i\n",r);

    //prueba 5, multi FP-Int
    a1 = FRAC_TO_FIXPOINT(22,10);
    //a2 = FRAC_TO_FIXPOINT(31,10);
    r = FIXPOINT_TO_INT_TRUNCATED(MULT_FP_INT(a1,3));
    printf("PRUEBA Multi FP-INT: 2.2 x 3 es: %i\n",r);

    //prueba 6, multi FP
    a1 = FRAC_TO_FIXPOINT(554,100);
    a2 = FRAC_TO_FIXPOINT(303,100);
    r = FIXPOINT_TO_INT_TRUNCATED(MULT_FP(a1,a2));
    printf("PRUEBA Multi FP: 5.54 x 3.03 es: %i\n",r);

    //prueba 7, div FP-Int
    a1 = FRAC_TO_FIXPOINT(224,10);
    //a2 = FRAC_TO_FIXPOINT(31,10);
    r = FIXPOINT_TO_INT_TRUNCATED(DIV_FP_INT(a1,8));
    printf("PRUEBA Division FP-INT: 22.4 / 8 es: %i\n",r);

    //prueba 8, div FP
    a1 = FRAC_TO_FIXPOINT(554,10);
    a2 = FRAC_TO_FIXPOINT(42,10);
    r = FIXPOINT_TO_INT_TRUNCATED(DIV_FP(a1,a2));
    printf("PRUEBA Division FP: 55.4 / 4.2 es: %i\n",r);

    printf("\nPruebas con ROUNDED\n");
    
    //prueba 1, suma FP-Int
    a1 =FRAC_TO_FIXPOINT(24,10);
    a2 =FIXPOINT_TO_INT_ROUNDED(ADD_FP_INT(a1,6));
    printf("PRUEBA Suma FP-INT: 2.4 + 6 es: %i\n",a2);
    
    //prueba 2, suma FP
    a1 = FRAC_TO_FIXPOINT(48,10);
    a2 = FRAC_TO_FIXPOINT(31,10);
    r = FIXPOINT_TO_INT_ROUNDED(ADD_FP(a1,a2));
    printf("PRUEBA Suma FP: 4.8 + 3.1 es: %i\n",r);

    //prueba 3, resta FP-Int
    a1 = FRAC_TO_FIXPOINT(224,10);
    //a2 = FRAC_TO_FIXPOINT(31,10);
    r = FIXPOINT_TO_INT_ROUNDED(SUB_FP_INT(a1,20));
    printf("PRUEBA Resta FP-INT: 22.4 - 20 es: %i\n",r);

    //prueba 4, resta FP
    a1 = FRAC_TO_FIXPOINT(554,100);
    a2 = FRAC_TO_FIXPOINT(202,100);
    r = FIXPOINT_TO_INT_ROUNDED(SUB_FP(a1,a2));
    printf("PRUEBA Resta FP: 5.54 - 2.02 es: %i\n",r);

    //prueba 5, multi FP-Int
    a1 = FRAC_TO_FIXPOINT(22,10);
    //a2 = FRAC_TO_FIXPOINT(31,10);
    r = FIXPOINT_TO_INT_ROUNDED(MULT_FP_INT(a1,3));
    printf("PRUEBA Multi FP-INT: 2.2 x 3 es: %i\n",r);

    //prueba 6, multi FP
    a1 = FRAC_TO_FIXPOINT(554,100);
    a2 = FRAC_TO_FIXPOINT(303,100);
    r = FIXPOINT_TO_INT_ROUNDED(MULT_FP(a1,a2));
    printf("PRUEBA Multi FP: 5.54 x 3.03 es: %i\n",r);

    //prueba 7, div FP-Int
    a1 = FRAC_TO_FIXPOINT(224,10);
    //a2 = FRAC_TO_FIXPOINT(31,10);
    r = FIXPOINT_TO_INT_ROUNDED(DIV_FP_INT(a1,8));
    printf("PRUEBA Division FP-INT: 22.4 / 8 es: %i\n",r);

    //prueba 8, div FP
    a1 = FRAC_TO_FIXPOINT(554,10);
    a2 = FRAC_TO_FIXPOINT(42,10);
    r = FIXPOINT_TO_INT_ROUNDED(DIV_FP(a1,a2));
    printf("PRUEBA Division FP: 55.4 / 4.2 es: %i\n",r);

    return 0;
}