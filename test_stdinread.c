#include "stdinread.h"
#include <stdio.h>

void test_stdinread()
{
	char ch;
	int i;
	float f;
	char str[12];

	printf("Enter a char: ");
	if (stdinread_char(&ch))
		printf("read char: %c\n", ch);
	else
		printf("[ERROR] read char failed\n");

	printf("Enter a int: ");
	if (stdinread_int(&i))
		printf("read int: %d\n", i);
	else
		printf("[ERROR] read int failed\n");

	printf("Enter a float: ");
	if (stdinread_float(&f))
		printf("read float: %f\n", f);
	else
		printf("[ERROR] read float failed\n");

	printf("Enter line: ");
	if (stdinread_line(str, sizeof(str)))
		printf("read line: %s\n", str);
	else
		printf("[ERROR read line failed\n");
}
