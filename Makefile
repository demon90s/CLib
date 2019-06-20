CC = gcc
CFLAGS = -g -Wall -std=c89

main: main.o \
	array.o \
	list.o \
	stack.o \
	stdinread.o \
	test_array.o \
	test_list.o \
	test_stack.o \
	test_stdinread.o

array.o: array.c array.h
list.o: list.c list.h
main.o: main.c list.h test_list.h test_stack.h test_stdinread.h
stack.o: stack.c stack.h
stdinread.o: stdinread.c stdinread.h
test_array.o: test_array.c test_array.h
test_list.o: test_list.c test_list.h list.h
test_stack.o: test_stack.c test_stack.h stack.h
test_stdinread.o: test_stdinread.c stdinread.h

clean:
	-rm -f *.o main
