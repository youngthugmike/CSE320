#include <stdio.h>
#include "/user/cse320/Projects/project12.support.h"

int main(){
    unsigned nPC,PC,IR,PSR;
    nPC = 0x00010004;
    PC = 0x00010000;
    IR = 0xABC0E080;
    PSR = 0x00000000;
    nPC = update(nPC, PC,IR,PSR);
    printf("IR is %8.8x   ,nPC is %8.8X\n",IR,nPC);
    nPC = update( 0x00010004, 0x00010000, 0x94014006, 0x00000000 );
	printf("ADDITION >> IR: %08x nPC: %08x \n", IR, nPC);
	nPC = update( 0x00010004, 0x00010000, 0x10800002, 0x00000000 );
	printf("BA >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x1a800002, 0x00000000 );
    printf("BCC >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x0a800002, 0x00000000 );
    printf("BCS >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x02800002, 0x00000000 );
    printf("BE >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x14800002, 0x00000000 );
    printf("BG >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x16800002, 0x00000000 );
    printf("BGE >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x18800002, 0x00000000 );
    printf("BGU >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x06800002, 0x00000000 );
    printf("BL >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x04800002, 0x00000000 );
    printf("BLE >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x08800002, 0x00000000 );
    printf("BLEU >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x00800002, 0x00000000 );
	printf("BN >> IR: %08x nPC: %08x \n", IR, nPC);
	nPC = update( 0x00010004, 0x00010000, 0x12800002, 0x00000000 );
	printf("BNE >> IR: %08x nPC: %08x \n", IR, nPC);
	nPC = update( 0x00010004, 0x00010000, 0x0c800002, 0x00000000 );
	printf("BNEG >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x1c800002, 0x00000000 );
	printf("BPOS >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x1EBFFFF8, 0x00000000 );
	printf("BVC >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x0e800002, 0x00000000 );
	printf("BVS >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0x4000004A, 0x00000000 );
    printf("CALL >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0xABC0E080, 0x00000000 );
    printf("JMPL >> IR: %08x nPC: %08x \n", IR, nPC);
    nPC = update( 0x00010004, 0x00010000, 0xE802A040, 0x00000000 );
    printf("LD >> IR: %08x nPC: %08x \n", IR, nPC);
	nPC = update( 0x00010004, 0x00010000, 0x292A1908, 0x00000000 );
	printf("SETHI >> IR: %08x nPC: %08x \n", IR, nPC);
	nPC = update( 0x00010004, 0x00010000, 0xC6228011, 0x00000000 );
	printf("ST >> IR: %08x nPC: %08x \n", IR, nPC);
    return 0;
}
