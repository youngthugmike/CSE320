
proj09: proj09.driver.o proj09.support.o /user/cse320/lib/reglib.o
	gcc proj09.driver.o proj09.support.o /user/cse320/lib/reglib.o /user/cse320/lib/bitlib.o -o proj09

proj09.driver.o: proj09.driver.c
	gcc -Wall -c proj09.driver.c

proj09.support.o: proj09.support.s
	gcc -Wall -c proj09.support.s
