#include "/user/cse320/Projects/project07.support.h"
#include "/user/cse320/Projects/project07.hardware.h"

//-- decompose the IR into the appropriate fields
//-- use the 5-bit "rs1" and "rs2" fields as signals to the register file
//-- compute a result based on the values copied out of the register file
//-- use the 5-bit "rd" field as a signal and update the register file


signal2 get_op(signal32);
signal3 get_op2(signal32);
signal6 get_op3(signal32);
signal1 get_i(signal32);                                          //chenxi28
signal5 get_rs1(signal32);                                        //A46959341
signal5 get_rs2(signal32);
signal5 get_rd(signal32);
signal13 get_simm(signal32);
signal22 get_imm(signal32);

void execute()
{

	signal5 op, op2, op3,
	 rs1, rs2, i, c, rd,
	simm, imm, RS1, RS2,
	 temp, result;//they all 32-bit

	//parts
	c = (PSR & 0x00100000) >> 20; //C-bit
	op = get_op(IR);
	op2 = get_op2(IR);
	op3 = get_op3(IR);
	i = get_i(IR); //i-bit
	rs1 = get_rs1(IR);
	rs2 = get_rs2(IR);
	rd = get_rd(IR);
	simm = get_simm(IR);
	imm = get_imm(IR);
	//PSR = PSR | 0x00000001;
	//test only//
	//deleting//

/*
	printf("IR: %08X \n", IR);
	printf("op: %01X \n", op);
	printf("op2: %03X \n", op2);
	printf("op3: %02X \n", op3);
	printf("i: %01X \n", i);
	printf("rs1: %02X \n", rs1);
	printf("rs2: %02X \n", rs2);
	printf("rd: %02X \n", rd);
	printf("simm: %03x \n", simm);
	printf("imm: %22X \n", imm);
*/

	//Sethi
	if (op == 0x0 && op2 == 0x4){ // op=0, op2=4 >>> sethi
		printf("sethi");
			result = imm << 10;
			write_reg_file(rd, result);
			PSR = PSR & 0xFFFFFFFE;
		}

	else if (op == 0x2) { //op=2
			read_reg_file(rs1, rs2, &RS1, &RS2);
			if (i == 0x00000000){ //i = 0
				temp = RS2;
			}
			else
			{
				temp = RS2; // i really didn't figure out this part
			}
			//Add
			if ((op3 == 0x0)){
				//printf("Add");
				//printf("temp: %18X \n", temp);
				//printf("RS2: %18X \n", RS2);
				result = RS1 + temp;
			}

			//Sub
			else if ((op3 == 0x4)){
				//printf("sub");
				result = RS1 - temp;
			}

			//Addx
			else if ((op3 == 0x8)){
				//printf("Addx");
				result = RS1 + temp + c;
			}

			//Subx
			else if (op3 == 0xC){
				//printf("Subx");
				result = RS1 - temp - c;
			}

			//And
			else if ((op3== 0x1)){
				//printf("And");
				result = RS1 & temp;
			}

			//Or
			else if (op3 == 0x2){
				//printf("or");
				result = RS1 | temp;
			}

			//Xor
			else if (op3 == 0x3)
			{
				//printf("Xor");
				result = RS1 ^ temp;
			}

			//Andn
			else if (op3 == 0x5){
				//printf("Andn");
				result = RS1 & ~temp;
			}

			//Orn
			else if (op3 == 0x6){
				//printf("Orn");
				result = RS1 | ~temp;
			}

			//Xnor
			else if (op3 == 0x7)
			{
				//printf("Xnor");
				result = RS1 ^ ~temp;
			}

			//else if ((op3 & 0x0f) == )
			if (rd != 0x0) {
				write_reg_file(rd, result);
				PSR = PSR & 0xFFFFFFFE;
			}
			else if(rd == 0x0) {
				PSR = PSR | 0x1; //assign one
			}
			else{
				PSR = PSR | 0x1; //assign one
			}
		}

	else{//illegal(ex. op=3)
		PSR = PSR | 0x1; //assign one
	}
}

// getters for IR//
signal2 get_op(signal32 ir){
	return (ir >> 30) & 0x3;
}

signal6 get_op3(signal32 ir){
	return (ir >> 19) & 0x3f;
}

signal1 get_i(signal32 ir){
	return (ir >> 13) & 0x1;
}

signal5 get_rs1(signal32 ir){
	return (ir >> 14) & 0x1f;
}

signal5 get_rs2(signal32 ir){
	return (ir) & 0x1f;
}

signal5 get_rd(signal32 ir){
	return (ir >> 25) &0x1f;
}

signal13 get_simm(signal32 ir){
	return (ir << 19) >> 19;
}

signal22 get_imm(signal32 ir){
	return (ir & 0x3fffff);
}

signal3 get_op2(signal32 ir){
	return (ir >> 22) & 0x7;
}
