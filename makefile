Tunez: library.c library.h list.h Tunez.c main.c list.o library.o
	gcc -c Tunez.c library.c
	gcc main.c
run:
	./a.out
clean:
	rm *~
