all: library.o node.o main.o
	gcc -o a library.o main.o node.o

library.o: library.c library.h
	gcc -c library.c

node.o: node.c node.h
	gcc -c node.c

main.o: main.c library.h node.h
	gcc -c main.c

clean:
	rm *.o

run: all
	./a
