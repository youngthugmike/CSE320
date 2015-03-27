#include <stdio.h>
#include "/user/cse320/Projects/project05.support.h"
#include "/user/cse320/lib/bitlib.h"

int main(){
	int curr_base = 0;  ///> current base
	int result = 0;     ///> 0=fail, 1 = succ

	char test_1[80];
	curr_base = 8;
	int input = 25;
	result = convert(input, curr_base, test_1);
	printf("\n Input= %d\n Base= %d\n Converted= %s\n Result= %d\n", input, curr_base,test_1, result);

	char test_2[80];
	curr_base = 2;
	input = -6;
	result = convert(input, curr_base, test_2);
	printf("\n Input= %d\n Base= %d\n Converted= %s\n Result= %d\n", input, curr_base,test_2, result);

	char test_3[80];
	curr_base = 16;
	input = 127;
	result = convert(input, curr_base, test_3);
	printf("\n Input= %d\n Base= %d\n Converted= %s\n Result= %d\n", input, curr_base,test_3, result);

	char test_4[80];
	curr_base = 36;
	input = 1000;
	result = convert(input, curr_base, test_4);
	printf("\n Input= %d\n Base= %d\n Converted= %s\n Result= %d\n", input, curr_base,test_4, result);

	char test_5[80];
	curr_base = 1000;
	input = -9999999;
	result = convert(input, curr_base, test_5);
	printf("\n Input= %d\n Base= %d\n Converted= %s\n Result= %d\n", input, curr_base,test_5, result);

	char test_6[80];
	curr_base = 17;
	input = 1998;
	result = convert(input, curr_base, test_6);
	printf("\n Input= %d\n Base= %d\n Converted= %s\n Result= %d\n", input, curr_base,test_6, result);

	char test_7[80];
	curr_base = 1;
	input = -9999999;
	result = convert(input, curr_base, test_7);
	printf("\n Input= %d\n Base= %d\n Converted= %s\n Result= %d\n", input, curr_base,test_7, result);

	char test_8[80];
	curr_base = 2;
	input = 0;
	result = convert(input, curr_base, test_8);
	printf("\n Input= %d\n Base= %d\n Converted= %s\n Result= %d\n", input, curr_base,test_8, result);

	return 0;
}
