#include <stdio.h>

unsigned update( unsigned nPC, unsigned PC, unsigned IR, unsigned PSR ){
    unsigned reg[32];
    unsigned x, i, result, disp30, rs1, rs2, simm13, op, op3, op2, n, z, v, c, condition, disp22;
    op = (IR >> 30) & 0xf;
    op2 = (IR >> 22) & 0x7;
    op3 = (IR >> 19) & 0x3f;
    for(x = 0; x != 32; x++) {
        reg[x] = x + x * 256 + x * (256 * 256) + x * (256 * 256 * 256);
    }
    i = IR & 0x00002000;
    rs1 = (IR & 0x7c000) >> 14;
    rs2 = IR & 0x1F;
    simm13 = IR & 0x1FFF;
    condition = (IR & 0x3E000000) >> 25;
    disp22 = (IR & 0x3FFFFF);
    disp30 = IR << 2 >> 2;
    n = PSR << 8 >> 31;
    z = PSR << 9 >> 31;
    v = PSR << 10 >> 31;
    c = PSR << 11 >> 31;
    if (op == 1) {
        result = disp30 * 4 + PC;
    }

    else if (op == 2) {
        //print("op == 2 \n");
        //print("op3 =: %u \n", op3 );
        if(op3 == 56) {
            if(i == 0) {
                result = reg[rs1] + reg[rs2];
            } else {
                if (simm13 > 0x2000)
                {
                    simm13 = simm13 | 0xFFFFE000;
                }
                //print("i != 0, simm13 = %u, rs1 = %u \n", simm13, reg[rs1]);
                result = reg[rs1] + simm13;
            } // i != 0
        }
        else {
            result = nPC + 4;
        } // op3 != 56
    } // op == 2

    else if (op == 3) {
        result = nPC + 4;
        //printf("IR: %\n",IR);
    }

    else if (op == 0) {
        if (op2 == 4) {
            result = nPC + 4;
        }

        else if (op2 == 2) {
            if (condition == 0) {
                result=nPC+4;
            }

            if (condition == 1) {
                if(z)
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }

            if (condition == 2) {
                if(z || (n ^ v))
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }

            if (condition == 3) {
                if(n ^ v)
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }

            if (condition == 4) {
                if(c || z)
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }

            if (condition == 5) {
                if(c)
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }

            if (condition == 6) {
                if(n)
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }

            if (condition == 7) {
                if(v)
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }

            if (condition == 8) {
                result = disp22 * 4 + PC;
            }

            if (condition == 9) {
                if(!z)
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }

            if (condition == 10) {
                if(!(z || (n ^ v)))
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }

            if (condition == 11) {
                if(!(n ^ v))
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }

            if (condition == 12) {
                if(c==0 && z==0)
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }

            if (condition == 13) {
                if(!c)
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }

            if (condition == 14) {
                if(!n)
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }

            if (condition == 15) {
                if(!v)
                    result = disp22 * 4 + PC;
                else
                    result = nPC + 4;
            }
        }
    }
    return result;
}
