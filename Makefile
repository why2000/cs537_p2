

prodcom: prodcom.o
	gcc -Wall -Wextra -o prodcom prodcom.o


prodcom.o: prodcom.c
	gcc -c prodcom.c


clean:
	-rm prodcom
