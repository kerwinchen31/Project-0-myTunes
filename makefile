all: main.o linked_list.o music_library.o
	gcc driver.o linked_list.o music_library.o


main.o: main.c linked_list.h music_library.h
	gcc -c main.c


linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c


music_library.o: music_library.c music_library.h
	gcc -c music_library.c

clean:
	rm *.o

run:
	./a.out
