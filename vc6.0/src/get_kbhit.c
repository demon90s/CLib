#include "get_kbhit.h"
#include <conio.h>

#define KEY_FUN				0x00
#define KEY_DIR				0xE0

int get_kbhit()
{
	int key1, key2;

	key1 = getch();

	switch (key1) {
	case KEY_FUN:
		key2 = getch();
		return -1;
		break;

	case KEY_DIR: {
		key2 = getch();
		switch (key2) {
		case 0x4B:
			return KEY_LEFT;
		case 0x4D:
			return KEY_RIGHT;
		case 0x48:
			return KEY_UP;
		case 0x50:
			return KEY_DOWN;
		default:
			return -1;	/* F11 F12 */
		}
	}
	break;
	}

	return key1;
}
