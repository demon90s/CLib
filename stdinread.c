#include "stdinread.h"
#include <stdio.h>
#include <ctype.h>

int stdinread_skip()
{
	int skipped = 0;
	while (getchar() != '\n') ++skipped;
	return skipped;
}

BOOL stdinread_char(char *c)
{
	scanf(" %c", c);
	return stdinread_skip() == 0;
}

BOOL stdinread_int(int *v)
{
	int res;

	res = scanf("%d", v);
	if (stdinread_skip() != 0)
		return FALSE;

	return res == 1 ? TRUE : FALSE;	
}

BOOL stdinread_float(float *v)
{
	int res;

	res = scanf("%f", v);
	if (stdinread_skip() != 0)
		return FALSE;

	return res == 1 ? TRUE : FALSE;
}

BOOL stdinread_line(char* str, int len)
{
	int ch, i = 0;
	BOOL ret = TRUE;

	while (isspace(ch = getchar()));

	while (1) {
		if (ch == '\n' || ch == EOF) break;

		if (i < len - 1)
        	str[i++] = ch;
		else
			ret = FALSE;

		ch = getchar();
	}

	str[i] = '\0';

	return ret;
}

