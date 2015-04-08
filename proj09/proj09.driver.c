#include <stdio.h>
#include "/user/cse320/Projects/project09.support.h"
int main(){


    printf("Negate:\n");
    printf("a=%08x, -(a) = %08x\n", 1, negate(1));
    printf("a=%08x, -(a) = %08x\n\n", 2, negate(2));

    printf("Absolute:\n");
    printf("a=%08x, abs(a) = %08x\n", 1, absolute(1));
    printf("a=%08x, abs(a) = %08x\n", 2, absolute(2));
    printf("a=%08x, abs(a) = %08x\n", -1, absolute(-1));
    printf("a=%08x, abs(a) = %08x\n", -2, absolute(-2));
    printf("a=%08x, abs(a) = %08x\n", 99, absolute(99));
    printf("a=%08x, abs(a) = %08x\n\n", -9, absolute(-9));

    printf("Add:\n");
    printf("a=%08x, b=%08x, a + b = %08x\n", 1,1,add(1,1));
    printf("a=%08x, b=%08x, a + b = %08x\n", -9,9,add(-9,9));
    printf("a=%08x, b=%08x, a + b = %08x\n", 9,-9,add(9,-9));
    printf("a=%08x, b=%08x, a + b = %08x\n", 4,-4,add(4,-4));
    printf("a=%08x, b=%08x, a + b = %08x\n\n", 5,4,add(5,4));

    printf("Sub:\n");
    printf("a=%08x, b=%08x, a - b = %08x\n", 1,1,sub(1,1));
    printf("a=%08x, b=%08x, a - b = %08x\n", -9,9,sub(-9,9));
    printf("a=%08x, b=%08x, a - b = %08x\n", 9,-9,sub(9,-9));
    printf("a=%08x, b=%08x, a - b = %08x\n", 4,-4,sub(4,-4));
    printf("a=%08x, b=%08x, a - b = %08x\n\n", 5,4,sub(5,4));

    printf("Mul:\n");
    printf("a=%08x, b=%08x, a * b = %08x\n", 1,1,mul(1,1));
    printf("a=%08x, b=%08x, a * b = %08x\n", -2,2,mul(-2,2));
    printf("a=%08x, b=%08x, a * b = %08x\n", 2,-2,mul(2,-2));
    printf("a=%08x, b=%08x, a * b = %08x\n", -2,-2,mul(-2,-2));
    printf("a=%08x, b=%08x, a * b = %08x\n\n", 5,4,mul(5,4));

    printf("Div:\n");
    printf("a=%08x, b=%08x, a / b = %08x\n", 1,1,divide(1,1));
    printf("a=%08x, b=%08x, a / b = %08x\n", -2,2,divide(-2,2));
    printf("a=%08x, b=%08x, a / b = %08x\n", 2,-2,divide(2,-2));
    printf("a=%08x, b=%08x, a / b = %08x\n", -2,-2,divide(-2,-2));
    printf("a=%08x, b=%08x, a / b = %08x\n\n", 8,4,divide(8,4));

    printf("Rmd:\n");
    printf("a=%08x, b=%08x, a mod b = %08x\n", 1,1,remain(1,1));
    printf("a=%08x, b=%08x, a mod b = %08x\n", 5,4,remain(5,4));
    printf("a=%08x, b=%08x, a mod b = %08x\n", 7,3,remain(7,3));
    printf("a=%08x, b=%08x, a mod b = %08x\n", 7,5,remain(7,5));
    printf("a=%08x, b=%08x, a mod b = %08x\n", 8,4,remain(8,4));
    printf("a=%08x, b=%08x, a mod b = %08x\n", -52,10,remain(-52,10));
    printf("a=%08x, b=%08x, a mod b = %08x\n", -54,-10,remain(-54,-10));
    printf("a=%08x, b=%08x, a mod b = %08x\n\n", 53,-10,remain(53,-10));

    printf("Pwr:\n");
    printf("a=%08x, b=%08x, a ^ b = %08x\n", 1,1, power(1,1));
    printf("a=%08x, b=%08x, a ^ b = %08x\n", 2,3, power(2,3));
    printf("a=%08x, b=%08x, a ^ b = %08x\n", 3,3, power(3,3));
    printf("a=%08x, b=%08x, a ^ b = %08x\n", 4,4, power(4,4));
    printf("a=%08x, b=%08x, a ^ b = %08x\n\n", 5,5, power(5,5));
    printf("a=%08x, b=%08x, a ^ b = %08x\n", 0,1, power(0,1));
    printf("a=%08x, b=%08x, a ^ b = %08x\n", -4,2, power(-4,2));
    printf("a=%08x, b=%08x, a ^ b = %08x\n", -5,5, power(-5,5));
    printf("a=%08x, b=%08x, a ^ b = %08x\n", 5,-5, power(5,-5));
    printf("a=%08x, b=%08x, a ^ b = %08x\n\n", -4,1, power(-4,1));

    printf("Fact:\n");
    printf("3! = %08x\n", factorial(3));
    printf("4! = %08x\n", factorial(4));
    printf("5! = %08x\n", factorial(5));
    printf("6! = %08x\n", factorial(6));
    printf("7! = %08x\n\n", factorial(7));


    return 0;
}
