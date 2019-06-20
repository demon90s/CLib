#include <stdio.h>
#include <ctype.h>
#include "get_kbhit.h"

void test_get_kbhit();

int main()
{
	test_get_kbhit();

	return 0;
}

void test_get_kbhit()
{
	int c;

	printf("Enter ESC to quit\n");

	while (1) {

		c = get_kbhit();

		switch (c) {
		case KEY_UP:
			printf("you enter UP\n");
			break;
		case KEY_DOWN:
			printf("you enter DOWN\n");
			break;
		case KEY_LEFT:
			printf("you enter LEFT\n");
			break;
		case KEY_RIGHT:
			printf("you enter RIGHT\n");
			break;

		default:
			if (isalnum(c)) {
				printf("you enter %c\n", c);
			}
			else {
				printf("you enter 0x%x\n", c);
			}
		}

		if (c == KEY_ESC)
			break;
	}
}