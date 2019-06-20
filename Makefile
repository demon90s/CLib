CC = gcc
CFLAGS = -g -Wall -std=c89

main: main.o list.o \
	stdinread.o \
	test_list.o \
	test_stdinread.o

list.o: list.c list.h
main.o: main.c list.h test_list.h
stdinread.o: stdinread.c stdinread.h
test_list.o: test_list.c test_list.h list.h
test_stdinread.o: test_stdinread.c stdinread.h

clean:
	-rm -f *.o main
