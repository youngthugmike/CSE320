proj06: project06.driver.o project06.support.o
	gcc project06.driver.o project06.support.o -o proj06

project06.driver.o: project06.driver.c
	gcc -Wall -c project06.driver.c

project06.support.o: project06.support.c
	gcc -Wall -c project06.support.c
