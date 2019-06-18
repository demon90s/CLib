#ifndef STDIN_READ_H
#define STDIN_READ_H

typedef enum BOOL_ { FALSE, TRUE } BOOL;

// skip the rest of line, return skipped count, 不包括\n
int stdinread_skip();

BOOL stdinread_char(char *c);

BOOL stdinread_int(int *v);

BOOL stdinread_float(float *v);

// 读一行，不包含换行符号，len是str空间长度
BOOL stdinread_line(char* str, int len);

#endif // STDIN_READ_H
