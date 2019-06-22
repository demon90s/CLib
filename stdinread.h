#ifndef STDIN_READ_H
#define STDIN_READ_H

typedef enum BOOL_
{ FALSE, TRUE } BOOL;

/* skip the rest of line, return skipped count, this count not include \n */
int stdinread_skip();

BOOL stdinread_char(char *c);

BOOL stdinread_int(int *v);

BOOL stdinread_float(float *v);

/* read a line, store it into str not include \n, the buffer size is len*/
BOOL stdinread_line(char *str, int len);

#endif /* STDIN_READ_H */
