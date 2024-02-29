run: lab05
	./lab05 < in

all: lab05

lab05: lab05.o ultron.o 
	gcc -Wall -Werror lab05.o ultron.o -lm -g -o lab05


lab05.o: lab05.c ultron.h
	gcc -std=c99 -Wall -Werror -g -c lab05.c

ultron.o: ultron.c ultron.h
	gcc -std=c99 -Wall -Werror -g -c ultron.c
