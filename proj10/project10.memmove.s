
/******************************************************************************
  Given two 12-byte records, use "memmove" to copy one record over the top
  of the other record, then display that area of memory.

  Translation:

    gcc /user/cse320/Projects/project10.memmove.s /user/cse320/lib/reglib.o
******************************************************************************/

        .global  main
 
        .section ".text"
        .align   4
  main:
        save     %sp, -112, %sp
 
        set      pointA, %o0
        set      pointB, %o1
        mov      12, %o2   
        call     memmove
        nop
 
        set      pointA, %o0
        set      pointB+12, %o1
        call     memory 
        nop
 
        ret
        restore
 
        .section ".data"
        .align   4
  pointA:
        .byte    'A'               ! Label
        .align   4
        .word    12, 16            ! X and Y coordinates
  pointB:
        .byte    'B'               ! Label
        .align   4
        .word    19, 14            ! X and Y coordinates
 
