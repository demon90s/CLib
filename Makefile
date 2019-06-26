CC = gcc
CFLAGS = -g -Wall -std=c89

# target
main: main.o \
	unity.o \
	except.o \
	assert.o \
	array.o \
	list.o \
	stack.o \
	stdinread.o \
	test_array.o \
	test_list.o \
	test_stack.o \
	test_stdinread.o \
	test_except.o

# unity is an external unit test library
unity.o: unity/unity.c
	$(CC) $(CFLAGS) -o $@ -c $<

# internal library
except.o: except/except.c except/except.h
	$(CC) $(CFLAGS) -o $@ -c $<

assert.o: except/assert.c except/assert.h
	$(CC) $(CFLAGS) -o $@ -c $<

array.o: array.c array.h
list.o: list.c list.h
main.o: main.c unity/unity.h unity/unity_internals.h test_except.h \
 test_array.h test_list.h list.h test_stack.h test_stdinread.h
stack.o: stack.c stack.h
stdinread.o: stdinread.c stdinread.h
test_array.o: test_array.c test_array.h array.h
test_except.o: test_except.c test_except.h except/except.h unity/unity.h \
 unity/unity_internals.h
test_list.o: test_list.c test_list.h list.h
test_stack.o: test_stack.c unity/unity.h unity/unity_internals.h \
 test_stack.h stack.h
test_stdinread.o: test_stdinread.c stdinread.h

clean:
	-rm -f *.o main core*
