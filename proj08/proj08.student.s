
		.global main
		.section ".text"
		.align 4

main:		save	%sp, -96, %sp
		clr	%r16	! total characters
		clr	%r17	! number of white space characters
		clr	%r18	! number of octal digits
		clr	%r19	! number of decimal digits
		clr	%r20	! number of hexadecimal digits
		clr	%r21	! number of letters
		clr	%r22	! printable characters


loop:	call	getchar
		nop

		cmp	%r8, -1
		beq	end
		nop

		call	putchar
		nop

		inc	%r16




if:		cmp	%r8, 0x09	! Tab, r17
		be	then
		nop

		cmp	%r8, 0x0A	! new line, r17
		be	then
		nop

		cmp	%r8, 0x20	! space, r17
		be	then
		nop

		ba	ifDigit
		nop

then:		inc	%r17

ifDigit:	cmp	%r8, 0x39	! a digit
		bgt	endDigit
		nop

		cmp	%r8, 0x30
		blt	endDigit
		nop

		ba	thenDigit
		nop

thenDigit:
		inc	%r19
		inc	%r20

endDigit:

ifOctal:	cmp	%r8, 0x37	! an octal digit
		bgt	endOctal
		nop

		cmp	%r8, 0x30
		blt	endOctal
		nop

		ba	thenOctal
		nop
thenOctal:
		inc	%r18

endOctal:

ifHexU:		cmp	%r8, 'F'	! an hex digit (Upper)
		bgt	endHexU
		nop

		cmp	%r8, 'A'
		blt	endHexU
		nop

		ba	thenHexU
		nop
thenHexU:
		inc	%r20
endHexU:

ifHexL:		cmp	%r8, 'f'	! an hex digit (Upper)
		bgt	endHexL
		nop

		cmp	%r8, 'a'
		blt	endHexL
		nop

		ba	thenHexL
		nop
thenHexL:
		inc	%r20
endHexL:


ifLetterU:
		cmp	%r8, 'Z'	! an hex digit (Upper)
		bgt	endLetterU
		nop

		cmp	%r8, 'A'
		blt	endLetterU
		nop

		ba	thenLetterU
		nop
thenLetterU:
		inc	%r21
endLetterU:


ifLetterL:
		cmp	%r8, 'z'	! an hex digit (Upper)
		bgt	endLetterL
		nop

		cmp	%r8, 'a'
		blt	endLetterL
		nop

		ba	thenLetterL
		nop
thenLetterL:
		inc	%r21
endLetterL:


ifPrintable:
		cmp	%r8, 0x20
		blt	endPrintable
		nop

		cmp	%r8, 0x7E
		bgt	endPrintable
		nop

		ba	thenPrintable
		nop
thenPrintable:
		inc	%r22
endPrintable:


endif:	cmp	%r8, -1
		beq	end
		nop

		ba	loop
		nop


end:		set	fmt, %r8
		mov	%r16, %r9
		call	printf
		nop

		set	fmt1, %r8
		mov	%r17, %r9
		call	printf
		nop

		set	fmt2, %r8
		mov	%r18, %r9
		call	printf
		nop

		set	fmt3, %r8
		mov	%r19, %r9
		call	printf
		nop

		set	fmt4, %r8
		mov	%r20, %r9
		call	printf
		nop

		set	fmt5, %r8
		mov	%r21, %r9
		call	printf
		nop

		set	fmt6, %r8
		mov	%r22, %r9
		call	printf
		nop

		ret
		restore

fmt:		.asciz	"\nNumber of Characters = %d\n"
fmt1:		.asciz	"Number of white space characters = %d\n" ! suppose to be 25
fmt2:		.asciz	"Number of octal digits = %d\n"
fmt3:		.asciz	"Number of decimal digits = %d\n"
fmt4:		.asciz	"Number of hexadecimal digits = %d\n"
fmt5:		.asciz	"Number of letters = %d\n"
fmt6:		.asciz	"Number of printable characters = %d\n\n"
