                .section     ".text"
                .align      4
                .global     search
                .global     delete
                .global     insert
search:
            	save	    %sp, -96, %sp
            	mov	        %i0, %l0		             !table address
            	mov	        %i1, %l1		             !ID
            	lduh	    [%i0+2], %l2		         !student count
            	ld	        [%i0+8], %l3		         !student
            	clr	        %l4                          !count of loops

searchloop:
            	cmp	        %l2, %l4                     !looked for everything
            	ble	        notfind
            	nop

            	ld	        [%l3+0], %l5	           	 !ID
            	cmp	        %l5, %i1		             !cmp tp the input id
            	be	        find		                 !find
            	nop

            	cmp	        %l5, %i1		             !cmp to the input id
            	bg	        notfind		                 !not find
            	nop

            	add	        %l3, 44, %l3		         !next
                inc	        %l4			                 !inc count

            	ba	        searchloop                   !back to top
            	nop

notfind:
            	set	        0, %i0                       !return 0
            	st          %l3, [%i2+0]                 !return the one that we stopped at
                ret                                      !so we know where to insert
                restore

find:
            	set	1, %i0                               !return 1
            	st	%l3, [%i2+0]                         !return address
                ret
                restore



delete:
                save        %sp, -96, %sp
                mov         %i0, %l0                     !table address
                mov         %i1, %l1                     !id
                lduh        [%l0+2], %l2                 !student count

                mov         %l0, %o0
                mov         %l1, %o1
                mov         %sp, %o2

                call        search                       !search
                nop

                mov         %o0, %l3                     !result
                ld          [%o2], %l4                   !student address

                cmp         %l3, 0
                be          notdeleted                   !no such student
                nop

                ld          [%l0+8], %l5                 !number of bytes
                sub         %l4, %l5, %l5
                sdiv        %l5, 44, %l5
                sub         %l2, %l5, %l5
                smul        %l5, 44, %o2

                sub         %l2, 1, %l2                  !student count -1
                stuh        %l2, [%i0+2]                 !table count
                mov         %l4, %o0
                add         %o0, 44, %o1

                call        memmove
                nop

                set         1, %i0                       !delete successed
                ret
                restore

notdeleted:
                set         0, %i0
                ret
                restore




insert:
            	save        %sp, -96, %sp
            	mov         %i0, %l0		             !table address
            	mov         %i1, %l1		             !id
            	lduh        [%l0+0], %l2		         !capacity
            	lduh        [%l0+2], %l3		         !student count

            	cmp         %l3, %l2		             !full
            	bge         notinserted
            	nop

            	mov         %l0, %o0
            	mov         %l1, %o1
            	mov         %sp, %o2

            	call        search
            	nop

            	mov         %o0, %l4                     !search results
            	ld          [%o2], %l6		             !find student address

            	cmp 	    %l4, 1
            	be          notinserted		             !student already exists
            	nop

            	ld          [%l0+8], %l7                 !how many bytes to move
            	sub         %l6, %l7, %l7
            	sdiv	    %l7, 44, %l7
            	sub	        %l3, %l7, %l7
            	smul	    %l7, 44, %o2

                add         %o1, 44, %o0		         !destination
            	mov         %l6, %o1		             !source

            	call        memmove
            	nop

            	add         %l3, 1, %l3		             !count++
            	stuh        %l3, [%i0+2]		         !table count++

            	st          %i1, [%l6+0]		         !id
                st          %i2, [%i6+4]                 !name
            	stuh        %i3, [%l6+30]                !exam 1
            	stuh        %i4, [%l6+32]                !exam 2
            	stuh        %i5, [%l6+34]                !hw

            	clr 	    %l5
            	addcc       %i3, %i4, %l5		         !total
            	addcc       %l5, %i5, %l5
            	st          %l5, [%l6+36]

            	set         1, %i0                       !insert successful
                ret
                restore

notinserted:
            	set         0, %i0
                ret
                restore
