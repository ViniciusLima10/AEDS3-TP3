### MAKEFILE ###

all: main clean

main: shiftAnd.o bruteForce.o kmp.o manipulaArquivos.o main.o

	gcc shiftAnd.o bruteForce.o kmp.o manipulaArquivos.o main.o -o tp3.out


main.o: main.c ./headers/manipulaArquivos.h
	gcc -c main.c

manipulaArquivos.o: manipulaArquivos.c ./headers/manipulaArquivos.h
	gcc -c manipulaArquivos.c

shiftAnd.o: shiftAnd.c ./headers/shiftAnd.h
	gcc -c shiftAnd.c

bruteForce.o: bruteForce.c ./headers/bruteForce.h
	gcc -c bruteForce.c

kmp.o: kmp.c ./headers/kmp.h
	gcc -c kmp.c

clean:
	rm *.o