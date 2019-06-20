#ifndef GET_KBHIT_H
#define GET_KBHIT_H

#define KEY_ESC				0x1B
#define KEY_LEFT			0xE04B
#define KEY_RIGHT			0xE04D
#define KEY_UP				0xE048
#define KEY_DOWN			0xE050

/* get keyboard hit button, return -1 for not support */
int get_kbhit();

#endif /* GET_KBHIT_H */