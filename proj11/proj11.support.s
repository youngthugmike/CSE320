                .section            ".text"
                .align              4

                .global             absolute
                .global             modulo
                .global             factorial
                .global             power
                .global             cosine
modulo:
        		save		        %sp,-96,%sp
        		std 		        %i0, [%sp+96]
        		ldd 		        [%sp+96], %f30
        		std			        %i2, [%sp+96]
        		ldd			        [%sp+96], %f28
                set                 inf, %l2
                ldd                 [%l2], %f2
                set                 nan, %l4
                ldd                 [%l4], %f4
                set 		        zero,%l0
                ldd			        [%l0],%f6
                fcmpd 		        %f30,%f2
                fbe			        INF
                nop
                fcmpd 		        %f30,%f4
        		fbe			        NAN
        		nop
                fcmpd 		        %f28,%f2
        		fbe			        NAN
        		nop
                fcmpd 		        %f28,%f4
        		fbe			        NAN
        		nop
                fcmpd 		        %f28,%f6
                fbe			        NAN
                nop
        		fdivd		        %f30,%f28,%f0
        		fdtoi		        %f0,%f0
        		fitod 		        %f0,%f0
        		fmuld 		        %f28,%f0,%f0
        		fsubd 		        %f30,%f0,%f0
        		ret
        		restore

absolute:
                save                %sp, -96, %sp
                std                 %i0, [%sp+96]
                ldd                 [%sp+96], %f26
                set                 -1, %l0
                std                 %l0, [%sp+96]
                ldd                 [%sp+96], %f24
                set                 0, %l4
                std                 %l4, [%sp+96]
                ldd                 [%sp+96], %f4
                fitod               %f4, %f4
                fitod               %f24, %f24
                fcmpd               %f26, %f4
                fbge                positive
                nop
                fmuld               %f26, %f24, %f0
                ret
                restore
positive:
                fmovd               %f26, %f0
                ret
                restore

power:
                save		        %sp, -96, %sp
                set                 inf, %l2
                ldd                 [%l2], %f2
                set                 nan, %l4
                ldd                 [%l4], %f4
        		std 		        %i0, [%sp+96]
        		ldd 		        [%sp+96],%f16
        		std			        %i2, [%sp+96]
        		ldd			        [%sp+96], %f14
        		fitod 		        %f14,%f14
        		set 		        one,%l0
        		ldd 		        [%l0],%f12
        		fcmpd 		        %f16,%f12
        		fbe 		        no_loop
        		nop
        		fcmpd 		        %f14,%f12
        		fble 		        no_loop
        		nop
                fcmpd               %f16, %f2
                fbe                 INF
                nop
                fcmpd               %f16, %f4
                fbe                 NAN
                nop
                fcmpd               %f14, %f2
                fbe                 INF
                nop
                fcmpd               %f14, %f4
                fbe                 NAN
                nop
        		fmovd 		        %f16,%f0
power_loop:
        		fsubd 		        %f14, %f12, %f14
        		fcmpd 		        %f14, %f12
        		fbl 		        end
        		nop
        		fmuld 		        %f16,%f0,%f0
        		ba 			        power_loop
        		nop
no_loop:
        		set 		        zero,%l0
        		ldd 		        [%l0],%f12
        		fcmpd 		        %f14,%f12
        		fbe 		        result_1
        		nop
        		fmovd 		        %f16,%f0
                ba                  end
                nop
end:
        		ret
        		restore

factorial:
                save		        %sp, -96, %sp
                set 		        zero, %l0
                ldd 		        [%l0], %f20
                set                 inf, %l2
                ldd                 [%l2], %f2
                set                 nan, %l4
                ldd                 [%l4], %f4
        		std 		        %i0, [%sp+96]
        		ldd			        [%sp+96], %f22
        		fitod 		        %f22, %f22
        		fcmpd 		        %f22, %f20
        		fbe 		        result_1
        		nop
                fcmpd 		        %f22, %f2
                fbe 		        INF
                nop
                fcmpd 		        %f22, %f4
                fbe 		        NAN
                nop
        		fmovd 		        %f22, %f18
        		set 		        one, %l0
        		ldd 		        [%l0], %f20
factorial_loop:
        		fcmpd 		        %f18, %f20
        		fble		        factorial_end
        		nop
        		fsubd 		        %f18, %f20, %f18
        		fmuld 		        %f18, %f22, %f22
        		ba 			        factorial_loop
        		nop
result_1:
        		set 	 	        one,%l0
        		ldd 		        [%l0],%f0
                ret
                restore
factorial_end:
        		fmovd 		        %f22,%f0
                ret
                restore

cosine:
        		save		        %sp,-96,%sp
        		std 		        %i0, [%sp+96]
        		ldd 		        [%sp+96],%f6		! Parameter
        		set 		        zero, %l0
        		ldd			        [%l0], %f4          ! 0
        		fcmpd 		        %f4,%f6 			! arg is 0, return 1
        		fbe 		        one_done
        		nop
        		set 		        nan, %l0
        		ldd			        [%l0], %f4
        		fcmpd 		        %f4,%f6 			! arg is NAN, return NAN
        		fbe 		        NAN
        		nop
        		set 		        inf, %l0
        		ldd			        [%l0], %f4
        		fcmpd 		        %f4,%f6 			! arg is +INF, return NAN
        		fbe 		        NAN
        		nop
        		set 		        0, %l0 				! a counter
                ba                  cosine_loop
                nop
cosine_loop:
                set                 -1, %l2
                std                 %l0, [%sp+96]
                ldd                 [%sp+96], %f24
                set                 2, %l4
                std                 %l2, [%sp+96]
                ldd                 [%sp+96], %f26
                smul                %l0, 2, %l4                 ! 2k
                mov                 %l2, %o0
                mov                 %l0, %o2
                call                power
                nop
                fmovd 		        %f0,%f30                !(-1)^k
                mov                 %l0, %o0
                mov                 %l4, %o2
                call                power
                nop
                fmovd       		%f0, %f28                      !(x)^(2k)
                fmuld               %f30, %f28, %f28
                mov                 %l0, %i0
                call                factorial
                nop
                fmovd 		        %f0,%f26                      ! (2k)!
                fdivd		        %f28,%f16,%f0
                fdtoi		        %f0,%f0
                fitod 		        %f0,%f0
                inc                 %l0
                call                absolute
                nop
                set                 pre, %l5               ! compare with the precision value
                ldd                 [%l5], %f14
                fcmpd               %f0, %f14
                fble                cosine_done
                nop
                ba                  cosine_loop
                nop
one_done:
                set 		        one,%l0
                ldd 		        [%l0],%f0
                ret
                restore
cosine_done:
                ret
                restore

!---------------------------------------------------------no time to debug, lol

NAN:
                set 		        nan,%l0
                ldd			        [%l0],%f0
                ret
                restore

INF:
                set 		        inf,%l0
                ldd			        [%l0],%f0
                ret
                restore

                .section	        ".data"
                .align		        8

zero:	.double 	0r0
nan: 	.double 	0rnan
one: 	.double 	0r1
inf: 	.double 	0rinf
two:    .double     0r2
pre:    .double     0r0.0000000001
