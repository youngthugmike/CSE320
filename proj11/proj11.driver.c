#include "/user/cse320/Projects/project11.support.h"
#include<stdio.h>
#include<math.h>
int main(){
    double A = 1.25;
    double B = -1.25;
    double C = 3.14159265;
    double D = -3.14159265;
    double E = 1;
    double F = -1;
    double G = 0;

    //union dp_item B;
    //B.drep = A;


    //-----------------------------------------------------------------absolute
    printf( "absolute(1.25): %16.8lf\n", absolute(A));
    printf( "absolute(-1.25): %16.8lf\n", absolute(B));
    printf( "absolute(pi): %16.8lf\n", absolute(C));
    printf( "absolute(-pi): %16.8lf\n", absolute(D));
    printf( "absolute(1): %16.8lf\n", absolute(E));
    printf( "absolute(-1): %16.8lf\n", absolute(F));
    printf( "absolute(0): %16.8lf\n", absolute(G));

    //-----------------------------------------------------------------modulo
    printf( "modulo(1.25, 1.25): %16.8lf\n", modulo(A, A));
    printf( "modulo(-1.25, -1.25): %16.8lf\n", modulo(B, B));
    printf( "modulo(pi, -pi): %16.8lf\n", modulo(C, D));
    printf( "modulo(-pi, 1.25): %16.8lf\n", modulo(D, A));
    printf( "modulo(pi, -1): %16.8lf\n", modulo(C, F));
    printf( "modulo(pi, 1): %16.8lf\n", modulo(C, E));
    printf( "modulo(pi, 1.25): %16.8lf\n", modulo(C, A));

    //-----------------------------------------------------------------factorial
    printf( "factorial(6): %16.8lf\n", factorial(6));
    printf( "factorial(5): %16.8lf\n", factorial(5));
    printf( "factorial(4): %16.8lf\n", factorial(4));
    printf( "factorial(3): %16.8lf\n", factorial(3));
    printf( "factorial(2): %16.8lf\n", factorial(2));
    printf( "factorial(1): %16.8lf\n", factorial(1));

    //-----------------------------------------------------------------power
    printf( "power(pi, 5): %16.8lf\n", power(C, 5));
    printf( "power(pi, 4): %16.8lf\n", power(C, 4));
    printf( "power(pi, 3): %16.8lf\n", power(C, 3));
    printf( "power(pi, 2): %16.8lf\n", power(C, 2));
    printf( "power(pi, 1): %16.8lf\n", power(C, 1));
    printf( "power(pi, 0): %16.8lf\n", power(C, 0));

    //-----------------------------------------------------------------cosine
    printf( "cosine(0): %16.8lf\n", cosine(0));
    printf( "cosine(pi): %16.8lf\n", cosine(M_PI));
    printf( "cosine(10): %16.8lf\n", cosine(10));
    printf( "cosine(15): %16.8lf\n", cosine(15));
    printf( "cosine(25): %16.8lf\n", cosine(25));
    printf( "cosine(30): %16.8lf\n", cosine(30));

    return 0;
}
