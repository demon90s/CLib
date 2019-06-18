CC = gcc
CFLAGS = -g -Wall -std=c99

main: main.o list.o test_list.o 

list.o: list.c list.h
main.o: main.c list.h test_list.h 
test_list.o: test_list.c test_list.h list.h

clean:
	-rm -f *.o main
