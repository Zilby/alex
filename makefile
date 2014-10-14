all: main.o pl.o 
	gcc -o Run main.o pl.o
	./Run
	make clean

main.o: main.c pl.h
	gcc -c main.c

pl.o: pl.c pl.h
	gcc -c pl.c

clean: 
	rm *o
	rm ./Run
