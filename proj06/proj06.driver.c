#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"
#include "/user/cse320/lib/bitlib.h"

#define INFINITY  (__builtin_inff())
#define NAN       (__builtin_nanf (""))

int main(){
	float result;

	printf("multiplying -14.5 and -0.375... \n");
	result = mult(-14.5, -0.375);
	printf("Correct value: %f \n", 5.4375);
	printf("Your value: %f \n\n", result);

	printf("multiplying 14.5 and 0.375... \n");
	result = mult(14.5, 0.375);
	printf("Correct value: %f \n", 5.4375);
	printf("Your value: %f \n\n", result);

	printf("multiplying 14.5 and -0.375... \n");
	result = mult(14.5, -0.375);
	printf("Correct value: %f \n", -5.4375);
	printf("Your value: %f \n\n", result);

	printf("multiplying -14.5 and 0.375... \n");
	result = mult(-14.5, 0.375);
	printf("Correct value: %f \n", -5.4375);
	printf("your value: %f \n\n", result);

	printf("multiplying -1.5 and -1.375... \n");
	result = mult(-1.5, -1.375);
	printf("Correct value: %f \n", 2.0625);
	printf("Your value: %f \n\n", result);

	printf("multiplying 1.5 and 1.375... \n");
	result = mult(1.5, 1.375);
	printf("Correct value: %f \n", 2.0625);
	printf("Your value: %f \n\n", result);
/*
	printf("multiplying INF and INF... \n");
	result = mult(INFINITY, INFINITY);
	printf("Multiplication Result: %f \n\n", result);

	printf("multiplying NAN and NAN... \n");
	result = mult(NAN, NAN);
	printf("Multiplication Result: %f \n\n", result);
*/
	printf("multiplying -1.0 and 1.0... \n");
	result = mult(-1.0, 1.0);
	printf("Correct value: %f \n", -1.0);
	printf("Your value: %f \n\n", result);

	printf("multiplying 1.0 and -1.0... \n");
	result = mult(1.0, -1.0);
	printf("Correct value: %f \n", -1.0);
	printf("Your value: %f \n\n", result);

	printf("multiplying 3.3 and 2.1... \n");
	result = mult(3.3, 2.1);
	printf("Correct value: %f \n", 6.93);
	printf("Your value: %f \n\n", result);

	printf("multiplying 3.1 and 2.3... \n");
	result = mult(3.1, 2.3);
	printf("Correct value: %f \n", 7.13);
	printf("Your value: %f \n\n", result);

	printf("multiplying 0.987654 and 3.21... \n");
	result = mult(0.987654, 3.21);
	printf("Correct value: %f \n", 3.17036934);
	printf("Your value: %f \n\n", result);

/*
	printf("printing the second test file... \n");
	printf("multiplying 10 and 10... \n");
	result = mult(10, 10);
	printf("Multiplication Result: %f \n\n", result);

	printf("printing the third test file... \n");
	printf("multiplying 0 and 0... \n");
	result = mult(0, 0);
	printf("Multiplication Result: %f \n\n", result);

	printf("printing the forth test file... \n");
	printf("multiplying 'a' and 'b'... \n");
	result = mult('a', 'b');
	printf("Multiplication Result: %f \n\n", result);

	printf("printing the fifth test file... \n");
	printf("multiplying -7.6 and -4... \n");
	result = mult('a', 'b');
	printf("Multiplication Result: %f \n\n", result);
*/

	return 0;
}
