            .section    ".text"
            .align      4

.global     negate
negate:
            save     %sp, -96, %sp

            cmp      %r24, '0x80000000'
            be       error
            nop

            smulcc   %r24, -1, %r24      !time by -1
            bvs      error               !overflow
            nop

            ba       done
            nop


.global     absolute
absolute:
            save        %sp, -96, %sp

            cmp         %i0, 0
            blt         negative
            nop

            ba          done
            nop

negative:
            smulcc      %i0, -1, %i0
            bvs         error
            nop

            ba          done
            nop


.global     add
add:
            save        %sp, -96, %sp
            addcc       %i0, %i1, %i0
            bvs         error
            nop

            ba          done
            nop


.global     sub
sub:
            save        %sp, -96, %sp
            subcc       %i0, %i1, %i0
            bvs         error
            nop

            ba          done
            nop


.global     mul
mul:
            save        %sp, -96, %sp
            smulcc      %i0, %i1, %i0
            bvs         error
            nop

            ba          done
            nop


.global     divide

divide:
            save        %sp, -96, %sp

            cmp         %i0, 0
            be          zero
            nop

            cmp         %i0, 0
            blt         neg_divide_1
            nop

            cmp         %i1, 0
            be          error
            nop

            cmp         %i1, 0
            blt         neg_divide_2
            nop

            sdivcc      %i0, %i1, %i0
            bvs         error
            nop

            ba          done
            nop

.global     neg_divide_2
neg_divide_2:

            smulcc       %i1, -1, %i1

            sdivcc       %i0, %i1, %i0
            bvs          error
            nop

            smulcc       %i0, -1, %i0

            ba           done
            nop

.global     neg_divide_1
neg_divide_1:
            cmp         %i1, 0
            be          error
            nop

            smulcc      %i0, -1, %i0

            sdivcc      %i0, %i1, %i0
            bvs         error
            nop

            smulcc      %i0, -1, %i0

            ba          done
            nop



.global     zero
zero:       set         0x0000000, %i0
            ba          done
            nop


.global     remain
remain:
            save        %sp,-96,%sp

            cmp         %i1, 0
            be          one
            nop

            cmp         %i0, 0
            blt         neg_rmd_0
            nop


            cmp         %i1, 0
            blt         neg_rmd_2
            nop

            cmp         %i0, 0
            be          zero
            nop


            sdivcc      %i0,%i1,%l7
            bvs         error
            nop

            smulcc      %l7,%i1,%l7
            bvs         error
            nop

            subcc       %i0,%l7,%i0
            bvs         error
            nop

            ba          done
            nop

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
.global     neg_rmd_0                ! -, +
neg_rmd_0:
            cmp         %i1, 0
            be          error
            nop

            cmp         %i1, 0
            blt         neg_rmd_1
            nop

            smulcc      %i0, -1, %i0

            sdivcc      %i0, %i1, %l7
            bvs         error
            nop

            smulcc      %l7, %i1, %l7
            bvs         error
            nop

            subcc       %i0, %l7, %i0
            bvs         error
            nop

            smulcc      %i0, -1, %i0

            ba          done
            nop

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
.global neg_rmd_1                       ! -, -
neg_rmd_1:

            smulcc      %i0, -1, %i0
            smulcc      %i1, -1, %i1

            sdivcc      %i0, %i1, %l7
            bvs         error
            nop

            smulcc      %l7, %i1, %l7
            bvs         error
            nop

            subcc       %i0, %l7, %i0
            bvs         error
            nop

            smulcc      %i0, -1, %i0

            ba          done
            nop



!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
.global neg_rmd_2                           ! +, -
neg_rmd_2:
            smulcc      %i1, -1, %i1

            sdivcc      %i0, %i1, %l7
            bvs         error
            nop

            smulcc      %l7, %i1, %l7
            bvs         error
            nop

            subcc       %i0, %l7, %i0
            bvs         error
            nop

            ba          done
            nop


.global     power
power:      save        %sp, -96, %sp


            cmp         %i0,0
            be          one
            nop

            cmp         %i0,1
            be          done
            nop

            cmp         %i1,1
            be          done
            nop

            !smaller than 0
            cmp         %i1, 0
            blt         zero
            nop

            mov         %i1,%l0
            mov         %i0,%l1

power_loop:
            sub         %l0,1,%l0
            cmp         %l0,0
            be          done
            nop

            smulcc      %i0,%l1,%i0
            bvs         error

            ba          power_loop
            nop

one:
            set         0x0000001, %i0
            ba          done
            nop


.global     factorial
factorial:
            save        %sp,-96,%sp

            cmp         %i0,0
            blt         error
            !nop

            mov         %i0, %r16

loop_fact:
            cmp         %l0,1
            ble         done
            nop

            sub         %r16, 1, %r16
            smulcc      %i0, %r16, %i0
            bvs         error
            nop

            ba          loop_fact
            nop


error:
            set     0x80000000, %i0

done:       ret
            restore
